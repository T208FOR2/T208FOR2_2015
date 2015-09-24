#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";

void openinputfile(ifstream& inputfile, string thefilename);
string getnexthashtag(string texti, int& pos);


int main()
{
    string currentline;
    ifstream inputfile;
    string tag;
    string t = "#TDSBreakingNews Hillary may delay presidential campaign. Makes the election that much more intense. #TantricCampaigning";
    cout << t << endl;




    /*
    openinputfile(inputfile, THEFILENAME);

    while (!inputfile.eof()) {
        getline(inputfile, currentline);
        cout << currentline << endl;
    }


    inputfile.close();
*/

    return 0;
}

string getnexthashtag(string texti, int& pos) {
    unsigned int hashstart, hashend;

    hashstart = texti.find("#", pos+1);

    if ( hashstart < t.length() ) {
        hashend = t.find_first_of(" .,\n\"#;?!", hashstart+1);
        tag = t.substr(hashstart, hashend - hashstart);
        pos = hashend;
        return tag;
    }
    else {
        return "no hash";
    }
}


void openinputfile(ifstream& inputfile, string thefilename) {
    inputfile.open(thefilename.c_str());

    if (inputfile.fail()) {
        cout << "Can't open " << thefilename << endl;
        exit(1);
    }
}

