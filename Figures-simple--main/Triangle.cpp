#include "Triangle.h"
#include <math.h>

Triangle::Triangle(string name, float t) : Figure(name)
{
    m_t = t;
}

float Triangle::Area() const
{
    return ((m_t*m_t)*sqrt(3))/4;
}

float Triangle::Perimeter() const
{
    return m_t*3;
}

void Triangle::Info() const
{
    cout << "Triangle: " << Name() << endl;
    cout << "Dimension: " << m_t << endl;
    cout << "Area: " << ((m_t*m_t)*sqrt(3))/4 << endl;
    cout << "Perimeter: " << m_t*3 << endl;
}
