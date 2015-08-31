#include <iostream>
using namespace std;

int main()
{
    int numberofseconds;

    int numberofyears;
    int numberofdays;
    int numberofhours;
    int numberofminutes;

    const int SECONDSINYEAR = 60*60*24*365;
    const int SECONDSINDAY = 60*60*24;
    const int SECONDSINHOUR = 60*60;
    const int SECONDSINMINUTE = 60;

    cin >> numberofseconds;
    if (numberofseconds > SECONDSINYEAR)
    {
        numberofyears = numberofseconds / SECONDSINYEAR;
        numberofseconds = numberofseconds - numberofyears*SECONDSINYEAR;
        cout << numberofyears << " year";
        if (numberofyears > 1) {
            cout << "s";
        }
        cout << endl;
    }

    if (numberofseconds > SECONDSINDAY)
    {
        numberofdays = numberofseconds / SECONDSINDAY;
        numberofseconds = numberofseconds - numberofdays*SECONDSINDAY;
        cout << numberofdays << " day";
        if (numberofdays > 1) {
            cout << "s";
        }
        cout << endl;
    }
    if (numberofseconds > SECONDSINHOUR)
    {
        numberofhours = numberofseconds / SECONDSINHOUR;
        numberofseconds = numberofseconds - numberofhours*SECONDSINHOUR;
        cout << numberofhours << " hour";
        if (numberofhours > 1) {
            cout << "s";
        }
        cout << endl;
    }

    if (numberofseconds > SECONDSINMINUTE)
    {
        numberofminutes = numberofseconds / SECONDSINMINUTE;
        numberofseconds = numberofseconds - numberofminutes*SECONDSINMINUTE;
        cout << numberofminutes << " minute";
        if (numberofminutes > 1) {
            cout << "s";
        }
        cout << endl;
    }
    if (numberofseconds > 0) {
        cout << numberofseconds << " second";
        if (numberofseconds > 1) {
            cout << "s";
        }
    }
    cout << endl;

    return 0;
}
