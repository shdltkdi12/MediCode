//User Interface Class

#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class UserInterface {
    public:
        string user;
        bool loggedIn;
        void displayMenu();
        void display(string);
        string read();
    private:
        int level;
        void login();
        void selectOption(string, bool&);
};