#include <iostream>
#include <string>
using namespace std;

// Function decleration
bool printtimeunits(int x, string singular, string plural);

int main()
{
    int x;

    const int SECONDSINYEAR = 60*60*24*365;
    const int SECONDSINDAY = 60*60*24;
    const int SECONDSINHOUR = 60*60;
    const int SECONDSINMINUTE = 60;

    cin >> x;

    printtimeunits(x / SECONDSINYEAR, "year", "years");
    x = x % SECONDSINYEAR;

    if (printtimeunits(x / SECONDSINDAY, "day", "days")) {
        cout << "printing worked ok!" << endl;
    }
    x = x % SECONDSINDAY;

    printtimeunits(x, "second", "seconds");

    return 0;
}

// Function definition
bool printtimeunits(int x, string singular, string plural) {
    if (x == 1) {
        cout << x << " " << singular << endl;
        return true;
    }
    else if (x > 1) {
        cout << x << " " << plural << endl;
        return true;
    }
    return false;
}

