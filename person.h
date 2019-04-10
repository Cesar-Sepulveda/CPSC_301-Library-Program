//Cesar Sepulveda
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Person{
  private:
    int cardID;
    bool active;
    string firstName;
    string lastName;
    vector<Book *> checked;
  public:
    Person();
    Person(int id, bool act, string fn, string ln);
    int getCardID();
    void setCardID(int id);
    bool getActive();
    void setActive(bool a);
    string getFirstName();
    void setFirstName(string fName);
    string getLastName();
    void setLastName(string lName);
    void addBook(Book *b);
    void checkout(bool user);
    int checkedSize();
};
#endif
