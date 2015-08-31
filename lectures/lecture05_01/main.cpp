#include <iostream>
#include <string>
using namespace std;

// Function decleration
void printtimeunits(int x, string singular, string plural);

int main()
{
    int numberofseconds;

    const int SECONDSINYEAR = 60*60*24*365;
    const int SECONDSINDAY = 60*60*24;
    const int SECONDSINHOUR = 60*60;
    const int SECONDSINMINUTE = 60;

    cin >> numberofseconds;

    printtimeunits(numberofseconds / SECONDSINYEAR, "year", "years");
    numberofseconds = numberofseconds % SECONDSINYEAR;

    printtimeunits(numberofseconds / SECONDSINDAY, "day", "days");
    numberofseconds = numberofseconds % SECONDSINDAY;

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

