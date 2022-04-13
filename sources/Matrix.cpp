#include "Matrix.hpp"

namespace zich {

    Matrix::Matrix(const vector<double> &m,int r,int c){ // need to check if its true to write like that.
        this->col=c;
        this->row=r;
        this->matrix=m;
    }
    
    Matrix::~Matrix(){
    }
    
    Matrix Matrix::operator+(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int length= m.col*m.row; 
        vector <double> result((unsigned int)(length), 0.0);
        int i=0; 
        int j=0;
        while(i<m.row){
            while(j<m.col){
                result[(unsigned int)(col*i+j)]=m.matrix[(unsigned int)(col*i+j)]+this->matrix[(unsigned int)(col*i+j)];
                j++;
            }
            i++;
        }
        Matrix res(result,this->row, m.col);

        return res;
    } 

    Matrix &Matrix::operator++(){
        int i=0; 
        int j=0;
        while(i<this->row){
            while(j<this->col){
                this->matrix[(unsigned int)(col*i+j)]+=1;
                j++;
            }
            i++;
        }
        return *this;
    }
    Matrix &Matrix::operator++(const int num){
        Matrix result= Matrix(this->matrix,this->row,this->col);
        int i=0; 
        int j=0;
        while(i<this->row){
            while(j<this->col){
               result.matrix[(unsigned int)(col*i+j)]+=1;
               j++;
            }
            i++;
        }
        return *this;
    }
    
    Matrix &Matrix::operator+=(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int i=0; 
        int j=0;
        while(i<m.row){
            while(j<m.col){
                this->matrix[(unsigned int)(col*i+j)]+=m.matrix[(unsigned int)(col*i+j)];
                j++;
            }
            i++;
        }
        return *this;
    } 

    Matrix &Matrix::operator--(){
        int i=0; 
        int j=0;
        while(i<this->row){
            while(j<this->col){
                this->matrix[(unsigned int)(col*i+j)]-=1;
                j++;
            }
            i++;
        }
        return *this;
    }
    
    Matrix &Matrix::operator--(const int num){
        int length= this->col*this->row; 
        vector <double> result((unsigned int)(length), 0.0);
        int i=0; 
        int j=0;
        while(i<this->row){
            while(j<this->col){
               result[(unsigned int)(col*i+j)]-=1;
               j++;
            }
            i++;
        }
        return *this;
    }
    Matrix &Matrix::operator-=(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int i=0; 
        int j=0;
        while(i<m.row){
            while(j<m.col){
                this->matrix[(unsigned int)(col*i+j)]-=m.matrix[(unsigned int)(col*i+j)];
                j++;
            }
            i++;
        }
        return *this;
    } 

     Matrix Matrix::operator-(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int length= m.col*m.row; 
        vector <double> result((unsigned int)(length), 0.0);
               int i=0; 
        int j=0;
        while(i<m.row){
            while(j<m.col){
                result[(unsigned int)(col*i+j)]=this->matrix[(unsigned int)(col*i+j)]-m.matrix[(unsigned int)(col*i+j)];
                j++;
            }
            i++;
        }
        Matrix res(result,this->row, m.col);
        return res;
    } 
    
    double Matrix::sumOfMatrix(const Matrix &m) const{
        double sum=0;
        for(int i=0;i<(m.row);i++){    
            for(int j=0;j<(m.col);j++){
              sum+=m.matrix[(unsigned int)(col*i+j)];
            }
        }
        return sum;
    }  
    bool Matrix::operator<(const Matrix &m) const{
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        return(sum_a<sum_b);
    }
    bool Matrix::operator>(const Matrix &m) const{
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        return(sum_a>sum_b);
    }
    bool Matrix::operator<=(const Matrix &m) const{
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        return (sum_a<=sum_b);
    }
    bool Matrix::operator>=(const Matrix &m) const{
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        return (sum_a>=sum_b);
    }
    bool operator==(Matrix const &m1,Matrix const &m2){
    
        if(m1.col!=m2.col || m1.row!=m2.row ){
            throw("error");
            return false;
        }
        int i=0; 
        int j=0;
        while(i<m1.row){
            while(j<m1.col){
                if(m1.matrix[(unsigned int)(m1.col*i+j)]!=m2.matrix[(unsigned int)(m2.col*i+j)]){
                    return false;
                }
                j++;
            }
            i++;
        }
        return true;
    }
    
    bool Matrix::operator!=(Matrix const &m) const{
        double sum_a=sumOfMatrix(m);
        double sum_b=sumOfMatrix(m);
        return (sum_a!=sum_b);
            
    }

    //  Matrix &Matrix::operator*=(double num){
    //     for(int i=0;i<(this->row);i++){    
    //         for(int j=0;j<(this->col);j++){
    //             this->matrix[(unsigned int)(col*i+j)]*=num;
    //         }
    //     }
    //     return *this;
    // }
    Matrix Matrix::operator*=(Matrix const &m){
        if( this->col!=m.row && this->row != m.col) {
             throw runtime_error("The matrices are not in the legal size for mult");
        }
        int length = m.col*this->row; 
        vector <double> result((unsigned int) (length), 0.0);
        int i=0;
        int j=0;
        double temp=0;
        while(i<this->row){
            while(j<m.col){
                 result[(unsigned int)(col*i+j)]=MultResult(m,i,j);
                 j++;
            }
            i++;
        }
        Matrix res(result,this->row, m.col);
        *this=res;
        return *this;
    } 

    Matrix Matrix::operator*(Matrix const &m){
        if( this->col!=m.row && this->row != m.col) {
             throw runtime_error("The matrices are not in the legal size for mult");
        }
        int length = m.col*this->row; 
        vector <double> result((unsigned int) (length), 0.0);
        int i=0;
        int j=0;
        double temp=0;
        while(i<this->row){
            while(j<m.col){
                 result[(unsigned int)(col*i+j)]=MultResult(m,i,j);
                 j++;
            }
            i++;
        }
        Matrix res(result,this->row, m.col);
        return res;
    } 

    double Matrix::MultResult(Matrix const &m,int c,int r){
        double sum=0;
        int i=0;
        int j=0;
        while(j<m.col){
            sum+=this->matrix[(unsigned int)(this->col*c+i)]*m.matrix[(unsigned int)(r+m.col*j)];
            i++;
            j++;
        }
        return sum;
    }  
    //        istream& operator>>(istream& input, const matrixType& source)
    //     {
    //         for(int i=0;i<numRows;i++)
    //               for(int j=0;j<numColumns;j++)
    //                        input>>source.matrix[i][j];
    //         return input;
    //      }     
    // }
    //I use the idea mentioned here: https://stackoverflow.com/a/18797672
    istream &operator>>(istream &input,const Matrix &m)
    {
        int i=0;
        int j=0;

        while(i<m.row){
            while(j<m.col){
                    // s+=m.matrix[(unsigned int)(i*m.col+j)];
                j++;
            }
            i++;
        }
        return input;
    }
  

    //I use the idea mentioned here: https://stackoverflow.com/a/44886537
    ostream &operator<<(ostream &o, const Matrix &m){ 
        int i=0;
        int j=0;
        while(i<m.row){
            o << "[";
            while(j<m.col){
                if(j==m.col-1){
                    o << m.matrix[(unsigned int)(i*m.col+j)] <<"]";
                }
                else{
                    o << m.matrix[(unsigned int)(i*m.col+j)] <<" ";
                }
                j++;
            }
            if(i!=m.row-1){
               o << '\n';
            }
            i++;
        }
        return o;
    }
    Matrix operator-(Matrix &m){

        return m;
    }
    Matrix operator*(double const num,Matrix &m){
        int length=m.col*m.row;
        vector <double> result((unsigned int)(length), 0.0);
        for(int i=0; i<m.row;i++){
            for(int j=0; j<m.col;j++){
                result[(unsigned int)(m.col*i+j)]*=num;
            }   
        }
        Matrix res(result,m.row, m.col);
        return res;
    }
    Matrix Matrix::operator*(double const num) const{
        int length=this->col*this->row;
        vector <double> result((unsigned int)(length), 0.0);
        for(int i=0; i<this->row;i++){
            for(int j=0; j<this->col;j++){
                result[(unsigned int)(this->col*i+j)]*=num;
            }   
        }
        Matrix res(result,this->row, this->col);
        return res;
    }
   
       Matrix Matrix::operator*=(double const num){
        int length=this->col*this->row;
        vector <double> result((unsigned int)(length), 0.0);
        for(int i=0; i<this->row;i++){
            for(int j=0; j<this->col;j++){
                result[(unsigned int)(this->col*i+j)]*=num;
            }   
        }
        Matrix res(result,this->row, this->col);
        *this=res;
        return *this;
    }
    
    
    Matrix Matrix::operator+(){
        return *this;
}
    Matrix Matrix::operator-() const{
    int length=this->col*this->row;
    vector <double> result((unsigned int)(length), 0.0);
        for(int i=0; i<this->row;i++){
            for(int j=0; j<this->col;j++){
                result[(unsigned int)(this->col*i+j)]*=-1;
            }   
        }
        Matrix res(result,this->row, this->col);
        return res;
    }
}