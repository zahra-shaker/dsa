#include <iostream>
using namespace std;

class bigNumber {
  private:
    string number;
  public:
    bigNumber();
    bigNumber(const string&);
    bigNumber add (const bigNumber&);
    bigNumber subtract (const bigNumber&);
    friend bigNumber operator<< (bigNumber);
    friend bigNumber operator>> (bigNumber);
} ;
