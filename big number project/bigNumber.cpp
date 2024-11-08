#include <iostream>
using namespace std;

class bigNumber {
  private:
    string value;
    bool isNegative;
  public:
    bigNumber() {
      value="0" ;
      isNegative=false; }
    bigNumber(const string& num) {
      if(num[0]=='+') {
        isNegative==false; }
      else{
        isNegative==true;}
      num<< ;
      value = num; }
    bigNumber add (const bigNumber& numOther) {
      string result="0";
      int lngth=value.length();
      if(numOther.value.length() > lngth) 
        lngth=numOther.value.length();
      if(isNegative == numOther.isNegative) {
      for(int i=lngth-1; i>0 ; i--) {
        result[i] = (value[i] + numOther.value[i])%10 ;
        result[i-1] += (value[i] + numOther.value[i])/10 ; }
      if(isNegative==true) {
        result[0] = '-' ;
        result.isNegative = true; }
      else{
        result[0] = '+' ;
        result.isNegative = false; } 
      }
      else if( isNegative && !numOther.isNegative) {
        result = numOther.subtract(*this) ; }
      else {
        result = *this.subtract(numOther);
        return result;
    }
    bigNumber subtract (const bigNumber& numOther) {
    string result="0";
    int lngth=value.length();
    if(numOther.value.length() > lngth)
      lngth=numOther.value.length();
    if (isNegative == numOther.isNegative ) {
    for(int i=length-1; i>0; i--) {
      if(numOther.value[i] > value[i] ) {
        value[i]+10;
        value[i-1]-1; }
      result[i] = value[i] - numOther.value[i] ; }
    }
    if( !isNegative && numOther.isNegative) {
      result = numOther.add(*this) ; 
      result[0]='+' ;
      result.isNegative = false ; }
    if( isNegative && !numOther.isNegative ) {
      result = numOther.add(*this) ; 
      result[0]='-' ;true ; } 
    return result; }
    friend bigNumber operator<< (bigNumber);
    friend bigNumber operator>> (bigNumber);
} ;

bigNumber operator<< (bigNumber num) {
  for(int i=0; i<num.value.length(); i++) {
    num[i-1] = num[i] ; }
  num[num.value.length()-1] = 0;
  return result; }

bigNumber operator>> (bigNumber num) {
  for(int i=num.value.length()-1; i>=0; i--) {
    num[i+1] = num[i] ; }
  num[0] = 0;
  return result; }
