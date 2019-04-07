#include <string>
using namespace std;

class Person{
  private:
    int cardID;
    bool active;
    string firstName;
    string lastName;
  public:
    Person();
    int getCardID();
    void setCardID(int id);
    bool getActive();
    void setActive(bool a);
    string getFirstName();
    void setFirstName(string fName);
    string getLastName();
    void setLastName(string lName);
};
