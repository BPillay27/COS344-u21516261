#include "Triangle.h"

template <int n>
Triangle<n>::Triangle(const Vector<n> &p1, const Vector<n> &p2, const Vector<n> &p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

template <int n>
Triangle<n>::Triangle(const Triangle<n> &t)
{
    this->p1 = t.p1;
    this->p2 = t.p2;
    this->p3 = t.p3;
}

template <int n>
Triangle<n> &Triangle<n>::operator*=(const Matrix<n, n> &_matrix)
{
    Matrix<n, 1> m1;

    for (int i = 0; i < n; i++)
    {
        m1[i][0] = p1[i];
    }

    m1 = _matrix * m1;

    for (int i = 0; i < n; i++)
    {
        p1[i] = m1[i][0];
    }

    //--------------------------------------------------------------

    Matrix<n, 1> m2;

    for (int i = 0; i < n; i++)
    {
        m2[i][0] = p2[i];
    }

    m2 = _matrix * m2;

    for (int i = 0; i < n; i++)
    {
        p2[i] = m2[i][0];
    }

    //--------------------------------------------------------------

    Matrix<n, 1> m3;

    for (int i = 0; i < n; i++)
    {
        m3[i][0] = p3[i];
    }

    m3 = _matrix * m3;

    for (int i = 0; i < n; i++)
    {
        p3[i] = m3[i][0];
    }

    return *this;
}

template <int n>
Triangle<n> *Triangle<n>::operator*(const Matrix<n, n> &_matrix) const
{
    Triangle<n>* temp = new Triangle<n>(*this);
    (*temp) *= _matrix;
    return temp;
}

template <int n>
float *Triangle<n>::getPoints() const
{
    float *temp = new float[n * 3];

    for (int i=0; i < n; i++)
    {
        temp[i] = p1[i];
    }

    for (int i=0; i < 2 * n; i++)
    {
        temp[n+i] = p2[i];
    }

    for(int i=0;i<3*n;i++){
        temp[(2*n)+i]=p3[i];
    }
    
    return temp;
}

template <int n>
int Triangle<n>::getNumPoints() const
{
    return 3*n;
}