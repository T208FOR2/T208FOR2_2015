#include <iostream>
#include "Numbers.h"

using namespace std;


void dummyfunction(Numbers &num) {
  cout << num << endl;
}

int main() {
    Numbers thenumbers;

    for (int j = 0; j < 100; j++) {
      thenumbers.add(j);
    }

    dummyfunction(thenumbers);

    cout << "Hi!" << endl;

  return 0;
}


