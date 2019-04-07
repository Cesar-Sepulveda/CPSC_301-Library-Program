#include "book.cpp"
#include "person.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------
void printmenu() {
    cout << "1. Book checkout" << endl;
    cout << "2. Book return" << endl;
    cout << "3. View all available books" << endl;
    cout << "4. View all outstanding rentals" << endl;
    cout << "5. View outstanding rentals for a cardholder" << endl;
    cout << "6. Open new library card" << endl;
    cout << "7. Close library card" << endl;
    cout << "8. Close program" << endl;
  }

void readBookFile(){

}

void readPersonFile(){

}

void bookCheckout(vector<Book *> bookVec, vector<Person *> perVec, int ID){
    int bookID;
    int person = -1;
    int book = -1;
    for(int i; i < perVec.size(); ++i){
        if(perVec.at(i)->getCardID() == ID){
           person = i;
        }
    }
    if(person  == -1){
        cout << "Card ID not found" << endl;
        return;
    }
    cout << "Cardholder: " << perVec.at(person)->getFirstName() << " " << perVec.at(person)->getLastName() << endl;
    cout << "Please enter the book ID: ";
    cin >> bookID;
    for(int j; j < bookVec.size(); ++j){
        if(bookVec.at(j)->getBookID() == bookID){
           book = j;
        }
    }
    if(book = -1){
        cout << "Book ID not found" << endl;
        return;
    }
    cout << "Title: " << bookVec.at(book)->getTitle() << endl;
    if(bookVec.at(book)->getChecked() == false){
        bookVec.at(book)->setChecked(true);
        cout << "Rental Completed" << endl;
    }else{
        cout << "Book already checked out" << endl;
    }
}



int main(){
  vector<Book *> books;
  vector<Person *> cardholders;
  int choice;
  int cardID;
  do{
    printmenu();
    cin >> choice;
    switch(choice){
      case 1:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        bookCheckout(books, cardholders, cardID);
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        cout << "Exiting program..." << endl;
        break;
      default:
        cout << "Invalid entry" << endl;
        break;
    }
    cout << endl;
  }while(choice != 8);
  for(int i = 0; i < books.size(); ++i){
    delete books.at(i);
  }
  for(int i = 0; i < cardholders.size(); ++i){
    delete cardholders.at(i);
  }

  return 0;
}
