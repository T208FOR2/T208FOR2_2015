#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* searchlinkedlist(Node* head, int value);
void insertintolinkedlist(Node* afterme, int value);

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

    currentlink = head;
    while (currentlink != NULL) {
        cout << currentlink->data << endl;
        currentlink = currentlink->next;
    }

    currentlink = searchlinkedlist(head, 4);
    if (currentlink != NULL) {
        cout << "I found it!: " << currentlink->data << endl;
    }

    return 0;
}

Node* searchlinkedlist(Node* head, int value) {
    Node* here = head;
    if (here == NULL) {
        return NULL;
    }

    while (here->data != value && here->next != NULL) {
        here = here->next;
    }

    if (here->data == value) {
        return here;
    }
    else {
        return NULL;
    }
}

void insertintolinkedlist(Node* afterme, int value) {
    Node *newnode = new Node;
    newnode->data = value;


}
