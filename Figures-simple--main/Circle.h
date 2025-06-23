#ifndef UNTITLED59_CIRCLE_H
#define UNTITLED59_CIRCLE_H

#include "Figure.h"

class Circle : public Figure
{
private:
    float m_r;
    float m_area;
    float m_perimeter;

public:
    Circle(string name = "", float r = 0);
    virtual ~Circle() {}
    virtual float Area() const;
    virtual float Perimeter() const;
    virtual void Info() const;
};


#endif //UNTITLED59_CIRCLE_H
