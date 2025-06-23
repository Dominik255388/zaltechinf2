#include "Circle.h"

Circle::Circle(string name, float r) : Figure(name)
{
    m_r = r;
    m_area = 3.14 * (m_r*m_r);
    m_perimeter = 2*3.14 * m_r;
}

float Circle::Area() const
{
    return m_area;
}

float Circle::Perimeter() const
{
    return m_perimeter;
}

void Circle::Info() const
{
    cout << "Circle: " << Name() << endl;
    cout << "Dimension: " << m_r << endl;
    cout << "Area: " << m_area << endl;
    cout << "Perimeter: " << m_perimeter << endl;
}