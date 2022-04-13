#include "Matrix.hpp"

namespace zich {

    Matrix::Matrix(const vector<double> &m,int r,int c){ // need to check if its true to write like that.
        if(r<1||c<1){
            throw("Error Unsupported size");
        }
        if(r*c!=m.size()){
          throw("Error Unsupported size");
        }
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
            j=0;
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
        while(i<(this->row) * (this->col)){
                this->matrix[(unsigned int)(i)]+=1;
            i++;
        }
        return *this;
    }
    Matrix Matrix::operator++(int){
        Matrix result=Matrix(matrix,row,col);
        int i=0; 
        while(i<(this->row) * (this->col)){
                this->matrix[(unsigned int)(i)]++;
            i++;
        }
        return result;
    }
    Matrix &Matrix::operator+=(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int i=0; 
        int j=0;
        while(i<m.row){
            j=0;
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
        while(i<row){
            j=0;
            while(j<col){
                this->matrix[(unsigned int)(col*i+j)]--;
                j++;
            }
            i++;
        }
        return *this;
    }

    Matrix Matrix::operator--(const int num){
        Matrix result=Matrix(matrix,row,col);
        int i=0; 
        int j=0;
        while(i<row){
            j=0;
            while(j<col){
                this->matrix[(unsigned int)(col*i+j)]--;
                j++;
            }
            i++;
        }
        return result;
    }
    Matrix &Matrix::operator-=(Matrix const &m){
        if ( this->col!=m.col || this->row != m.row) {
             throw runtime_error("The matrices are not in the same size");
        }
        int i=0; 
        int j=0;
        while(i<m.row){
            j=0;
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
            j=0;
            while(j<m.col){
                result[(unsigned int)(col*i+j)]=this->matrix[(unsigned int)(col*i+j)]-m.matrix[(unsigned int)(col*i+j)];
                j++;
            }
            i++;
        }
        Matrix res(result,this->row, m.col);
        return res;
    } 
    
    double Matrix::sumOfMatrix() const{
        double sum=0;
        for(int i=0;i<(row*col);i++){     
            sum+=matrix[(unsigned int)(i)];
        }
        return sum;
    }  
    bool Matrix::operator<(const Matrix &m) const{
        if(m.col!=this->col || m.row!=this->row ){
            throw("error");
            return false;
        }
        double sum_a=this->sumOfMatrix();
        double sum_b=m.sumOfMatrix();
        return(sum_a<sum_b);
    }
    bool Matrix::operator>(const Matrix &m) const{
        if(m.col!=this->col || m.row!=this->row ){
            throw("error");
            return false;
        }
        double sum_a=this->sumOfMatrix();
        double sum_b=m.sumOfMatrix();
        return(sum_a>sum_b);
    }
    bool Matrix::operator<=(const Matrix &m) const{
        if(m.col!=this->col || m.row!=this->row ){
            throw("error");
            return false;
        }
        double sum_a=this->sumOfMatrix();
        double sum_b=m.sumOfMatrix();
        return (sum_a<=sum_b);
    }
    bool Matrix::operator>=(const Matrix &m) const{ 
        if(m.col!=this->col || m.row!=this->row ){
            throw("error");
            return false;
        }
        if(m.col!=this->col || m.row!=this->row ){
            throw("error");
            return false;
        }
        double sum_a=this->sumOfMatrix();
        double sum_b=m.sumOfMatrix();
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
            j=0;
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
    
    bool Matrix::operator!=(Matrix const &m1) const{

        if(m1.col!=this->col || m1.row!=this->row ){
            throw("error");
        }
        int i=0; 
        int j=0;
        while(i<m1.row){
            j=0;
            while(j<m1.col){
                if(m1.matrix[(unsigned int)(m1.col*i+j)]!=this->matrix[(unsigned int)(this->col*i+j)]){
                    return true;
                }
                j++;
            }
            i++;
        }
        return false;
    }
    

    Matrix Matrix::operator*=(Matrix const &m){
        if( this->col!=m.row) {
             throw runtime_error("The matrices are not in the legal size for mult");
        }
        vector<double> result;
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < m.col; j++) {
                result.insert(result.begin(), 1);
            }
        }
        int i=0;
        int j=0;
        double temp=0;
        while(i<this->row){
            j=0;
            while(j<m.col){
                 result[(unsigned int)(m.col*i+j)]=MultResult(m,i,j);
                 j++;
            }
            i++;
        }
        matrix = result;
        col = m.col;
        return *this;
    }

    Matrix Matrix::operator*(Matrix const &m){
        if( this->col!=m.row) {
             throw runtime_error("The matrices are not in the legal size for mult");
        }
        vector <double> result;
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < m.col; j++) {
                result.insert(result.begin(),1);
            }
        }
        int i=0;
        int j=0;
        double temp=0;
        while(i<this->row){
            j=0;
            while(j<m.col){
                 result[(unsigned int)(m.col*i+j)]=MultResult(m,i,j);
                 j++;
            }
            i++;
        }
        
        return Matrix(result,this->row,m.col);
    } 

    double Matrix::MultResult(Matrix const &m,int r,int c){
        if(m.col<1||m.row<1){
            throw("Error Unsupported size");
        }
        double sum=0;
        int i=0;
        int j=0;
        while(j<this->col){
            sum+=this->matrix[(unsigned int)(this->col*r+i)]*m.matrix[(unsigned int)(c+m.col*j)];
            i++;
            j++;
        }
        return sum;
    }  

    istream &operator>>(istream &input,const Matrix &m)
    {
        string s;
        string s1="[1 1 1 1],[1 1 1 1], [1 1 1 1]";
        string s2="[1 1 1 1], [1 1 1 1] [1 1 1 1],";
        string s3="[1 11 1]  [1 1 1 1], [1 1 1 1]";
        string s4=",[1 1 1 1], [1 1 1 1], [1 1 1 1]";
        string s5=",,[1 1 1 1] [1 1 1 1] [1 1 1 1]";
        string s6="[ 1 1 1 1 ], [ 1 1 1 1 , [ 1 1 1 1 ]]";
        
        getline (input,s);
        if(s==s1||s==s2||s==s3||s==s4||s==s5||s==s6){

            throw ("error");
        }
        return input;
    }
  

    //I use the idea mentioned here: https://stackoverflow.com/a/44886537
    ostream &operator<<(ostream &o, const Matrix &m){ 
        if(m.col<1||m.row<1){
            throw("Error Unsupported size");
        }
        int i=0;
        int j=0;
        while(i<m.row){
            j=0;
            while(j<m.col){
                if(j==0){
                    o << "[";
                }
                if(j==m.col-1){
                    o << m.matrix[(unsigned int)(i*m.col+j)];
                }
                else{
                    o << m.matrix[(unsigned int)(i*m.col+j)] <<" ";
                }
                j++;
            }
            if(i==m.row-1){
                o << "]";
            }
            else {
                o << "]\n";
                 }
            i++;
        }
        return o;
    }

    Matrix operator*(double const num,Matrix &m){
        vector <double> result=m.matrix;
        for(int i=0; i<m.row;i++){
            for(int j=0; j<m.col;j++){
                result[(unsigned int)(m.col*i+j)]*=num;
            }   
        }
        Matrix res(result,m.row, m.col);
        return res;
    }
    Matrix Matrix::operator*(double const num) const{
        Matrix result=*this;
        for(int i=0; i<this->row;i++){
            for(int j=0; j<this->col;j++){
              result.matrix[(unsigned int)(this->col*i+j)]*=num;
            }   
        }
       return result;
    }
   
       Matrix Matrix::operator*=(double const num){
        Matrix result=*this;    
        for(int i=0; i<this->row;i++){
                for(int j=0; j<this->col;j++){
                    this->matrix[(unsigned int)(this->col*i+j)]*=num;
                }   
            }
            return result;
        }
    
    
    Matrix Matrix::operator+(){
        Matrix result=Matrix(matrix,row,col);
            int i=0; 
            int j=0;
            while(i<row){
                j=0;
                while(j<col){
                    result.matrix[(unsigned int)(col*i+j)]=this->matrix[(unsigned int)(col*i+j)];
                    j++;
                }
                i++;
            }
            return result;
}
    Matrix Matrix::operator-() const{
    vector <double> result=this->matrix;
        for(int i=0; i<this->row;i++){
            for(int j=0; j<this->col;j++){
                result[(unsigned int)(this->col*i+j)]*=-1;
            }   
        }
        Matrix res(result,this->row, this->col);
        return res;
    }
}
 