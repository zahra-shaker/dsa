#include <iostream>
#include <cmath>
using namespace std;

class bigNumber {
  private:
    string value;
    bool isNegative;
  public:
  bigNumber();
  bigNumber(const string&);
  bigNumber add (bigNumber);
  bigNumber subtract (bigNumber);
  string getVal ();
  char getValIndx(int) ;
  bool getB () ;
  void setVal (string);
  void setValIndx(char,int) ;
  void setB (bool) ;
  bigNumber operator<< (int);
  bigNumber operator>> (int);
  void operator= (bigNumber) ;
  string multiplyByOne (int) ;
  bigNumber multiply (bigNumber) ;
  bigNumber power (int) ;
  bigNumber fact ();
  bigNumber division ();
  bigNumber karatsuba (bigNumber);
} ;

bigNumber :: bigNumber () {
      value="0" ;
      isNegative=false; }
bigNumber :: bigNumber(const string& num) {
      if(num[0]=='+') {
        isNegative==false; }
      else{
        isNegative==true;}
      for(int i=0; i<num.length()-1 ; i++) {
        value[i] = num[i+1] ;
      }
      }

string bigNumber :: getVal() {
  return value;
}

char bigNumber :: getValIndx (int i) {
  return value[i] ;
}

bool bigNumber ::getB() {
  return isNegative;
} 

void bigNumber :: setVal (string s) {
  value = s;
}

void bigNumber :: setB (bool b) {
  isNegative = b ;
}

void bigNumber ::setValIndx(char c, int i) {
  value[i] = c ;
}

void bigNumber :: operator= (bigNumber b) {
  value = b.value;
  isNegative = b.isNegative ;
}

bigNumber bigNumber:: add (bigNumber numOther) {
      bigNumber result;
      int lngth=value.length();
      if(numOther.value.length() > lngth) 
        lngth=numOther.value.length();
      if(isNegative == numOther.isNegative) {
      for(int i=lngth-1; i>0 ; i--) {
        result.setValIndx((value[i] + numOther.value[i])%10 , i);
        result.setValIndx((value[i] + numOther.value[i])/10 + getValIndx(i-1), i-1) ; }
      if(isNegative==true) {
        result.setValIndx('-', 0) ;
        result.isNegative = true; }
      else{
        result.setValIndx('+',0) ;
        result.isNegative = false; } 
      }
      else if( isNegative && !numOther.isNegative) {
        result = numOther.subtract(*this) ; }
      else {
        result = this->subtract(numOther); }
        return result;
    }
bigNumber bigNumber :: subtract (bigNumber numOther) {
    bigNumber result;
    int lngth=value.length();
    if(numOther.value.length() > lngth)
      lngth=numOther.value.length();
    if (isNegative == numOther.isNegative ) {
    for(int i=lngth-1; i>0; i--) {
      if(numOther.value[i] > value[i] ) {
        value[i]+10;
        value[i-1]-1; }
      result.setValIndx(value[i] - numOther.value[i],i)  ; }
    }
    if( !isNegative && numOther.isNegative) {
      result = numOther.add(*this) ; 
      result.setB(false) ;
      result.isNegative = false ; }
    if( isNegative && !numOther.isNegative ) {
      result = numOther.add(*this) ; 
      result.setB(true); }
    return result; }

bigNumber bigNumber :: operator<< (int num) {
  for(int i=0; i<num; i++) {
    for(int l=0; l<value.length(); l++) { 
    value[l-1] = value[l] ; }
  value[value.length()-1] = '0'; }
  return *this; }

bigNumber bigNumber :: operator>> (int num) {
  for(int i=0; i<num; i++) {
    for(int l=value.length()-1; l>=0; l--) {
    value[l+1] = value[l] ; }
    value[0]='0';}
    return *this; }

string bigNumber :: multiplyByOne (int j) {
  string result;
  for(int i=getVal().length()-1; i>=0; i--) {
    result[i] += (value[i]*j) % 10;
    result[i-1] += ( value[i]*j ) /10;
  }
  return result;
}

bigNumber bigNumber :: multiply ( bigNumber numOther) {
  bigNumber result;
  if(numOther.isNegative == isNegative) result.isNegative=false;
  else result.isNegative=true;
  for(int i=numOther.value.length()-1; i>=0; i--) {
    result = result.add(this->multiplyByOne(numOther.value[i])) ;
    numOther.setValIndx('0', i) ;
  }
}

bigNumber bigNumber :: power (int n) {
  for (int i=0; i<n; i++) {
    *this = multiply(*this) ;
  }
  return *this ;
}

bigNumber bigNumber :: fact() {
  if (isNegative==true) return -1;
  bool d = false;
  if(value.length()<4) {
    if(value[0]==1 && value[1]==0 && value[2]==0) d=true;
    if(value[0]==0) d=true;
  }
  bigNumber result("+001");
  if(!d) return -2;
  else {
    if(value=="001") return result;
    bigNumber bNum;
    bNum = this;
    this = this->subtract("1") ;
    return bNum.multiply(this->fact()) ;
  }
  }

  bigNumber bigNumber :: karatsuba (bigNumber numOther) {
    bigNumber result;
    int l1 = value.length();
    int l2 = numOther.value.length();
    if(l1==2 || l2==2) {
      result = this->multiply(numOther) ;
      return result;
    }
    bigNumber b1(value.substr(0,l1/2));
    bigNumber b2(value.substr(l1/2+1; l1));
    bigNumber c1(numOther.value.substr(0,l2/2));
    bigNumber c2(numOther.value.substr(l2/2+1; l2));
    bigNumber z1;
    bigNumber z2;
    bigNumber z3;
    z1 = b1.karatsuba(c1); 
    z2 = b2.karatsuba(c2);
    z3 = (b1.add(b2)).karatsuba(c1.add(c2)) ;
    result = (z1.multiply("10".pow(l1))).add(z3.subtract(z1.add(z2))).multiply("10".pow(l1/2)).add(z2) ;
    return result;
  }