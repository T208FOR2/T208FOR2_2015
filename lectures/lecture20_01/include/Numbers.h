#ifndef NUMBERS_H
#define NUMBERS_H

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

#endif // NUMBERS_H
