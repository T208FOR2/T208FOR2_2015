#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>



using namespace std;

const string FILENAME = "C:/Users/hjorleifur12/Desktop/songlist.txt";
const string OUTFILENAME = "C:/Users/hjorleifur12/Desktop/prettysonglist.txt";
const int SIZEARRAY = 10;

void openFilename(ifstream& infile);
string getData(ifstream& infile);
string makeSpace(string input);
string upperChase(string input);

int main()
{
    ifstream infile;
    openFilename(infile);
    string input[SIZEARRAY];
    string locVar;

    for(int i = 0; i < SIZEARRAY; i++)
    {
        input[i] = getData(infile);
        cout << input[i] << endl;
    }

    for(int i = 0; i < SIZEARRAY; i++)
    {
        locVar = input[i];
        if(locVar[0] == '/' && locVar[1] == '/')
        {
            //Vantar hér
        }
        else
        {
            locVar = makeSpace(locVar);
            locVar = locVar.substr(0, locVar.length()-3) + "mp3";
            cout << upperChase(locVar) << endl;

        }
    }

}

void openFilename(ifstream& infile)
{
    infile.open(FILENAME.c_str());
    if(infile.fail())
    {
        cout << "dem" << endl;
    }
}

string getData(ifstream& infile)
{
    string input;
    getline(infile, input);
    return input;


}

string makeSpace(string input)
{
    int pos;
    pos = input.find('_');
    while(pos > 0)
    {

        input[pos] = ' ';
        pos = input.find('_');
    }

    return input;
}

string upperChase(string input)
{
    int pos = input.find('.');
    input[pos+1] = toupper(input[pos+1]);
    pos = input.find(' ');
    while(pos > 0)
    {
        input[pos+1] = toupper(input[pos+1]);
        pos = input.find(' ', pos+1);
    }
    return input;
}
