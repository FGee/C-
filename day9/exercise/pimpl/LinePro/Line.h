#ifndef __LINE_H__  
#define __LINE_H__

class Line {
public:
    Line(float, float, float, float);
    ~Line();
    void printLine() const;
    float distance() const;
    class LineImply;
private:
    LineImply* _pLineImply;
};

#endif
