#include <iostream>
using namespace std;

class bigNumber {
  private:
    string number;
  public:
    bigNumber() {
      number="0" ; }
    bigNumber(const string& num) {
      number = num; }
    bigNumber add (const bigNumber& numOther) {
      string result="0";
      int lngth=number.length();
      if(numOther.number.length() > lngth) 
        lngth=numOther.number.length();
      for(int i=lngth-1; i>-1 ; i--) {
        result[i] = (number[i] + numOther.number[i])%10 ;
        result[i-1] += (number[i] + numOther.number[i])/10 ; }
        return result;
    }
    bigNumber subtract (const bigNumber& numOther) {
    string result="0";
    int lngth=number.length();
    if(numOther.number.length() > lngth)
      lngth=numOther.number.length();
    for(int i=length-1; i>-1; i--) {
      if(numOther.number[i] > number[i] ) {
        number[i]+10;
        number[i-1]-1; }
      result[i] = number[i] - numOther.number[i] ; }
    return result; }
    friend bigNumber operator<< (bigNumber);
    friend bigNumber operator>> (bigNumber);
} ;
