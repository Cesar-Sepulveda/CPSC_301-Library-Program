#include "person.h"
#include <string>

using namespace std;

Person::Person(){
  cardID = -1;
  active = false;
  firstName = " ";
  lastName = " ";
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
