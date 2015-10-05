#include <iostream>
#include <string>

using namespace std;

struct Director {
    string name;
    int birthyear;
};

class Movie {
public:
    string title;
    int year;
    Director directedby;

    void printMovie();
    void getInfo();
};

Director fallsemskilarleikstjora(Movie m) {
    return m.directedby;
}

void Movie::printMovie() {
    cout << "<I'm part of the class!>" << endl;
    cout << title << " (" << year << ")";
    cout << " - directed by " << directedby.name;
    cout << ", born in " << directedby.birthyear << endl;
}

void Movie::getInfo() {
    cout << "Name of movie: ";
    getline(cin, title);
    cout << "Year: ";
    cin >> year;
    cin.ignore();
}

void printMovie(Movie m) {
    cout << "<I'm not in the class...>" << endl;
    cout << m.title << " (" << m.year << ")";
    cout << " - directed by " << m.directedby.name;
    cout << ", born in " << m.directedby.birthyear << endl;
}

int main()
{
    int fjoldimovies;
    cout << "How many movies do you own? ";
    cin >> fjoldimovies;
    cin.ignore();

    Movie *themovies = new Movie[fjoldimovies];
    for (int i = 0; i < fjoldimovies; i++) {
        // lesa inn
        themovies[i].getInfo();
    }

    string lookup;
    cout << "What movie are you looking for? ";
    getline(cin, lookup);

    for(int i = 0; i < fjoldimovies; i++) {
        if (themovies[i].title == lookup) {
            cout << "This is the movie: " << endl;
            themovies[i].printMovie();
        }
    }

    delete [] themovies;
    return 0;
}
