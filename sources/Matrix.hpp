#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace zich
{
class Matrix {
private:
    int col;
    int row;
    vector<double> matrix;

public:
    Matrix(const vector<double> &m,int r,int c);
    Matrix operator+(const Matrix &m);
    ~Matrix();
    Matrix& operator+=(const Matrix &m);
    Matrix& operator++();
    Matrix& operator++(const int num);
    Matrix& operator--();
    Matrix& operator--(const int num);
    Matrix&operator-=(Matrix const &m);
    Matrix operator-(Matrix const &m);
    double sumOfMatrix(const Matrix &m) const;
    bool operator<(const Matrix &m) const;
    bool operator>(const Matrix &m) const;
    bool operator<=(const Matrix &m) const;
    bool operator>=(const Matrix &m) const;
    friend bool operator==(Matrix const &m1,Matrix const &m2);
    bool operator!=(const Matrix &m) const;
    Matrix operator*=(const Matrix &m);
    Matrix operator*(const Matrix &m);

    friend ostream& operator<<(ostream &o, const Matrix &m);
    friend istream& operator>>(istream &input, const Matrix &m);
    double MultResult(Matrix const &m,int col,int row);
    // friend Matrix operator-(Matrix &m);
    // friend Matrix operator+(Matrix &m);
    Matrix operator+() ;
    Matrix operator-() const;
    Matrix operator*(double const num) const;
    friend Matrix operator*(double const num,Matrix &m);
    Matrix operator*=(double const num);

};
}
