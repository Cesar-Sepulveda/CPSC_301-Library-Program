#include <string>
using namespace std;

class Book{
  private:
    int bookID;
    string title;
    string author;
    string category;
  public:
    Book();
    int getBookID();
    void setBookID(int id);
    string getTitle();
    void setTitle(string t);
    string getAuthor();
    void setAuthor(string a);
    string getCategory();
    void setCategory(string c);
};
