#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// typedef says: When i type NodePtr what I actually mean is Node*
typedef Node* NodePtr;

// Creates new node
NodePtr createNode(int d, NodePtr n);

// Prints the data in the list
void printList(NodePtr head);

// Adds 'newNode' to the list
void addToList(NodePtr &head, NodePtr newNode);

// Returns the last node in the list
NodePtr getLast(NodePtr head);

// Looks for a number in the list
bool findNumber(NodePtr head, int n);

// Returns memory from all nodes
void delList(NodePtr head);

int main() {
	NodePtr head = NULL;
	int n, find, inp;
	cin >> n;
	for(int i = 0; i < n; i++) {
		// If list is empty, the head node is created
		cin >> inp;
		if(head == NULL) {
			head = createNode(inp, NULL);
		} else { // Else add to list
			addToList(head, createNode(inp, NULL));
		}
	}
	cin >> find;

	cout << "Data in list : ";
	printList(head);

	cout << "Data in back: " << getLast(head)->data << endl;

	if(findNumber(head, find)) {
		cout << "The number " << find << " is in the list" << endl;
	} else {
		cout << "The number " << find << " is not in the list" << endl;
	}
	// Return memory
	delList(head);
	return 0;
}

Node* createNode(int d, Node* n) {
	// Create new node
	NodePtr newNode = new Node();
	// Put data in node
	newNode->data = d;
	newNode->next = n;
	// Return new node
	return newNode;
}

void printList(NodePtr head) {
	// Print data until you reach the end (an empty node)
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next; // Make sure you move to the next node! Otherwise: infinite loop
	}
	cout << endl;
}

void addToList(NodePtr &head, NodePtr newNode) {
	// Find the last node and append to the list
	NodePtr last = getLast(head);
	last->next = newNode;
}

NodePtr getLast(NodePtr head) {
	// Go through list until you find the last node (when next node is NULL)
	while(head->next != NULL) {
		head = head->next;
	}
	return head;
}

bool findNumber(NodePtr head, int n) {
	// Walk through list and see if a number is in the list
	while(head != NULL) {
		// If you find the number return true
		if(head->data == n) {
			return true;
		}
		head = head->next;
	}
	// If you walk through the whole list (don't find the number) return false
	return false;
}

void delList(NodePtr head) {
	// Walk through the list and return the memory from each node
	while(head != NULL) {
		NodePtr tmp = head;
		head = head->next;
		delete tmp;
	}
}