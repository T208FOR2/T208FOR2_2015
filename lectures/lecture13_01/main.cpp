#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++) {
        p[i] = 0;
    }

    // Here we have a dynamic and initialized array called p with n elements

    delete [] p;

    return 0;
}
