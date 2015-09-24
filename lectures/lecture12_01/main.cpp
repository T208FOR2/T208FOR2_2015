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

void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements);

void insertionSort_int_dec(int array[], string tags[], int length);
void insertionSort_str_asc(int array[], string tags[], int length);

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

    unsigned int pos;

    while (!inputfile.eof())
    {
        getline(inputfile, t);  // get one line at a time from the file

        pos = 0; // initialize the position for the current line
        tag = getnexthashtag(t, pos);  // find the first hashtag in the line
        while (tag != NOHASHTAG)     // while we have some hashtags...
        {
            // Add to array if tag is new, otherwise update counter
            insertorupdatearrays(hashtags, hashcount, tag, numberofelements);

            tag = getnexthashtag(t, pos);  // get the next hashtag in the current line
        }
    }

    insertionSort_int_dec(hashcount, hashtags, numberofelements);  // Sort by count (decreasing)
    insertionSort_str_asc(hashcount, hashtags, numberofelements);  // Sort by tags (alphabetically)

    for (int i = 0; i < 30; i++)   // Print out the top tags
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

void insertionSort_int_dec(int counts[], string tags[], int length) {
    int i, j, tmp_int;
    string tmp_str;

    for (i = 1; i < length; i++)
    {
        tmp_int = counts[i];
        tmp_str = tags[i];

        j = i;
        while (j > 0 && counts[j - 1] < tmp_int)
        {
            counts[j] = counts[j - 1];
            tags[j] = tags[j - 1];
            j--;
        }
        counts[j] = tmp_int;
        tags[j] = tmp_str;
    }
}

void insertionSort_str_asc(int counts[], string tags[], int length) {
    int i, j, tmp_int;
    string tmp_str;

    for (i = 1; i < length; i++)
    {
        tmp_int = counts[i];
        tmp_str = tags[i];

        j = i;
        while (j > 0 && tags[j - 1] > tmp_str)
        {
            counts[j] = counts[j - 1];
            tags[j] = tags[j - 1];
            j--;
        }
        counts[j] = tmp_int;
        tags[j] = tmp_str;
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


