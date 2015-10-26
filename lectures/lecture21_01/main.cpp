#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int main()
{
    Node *head = NULL;
    Node *newlink;

    newlink = new Node;
    //(*newlink).data = 42;
    newlink->data = 42;  // -> is the same as (*   ).

    head = newlink;

    cout << newlink->data << endl;

    return 0;
}
