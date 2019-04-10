//Cesar Sepulveda
#include "person.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Person::Person(){
  cardID = -1;
  active = false;
  firstName = " ";
  lastName = " ";
}
Person::Person(int id, bool act, string fn, string ln){
  cardID = id;
  active = act;
  firstName = fn;
  lastName = ln;
}
int Person::getCardID(){
  return cardID;
}
void Person::setCardID(int id){
  cardID = id;
}
bool Person::getActive(){
  return active;
}
void Person::setActive(bool a){
  active = a;
}
string Person::getFirstName(){
  return firstName;
}
void Person::setFirstName(string fName){
  firstName = fName;
}
string Person::getLastName(){
  return lastName;
}
void Person::setLastName(string lName){
  lastName = lName;
}
void Person::addBook(Book *b){
    checked.push_back(b);
}
void Person::checkout(bool user){
    if(checked.size() > 0){
        for(int i = 0; i < checked.size(); ++i){
            cout << "Book ID : " << checked.at(i)->getBookID() << endl;
            cout << "Title: " << checked.at(i)->getTitle() << endl;
            cout << "Author: " << checked.at(i)->getAuthor() << endl;
            if(user == false){
              cout << "Cardholder: " << getFirstName() << " " << getLastName();
              cout << "Card ID: " << getCardID() << endl;
            }
        }
    }
}

int Person::checkedSize(){
    return checked.size();
}
