#include "DoubleArray.h"

DoubleArray::DoubleArray()
{
    size = 0;
    array = NULL;
}

DoubleArray::~DoubleArray()
{
    if(array != NULL) {
        delete[] array;
    }
}

DoubleArray::DoubleArray(int n, double value) {
    array = new double[n];
    for(int i = 0; i < n; i++) {
        array[i] = value;
    }
    size = n;
}

double DoubleArray::average() const{
    if(array != NULL){
        double sum = 0;
        for(int i = 0; i < size; i++) {
            sum += array[i];
        }
        return sum/size;
    }
    return 0;
}

double DoubleArray::stddev() const{
    if(array != NULL) {
        double ave = average();
        double sum = 0;

        for(int i = 0; i < size; i++) {
            sum += (array[i] - ave) * (array[i] - ave);
        }

        sum /= (size - 1);
        return sqrt(sum);
    }
    return 0;
}

ostream& operator<<(ostream& out, const DoubleArray &da) {
    out << "n = " << da.size << " mean = " << da.average() << " stddev = " << da.stddev() << endl;
    return out;
}

istream& operator>>(istream& ins, DoubleArray &da) {
    ins >> da.size;
    if(da.array == NULL) {
        da.array = new double[da.size];
    }

    for(int i = 0; i < da.size; i++) {
        ins >> da.array[i];
    }
    return ins;
}

bool operator> (const DoubleArray &lhs, const DoubleArray &rhs) {
    return (lhs.average() > rhs.average());
}

double operator+(const DoubleArray &lhs, const DoubleArray &rhs) {
    return lhs.average() + rhs.average();
}
