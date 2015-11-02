#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int main() {
    Person* Steve;
    Person* newguy;
    Person* tmpperson;

    Steve = new Person("Steve Rogers");

    newguy = new Person("Peter Parker");
    Steve->addChild(newguy);
    newguy->addChild(new Person("Eddie Brock"));
    newguy->addChild(new Person("Mary Jane Watson"));
    tmpperson = new Person("Norman Osborne");
    newguy->addChild(tmpperson);
    tmpperson->addChild(new Person("Harry Osborne"));

    newguy = new Person("Clark Kent");
    newguy->addChild(new Person("Lois Lane"));
    newguy->addChild(new Person("Lex Luthor"));
    Steve->addChild(newguy);

    newguy = new Person("Bruce Wayne");
    newguy->addChild(new Person("Dick Grayson"));
    tmpperson = new Person("Jim Gordon");
    tmpperson->addChild(new Person("Barbara Gordon"));
    newguy->addChild(tmpperson);
    Steve->addChild(newguy);
    newguy->addChild(new Person("Bane"));
    newguy->addChild(new Person("Oswald Chesterfield Cobblepot"));

    //Steve->removeChild(newguy);
    cout << endl << endl;
    Steve->printFamilyTree();
    cout << endl << endl;

    //delete Steve;
    return 0;
}
