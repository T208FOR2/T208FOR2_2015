#ifndef DOUBLEARRAY_H
#define DOUBLEARRAY_H

#include <iostream>
#include <cmath>

using namespace std;

class DoubleArray
{
    public:
        DoubleArray();
        DoubleArray(int n, double value);
        ~DoubleArray();

        double average() const;
        double stddev() const;

        friend ostream& operator<<(ostream& out, const DoubleArray &da);
        friend istream& operator>>(istream& ins, DoubleArray &da);
        friend bool operator> (const DoubleArray &lhs, const DoubleArray &rhs);
        friend double operator+(const DoubleArray &lhs, const DoubleArray &rhs);
    private:
        double *array;
        int size;
};

#endif // DOUBLEARRAY_H
