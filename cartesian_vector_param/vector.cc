# include "vector.hh"

# include <iostream>

Vector::Vector()
{
    for (size_t i = 0; i < NDIM; ++i)
        data[i] = 0;
}

Vector::Vector(std::initializer_list<value> list)
{
    size_t i = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        data[i] = *it;
        ++i;
    }
}

Vector& Vector::operator+=(const Vector& rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        data[i] += rhs.data[i];
    return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
    auto tmp = Vector();
    for (size_t i = 0; i < NDIM; ++i)
        tmp.data[i] = data[i] + rhs.data[i];
    return tmp;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    for (size_t i = 0; i < NDIM; ++i)
        data[i] -= rhs.data[i];
    return *this;
}

Vector Vector::operator-(const Vector& rhs)
{
    auto tmp = Vector();
    for (size_t i = 0; i < NDIM; ++i)
        tmp.data[i] = data[i] - rhs.data[i];
    return tmp;
}

value Vector::operator*(const Vector& rhs)
{
    value tmp = 0;
    for (size_t i = 0; i < NDIM; ++i)
        tmp += rhs[i] * (*this)[i];
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << "{";
    for (size_t i = 0; i < NDIM; ++i)
    {
        os << v[i];
        if (i != NDIM - 1)
            os << ",";
    }
    os << "}";
    return os;
}

Vector operator*(Vector& rhs, const value v)
{
    auto tmp = Vector();
    for (size_t i = 0; i < NDIM; ++i)
        tmp[i] = v * rhs[i];
    return tmp;
}

Vector operator*=(Vector& rhs, const value v)
{
    for (size_t i = 0; i < NDIM; ++i)
        rhs[i] *= v;
    return rhs;
}

Vector operator+=(Vector& rhs, const value v)
{
    for (size_t i = 0; i < NDIM; ++i)
        rhs[i] += v;
    return rhs;
}

value& Vector::operator[](size_t i)
{
    return data[i];
}

value Vector::operator[](size_t i) const
{
    return data[i];
}
