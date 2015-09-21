#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int const NUM = 1000000;

int const ITERATIONS = 100;

int sequentialSearch(int array[], int size, int find);
int binarySearch(int array[], int size, int find);

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    int a[NUM];
    int value, searchindex;
    clock_t cstart, cend;
    double seqtime = 0, bintime = 0;

    cout << "Creating the array";
    for (int i = 0; i < NUM; i++)
    {
        a[i] = i;
        if (i % 10000 == 0)
            cout << ".";
    }

    cout << "\nCalculating";

    for (int i = 0; i < ITERATIONS; i++)
    {
        value = rand() % NUM;

        //Time the sequential search
        cstart = clock();

        searchindex = sequentialSearch(a, NUM, value);

        cend = clock();
        seqtime += (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);

        //Time the binary search
        cstart = clock();

        searchindex = binarySearch(a, NUM, value);

        cend = clock();
        bintime += (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);

        cout << ".";
    }
    cout << endl;

    cout.setf(ios::fixed);
    cout << "\nRunning Time for " << ITERATIONS << " iterations: " << endl;
    cout << "Sequential search over " << NUM << " elements: " << seqtime << endl;
    cout << "Binary search over " << NUM << " elements:     " << bintime << endl << endl;

    return 0;
}

int sequentialSearch(int array[], int size, int find)
{
    int i = 0;
    while (i < size)
    {
        if (array[i] == find)
        {
            return i;
        }
        i++;
    }

    return -1;
}

int binarySearch(int array[], int size, int find)
{
    int low = 0, high = size-1;
    int middle = (low + high)/2;

    while (low < high)
    {
        if (array[middle] < find)
            low = middle + 1;
        else if (array[middle] > find)
            high = middle-1;
        else
            return middle;

        middle = (low+high)/2;
    }

    return -1;
}
