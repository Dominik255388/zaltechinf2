#include "Triangle.h"
#include <math.h>

Triangle::Triangle(string name, float t) : Figure(name)
{
    m_t = t;
    m_area = ((m_t*m_t)*sqrt(3))/4;
    m_perimeter = m_t*3;
}

float Triangle::Area() const
{
    return m_area;
}

float Triangle::Perimeter() const
{
    return m_perimeter;
}

void Triangle::Info() const
{
    cout << "Triangle: " << Name() << endl;
    cout << "Dimension: " << m_t << endl;
    cout << "Area: " << m_area << endl;
    cout << "Perimeter: " << m_perimeter << endl;
}
