#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

// This program takes as input a textfile with some twitterfeed
// The program finds all hashtags, counts them and prints out the
// most popular hashtags used (in decreasing order).

// Constants (the filename for the input file and maximum number of unique hashtags)
const string THEFILENAME = "twitterfeed.txt";
const int NUM = 1000;
const string NOHASHTAG = "no hashtag";

void openinputfile(ifstream& inputfile, string thefilename);

string getnexthashtag(string texti, unsigned int& pos);

int indexofelement(string tags[], int n, string newelement);

void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements)

void insertionSort(int array[], string tags[], int length);

string stringtolower(string s);


int main()
{
    ifstream inputfile;
    string tag, t, hashtags[NUM];
    int hashcount[NUM], numberofelements = 0;

    for (int i = 0; i < NUM; i++)
    {
        hashtags[i] = "";
        hashcount[i] = 0;
    }

    openinputfile(inputfile, THEFILENAME);

    unsigned int pos = 0;

    while (!inputfile.eof())
    {
        getline(inputfile, t);

        tag = getnexthashtag(t, pos);
        while (tag != NOHASHTAG)
        {
            // Add to array?
            insertorupdatearrays(hashtags, hashcount, tag);

            tag = getnexthashtag(t, pos);
        }
    }

    insertionSort(hashcount, hashtags, numberofelements);

    for (int i = 0; i < 30; i++)
    {
        cout << hashtags[i] << " - " << hashcount[i] << endl;
    }

    inputfile.close();

    return 0;
}


void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements)
{
    int index = indexofelement(tags, numberofelements, newelement);

    if (index >= 0)  // Hashtag exists -> increase counter
    {
        counts[index]++;
    }
    else if (numberofelements < NUM)    // Add new hashtag (if there is space)
    {
        tags[numberofelements] = newelement;
        counts[numberofelements] = 1;
        numberofelements++;
    }
    else {  // Running out of space
        cout << "The number of unique hashtags is more than the limit of " << NUM << endl;
    }
}

string getnexthashtag(string texti, unsigned int& pos)
{
    unsigned int hashstart = texti.find("#",pos);
    if (hashstart < texti.length())
    {
        unsigned int hashend = texti.find_first_of(" .,\n\"#;?!:'", hashstart+1);
        pos = hashend;
        return texti.substr(hashstart, hashend - hashstart);
    }
    else
    {
        return NOHASHTAG;
    }
}


void insertionSort(int array[], string tags[], int length)
{
    int i, j, tmp;
    string tmp2;

    for (i = 1; i < length; i++)
    {
        tmp = array[i];
        tmp2 = tags[i];

        j = i;
        while (j > 0 && array[j - 1] < tmp)
        {
            array[j] = array[j - 1];
            tags[j] = tags[j - 1];
            j--;
        }
        array[j] = tmp;
        tags[j] = tmp2;
    }
}

int indexofelement(string tags[], int n, string newelement)
{
    for (int i = 0; i < n; i++)
    {
        if (stringtolower(tags[i]) == stringtolower(newelement))
        {
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

string stringtolower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}


