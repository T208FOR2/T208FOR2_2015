#include <iostream>
#include <fstream> // Til ad geta notad ifstream og ofstream
#include <cstdlib>  // Geymir exit(1)
using namespace std;
// const string  INPUTFILENAME = "....."

// 1) Void fall sem tekur við ifsteam breytu. Fallið þarf að athuga hvort skráinn opnðist ef ekki þá þarf að gefa villumerking og hætta forritinu
void openFile(ifstream& fin);

// 2) Fall sem tekur við ifstream breytu og fer í gegnum skrána og setur allan texta í string breytu og skilar henni svo til baka
// while (ifstream << next)
string readTextWords(ifstream& fin);

// 3) Fall sem tekur við ifstream breytu og fer í gegnum skrána og setur allan texta í string breytu og skilar henni svo til baka
// while (!file.eof())
string readTextChars(ifstream& fin);

// 4) Void fall sem tekur við string breytu og býr til nýja skrá og textann í string breytu í nýju skránna
void writeToFile(string textToWrite);

// 5) Void fall sem tekur við string breytu og prentar út texta
void printText(string textToPrint);


int main()
{
    ifstream fin;
    openFile(fin);
    string textWords = readTextWords(fin);
    fin.close();

    openFile(fin);
    string textChars = readTextChars(fin);
    fin.close();

    writeToFile(textWords);
    printText(textChars);

    return 0;
}

void openFile(ifstream& fin)
{
    fin.open("DT03textfile.txt");

    if (fin.fail())
    {
        cout << "Couldn't open the file!" << endl;
        exit(1);
    }
}

string readTextWords(ifstream& fin)
{
    string word, text;

    while (fin >> word)
    {
        text += word + " "; // text = text + word + " ";
    }
    return text;
}

string readTextChars(ifstream& fin)
{
    string text;

    while (!fin.eof())
    {
        text += fin.get(); // Les lika newline, bil, tab
    }
    return text;
}

void writeToFile(string textToWrite)
{
    ofstream fout;
    fout.open("DT03writefile.txt");
    fout << textToWrite << endl;
    fout.close();
}

void printText(string textToPrint)
{
    cout << textToPrint << endl;
}
