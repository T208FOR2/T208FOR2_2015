#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person::Person() {
    firstChild = NULL;
    lastChild = NULL;
    nextSibling = NULL;
    prevSibling = NULL;
    parent = NULL;
    m_name = "";
}

Person::Person(string personname) {
    firstChild = NULL;
    lastChild = NULL;
    nextSibling = NULL;
    prevSibling = NULL;
    parent = NULL;
    m_name = personname;
}

Person::Person(const Person& p) {
    m_name = p.m_name;
    firstChild = NULL;
    lastChild = NULL;
    nextSibling = NULL;
    prevSibling = NULL;
    parent = NULL;

    Person* tmp = p.firstChild;

    while (tmp != NULL) {
        addChild(copyFamilyTree(*tmp));

        tmp = tmp->nextSibling;
    }
}

void Person::operator= (const Person& p) {
    if (this != &p) {
        Person* tmp;

        parent = NULL;
        nextSibling = NULL;
        prevSibling = NULL;

        m_name = p.m_name;

        tmp = firstChild;
        while (tmp != NULL) {
            removeChild(tmp);
            delete tmp;
            tmp = firstChild;
        }

        tmp = p.firstChild;
        while (tmp != NULL) {
            addChild(copyFamilyTree(*tmp));
            tmp = tmp->nextSibling;
        }
    }
}

Person* Person::copyFamilyTree(const Person& copymytree) {
    Person* me = new Person;
    me->m_name = copymytree.m_name;

    Person* tmp = copymytree.firstChild;

    while (tmp != NULL) {
        me->addChild(copyFamilyTree(*tmp));

        tmp = tmp->nextSibling;
    }

    return me;
}

Person::~Person() {
    //cout << "destructor for " << this->m_name << endl;
    deleteFamilyTree(this);
}

void Person::deleteFamilyTree(Person* deleteme) {
    Person* tmp;
    while (firstChild != NULL) {
        tmp = firstChild;
        removeChild(firstChild);

        deleteFamilyTree(tmp);

        //cout << "deleting: " << tmp->m_name << endl;
        delete tmp;
    }
}

void Person::addChild(Person* newchild) {
    newchild->prevSibling = lastChild;

    if (lastChild != NULL)
        lastChild->nextSibling = newchild;

    lastChild = newchild;

    if (firstChild == NULL)
        firstChild = newchild;

    newchild->parent = this;
}

void Person::removeChild(Person* remchild) {
    if (firstChild == remchild)
        firstChild = firstChild->nextSibling;
    if (lastChild == remchild)
        lastChild = remchild->prevSibling;

    if (remchild->prevSibling != NULL)
        remchild->prevSibling->nextSibling = remchild->nextSibling;

    if (remchild->nextSibling != NULL)
        remchild->nextSibling->prevSibling = remchild->prevSibling;

    remchild->parent = NULL;
    remchild->nextSibling = NULL;
    remchild->prevSibling = NULL;
}

void Person::printFamilyTree() {
    printFamily(this, "");
}

void Person::printFamily(Person* theperson, string addspace) {
    if (theperson == NULL)
        return;

    cout << addspace << theperson->m_name << endl;
    printFamily(theperson->firstChild, addspace + "  ");
    printFamily(theperson->nextSibling, addspace);
}

string findCommonAncestor(Person* p1, Person* p2) {
    if (p1->parent == NULL)
        return p1->m_name + " has no parent";
    if (p2->parent == NULL)
        return p2->m_name + " has no parent";
    if (p1->m_name == p2->m_name)
        return p1->m_name + " and " + p2->m_name + " are the same person";

    int n1, n2;
    string* a1 = getAncestors(p1, n1);
    string* a2 = getAncestors(p2, n2);

    string returnvalue = "";
    if (a1[n1] != a2[n2]) {
        returnvalue = "no common ancestor";
    }
    else {
        while ((n1 >= 0) && (n2 >= 0)) {
            if (a1[n1-1] != a2[n2-1]) {
                returnvalue = a1[n1];
                n1 = 0;
            }
            n1--;
            n2--;
        }
    }

    delete [] a1;
    delete [] a2;
    return returnvalue;
}

string* getAncestors(Person* p, int& n) {
    n = 0;
    Person* tmp = p;
    while (tmp != NULL) {
        n++;
        tmp = tmp->parent;
    }
    string* ancestors = new string[n+1];

    int i = 0;
    tmp = p;
    while (tmp != NULL) {
        ancestors[i] = tmp->m_name;
        tmp = tmp->parent;
        i++;
    }
    return ancestors;
}
