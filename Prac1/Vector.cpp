#include "Vector.h"

template <int n>
Vector<n>::Vector()
{
    arr = new float[n]();

    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

template <int n>
Vector<n>::Vector(std::initializer_list<float> list)
{
    arr = new float[n];

    int i = 0;

    for (std::initializer_list<float>::const_iterator it = list.begin(); it != list.end() && i < n; it++)
    {
        arr[i++] = *it;
    }

    while (i < n)
    {
        arr[i++] = 0;
    }
}

template <int n>
Vector<n>::Vector(float *f)
{
    arr = new float[n];

    if (f != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = f[i];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
    }
}

template <int n>
Vector<n>::~Vector()
{
    if (arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;
    }
}

template <int n>
Vector<n>::Vector(const Vector<n> &v)
{
    arr = new float[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = v[i];
    }
}

template <int n>
Vector<n>::Vector(const Matrix<n, 1> &m)
{
    arr = new float[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = m[i][0];
    }
}

template <int n>
Vector<n> &Vector<n>::operator=(const Vector<n> &v)
{
    if (this == &v)
    {
        return *this;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = v[i];
    }

    return *this;
}

template <int n>
Vector<n> Vector<n>::operator+(const Vector<n> v) const
{
    Vector<n> result;

    for (int i = 0; i < n; i++)
    {
        result.arr[i] = this->arr[i] + v.arr[i];
    }

    return result;
}

template <int n>
Vector<n> Vector<n>::operator-(const Vector<n> v) const
{
    Vector<n> result;

    for (int i = 0; i < n; i++)
    {
        result.arr[i] = this->arr[i] - v.arr[i];
    }

    return result;
}

template <int n>
Vector<n> Vector<n>::operator*(const float f) const
{
    Vector<n> result;

    for (int i = 0; i < n; i++)
    {
        result.arr[i] = this->arr[i] * f;
    }

    return result;
}

template <int n>
float Vector<n>::operator*(const Vector<n> v) const
{
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += this->arr[i] * v.arr[i];
    }

    return sum;
}

template <int n>
float Vector<n>::magnitude() const
{
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += this->arr[i] * this->arr[i]; // more efficient than pow. std::pow is slow, but accurate?
    }

    return std::sqrt(sum);
}

template <int n>
Vector<n>::operator Matrix<n, 1>() const
{
    Matrix<n, 1> m;
    for (int i = 0; i < n; i++)
    {
        m[i][0] = arr[i];
    }

    return m;
}

template <>
Vector<3> Vector<3>::crossProduct(const Vector<3> v) const
{
    return Vector<3>{arr[1] * v[2] - arr[2] * v[1], arr[2] * v[0] - arr[0] * v[2], arr[0] * v[1] - arr[1] * v[0]};
}

template <int n>
Vector<n> Vector<n>::unitVector() const
{
    float m = this->magnitude();

    if (m == 0)
    {
        throw "Invalid unit vector";
    }

    Vector<n> result(*this);

    for (int i = 0; i < n; i++)
    {
        result.arr[i] = this->arr[i] / m;
    }

    return result;
}

template <int n>
int Vector<n>::getN() const
{
    return n;
}
