//Cesar Sepulveda
#include "book.cpp"
#include "person.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

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

vector<Book *>readBookFile(vector<Book *> bookVec, string fileName){
  fstream myFile;
  myFile.open(fileName);
  int bookID;
  string author;
  string category;
  string title;
  string space;
  while(myFile){
    myFile >> bookID;
    getline(myFile, space);
    getline(myFile, title);
    getline(myFile, author);
    getline(myFile, category);
    bookVec.push_back(new Book(bookID, title, author, category));
  }
  bookVec.pop_back();
  myFile.close();
  return bookVec;
}

vector<Person *> readPersonFile(vector<Person *> perVec, string fileName){
  fstream myFile;
  myFile.open(fileName);
  string fName;
  string lName;
  int cardID;
  bool active;
  string space;
  while(myFile){
    myFile >> cardID;
    myFile >> active;
    myFile >> fName >> lName;
    getline(myFile,space);
    perVec.push_back(new Person(cardID, active, fName, lName));
  }
  perVec.pop_back();
  myFile.close();
  return perVec;
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
        perVec.at(person)->addBook(bookVec.at(book));
        cout << "Rental Completed" << endl;
    }else{
        cout << "Book already checked out" << endl;
    }
}

void bookReturn(vector<Book *> bookVec, int bookID){
    int book = -1;
    for(int i = 0; i < bookVec.size(); ++i){
        if(bookVec.at(i)->getBookID() == bookID){
           book = i;
        }
    }
    if(book == -1){
        cout << "Book ID not found" << endl;
        return;
    }
    bookVec.at(book)->setChecked(false);
    cout << "Title: " << bookVec.at(book)->getTitle() << endl;
    cout << "Return Completed" << endl;

}

void availableBooks(vector<Book *> bookVec){
    int count = 0;
    for(int i = 0; i < bookVec.size(); ++i){
        if(bookVec.at(i)->getChecked() == false){
            cout << "Book ID: " << bookVec.at(i)->getBookID() << endl;
            cout << "Title: " << bookVec.at(i)->getTitle() << endl;
            cout << "Author: " << bookVec.at(i)->getAuthor() << endl;
            cout << "Category: " << bookVec.at(i)->getCategory() << endl;
            ++count;
        }
    }
    if(count == 0){
        cout << "No available books" << endl;
    }
}

void outstandingRentals(vector<Person *> perVec){
    int count = 0;
    for(int i = 0; i < perVec.size(); ++i){
            perVec.at(i)->checkout(false);
            if(perVec.at(i)->checkedSize() > 0){
                count = perVec.at(i)->checkedSize();
            }
    }
    if(count == 0){
        cout << "No outstanding rentals" << endl;
    }
}

void cardholderRentals(vector<Person *> perVec, int cardID){
  int cardholder = 0;
  for(int i = 0; i < perVec.size(); ++i){
    if(perVec.at(i)->getCardID() == cardID){
      cardholder = cardID;
    }
  }
  if(cardholder == 0){
    cout << "Card ID not found" << endl;
    return;
  }else{
    if(perVec.at(cardholder)->checkedSize() == 0){
      cout << "No outstanding rentals" << endl;
      return;
    }else{
      perVec.at(cardholder)->checkout(true);
    }
  }
}

int findLargest(vector<Person *> perVec){
  int largest = 0;
  for(int i = 0; i < perVec.size(); ++i){
    if(perVec.at(i)->getCardID() > largest){
      largest = perVec.at(i)->getCardID();
    }
  }
  return largest;
}

void newLibraryCard(vector<Person *> perVec){
  int count = 0;
  for(int i = 0; i < perVec.size(); ++i){
    count = i;
  }
  Person *temp;
  string fname;
  string lname;
  perVec.push_back(temp);
  cout << "Please enter the first name: ";
  cin >> fname;
  cout << endl;
  cout << "Please enter the last name: ";
  cin >> lname;
  cout << endl;
  perVec.at(count+1)->setFirstName(fname);
  perVec.at(count+1)->setLastName(lname);
  perVec.at(count+1)->setCardID(findLargest(perVec)+1);
  perVec.at(count+1)->setActive(true);
  cout << "Card ID " << perVec.at(count+1)->getCardID() << " active" << endl;
  cout << "Cardholder: " << perVec.at(count+1)->getFirstName() << " " << perVec.at(count+1)->getLastName() << endl;
}

void closeLibraryCard(vector<Person *> perVec, int cardID){
  int found = -1;
  char answer;
  for(int i = 0; i < perVec.size(); ++i){
    if(perVec.at(i)->getCardID() == cardID){
      found = i;
    }
  }
  if(found == -1){
    cout << "Card ID not found" << endl;
    return;
  }else if(perVec.at(found)->getActive() == false){
    cout << "Card ID is already inactive" << endl;
    return;
  }else{
    cout << "Cardholder: " << perVec.at(found)->getFirstName() << " " << perVec.at(found)->getLastName() << endl;
    cout << "Are you sure you want to deactivate card (y/n)?";
    cin >> answer;
    cout << endl;
    if(answer == 'y'){
      perVec.at(found)->setActive(false);
      cout << "Card ID deactivated" << endl;
    }
  }
}

void displayBooks(vector<Book *> bookVec){
  cout << bookVec.size() << endl;
  for(int i = 0; i < bookVec.size(); ++i){
    cout << "Book ID: " << bookVec.at(i)->getBookID() << endl;
    cout << "Title: " << bookVec.at(i)->getTitle() << endl;
    cout << "Author: " << bookVec.at(i)->getAuthor() << endl;
    cout << "Category: " << bookVec.at(i)->getCategory() << endl;
    cout << "checked: " << bookVec.at(i)->getChecked() << endl;
  }
}

void displayCardholders(vector<Person *> perVec){
  for(int i = 0; i < perVec.size(); ++i){
    cout << "Card ID: " << perVec.at(i)->getCardID() << endl;
    cout << "Active: " << perVec.at(i)->getActive() << endl;
    cout << "Name: " << perVec.at(i)->getFirstName() << " " << perVec.at(i)->getLastName() << endl;
  }
}

int main(){
  vector<Book *> books;
  vector<Person *> cardholders;
  int choice;
  int cardID;
  int bookID;
  cardholders = readPersonFile(cardholders, "persons.txt");
  books = readBookFile(books, "books.txt");
  do{
    printmenu();
    cin >> choice;
    switch(choice){
      case 1:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        cout << endl;
        bookCheckout(books, cardholders, cardID);
        break;
      case 2:
        cout << "Please enter the book ID to return: ";
        cin >> bookID;
        cout << endl;
        bookReturn(books, bookID);
        break;
      case 3:
        availableBooks(books);
        break;
      case 4:
        outstandingRentals(cardholders);
        break;
      case 5:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        cout << endl;
        cardholderRentals(cardholders, cardID);
        break;
      case 6:
        newLibraryCard(cardholders);
        break;
      case 7:
        cout << "Please enter the card ID: ";
        cin >> cardID;
        cout << endl;
        closeLibraryCard(cardholders, cardID);
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
