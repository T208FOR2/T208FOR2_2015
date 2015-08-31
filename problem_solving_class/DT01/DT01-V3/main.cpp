/*
	Forritið segir að allar tölur minni en 2 séu prime,
	þ.a.l. gerum ráð fyrir að notandi slá inni tölur stærri en 0.
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number" << endl;
    cin >> n;
    // 'Sannleikurinn' notaður til að athuga hvort 'n' sé frumtala í while lykkju.
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
                break; // break stekkur úr while lykkju
            }
           i += 1;
        }
        if(Sannleikurinn) // Þarf ekki að gera == true þar sem 'Sannleikurinn' er bool breyta
        {
            cout << n << "is a prime number!" << endl;
        }

    }



}
