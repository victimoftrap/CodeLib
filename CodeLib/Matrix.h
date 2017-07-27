#pragma once

class Matrix
{
public:
    /*
     * Default constructor;
     */
    Matrix();
    /*
     * Constuctor creates Matrix with specified by arg[0] and arg[1] size, and fills it with arg[2];
     */
    Matrix(int, int, int);


    /*
     * Returns value of item.
     * Throws exception if it does not exist;
     */
    int get(int, int) const;
    /*
    * Sets value of item.
    * Throws exception if it does not exist;
    */
    void set(int, int, int);

    /*
     * Returns true if its square matrix;
     */
    bool isSquare() const;
    /*
     * Computes trace of matrix;
     * Throws exception if its not square matrix;
     */
    int computeTrace() const;
    /*
     * Excludes specified row and column from matrix;
     * By other words - creates a minor;
     */
    void exclude(int, int);
    /*
     * Computes determinant of current matrix. 
     * Throws exception if its not square matrix;
     */
    long int computeDeterminant();

    bool operator==(const Matrix&);

    friend Matrix& operator+(const Matrix&, const Matrix&);
    friend Matrix& operator-(const Matrix&, const Matrix&);
    friend Matrix& operator*(const Matrix&, const Matrix&);
    friend Matrix& operator*(const Matrix&, int);

private:
    int** _values = nullptr;
    int _rowsCount = 0;
    int _colsCount = 0;


};