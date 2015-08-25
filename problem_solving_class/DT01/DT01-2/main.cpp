#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Veldu fjolda itranir" << endl;
    cin >> n;

    double summa1 = 0.0;
    double summa2 = 0.0;
    int i = 1;

    double j = 0.5;


    while(i < n)
    {
        summa1 += (1.0/(i*i));
        summa2 +=  j;
        j = 0.5 * j;
        i += 1;
    }

    cout << summa1 << endl;
    cout << summa2 << endl;
    
    // Önnur aðferð með forlykkju
    
    //upphafstillum breyturnar
    summa1 = 0;
    summa2 = 0;
    j = 0.5;
    
    for( int k = 1 ; k < n ; k++)
    {
        summa1 = summa1 + (1.0 / (k*k));
        summa2 = summa2 + j;
        j = j * 0.5;
    }
    
    cout << summa1 << endl;
    cout << summa2 << endl;



}
