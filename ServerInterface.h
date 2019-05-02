#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class ServerInterface {
    public:
        string* read(string);
        int readSize(string);
        string write(string*, int, string);
        void writeOver(string*, int, string);
        bool find(string);
        void send(string, string);
        int verifyUser(string, string);
        void addUser(string, string, string);
        void deleteFile(string);
};