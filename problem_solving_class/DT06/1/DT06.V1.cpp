//
//  main.cpp
//  DT07.verkefni1
//
//  Created by Silja Guðbjörg Tryggvadóttir on 29/09/15.
//  Copyright (c) 2015 siljagudbjorg. All rights reserved.
//

/*  Skrifið forrit sem les inn nokkrar heiltölur. Fyrsta heiltalan segir til um fjölda talna og síðan koma heiltölurnar. Heiltölurnar geta verið jákvæðar eða neikvæðar. Forritið á að prenta út tvö stærstu tölugildin sem koma fyrir í tölunum.
 */

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    int *array;
    array = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        
        if (array[i] < 0)
        {
            array[i] = -array[i];
        } // Lika haegt ad nota: array[i] = abs(array[i]);
    }
    
    int max = 0, almostMax = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (max < array[i])
        {
            almostMax = max;
            max = array[i];
        }
        else if (almostMax < array[i] && max > array[i])
        {
            almostMax = array[i];
        }
    }
    
    cout << "Staersta talan er: " << max << endl;
    cout << "Naeststaersta talan er: " << almostMax << endl;
    
    delete [] array;
    
    return 0;
}