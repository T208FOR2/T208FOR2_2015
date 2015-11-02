#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person();
    Person(string personname);
    Person(const Person& p);
    ~Person();
    void operator= (const Person& p);

    void addChild(Person* newchild);
    void removeChild(Person* remchild);

    void set_name(string newname) { m_name = newname; };
    string get_name() const { return m_name; };

    void printFamilyTree();

    friend string findCommonAncestor(Person* p1, Person* p2);
    friend string* getAncestors(Person* p, int& n);

private:
    string m_name;

    Person* firstChild;
    Person* lastChild;
    Person* nextSibling;
    Person* prevSibling;

    Person* parent;

    void printFamily(Person* theperson, string addspace);

    Person* copyFamilyTree(const Person& copymytree);

    void deleteFamilyTree(Person* deleteme);
};

#endif // PERSON_H
