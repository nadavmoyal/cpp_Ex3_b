#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace zich;

 TEST_CASE("different sizes of matrices")
 {    
    std::vector<double> identity = {1, 0, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a{identity, 2, 2}; 
    Matrix b{arr, 3, 3}; 
   //  CHECK_THROWS(a*b);
   //  CHECK_THROWS(b*a);
   //  CHECK_THROWS((-a)*(-b));
   //  CHECK_THROWS(a+b);
   //  CHECK_THROWS(b-a);
   //  CHECK_THROWS((b-a)*(-b));
   //  CHECK_THROWS(a+=b);
   //  CHECK_THROWS(a-=b);
   //  CHECK_THROWS(a*b);
   //  CHECK_THROWS(a--);
}

 TEST_CASE("operators tests")
 {    
   //  int const ten = 10;
   //  std::vector<double> identity = {1, 0, 0, ten,ten, 0, ten, ten, 0, 1,1,ten};
   //  std::vector<double> arr = {2, 2, 0, 2, 3, 0, 0, 0, 3};
   //  Matrix a{identity, 3, 4}; 
   //  Matrix b{arr, 3, 3}; 
   //  CHECK_EQ(a<b, false);
   //  CHECK_EQ(a<=b, false);
   //  CHECK_EQ(b>a, false);
   //  CHECK_EQ(b>=a, false);
   //  CHECK_EQ(a==b, false);
   //  CHECK_EQ(a!=a, false);
   //  CHECK_EQ(b!=b, false);
   //  CHECK_EQ(a!=a, false);
   //  CHECK_EQ(a < b, false);
   //  CHECK_EQ(a>b, true);
   //  CHECK_EQ(a>=b, true);
   //  CHECK_EQ(b<a, true);
   //  CHECK_EQ(b<=a, true);
   //  CHECK_EQ(a!=b, true);
   //  CHECK_EQ(a==a, true);
   //  CHECK_EQ(b==b, true);
   //  CHECK_EQ(a==a, true);
   //  CHECK_EQ(a >= b, true);
 }











