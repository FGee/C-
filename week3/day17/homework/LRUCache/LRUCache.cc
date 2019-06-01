#include <iostream>
#include <list>
#include <unordered_map>

using std::cout;
using std::endl;
using std::cin;
using std::make_pair;

class LRUCache {
public:
    struct CacheNode {
        CacheNode(int key, int value) : _key(key), _value(value) {}
        int _key;
        int _value;
    };
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto retIter = _hashMap.find(key);
        if (retIter == _hashMap.end()) {
            return -1;
        }
        int tmpValue = retIter->second->_value;
        _listCacheNode.splice(_listCacheNode.begin(), _listCacheNode, retIter->second);
        retIter->second = _listCacheNode.begin();
        return tmpValue;
    }

    void put(int key, int value) {
        auto retIter = _hashMap.find(key);
        if (retIter != _hashMap.end()) {
            retIter->second->_value = value;
            _listCacheNode.splice(_listCacheNode.begin(), _listCacheNode, retIter->second);
            retIter->second = _listCacheNode.begin();
            return;
        }
        if (_listCacheNode.size() == _capacity) {
            _hashMap.erase(_listCacheNode.back()._key);
            _listCacheNode.pop_back();
        }
        _listCacheNode.push_front(CacheNode(key, value));
        //_hashMap.insert(make_pair(key, _listCacheNode.begin()));
        _hashMap[key] = _listCacheNode.begin();
        return;
    }
private:
    size_t _capacity;
    std::list<CacheNode> _listCacheNode;
    std::unordered_map<int, std::list<CacheNode>::iterator> _hashMap;
};

int main()
{
    LRUCache cache( 2 /* capacity */ );
    cache.put(1, 1); cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

    return 0;
}

