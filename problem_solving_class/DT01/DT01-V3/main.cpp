#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number" << endl;
    cin >> n;
    bool Sannleikurinn = true;
    if(n < 2)
    {
        cout << n << "is a prime number!" << endl;
    }
    else
    {
        int i = 2;

        while(i < n)
        {
            if(n % i == 0)
            {
                cout << n << "is not a prime number!" << endl;
                Sannleikurinn = false;
                break;
            }
           i += 1;
        }
        if(Sannleikurinn)
        {
            cout << n << "is a prime number!" << endl;
        }

    }



}
