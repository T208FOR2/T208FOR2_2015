#include <iostream>
#include <string>

using namespace std;

int main()
{
    string t = "This is a text to see how often the word \"the\" \noccurs.  The simple function does not \ndeal with capital letters, the word we're looking \nfor has to be exacly the same as the word \nin the text.";

    string leitarord = "the";
    int fjoldi = 0;
    unsigned int pos;

    cout << t << endl;

    pos = t.find(leitarord);
    cout << pos << endl;
    while (pos < t.length()) {
        fjoldi++;
        pos = t.find(leitarord, pos+leitarord.length());
        cout << pos << endl;
    }
    cout << "-------------" << endl;
    cout << fjoldi << endl;

    return 0;
}
