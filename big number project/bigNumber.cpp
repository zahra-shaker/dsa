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
    bigNumber add (const bigNumber&);
    bigNumber subtract (const bigNumber&);
    friend bigNumber operator<< (bigNumber);
    friend bigNumber operator>> (bigNumber);
} ;
