#include <iostream>

using namespace std;


class bok
{
public:
    bok();
    bok(string Author, string book, int pages);
    void read();
    void show();
    int Npage();
    void changepages(int tala);

private:
    string Author;
    string book;
    int pages;
};



int main()
{
    bok daudarosir("Arnaldur Indr", "daudarosir", 300);
    daudarosir.show();
}

bok::bok()
{
    Author = "";
    book = "";
    pages = 0;
}

bok::bok(string A, string b, int p)
{
    Author = A;
    book = b;
    pages = p;
}


void bok::show()
{
    cout << "The Author is " << Author << endl;
    cout << "The bok is " << book << endl;
    cout << "Number of pages is " << pages << endl;
}

void bok::read()
{
    cout << "Please enter some data "<< endl;
    cin >> Author;
    cin >> book;
    cin >> pages;
}

int bok::Npage()
{
    return pages;
}

void bok::changepages(int tala)
{
    pages = tala;
}
