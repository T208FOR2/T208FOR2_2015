#include <iostream>
#include <string>
using namespace std;

const double PI = 3.1415926;

// Function decleration
double area(double radius);
double area(double width, double height);

int main()
{
    double theradius, thewidth, theheight;
    cin >> theradius >> thewidth >> theheight;

    cout << "Area of circle: " << area(theradius) << endl;
    cout << "Area of box: " << area(thewidth, theheight) << endl;

    return 0;
}

double area(double radius) {
    return PI * radius * radius;
}

double area(double width, double height) {
    return width * height;
}
