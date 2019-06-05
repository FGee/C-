#pragma once
#include "textQuery.h"
#include "query.h"
#include <algorithm>
#include <iterator>

class Query;
class QueryBase
{
    friend class Query;
public:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default; //通过基类访问，那么也是通过基类的接口进行析构，所以，需要对析构函数进行virtual，这样就可以放与基类的虚表中，进行多态访问
private:
    virtual QueryResult eval(const TextQuery& tq) const = 0;
    virtual string rep() const = 0;
};

class WordQuery
: public QueryBase
{
    friend class Query;
public:
    WordQuery(string s) : _wordQuery(s) {}
    QueryResult eval(const TextQuery& tq) const { return tq.query(_wordQuery); }
    string rep() const { return _wordQuery; }
    string _wordQuery;
};

class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query& lhs, const Query& rhs);
    friend Query operator&(const Query& lhs, const Query& rhs);
public:
    //Query(const string& s) {}
    //Query(const string& s) { _spBase = shared_ptr<QueryBase>(new WordQuery(s)); }
    //Query(const string& s) { _spBase = make_shared<QueryBase>(new WordQuery(s)); } // 唯独这种方式不行，提示抽象基类不能实例化
    Query(const string& s) : _spBase(new WordQuery(s)) {}
    QueryResult eval(const TextQuery& tq) const { return _spBase->eval(tq); }
    string rep() const { return _spBase->rep(); }
private:
    Query(shared_ptr<QueryBase> spQuery) : _spBase(spQuery) {};
    shared_ptr<QueryBase> _spBase;
};

class NotQuery
: public QueryBase
{
    friend Query operator~(const Query&);
public:
    NotQuery(const Query& rhs) : _query(rhs) {}
    QueryResult eval(const TextQuery& tq) const;
    string rep() const { return "~(" + _query.rep() + ")"; }
    Query _query;
};

inline
Query operator~(const Query& rhs)
{
    return shared_ptr<QueryBase>(new NotQuery(rhs));
}

class BinaryQuery
: public QueryBase
{
protected:
    BinaryQuery(const Query& l, const Query& r, const string& op) 
        : _lhs(l), _rhs(r), _opSys(op) {}
    string rep() const { return "(" + _lhs.rep() + _opSys + _rhs.rep() + ")"; }
    Query _lhs;
    Query _rhs;
    string _opSys;
};

class AndQuery
: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
public:
    AndQuery(const Query& lhs, const Query& rhs)
        : BinaryQuery(lhs, rhs, "&") {}
    QueryResult eval(const TextQuery& tq) const;
};

inline
Query operator&(const Query& lhs, const Query& rhs)
{
    return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

class OrQuery
: public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
public:
    OrQuery(const Query& lhs, const Query& rhs)
        : BinaryQuery(lhs, rhs, "|") {}
    QueryResult eval(const TextQuery& tq) const;
};

inline
Query operator|(const Query& lhs, const Query& rhs)
{
    return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult NotQuery::eval(const TextQuery& tq) const
{
    auto tmpQr = _query.eval(tq);
    shared_ptr<set<line_no>> spSet(new set<line_no>());
    line_no n = tmpQr.get_file()->size();
    auto beg = tmpQr.begin();
    auto end = tmpQr.end();
    for (line_no i = 0; i < n; ++i) {
        if (beg == end || *beg != i) {
            spSet->insert(i);
        } else if (beg != end) {
            ++beg;
        } 
    }
    return QueryResult(rep(), tmpQr.get_file(), spSet);
}

QueryResult AndQuery::eval(const TextQuery& tq) const
{
    auto tmpLhs = _lhs.eval(tq);
    auto tmpRhs = _rhs.eval(tq);
    shared_ptr<set<line_no>> spSet(new set<line_no>());
    set_intersection(tmpLhs.begin(), tmpLhs.end(), 
                          tmpRhs.begin(), tmpRhs.end(), 
                          inserter(*spSet, spSet->begin()));
    return QueryResult(rep(), tmpLhs.get_file(), spSet);
}

QueryResult OrQuery::eval(const TextQuery& tq) const
{
    auto tmpLhs = _lhs.eval(tq);
    auto tmpRhs = _rhs.eval(tq);
    shared_ptr<set<line_no>> spSet(new set<line_no>());
    auto begLhs = tmpLhs.begin();
    auto endLhs = tmpLhs.end();
    for (; begLhs != endLhs; ++begLhs) {
        spSet->insert(*begLhs);
    }
    auto begRhs = tmpRhs.begin();
    auto endRhs = tmpRhs.end();
    for (; begRhs != endRhs; ++begRhs) {
        spSet->insert(*begRhs);
    }
    return QueryResult(rep(), tmpLhs.get_file(), spSet);
}
