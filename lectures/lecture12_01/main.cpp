#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";
const int NUM = 1000;

void openinputfile(ifstream& inputfile, string thefilename);
string getnexthashtag(string texti, int& pos);


int main() {
    string currentline;
    ifstream inputfile;
    string tag;
    string t;
    string hashtags[NUM];
    int hashcount[NUM];

    openinputfile(inputfile, THEFILENAME);

    unsigned int hashstart, hashend;
    cout << "--------------------" << endl;


    while (!inputfile.eof()) {
        getline(inputfile, t);

        hashstart = t.find("#");
        while ( hashstart < t.length() ) {
            // Fann hashtag!
            hashend = t.find_first_of(" .,\n\"#;?!", hashstart+1);

            tag = t.substr(hashstart, hashend - hashstart);
            cout << "\"" << tag << "\"" << endl;

            hashstart = t.find("#", hashstart+1);
        }
    }

    inputfile.close();

    return 0;
}



void openinputfile(ifstream& inputfile, string thefilename)
{
    inputfile.open(thefilename.c_str());

    if (inputfile.fail())
    {
        cout << "Can't open " << thefilename << endl;
        exit(1);
    }
}

