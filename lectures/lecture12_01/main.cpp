#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string THEFILENAME = "twitterfeed.txt";
const int NUM = 1000;

void openinputfile(ifstream& inputfile, string thefilename);
string getnexthashtag(string texti, int& pos);
int indexofelement(string tags[], int n, string newelement);
void insertionSort(int array[], string tags[], int length);
string stringtolower(string s);


int main() {
    ifstream inputfile;
    string tag, t;
    int index;
    string hashtags[NUM];
    int hashcount[NUM];
    int numberofelements = 0;

    for (int i = 0; i < NUM; i++) {
        hashtags[i] = "";
        hashcount[i] = 0;
    }

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

            // Add to array?
            index = indexofelement(hashtags, numberofelements, tag);
            if (index == -1) {  // Add new hashtag
                hashtags[numberofelements] = tag;
                hashcount[numberofelements] = 1;
                numberofelements++;
            }
            else {
                hashcount[index]++;
            }

            hashstart = t.find("#", hashstart+1);
        }
    }

    insertionSort(hashcount, hashtags, numberofelements);

    for (int i = 0; i < 30; i++) {
        cout << hashtags[i] << " - " << hashcount[i] << endl;
    }

    inputfile.close();

    return 0;
}

void insertionSort(int array[], string tags[], int length) {
  int i, j, tmp;
  string tmp2;

  for (i = 1; i < length; i++) {
    tmp = array[i];
    tmp2 = tags[i];

    j = i;
    while (j > 0 && array[j - 1] < tmp) {
      array[j] = array[j - 1];
      tags[j] = tags[j - 1];
      j--;
    }
    array[j] = tmp;
    tags[j] = tmp2;
  }
}

int indexofelement(string tags[], int n, string newelement) {
    for (int i = 0; i < n; i++) {
        if (tags[i] == newelement) {
            return i;
        }
    }
    return -1;
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

string stringtolower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}


