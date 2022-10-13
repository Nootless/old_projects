#ifndef MATRIX_H
#define MATRIX_H

typedef unsigned int uint;

class Matrix
{
private:
    double** matrix_ptr;
    uint col;
    uint row;

public:

    /**
     * This constructor creates a new Matrix object
     * with a dynamically allocated amount of {@code rows}
     * and {@code columns}.
     *
     * @param rows how many rows in the matrix
     * @param cols the amount of columns in the matrix
     */
    Matrix(uint rows, uint cols);

    /**
     * This constructor copies an existing Matrix and creates a deep copy.
     *
     * @param Matrix a constant reference Matrix object that is to be copied
     */
    Matrix(const Matrix & m);

    /**
     * This is the destructor which deallocates the memory of the Matrix.
     */
    ~Matrix();

    /**
     * This function adds a scalar value to every index of the matrix.
     *
     * @param s the scalar being added to the Matrix
     * @return the resultant matrix
     */
    Matrix add(double s) const;

    /**
     * This function adds another Matrix to the current Matrix.
     *
     * @param Matrix a constant reference to a Matrix being added
     * @return the resultant matrix
     */
    Matrix add(const Matrix & m) const;

    /**
     * This function subtracts a scalar value from the calling Matrix.
     *
     * @param s the scalar being subtracted from the Matrix
     * @return the resultant matrix
     */
    Matrix subtract(double s) const;

    /**
     * This functions subtracts each index of the parameter Matrix from the
     * calling Matrix.
     *
     * @param Matrix another Matrix to be subtracted from the calling Matrix
     * @return the resultant matrix
     */
    Matrix subtract(const Matrix & m) const;

    /**
     * This function multiplies a scalar value for each index of the calling Matrix.
     *
     * @param s the scalar to multiply the indicies by
     * @return the resultant matrix
     */
    Matrix multiply(double s) const;

    /**
     * This function multiplies two matricies together, also known as the dot product.
     *
     * @param Matrix the Matrix to multiply the calling Matrix
     * @return the resultant matrix
     */
    Matrix multiply(const Matrix & m) const;

    /**
     * This function divides all indicies by a given scalar.
     *
     * @param s the scalar to divide the matrix by
     * @return the resultant matrix
     */
    Matrix divide(double s) const;

    /**
     * This function transposes a matrix across the diagonal.
     *
     * @return the resultant matrix
     */
    Matrix t() const;

    /**
     * Returns the number of rows the calling Matrix has.
     *
     * @return the number of rows
     */
    const uint numRows() const;

    /**
     * Returns the number of columns the calling Matrix has.
     *
     * @return the number of columns
     */
    const uint numCols() const;

    /**
     * This gets the value at a specific column and specific row.
     * It allows the value to be modified.
     *
     * @param row the row of the value
     * @param col the column of the value
     * @return the value at the specified row and column
     */
    double & at(uint row, uint col);

    /**
     * This gets the value at a specific column and specific row.
     * It does not allow for modification
     *
     * @param row the row of the value
     * @param col the column of the value
     * @return the value of the specified row and column
     */
    const double & at (uint row, uint col) const;

}; // Matrix

#endif
