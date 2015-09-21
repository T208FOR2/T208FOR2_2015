#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Veldu fjolda itranir" << endl;
    cin >> n;
    // Notum double þar sem summur þurfa aukastafi
    double summa1 = 0.0;
    double summa2 = 0.0;
    int i = 1;

    double j = 0.5;


    while(i <= n)
    {
        summa1 += (1.0/(i*i));
        summa2 +=  j;
        j = 0.5 * j;
        i += 1; // "i += 1" sama og "i = i + 1". Skoða líka ++ virkjann
    }

    cout << summa1 << endl;
    cout << summa2 << endl;
    
    // Önnur aðferð með forlykkju
    
    //upphafstillum breyturnar
    summa1 = 0;
    summa2 = 0;
    j = 0.5;
    
    for( int k = 1 ; k <= n ; k++)
    {
        summa1 = summa1 + (1.0 / (k*k)); // Hægt að nota += virkjann
        summa2 = summa2 + j; // Hægt að nota += virkjann
        j = j * 0.5; // Hægt að nota *= virkjann
    }
    
    cout << summa1 << endl;
    cout << summa2 << endl;



}
