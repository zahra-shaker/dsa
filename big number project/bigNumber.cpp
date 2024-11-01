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
      int lnght=number.lenght();
      if(numOther.number.lenght() > lnght) 
        lnght=numOther.number.lenght();
      for(int i=lnght-1; i>-1 ; i--) {
        result[i] = (number[i] + numOther[i])%10 ;
        result[i-1] += (number[i] + numOther[i])/10 ; }
        return result;
    }
        
      
    bigNumber subtract (const bigNumber&);
    friend bigNumber operator<< (bigNumber);
    friend bigNumber operator>> (bigNumber);
} ;
