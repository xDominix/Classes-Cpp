#include <iostream>
#include <string>

using namespace std;

#include "matrix.h"

/*
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
*/

TwoDimensionMatrix::TwoDimensionMatrix(){for(size_t i =0;i<size;i++) for(size_t j =0;j<size;j++) matrix[i][j]=0;}
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &m) {for(size_t i =0;i<size;i++) for(size_t j =0;j<size;j++) matrix[i][j]=m[i][j];}
TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement m[size][size]){for(size_t i =0;i<size;i++) for(size_t j =0;j<size;j++) matrix[i][j]=m[i][j];}

std::ostream& operator<<(std::ostream& os,const TwoDimensionMatrix& m)
{
    for (size_t i = 0; i < m.getSize(); ++i) {
        os << m.get(i,0);
        for (size_t j = 1; j < m.getSize(); ++j) {
            os << " " << m.get(i,j);
        }
        os << endl;
    }
    return os;
}

std::istream& operator>> (std::istream& is,TwoDimensionMatrix& m)
{
    for (size_t i = 0; i < m.getSize(); ++i) {
        for (size_t j = 0; j < m.getSize(); ++j) {
            is >> m[i][j];
        }
    }
    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2)
{
    TwoDimensionMatrix newmatrix(matrix1);
    return (newmatrix += matrix2);
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix& m)
{
    if (this == &m) {return *this;}
    for(size_t i =0;i<size;i++) for(size_t j =0;j<size;j++) matrix[i][j] = m[i][j];
    return *this;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator+=(const TwoDimensionMatrix& m)//additional
{
    for(size_t i =0;i<getSize();i++)
    {
        for(size_t j =0;j<getSize();j++)
        {
            matrix[i][j] += m.get(i,j);
        }
    }
    return *this;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) 
{   
    for(size_t i =0;i<size;i++) for(size_t j =0;j<size;j++) this->matrix[i][j] *= number;
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& m) const {
    TwoDimensionMatrix newmatrix;
    for(size_t i =0;i<size;i++)
    {
        for(size_t j =0;j<size;j++)
        {
            newmatrix[i][j] = this->matrix[i][j] && m.get(i,j);
        }
    }
    return newmatrix;
}