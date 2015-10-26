#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int main()
{
    int n = 10;
    Node *head = NULL;
    Node *newlink, *currentlink;

    newlink = new Node;
    //(*newlink).data = 42;
    newlink->data = 42;  // -> is the same as (*   ).
    newlink->next = NULL;
    head = newlink;

    for (int i = 0; i < n; i++) {
        newlink = new Node;
        newlink->data = i;
        newlink->next = head;
        head = newlink;
    }



    cout << newlink->data << endl;

    return 0;
}
