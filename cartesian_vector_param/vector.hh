#pragma once

#include <ostream>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    //Vector(/*args*/);
    // Using initializer list as argument :
    Vector(std::initializer_list<value> list);

// Public Member functions here
    // Addition
    Vector& operator+=(const Vector& rhs);
    Vector operator+(const Vector& rhs);
    // Soustraction
    Vector& operator-=(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    // Multiplication
    value operator*(const Vector& rhs);
    // Brackets
    value& operator[](size_t i);
    value operator[](size_t i) const;

    // More to go

private:
// Private Member functions here
    // Data of the vector
    value data[NDIM];
// Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
// Output operator
std::ostream& operator<<(std::ostream& os, const Vector& v);
// Operator overloading
Vector operator*(Vector& rhs, const value v);
Vector operator*=(Vector& rhs, const value v);
Vector operator+=(Vector& rhs, const value v);
