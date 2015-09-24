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
const int NUM = 1000;  // maximum number of unique hashtags
const string NOHASHTAG = "no hashtag";  // string constant if we don't find a hashtag
const int WHITESPACE = 40;  // how far to the right the counter appears
const int TOPCOUNT = 30;  // how many hashtags should we print

// Open the input file and check if it is ok
void openinputfile(ifstream& inputfile, string thefilename);

// Get the next hashtag from a string (starting from pos + updating pos)
string getnexthashtag(string texti, unsigned int& pos);

// Returns the index of newelement in the array tags, -1 if it is not there
int indexofelement(string tags[], int n, string newelement);

// Adds newelement to tags and increases counts and numberofelements if newelement is not in tags
// otherwise it just increases the counts for that tag
void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements);

// Sorting, two functions, one sorts on the int array, the other on the string array
void insertionSort_int_dec(int array[], string tags[], int length);
void insertionSort_str_asc(int array[], string tags[], int length);

// Takes a string and turns it into lowercase, used for comparing two hashtags
string stringtolower(string s);


int main()
{
    // Define variables
    ifstream inputfile;
    string tag, t, hashtags[NUM];
    int hashcount[NUM], numberofelements = 0;
    unsigned int pos;

    // Initialize arrays
    for (int i = 0; i < NUM; i++)
    {
        hashtags[i] = "";
        hashcount[i] = 0;
    }

    openinputfile(inputfile, THEFILENAME);

    // Read through the input file
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

    // If we first sort the two arrays by the hashtags (alphabetically) and
    // then by count (decreasing) we get all tags with the same count in
    // alphabetical order.
    insertionSort_str_asc(hashcount, hashtags, numberofelements);  // Sort by tags (alphabetically)
    insertionSort_int_dec(hashcount, hashtags, numberofelements);  // Sort by count (decreasing)

    for (int i = 0; i < TOPCOUNT; i++)   // Print out the top tags
    {
        cout << hashtags[i];  // Print the hashtag

        // Print whitespace so that the counters line up
        for (unsigned int j = 0; j < WHITESPACE - hashtags[i].length(); j++) {
            cout << " ";
        }
        cout << " x " << hashcount[i] << endl;  // print the counter
    }

    inputfile.close();

    return 0;
}


void insertorupdatearrays(string tags[], int counts[], string newelement, int& numberofelements)
{
    // get the index of newelement (-1 if it is not in the array tags)
    int index = indexofelement(tags, numberofelements, newelement);

    if (index >= 0) { // Hashtag exists -> increase counter
        counts[index]++;
    }
    else if (numberofelements < NUM) {   // Add new hashtag (if there is space)
        tags[numberofelements] = newelement;
        counts[numberofelements] = 1;
        numberofelements++;
    }
    else {  // Running out of space - can't add new hashtag
        cout << "The number of unique hashtags is more than the limit of " << NUM << endl;
    }
}

// Return the next hashtag in the string texti, starting at position pos
string getnexthashtag(string texti, unsigned int& pos)
{
    unsigned int hashstart = texti.find("#",pos);  // hashtags start with #
    if (hashstart < texti.length()) {
        // We've found the start of a hashtag, let's find where it ends
        unsigned int hashend = texti.find_first_of(" .,\n\"#;?!:'", hashstart+1);
        pos = hashend; // Update the call-by-reference variable pos (to be ready for next iteration)
        return texti.substr(hashstart, hashend - hashstart);  // return the hashtag
    }
    else {
        return NOHASHTAG;  // Return something to indicate that there are no more hashtags in this string
    }
}

// Classic insertion sort, here sorting two arrays
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

// And again sorting, here on the string array
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

// Find the index of an element in an array, return -1 if not found
int indexofelement(string tags[], int n, string newelement) {
    for (int i = 0; i < n; i++) {
        // compare hashtags using lowercase, to eliminate duplications
        if (stringtolower(tags[i]) == stringtolower(newelement)) {
            return i;  // return the correct index
        }
    }
    return -1;  // if not found, return -1
}

// Open the inputfile and check if it opened ok
void openinputfile(ifstream& inputfile, string thefilename)
{
    inputfile.open(thefilename.c_str());

    if (inputfile.fail())
    {
        cout << "Can't open " << thefilename << endl;
        exit(1);
    }
}

// Take a string variable (call-by-value) and return a lowercase copy of it.
string stringtolower(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}


