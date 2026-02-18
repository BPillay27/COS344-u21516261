#include "Matrix.h"

template <int n, int m>
Matrix<n, m>::Matrix()
{
    arr = new float *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new float[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }
}

template <int n, int m>
Matrix<n, m>::Matrix(float **f)
{
    arr = f;
}

template <int n, int m>
Matrix<n, m>::Matrix(const Matrix<n, m> &matrix)
{
    arr = new float *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new float[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = matrix[i][j];
        }
    }
}

template <int n, int m>
Matrix<n, m>::~Matrix()
{
    if (arr != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != nullptr)
            {
                delete[] arr[i];
                arr[i] = nullptr;
            }
        }

        delete[] arr;
    }
}

template <int n, int m>
Matrix<n, m> &Matrix<n, m>::operator=(const Matrix<n, m> &matrix)
{
    if (this == &matrix)
    {
        return *this;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = matrix[i][j];
        }
    }

    return *this;
}

template <int n, int m>
template <int a>
Matrix<n, a> Matrix<n, m>::operator*(const Matrix<m, a>other) const
{
    Matrix<n, a> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a; j++)
        {
            float sum = 0.0f;

            for (int k = 0; k < m; k++)
            {
                sum += (*this)[i][k] * other[k][j];
            }

            result[i][j] = sum;
        }
    }

    return result;
}

template <int n, int m>
Matrix<n, m> Matrix<n, m>::operator*(const float f) const
{
    Matrix<n, m> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = arr[i][j] * f;
        }
    }

    return result;
}

template <int n, int m>
Matrix<n, m> Matrix<n, m>::operator+(const Matrix<n, m> matrix) const
{
    Matrix<n, m> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = arr[i][j] + matrix.arr[i][j];
        }
    }

    return result;
}

template <int n, int m>
Matrix<m, n> Matrix<n, m>::operator~() const
{
    Matrix<m, n> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[j][i] = arr[i][j];
        }
    }

    return result;
}

template <int n, int m>
int Matrix<n, m>::getM() const
{
    return m;
}

template <int n, int m>
int Matrix<n, m>::getN() const
{
    return n;
}

template <int n, int m>
float Matrix<n, m>::determinant() const
{
    if (n != m)
    {
        throw "Matrix is not square";
    }

    float det = 0;

    for (int col = 0; col < n; col++)
    {
        Matrix<n - 1, n - 1> minor;

        for (int i = 1; i < n; i++)
        {
            int minorCol = 0;

            for (int j = 0; j < n; j++)
            {
                if (j == col)
                    continue;
                minor[i - 1][minorCol] = arr[i][j];
                minorCol++;
            }
        }

        float sign = (col % 2 == 0) ? 1 : -1;

        det += sign * arr[0][col] * minor.determinant();
    }

    return det;
}

template <>
float Matrix<1, 1>::determinant() const
{
    return arr[0][0];
}

template <>
float Matrix<2, 2>::determinant() const
{
    return (arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]);
}

template <>
float Matrix<3, 3>::determinant() const
{
    float p1 = 0, p2 = 0, p3 = 0;

    p1 = arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1]));
    p2 = arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0]));
    p3 = arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0]));

    return p1 - p2 + p3;
}
