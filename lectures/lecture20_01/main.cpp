#include <iostream>
#include "Numbers.h"

using namespace std;


void dummyfunction(Numbers &num) {
  cout << num << endl;
}

int main() {
  for (int i = 0; i < 5; i++) {
    cout << "----------------" << endl;
    Numbers thenumbers;

    for (int j = 0; j < 100; j++) {
      thenumbers.add(j);
    }

    cout << thenumbers - 1 << endl;

    thenumbers[0] = 99;

    //cout << thenumbers << endl;
    dummyfunction(thenumbers);

    cout << "Hi!" << endl;
  }

  return 0;
}


