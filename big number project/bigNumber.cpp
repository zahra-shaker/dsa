#include <iostream>
using namespace std;

class bigNumber {
  private:
    string value;
    bool isNegative;
  public:
  bigNumber();
  bigNumber(const string&);
  bigNumber add (const bigNumber&);
  bigNumber subtract (const bigNumber&);
  string getVal ();
  char getValIndx(int) ;
  bool getB () ;
  void setVal (string);
  void setValIndx(char,int) ;
  void setB (bool) ;
  bigNumber operator<< (int);
  bigNumber operator>> (int);
  void operator= (bigNumber) ;
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

bigNumber bigNumber:: add (const bigNumber& numOther) {
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
        result = *this.subtract(numOther); }
        return result;
    }
bigNumber bigNumber :: subtract (const bigNumber& numOther) {
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
