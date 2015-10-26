#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* searchlinkedlist(Node* head, int value);
void insertintolinkedlist(Node* afterme, int value);
void removefromlinkedlist(Node* before);

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

    cout << "-------------------" << endl;

    currentlink = searchlinkedlist(head, 4);
    if (currentlink != NULL) {
        insertintolinkedlist(currentlink, 444);
    }

    currentlink = head;
    while (currentlink != NULL) {
        cout << currentlink->data << endl;
        currentlink = currentlink->next;
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

    newnode->next = afterme->next;
    afterme->next = newnode;
}

void removefromlinkedlist(Node* before) {
    Node* deleteme = before->next;
    before->next = before->next->next;
    delete deleteme;
}

