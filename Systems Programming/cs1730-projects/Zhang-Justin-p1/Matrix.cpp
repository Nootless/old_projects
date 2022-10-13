#include "Matrix.h"
#include <cstdlib>
#include <iostream>


Matrix::Matrix(uint rows, uint cols)
{

    // stores the columns and rows for the specific Matrix object
    col = cols;
    row = rows;

    // creates a pointer to the array which holds pointers
    matrix_ptr = new double* [rows];


    // adds pointers to the array for the 2nd dimension of arrays
    for (uint i = 0; i < row; i++) {
        matrix_ptr[i] = new double[col];
    } // for

    // assigns 0s to each matrix position
    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            matrix_ptr[i][j] = 0;
        } // for
    } // for
} // Matrix Constructor


Matrix::Matrix(const Matrix & m)
{

    // stores the columns and rows for the new Matrix
    row = m.numRows();
    col = m.numCols();

    // creates a pointer to the array holding pointers
    matrix_ptr = new double* [row];

    // adds pointers to the array holding pointers
    for (uint i = 0; i < row; i++) {
        matrix_ptr[i] = new double[col];
    } // for

    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            matrix_ptr[i][j] = m.at(i , j);
        } // for
    } // for
} // Matrix Copy Constructor

Matrix::~Matrix()
{
    // deallocates the dynamically allocated arrays
    // inside of the 1st array
    for (uint i = 0; i < row; i++) {
        delete [] matrix_ptr[i];
    } // for

    // deallocates the first array
    delete [] matrix_ptr;
} // Matrix Destructor


Matrix Matrix::add(double s) const
{
    Matrix addm(*this);
    // loops through the 2d array and adds the value to each index
    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            addm.at(i , j) += s;
        } // for
    } // for
    return addm;
} // add


Matrix Matrix::add(const Matrix & m) const
{
    Matrix addm(*this);
    // loops through both arrays and adds their matching indicies
    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            addm.at(i , j) += m.at(i,j);
        } // for
    } // for
    return addm;
} // add


Matrix Matrix::subtract(double s) const
{
    Matrix subtractm(*this);
    // loops through the array and subtracts value from it
    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            subtractm.at(i , j) -= s;
        } // for
    } // for
    return subtractm;
} // subtract


Matrix Matrix::subtract(const Matrix & m) const
{
    Matrix subtractm(*this);
    // loops through the calling array and subtracts the given array
    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            subtractm.at(i , j) -= m.at(i , j);
        } // for
    } // for
    return subtractm;
} // subtract



Matrix Matrix::multiply(double s) const
{
    Matrix multm(*this);
    // loops through the array and multiplys each index with a scalar
    for (uint i = 0; i < row; i++) {
        for (uint j = 0; j < col; j++) {
            multm.at(i , j) *= s;
        } // for
    } // for
    return multm;
} // multiply


Matrix Matrix::multiply(const Matrix & m) const
{
    // Array to hold the dot product
    Matrix multMatrix(this -> numRows(), m.numCols());

    // loops through the array for the first two for loops
    // loops through the rows for the given array for the most nested loop
    // adds up all the values of the row * col and assigns it to the new matrix
    for (uint i = 0; i < this -> numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            for (uint k = 0; k < this -> numCols(); k++) {
                multMatrix.at(i,j) += ( this -> at(i , k)  * m.at(k , j) );
                } // for
        } // for
    } // for

    return multMatrix;

} // multiply


Matrix Matrix::divide(double s) const
{
    Matrix dividem(*this);
    // loops thorugh the entire Matrix and divides each value
    for (uint i = 0; i < numRows(); i++) {
        for (uint j = 0; j < numCols(); j++) {
            dividem.at(i , j) /= s; // divides each value
        } // for
    } // for
    return dividem;
} // divide


Matrix Matrix:: t() const
{
    Matrix transpose(this -> numRows() , this -> numCols());

    // loops through the array and assigns the value
    for (uint i = 0; i < numRows(); i++) {
        for (uint j = 0; j < numCols(); j++) { // asigns the transpose
            transpose.at(i , j) = this->at(j , i);
        } // for

    } // for
    return transpose;
} // t


const uint Matrix::numRows() const
{
    return row;
} // numRows


const uint Matrix::numCols() const
{ // returns the column
    return col;
} // numCol


double & Matrix::at(uint row, uint col)
{ // returns the value at the pointer location
    return matrix_ptr[row][col];
} // at


const double & Matrix::at(uint row, uint col) const
{ // returns the value at the pointer location
    return this -> matrix_ptr[row][col];
} // at
