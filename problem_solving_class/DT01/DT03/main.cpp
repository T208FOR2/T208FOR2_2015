#include <iostream>
#include <fstream>
#include <cstdlib> // for exit function in openFiles
using namespace std;


const string FILENAME = "C:/Users/hjorleifur12/Desktop/download.txt";

void openFile(ifstream& file);

string inputFromFile(ifstream& file);

string inputFromFile2(ifstream& file);

int main()
{
    ifstream file;
    openFile(file);
    inputFromFile2(file);



}


void openFile(ifstream& file)
{
    file.open(FILENAME.c_str());
    if(file.fail())
    {
        cout << "File didnt open" << endl;
        exit(1);
    }
}


string inputFromFile(ifstream& file)
{
    string next;
    string totalText;
    while(file >> next)
    {
        //cout << next << endl;
        totalText += ' ' + next;
    }
    return totalText;
}

string inputFromFile2(ifstream& file)
{
    string next;
    string totalText; // Do I need to do this now?

    while(!file.eof())
    {
            getline(file, next);
            cout << "| " << next << " |"<< endl;
            if(next == "\n") cout << "yoyomagic" << endl;
    }

    return "asda";

}


