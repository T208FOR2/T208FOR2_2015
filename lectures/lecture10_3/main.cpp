#include <iostream>
#include <ctime>
using namespace std;

void insertionSortwithShift(int array[], int length);
void insertionSortwithSwap(int array[], int length);

void selectionSort(int array[], int length);

int partition(int array[], int low,int high);
void quickSort(int array[], int low,int high);

void initializearray(int array[], int length);

double measure_insertionsort1();
double measure_insertionsort1_sorted();
double measure_insertionsort2();
double measure_insertionsort2_sorted();
double measure_selectionsort();
double measure_selectionsort_sorted();
double measure_quicksort();
double measure_quicksort_sorted();

const int NUMBEROFELEMENTS = 100000;
const int ITERATIONS = 1; //100;

int main()
{
    double timeinsertionsort1 = 0.0,timeinsertionsort2 = 0.0,timeselectionsort = 0.0,timequicksort= 0.0;
    double timeinsertionsort1_sorted = 0.0,timeinsertionsort2_sorted = 0.0,timeselectionsort_sorted = 0.0,timequicksort_sorted=0.0;
    double totaltime = 0.0;
    clock_t cstart, cend;

    srand(static_cast<unsigned int>(time(NULL)));

    cstart = clock();

    timeinsertionsort1 = measure_insertionsort1();
    timeinsertionsort1_sorted = measure_insertionsort1_sorted();

    timeinsertionsort2 = measure_insertionsort2();
    timeinsertionsort2_sorted = measure_insertionsort2_sorted();

    timeselectionsort = measure_selectionsort();
    timeselectionsort_sorted = measure_selectionsort_sorted();

    timequicksort = measure_quicksort();
    timequicksort_sorted = measure_quicksort_sorted();

    cend = clock();
    totaltime += (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);

    cout.setf(ios::fixed);
    cout << "\nRunning Time: " << endl;
    cout << "Insertion sort with shifts:\n";
    cout << "Random: " << timeinsertionsort1 << endl;
    cout << "Sorted: " << timeinsertionsort1_sorted << endl << endl;
    cout << "Insertion sort with swaps:\n";
    cout << "Random: " << timeinsertionsort2 << endl;
    cout << "Sorted: " << timeinsertionsort2_sorted << endl << endl;
    cout << "Selection sort:\n";
    cout << "Random: " << timeselectionsort << endl;
    cout << "Sorted: " << timeselectionsort_sorted << endl << endl;
    cout << "Quick sort:\n";
    cout << "Random: " << timequicksort << endl;
    cout << "Sorted: " << timequicksort_sorted << endl << endl;
    cout << "Total time: " << totaltime << endl << endl;

    return 0;
}

double measure_insertionsort1()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        initializearray(array, NUMBEROFELEMENTS);
        insertionSortwithShift(array, NUMBEROFELEMENTS);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_insertionsort1_sorted()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    initializearray(array, NUMBEROFELEMENTS);
    insertionSortwithShift(array, NUMBEROFELEMENTS);

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        insertionSortwithShift(array, NUMBEROFELEMENTS);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_insertionsort2()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        initializearray(array, NUMBEROFELEMENTS);
        insertionSortwithSwap(array, NUMBEROFELEMENTS);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_insertionsort2_sorted()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    initializearray(array, NUMBEROFELEMENTS);
    insertionSortwithSwap(array, NUMBEROFELEMENTS);

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        insertionSortwithSwap(array, NUMBEROFELEMENTS);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_selectionsort()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        initializearray(array, NUMBEROFELEMENTS);
        selectionSort(array, NUMBEROFELEMENTS);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_selectionsort_sorted()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    initializearray(array, NUMBEROFELEMENTS);
    selectionSort(array, NUMBEROFELEMENTS);

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        selectionSort(array, NUMBEROFELEMENTS);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_quicksort()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        initializearray(array, NUMBEROFELEMENTS);
        quickSort(array, 0, NUMBEROFELEMENTS-1);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

double measure_quicksort_sorted()
{
    int array[NUMBEROFELEMENTS];
    clock_t cstart, cend;

    initializearray(array, NUMBEROFELEMENTS);
    quickSort(array, 0, NUMBEROFELEMENTS-1);

    cstart = clock();
    for (int i = 0; i < ITERATIONS; i++)
    {
        quickSort(array, 0, NUMBEROFELEMENTS-1);
    }
    cend = clock();

    return (cend - cstart) / static_cast<double> (CLOCKS_PER_SEC);
}

void initializearray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        array[i] = rand();
}

void insertionSortwithShift(int array[], int length)
{
    int i, j, tmp;

    for (i = 1; i < length; i++)
    {
        tmp = array[i];
        j = i;
        while (j > 0 && array[j - 1] > tmp)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = tmp;
    }
}

void insertionSortwithSwap(int array[], int length)
{
    int i, j, tmp;

    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
            j--;
        }
    }
}

void selectionSort(int array[], int length)
{
    int i, j, min_value, min_index, tmp;

    for (i = 0; i < length; i++)
    {
        min_value = array[i];
        min_index = i;

        for (j = i+1; j < length; j++)
        {
            if (array[j] < min_value)
            {
                min_value = array[j];
                min_index = j;
            }
        }

        if (min_value < array[i])
        {
            tmp = array[i];
            array[i] = min_value;
            array[min_index] = tmp;
        }
    }
}


int partition(int array[], int low, int high)
{
    int swap = 0;
    int pivot = (low+high)/2;
    int pivotvalue = array[pivot];

    while (high > low)
    {

        while (array[low] < pivotvalue)
        {
            low++;
        }

        while (array[high] > pivotvalue)
        {
            high--;
        }

        if (low == pivot)
        {
            pivot = high;
        }
        else if (high == pivot)
        {
            pivot = low;
        }

        swap = array[low];
        array[low] = array[high];
        array[high] = swap;
    }

    return pivot;
}

void quickSort(int array[], int low,int high)
{
    int pivot;

    if(low < high)
    {
        pivot = partition(array, low, high);
        quickSort(array, low, pivot-1);
        quickSort(array, pivot+1, high);
    }
}
