#include <iostream>
#include <string>

using namespace std;

int main()
{
    string t = "This is a text to see how often the word \"the\" \noccurs.  The simple function does not \ndeal with capital letters, the word we're looking \nfor has to be exacly the same as the word \nin the text.";

    string leitarord = "the";
    int fjoldi = 0;

    cout << t << endl;

    while (t.find(leitarord) < t.length()) {
        fjoldi++;
    }

    cout << fjoldi << endl;

    return 0;
}
