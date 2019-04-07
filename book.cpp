#include "book.h"
#include <string>

using namespace std;

Book::Book(){
  bookID = -1;
  title = " ";
  author = " ";
  category = " ";
}
int Book::getBookID(){
  return bookID;
}
void Book::setBookID(int id){
  bookID = id;
}
string Book::getTitle(){
  return title;
}
void Book::setTitle(string t){
  title = t;
}
string Book::getAuthor(){
  return author;
}
void Book::setAuthor(string a){
  author = a;
}
string Book::getCategory(){
  return category;
}
void Book::setCategory(string c){
  category = c;
}
