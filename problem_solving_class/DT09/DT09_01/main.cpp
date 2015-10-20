#include <iostream>

using namespace std;

class Triangle
{
public:
    Triangle();
    Triangle(int aa, int bb, int cc);
    bool isTriangle() const;
    bool isEquilateral() const;
    bool isRight() const;
    double AreaR() const;

    friend ostream& operator <<(ostream& outs, const Triangle &prentTriangle);
    friend istream& operator >>(istream& ins, Triangle &getTriangle);
private:
    int A;
    int B;
    int C;

};





int main()
{
    Triangle tri1;
    Triangle tr2(10,3,4);
    cout << tri1.isTriangle() << endl;
    cout << tr2.isTriangle() << endl;
    cout << tri1.isEquilateral() << endl;
    cout << tr2.isEquilateral() << endl;
    cout << tri1 << endl;
    cout << tr2 << endl;

    cin >> tri1;
}



Triangle::Triangle()
{
    A = 6;
    B = 6;
    C = 6;
}
Triangle::Triangle(int aa, int bb, int cc)
{
    A = aa;
    B = bb;
    C = cc;
}

bool Triangle::isTriangle() const
{
    if((A > 0) && (B > 0) && (C > 0))
    {
        if(((A + B) > C) && ((A + C) > B) && ((B + C) > A))
        {
            return true;
        }
    }

    return false;
}



bool Triangle::isEquilateral() const
{
    if(A == B && B == C)
    {
        return true;
    }
    return false;
}


bool Triangle::isRight() const
{
    if(((C*C) == A*A + B*B) || ((A*A == B*B + C*C)) || ((B*B) == A*A + C*C))
    {
        return true;
    }
    return false;
}


double Triangle::AreaR() const
{
    if(isRight())
    {
        if(C > A && C > B)
        {
            return (0.5 * A * B);
        }
        else if(A > B && A > C)
        {
            return (0.5 * B*C);
        }
        return (0.5 * C * A);
    }
    return 0.0;
}



ostream& operator <<(ostream& outs, const Triangle &prentTriangle)
{
    if(prentTriangle.isTriangle())
    {
        if(prentTriangle.isEquilateral())
        {
            outs << "The triangle is a equilateral triangle with the sides " << endl;
            outs << "A = " << prentTriangle.A << endl;
            outs << "B = " << prentTriangle.B << endl;
            outs << "C = " << prentTriangle.C << endl;
        }
        else if(prentTriangle.isRight())
        {
            outs << "The triangle is a right triangle with the sides " << endl;
            outs << "A = " << prentTriangle.A << endl;
            outs << "B = " << prentTriangle.B << endl;
            outs << "C = " << prentTriangle.C << endl;
            outs << "The area is = "<<prentTriangle.AreaR() << endl;
        }
    }
    else
    {
        outs << "This is not a triangle!" << endl;
    }

    return outs;
}



istream& operator >> (istream& ins, Triangle &getTriangle)
{
    ins >> getTriangle.A >> getTriangle.B >> getTriangle.C;
    return ins;
}
