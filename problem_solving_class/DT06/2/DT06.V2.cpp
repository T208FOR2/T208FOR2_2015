//
//  main.cpp
//  DT07.verkefni2
//
//  Created by Silja Guðbjörg Tryggvadóttir on 29/09/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

/*  Þið eigið að skrifa tvo föll sem tekur við kvik fylki og skilar max eða min af stökunum af fylkinu. Þið byrjið á að bua til kvik fylki af stærð n sem notandi slær inn og svo eigi þið að setja inn tölurnar sem koma inn frá notandanum. Eftir það eigi þið að nýta ykkur max og min föllinn og prenta út hvað var stærsta stakið og það minnsta. */

#include <iostream>

using namespace std;

int findMax(int *array, int size);
int findMin(int *array, int size);

int main()
{
    int n = 0, max = 0, min = 0;
    cin >> n;
    
    int *array;
    array = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    
    max = findMax(array, n);
    min = findMin(array, n);
    
    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;
    
    delete [] array;
    
    return 0;
}


int findMax(int *array, int size)
{
    int max = array[0];
    
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

int findMin(int *array, int size)
{
    int min = array[0];
    
    for (int i = 1; i < size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}