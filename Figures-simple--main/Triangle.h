#ifndef UNTITLED59_TRIANGLE_H
#define UNTITLED59_TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure
{
private:
    float m_t;
    float m_area;
    float m_perimeter;

public:
    Triangle(string name = "", float t = 0);
    virtual ~Triangle() {}
    virtual float Area() const;
    virtual float Perimeter() const;
    virtual void Info() const;
};



#endif //UNTITLED59_TRIANGLE_H
