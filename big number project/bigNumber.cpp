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
    friend bigNumber operator<< (int);
    friend bigNumber operator>> (int);
} ;

bigNumber :: bigNumber operator<< (int num) {
  for(int i=0; i<num; i++) {
    for(int l=0; l<value.length(); l++) { 
    value[l-1] = value[l] ; }
  value[value.length()-1] = '0'; }
  return *this; }

bigNumber :: bigNumber operator>> (int num) {
  for(int i=0; i<num; i++) {
    for(int l=value.length()-1; l>=0; l--) {
    value[l+1] = value[l] ; }
    value[0]='0';}
    return *this; }
