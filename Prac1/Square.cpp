#include "Square.h"

template <int n>
Square<n>::Square(const Vector<n> &center, float height, float width)
{
    tl = center;
    tr = center;
    br = center;
    bl = center;

    tl[0] -= (width / 2);
    tl[1] += (height / 2);

    bl[0] -= (width / 2);
    bl[1] -= (height / 2);

    tr[0] += (width / 2);
    tr[1] += (height / 2);

    br[0] += (width / 2);
    br[1] -= (height / 2);
}

template <int n>
Square<n>::Square(const Vector<n> &tl, const Vector<n> &tr, const Vector<n> &br, const Vector<n> &bl)
{
    this->tl = tl;
    this->tr = tr;
    this->br = br;
    this->bl = bl;
}

template <int n>
Square<n>::Square(const Square<n> &_square)
{
    this->tl = _square.tl;
    this->tr = _square.tr;
    this->bl = _square.bl;
    this->br = _square.br;
}

template <int n>
Square<n> &Square<n>::operator*=(const Matrix<n, n> &_matrix)
{
    Matrix<n, 1> m_tl;

    for (int i = 0; i < n; i++)
    {
        m_tl[i][0] = tl[i];
    }

    m_tl = _matrix * m_tl;

    for (int i = 0; i < n; i++)
    {
        tl[i] = m_tl[i][0];
    }

    //-------------------------------------------------

    Matrix<n, 1> m_tr;

    for (int i = 0; i < n; i++)
    {
        m_tr[i][0] = tr[i];
    }

    m_tr = _matrix * m_tr;

    for (int i = 0; i < n; i++)
    {
        tr[i] = m_tr[i][0];
    }

    //-------------------------------------------------

    Matrix<n, 1> m_br;

    for (int i = 0; i < n; i++)
    {
        m_br[i][0] = br[i];
    }

    m_br = _matrix * m_br;

    for (int i = 0; i < n; i++)
    {
        br[i] = m_br[i][0];
    }

    //--------------------------------------------------

    Matrix<n, 1> m_bl;

    for (int i = 0; i < n; i++)
    {
        m_bl[i][0] = bl[i];
    }

    m_bl = _matrix * m_bl;

    for (int i = 0; i < n; i++)
    {
        bl[i] = m_bl[i][0];
    }

    return *this;
}

template <int n>
Square<n> *Square<n>::operator*(const Matrix<n, n> &_matrix) const
{
    Square<n> *temp = new Square<n>(*this);
    (*temp) *= _matrix;
    return temp;
}

template <int n>
float *Square<n>::getPoints() const
{
    float *temp = new float [4 * n];

    for (int i = 0; i < n; i++)
    {
        temp[i] = tl[i];
    }

    for (int i = 0; i < n; i++)
    {
        temp[n + i] = tr[i];
    }

    for (int i = 0; i < n; i++)
    {
        temp[(2 * n) + i] = br[i];
    }

    for (int i = 0; i < n; i++)
    {
        temp[(3 * n) + i] = bl[i];
    }

    return temp;
}

template <int n>
int Square<n>::getNumPoints() const
{
    return 4*n;
}