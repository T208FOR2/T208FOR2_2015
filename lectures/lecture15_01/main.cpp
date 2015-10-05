#include <iostream>
#include <string>

using namespace std;

struct Director {
    string name;
    int birthyear;
};

struct Movie {
    string title;
    int year;
    Director directedby;
};

Director fallsemskilarleikstjora(Movie m) {
    return m.directedby;
}

void printMovie(Movie m) {
    cout << m.title << " (" << m.year << ")";
    cout << " - directed by " << m.directedby.name;
    cout << ", born in " << m.directedby.birthyear << endl;
}

int main()
{
    Director scott = {"Ridley Scott", 1937};
    Movie m1, m2;

    m1.title = "Alien";
    m1.year = 1979;

    m1.directedby = scott;

    m2 = m1;

    printMovie(m1);

    return 0;
}
