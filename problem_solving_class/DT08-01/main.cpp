#include <iostream>

using namespace std;


class Dagsetning
{
    public:
        Dagsetning();
        Dagsetning(int day, int month, int year);
        int getDay();
        int getMonth();
        int getYear();
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        void readData();
        void writeData();
        bool leapYear();
    private:
        int dag;
        int manud;
        int ar;
};






int main()
{
    Dagsetning d1;
    Dagsetning d2(2,2,2012);
    d1.readData();
    cout << d1.getDay() << " day" << endl;
    cout << d1.getMonth() << " month" << endl;
    cout << d1.getYear() << " year" << endl;
    return 0;
}

void fall();

Dagsetning::Dagsetning()
{
    dag = 0;
    manud = 0;
    ar = 0;
}
Dagsetning::Dagsetning(int day, int month, int year)
{
    dag = day;
    manud = month;
    ar = year;
}

int Dagsetning::getYear()
{
    return ar;
}

int Dagsetning::getDay()
{
    return dag;
}
int Dagsetning::getMonth()
{
    return manud;
}

void Dagsetning::setDay(int day)
{
    dag = day;
}


void Dagsetning::setMonth(int month)
{
    manud = month;
}
void Dagsetning::setYear(int year)
{
    ar = year;
}

void Dagsetning::readData()
{
    cin >> dag;
    cin >> manud;
    cin >> ar;
}

void Dagsetning::writeData()
{
    if(dag < 10)
    {
        cout << "0" << dag << "/";
    }
    else
    {
        cout << dag << "/";
    }

    if(manud < 10)
    {
        cout << "0" <<  manud << "/";
    }
    else
    {
        cout << manud << "/";
    }
    cout << ar << endl;
}

bool Dagsetning::leapYear()
{
    if(ar % 4 == 0)
    {
        return true;
    }

}
