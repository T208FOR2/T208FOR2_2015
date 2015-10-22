#include <iostream>

using namespace std;

class Numbers {
public:
  Numbers();   // Constructor
  Numbers(int thesize);

  Numbers(const Numbers& copyme);  // Copy constructor

  ~Numbers();  // Destructor

  void operator = (const Numbers& sameasme);  // Assignment operator

  void add(int tala);
  void setsize(int newsize);
  int size() const {return n;};

  friend Numbers operator + (const Numbers &lhs, const Numbers &rhs);
  friend Numbers operator + (const Numbers &lhs, int tala);
  friend Numbers operator + (int tala, const Numbers &rhs);

  friend Numbers operator - (const Numbers &lhs, const Numbers &rhs);
  friend Numbers operator - (const Numbers &lhs, int tala);
  friend Numbers operator - (int tala, const Numbers &rhs);

  friend Numbers operator * (const Numbers &lhs, int tala);
  friend Numbers operator * (int tala, const Numbers &rhs);
  friend Numbers operator / (const Numbers &rhs, int tala);

  friend Numbers operator - (const Numbers &rhs);

  friend ostream& operator << (ostream& outs, const Numbers &num);
  friend istream& operator >> (istream& ins, Numbers &num);

  int& operator [] (int index);

private:
  int n;
  int *p;

  void initializenumbers();
};

int mymax(int a, int b) {
  if (a > b) {
    return a;
  }
  else {
    return b;
  }
}

int mymin(int a, int b) {
  if (a < b) {
    return a;
  }
  else {
    return b;
  }
}

Numbers::Numbers() {
  n = 1;
  p = new int[n];

  initializenumbers();
}

Numbers::Numbers(int thesize) {
  n = thesize;
  p = new int[n];

  initializenumbers();
}

Numbers::Numbers(const Numbers& copyme) {
  n = copyme.n;
  p = new int[n];
  for (int i = 0; i < n; i++) {
    p[i] = copyme.p[i];
  }
}

void Numbers::operator = (const Numbers& sameasme) {
  if (n != sameasme.n) {
    delete [] p;
    p = new int[sameasme.n];
    n = sameasme.n;
  }
  for (int i = 0; i < n; i++) {
    p[i] = sameasme.p[i];
  }
}

Numbers::~Numbers() {
  delete [] p;
}

void Numbers::add(int tala) {
  setsize(n + 1);
  p[n-1] = tala;
}

void Numbers::setsize(int newsize) {
  int *pnew = new int[newsize];
  for (int i = 0; i < newsize; i++) {
    pnew[i] = 0;
  }
  for (int i = 0; i < mymin(n, newsize); i++) {
    pnew[i] = p[i];
  }
  delete [] p;
  p = pnew;
  n = newsize;
}

Numbers operator + (const Numbers &lhs, const Numbers &rhs) {
  Numbers num(mymax(lhs.n, rhs.n));

  for (int i = 0; i < lhs.n; i++) {
    num.p[i] = lhs.p[i];
  }

  for (int i = 0; i < rhs.n; i++) {
    num.p[i] += rhs.p[i];
  }

  return num;
}

Numbers operator + (const Numbers &lhs, int tala) {
  Numbers num(lhs.n);

  for (int i = 0; i < lhs.n; i++) {
    num.p[i] = lhs.p[i] + tala;
  }
  return num;
}
Numbers operator + (int tala, const Numbers &rhs) {
  return rhs + tala;
}


Numbers operator - (const Numbers &lhs, const Numbers &rhs) {
  Numbers num(mymax(lhs.n, rhs.n));

  for (int i = 0; i < lhs.n; i++) {
    num.p[i] = lhs.p[i];
  }

  for (int i = 0; i < rhs.n; i++) {
    num.p[i] -= rhs.p[i];
  }

  return num;
}


Numbers operator - (const Numbers &lhs, int tala) {
  Numbers num(lhs.n);

  for (int i = 0; i < lhs.n; i++) {
    num.p[i] = lhs.p[i] - tala;
  }
  return num;
}
Numbers operator - (int tala, const Numbers &rhs) {
  Numbers num(rhs.n);

  for (int i = 0; i < rhs.n; i++) {
    num.p[i] = tala - rhs.p[i];
  }
  return num;
}


Numbers operator * (const Numbers &lhs, int tala) {
  Numbers num(lhs.n);

  for (int i = 0; i < lhs.n; i++) {
    num.p[i] = lhs.p[i] * tala;
  }
  return num;
}
Numbers operator * (int tala, const Numbers &rhs) {
  return rhs + tala;
}


Numbers operator / (const Numbers &lhs, int tala) {
  Numbers num(lhs.n);

  for (int i = 0; i < lhs.n; i++) {
    num.p[i] = lhs.p[i] / tala;
  }
  return num;
}

Numbers operator - (const Numbers &rhs) {
  Numbers num(rhs.n);

  for (int i = 0; i < rhs.n; i++) {
    num.p[i] = -rhs.p[i];
  }
  return num;
}

int& Numbers::operator [] (int index) {
  if (index < 0 || index >= n) {
    cout << "Error: Index out of bounds." << endl;
    exit(1);
  }
  return p[index];
}

ostream& operator << (ostream& outs, const Numbers &num) {
  for (int i = 0; i < num.n; i++) {
    outs << num.p[i] << " ";
  }
  return outs;
}

istream& operator >> (istream& ins, Numbers &num) {
  for (int i = 0; i < num.n; i++) {
    ins >> num.p[i];
  }
  return ins;
}

void Numbers::initializenumbers() {
  for (int i = 0; i < n; i++) {
    p[i] = 0;
  }
}

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


