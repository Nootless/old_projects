#include "Matrix.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    // defining new matricies
    Matrix m1(3,3);
    Matrix m2 = m1.add(4);
    Matrix m3 = m2.add(m2);
    Matrix c1(3,4);

    cout << "Original matrix" << endl;
    cout << m1.at(0,0) << " " << m1.at(0,1) << " " << m1.at(0,2) << endl
         << m1.at(1,0) << " " << m1.at(1,1) << " " << m1.at(1,2) << endl
         << m1.at(2,0) << " " << m1.at(2,1) << " " << m1.at(2,2) << endl;
    cout << "-----ADDING-----" << endl;
    cout << "Adding 4" << endl;
    cout << m2.at(0,0) << " " << m2.at(0,1) << " " << m2.at(0,2) << endl
         << m2.at(1,0) << " " << m2.at(1,1) << " " << m2.at(1,2) << endl
         << m2.at(2,0) << " " << m2.at(2,1) << " " << m2.at(2,2) << endl;
    cout << "adding itself" << endl;
    cout << m3.at(0,0) << " " << m3.at(0,1) << " " << m3.at(0,2) << endl
         << m3.at(1,0) << " " << m3.at(1,1) << " " << m3.at(1,2) << endl
         << m3.at(2,0) << " " << m3.at(2,1) << " " << m3.at(2,2) << endl;

    // changing values of m3
    m3.at(0,0) = 12;
    m3.at(1,1) = 12;
    m3.at(2,2) = 12;

    cout << "at changed" << endl;
    cout << m3.at(0,0) << " " << m3.at(0,1) << " " << m3.at(0,2) << endl
         << m3.at(1,0) << " " << m3.at(1,1) << " " << m3.at(1,2) << endl
         << m3.at(2,0) << " " << m3.at(2,1) << " " << m3.at(2,2) << endl;
    // copy constructor and adding m4 + m2
    Matrix m4(m3);
    Matrix m6 = m4.add(m2);

    cout << "Copy Constructor with a diagonal changed" << endl;
    cout << m4.at(0,0) << " " << m4.at(0,1) << " " << m4.at(0,2) << endl
         << m4.at(1,0) << " " << m4.at(1,1) << " " << m4.at(1,2) << endl
         << m4.at(2,0) << " " << m4.at(2,1) << " " << m4.at(2,2) << endl;

    cout << "Adding array with 12 diagonal with 8 and array of 4s" << endl;
    cout << m6.at(0,0) << " " << m6.at(0,1) << " " << m6.at(0,2) << endl
         << m6.at(1,0) << " " << m6.at(1,1) << " " << m6.at(1,2) << endl
         << m6.at(2,0) << " " << m6.at(2,1) << " " << m6.at(2,2) << endl;

    cout << "-----SUBTRACTING-----" << endl;
    // Subtraction
    Matrix sub = m6.subtract(m2);
    Matrix sub2 = m6.subtract(20);
    cout << "\nOriginal Array" << endl;
    cout << m6.at(0,0) << " " << m6.at(0,1) << " " << m6.at(0,2) << endl
         << m6.at(1,0) << " " << m6.at(1,1) << " " << m6.at(1,2) << endl
         << m6.at(2,0) << " " << m6.at(2,1) << " " << m6.at(2,2) << endl;
    cout << "Subtracting array from another array (8 - 4)" << endl;
    cout << sub.at(0,0) << " " << sub.at(0,1) << " " << sub.at(0,2) << endl
         << sub.at(1,0) << " " << sub.at(1,1) << " " << sub.at(1,2) << endl
         << sub.at(2,0) << " " << sub.at(2,1) << " " << sub.at(2,2) << endl;
    cout << "Subtracting array by scalar (8 - 20)" << endl;
    cout << sub2.at(0,0) << " " << sub2.at(0,1) << " " << sub2.at(0,2) << endl
         << sub2.at(1,0) << " " << sub2.at(1,1) << " " << sub2.at(1,2) << endl
         << sub2.at(2,0) << " " << sub2.at(2,1) << " " << sub2.at(2,2) << endl;

    cout << "-----MULTIPLYING-----" << endl;
    Matrix mult = m6.multiply(3);
    cout << "\nOriginal Array" << endl;
    cout << m6.at(0,0) << " " << m6.at(0,1) << " " << m6.at(0,2) << endl
         << m6.at(1,0) << " " << m6.at(1,1) << " " << m6.at(1,2) << endl
         << m6.at(2,0) << " " << m6.at(2,1) << " " << m6.at(2,2) << endl;
    cout << "multiplying by 3" << endl;
    cout << mult.at(0,0) << " " << mult.at(0,1) << " " << mult.at(0,2) << endl
         << mult.at(1,0) << " " << mult.at(1,1) << " " << mult.at(1,2) << endl
         << mult.at(2,0) << " " << mult.at(2,1) << " " << mult.at(2,2) << endl;

    cout << "\nMatrix Multiplication" << endl;
    Matrix a(2, 2);
    cout << "First Array" << endl;
    cout << "[1,2] \n[1,3]" << endl;
    cout << "Second Array" << endl;
    cout << "[3] \n[2]" << endl;
    a.at(0, 0) = 1; // [ 1, 2 ]
    a.at(0, 1) = 2; // [ 1, 3 ]
    a.at(1, 0) = 1;
    a.at(1, 1) = 3;
    Matrix b(2, 1);
    b.at(0, 0) = 3; // [ 3 ]
    b.at(1, 0) = 2; // [ 2 ]
    Matrix c = a.multiply(b);
    cout << "Result" << endl;
    cout << "[ " << c.at(0, 0) << " ]" << endl // [ 7 ]
         << "[ " << c.at(1, 0) << " ]" << endl; // [ 9 ]

    cout << "Matrix Multiplication 2" << endl;
    Matrix d(3,5);
    Matrix f = d.add(4);
    Matrix e(5,3);
    Matrix g = e.add(7);
    f.at(0,1) = 12;
    f.at(0,2) = 13;
    g.at(1,0) = 11;
    g.at(4,1) = 6;
    Matrix h = f.multiply(g);

    cout << "Original Arrays " << endl;

    cout << "First Array" << endl;
    cout << f.at(0,0) << " " << f.at(0,1) << " " << f.at(0,2) << " "
         << f.at(0,3) << " " << f.at(0,4) << " " << endl
         << f.at(1,0) << " " << f.at(1,1) << " " << f.at(1,2) << " "
         << f.at(1,3) << " " << f.at(1,4) << " " << endl
         << f.at(2,0) << " " << f.at(2,1) << " " << f.at(2,2) << " "
         << f.at(2,3) << " " << f.at(2,4) << endl;

    cout << "Second Array" << endl;
    cout << g.at(0,0) << " " << g.at(0,1) << " " << g.at(0,2) << endl
         << g.at(1,0) << " " << g.at(1,1) << " " << g.at(1,2) << endl
         << g.at(2,0) << " " << g.at(2,1) << " " << g.at(2,2) << endl
         << g.at(3,0) << " " << g.at(3,1) << " " << g.at(3,2) << endl
         << g.at(4,0) << " " << g.at(4,1) << " " << g.at(4,2) << endl;

    cout << "Multiplied Array" << endl;
    cout << h.at(0,0) << " " << h.at(0,1) << " " << h.at(0,2) << endl
         << h.at(1,0) << " " << h.at(1,1) << " " << h.at(1,2) << endl
         << h.at(2,0) << " " << h.at(2,1) << " " << h.at(2,2) << endl;

    cout << "-----DIVIDING-----" << endl;
    Matrix div = m6.divide(3);
    cout << "\nOriginal Array" << endl;
    cout << m6.at(0,0) << " " << m6.at(0,1) << " " << m6.at(0,2) << endl
         << m6.at(1,0) << " " << m6.at(1,1) << " " << m6.at(1,2) << endl
         << m6.at(2,0) << " " << m6.at(2,1) << " " << m6.at(2,2) << endl;
    cout << "dividing by 3" << endl;
    cout << div.at(0,0) << " " << div.at(0,1) << " " << div.at(0,2) << endl
         << div.at(1,0) << " " << div.at(1,1) << " " << div.at(1,2) << endl
         << div.at(2,0) << " " << div.at(2,1) << " " << div.at(2,2) << endl;

    // testing transposing
    m6.at(1,2) = 37;
    m6.at(0,2) = 2;
    m6.at(1,0) = 23;
    m6.at(0,1) = 26;
    m6.at(2,1) = 11;
    m6.at(2,0) = 68;
    Matrix t = m6.t();
    cout << "-----TRANSPOSING-----" << endl;
    cout << "\nOriginal Array" << endl;
    cout << m6.at(0,0) << " " << m6.at(0,1) << " " << m6.at(0,2) << endl
         << m6.at(1,0) << " " << m6.at(1,1) << " " << m6.at(1,2) << endl
         << m6.at(2,0) << " " << m6.at(2,1) << " " << m6.at(2,2) << endl;
    cout << "Transposed array" << endl;
    cout << t.at(0,0) << " " << t.at(0,1) << " " << t.at(0,2) << endl
         << t.at(1,0) << " " << t.at(1,1) << " " << t.at(1,2) << endl
         << t.at(2,0) << " " << t.at(2,1) << " " << t.at(2,2) << endl;

    cout << "num Rows: "  << m6.numRows() << endl;
    cout << "num Cols: " << m6.numCols() << endl;

    // constant matrix defined and copied
    const Matrix c2(3,3);
    const Matrix c3(c2);
    // testing at()
    cout << "constant matrix defined (3 , 3)" << endl;
    cout << c3.at(0,0) << " " << c3.at(0,1) << " " << c3.at(0,2) << endl
         << c3.at(1,0) << " " << c3.at(1,1) << " " << c3.at(1,2) << endl
         << c3.at(2,0) << " " << c3.at(2,1) << " " << c3.at(2,2) << endl;
    cout << "num rows: " << c3.numRows() << " num cols: " << c3.numCols() << endl;

    // testing for at not allowing for change
    // c3.at(0,0) = 2; (const function)
} // main
