// RECURSIVE FUNCTIONS

#include <iostream>
#include <string>

using namespace std;

// n number of disks
// s source pin
// i intermediate pin
// d destination pin
// moves: number of moves

void towersofhanoi(int n, int s, int i, int d, int &moves) {
    if (n > 0) {
        towersofhanoi(n-1, s, d, i, moves);
        cout << "Move "<< moves++ << ": Disk " << n
        << " is moved from pin " << s << " to pin " << d << endl;
        towersofhanoi(n-1, i, s, d, moves);
    }
}

int factorial(int n) {
    if (n <= 1) {  // base case
        return 1;
    }
    else {  // recursive / iterative case
        return n * factorial( n-1 );
    }
}

void write_vertical(int n) {
    if (n < 10) {
        cout << n << endl;
    }
    else {
        write_vertical(n / 10);
        cout << n % 10 << endl;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    /*
    cout << factorial(6) << endl;
    cout << "-------------------" << endl;
    write_vertical(123456);
    cout << "-------------------" << endl;
    cout << gcd(64, 20) << endl;
    cout << "-------------------" << endl;
*/
    int moves = 1;
    int disks;
    cin >> disks;
    towersofhanoi(disks, 1,2,3, moves);

    return 0;

}





