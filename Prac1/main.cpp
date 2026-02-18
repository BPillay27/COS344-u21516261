#include "Matrix.h"
#include "Vector.h"
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"

#include <iostream>

#include <sstream>

void testVector()
{
    Vector<3> v1;
    v1.print();

    Vector<3> v2 = {2, 3, 4};
    v2.print();

    float *nums = new float[3];
    for (int i = 0; i < 3; i++)
    {
        nums[i] = 67;
    }

    Vector<3> v3(nums);
    v3.print();

    Vector<3> v4(v2);
    v4.print();

    Matrix<3, 1> m1;
    Vector<3> v5(m1);
    v5.print();

    Vector<3> v6;
    v6 = v2;
    v6.print();

    Vector<3> v7;
    v7 = v2 + v6;
    v7.print();

    Vector<3> v8;
    v8 = v7;
    v8 = v8 - v6;
    v8.print();

    Vector<3> v9;
    v9 = v2 * 11;
    v9.print();

    std::cout << "Testing multiplication operator between 2 vectors..." + std::to_string(v8 * v7) + "\n";
    std::cout << std::to_string(v9[0]) + "\n";

    std::cout << "Magnitude of v2: " + std::to_string(v2.magnitude()) + "\n";

    Vector<3> v10;
    v10 = v2.crossProduct(v3);
    v10.print();

    std::cout << "This is v10 in unit vector...\n";
    v10.unitVector().print();

    std::cout << std::to_string(v10.getN());
}

void testMatrix()
{
    Matrix<3, 3> m1;
    m1.print();

    float **f = new float *[3];
    for (int i = 0; i < 3; i++)
    {
        f[i] = new float[3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            f[i][j] = 67;
        }
    }
    Matrix<3, 3> m2(f);
    m2.print();

    Matrix<3, 3> m3(m2);
    m3.print();

    Matrix<3, 3> m4;
    m4 = m3;
    m4.print();

    Matrix<3, 3> m5;
    m5 = m3 * m4;
    m5.print();

    float **f1 = new float *[3];
    for (int i = 0; i < 3; i++)
    {
        f1[i] = new float[3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            f1[i][j] = 1;
        }
    }
    Matrix<3, 3> m6(f1);
    m6 = m6 * 7;
    m6.print();

    Matrix<3, 3> m7;
    m7 = m7 + m6;
    m7.print();

    (~m7).print();
    std::cout << "M : " + std::to_string(m7.getM()) + "and N : " + std::to_string(m7.getN()) + "\n";
    std::cout << "Det(m6) : " + std::to_string(m6.determinant());
}

void testTriangle()
{
    Vector<3> p1 = {2, 1, 4};
    Vector<3> p2 = {3, 3, 3};
    Vector<3> p3 = {4, 4, 4};

    Triangle<3> t1(p1, p2, p3);
    t1.print();

    Triangle<3> t2(t1);
    t2.print();

    Matrix<3, 3> m1;
    t2 *= m1;
    t2.print();

    t2.getNumPoints();
    t2.getPoints();
}

void testSquare()
{
    Vector<3> v1 = {3, 3, 3};
    Square<3> s1(v1, 10, 10);
    s1.print();

    Square<3> s2(s1);

    Matrix<3, 3> m1;
    s2 *= m1;

    s1.getNumPoints();
    s1.getPoints();
}

int main(int argc, char const *argv[])
{
    try{
    testVector();
    testMatrix();
    testTriangle();
    testSquare();
    } catch (const char* s){
        std::cout<<s;
    }
}
