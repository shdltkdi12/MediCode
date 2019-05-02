#include "ServerInterface.h"

string* ServerInterface::read(string filename) {
    ifstream my_file(filename.c_str());
    ifstream infile;
    string temp;
    string* record;
    int numLines = 0;


    if(my_file.good()){
        my_file.close();
        infile.open(filename.c_str());
        while(getline(infile, temp)) {
            numLines++;
        }
        infile.close();

        infile.open(filename.c_str());
        record = new string[numLines];
        for (int i = 0; i < numLines; i++) {
            getline(infile, record[i]);
        }
        infile.close();
    }

    else {
        cout << "SI READ ERROR" << endl;
    }

    return record;

}

int ServerInterface::readSize(string filename) {
    ifstream my_file(filename.c_str());
    ifstream infile;
    string temp;
    string* record;
    int numLines = 0;


    if(my_file.good()){
        my_file.close();
        infile.open(filename.c_str());
        while(getline(infile, temp)) {
            numLines++;
        }
        infile.close();
    }

    else {
        cout << "SI READ SIZE ERROR" << endl;
    }

    return numLines;

}

string ServerInterface::write(string* record, int recordLines, string patient) {
    string filename = patient;
    ifstream my_file(filename.c_str());
    ofstream outfile;
    ifstream infile;
    string temp;
    int numLines;

    if (my_file.good()) {
        my_file.close();
        infile.open(filename.c_str());
        while(getline(infile, temp)) {
            numLines++;
        }
        infile.close();

        outfile.open(filename.c_str(), ios::app);
        filename = filename + to_string(numLines);
        outfile << filename << endl;
        outfile.close();

        outfile.open(filename.c_str());
        for (int i = 0; i < recordLines; i++) {
            outfile << record[i] << endl;
        }
        outfile.close();
    }

    else {
        cout << "SI WRITE ERROR" << endl;
    }

    return filename;
}

void ServerInterface::writeOver(string* record, int numLines, string filename) {
    ifstream my_file(filename.c_str());
    ofstream outfile;
    ifstream infile;
    string temp;

    if (my_file.good()) {
        my_file.close();

        outfile.open(filename.c_str());
        for (int i = 0; i < numLines; i++) {
            outfile << record[i] << endl;
        }
        outfile.close();
    }

    else {
        cout << "SI WRITE ERROR" << endl;
    }

}

bool ServerInterface::find(string patient) {
    string filename = patient;
    ifstream my_file(filename.c_str());
    if (my_file.good()) {
        return true;
    }

    else {
        return false;
    }

}


void ServerInterface::send(string record, string affiliate) {
    ifstream my_file(affiliate.c_str());
    ofstream outfile;

    if (my_file.good()) {
        my_file.close();
        outfile.open(affiliate.c_str(), ios::app);
        outfile << record << endl;
        outfile.close();
    }

    else {
        cout << "SI SEND ERROR" << endl;
    }
}

int ServerInterface::verifyUser(string user, string pass) {
    string filename;
    int i;

    for (i = 0; i < 4; i++) {
        switch(i) {
            case 0:
                filename = "patients";
                break;
            
            case 1:
                filename = "medstaff";
                break;
            
            case 2:
                filename = "admins";
                break;

            case 3: 
                filename = "affiliates";
                break;

        }

        ifstream my_file(filename.c_str());
        ifstream infile;
        string tempUser;
        string tempPass;

        if (my_file.good()) {
            my_file.close();
            infile.open(filename.c_str());
            while (getline(infile, tempUser)) {
                getline(infile, tempPass);

                if (user.compare(tempUser) == 0) {
                    if (pass.compare(tempPass) == 0) {
                        return i;
                    }
                }
            }
            infile.close();
        }
    }

    return i;
}

void ServerInterface::addUser(string username, string password, string status) {
    string filename;

    if (status.compare("Patient") == 0) {
        filename = "patients";
    }

    else if (status.compare("Medical") == 0) {
        filename = "medstaff";
    }

    else if (status.compare("Admin") == 0) {
        filename = "admins";
    }

    else if (status.compare("Affiliate") == 0) {
        filename = "affiliates";
    }

    ofstream outfile;

    
    outfile.open(filename.c_str(), ios::app);
    outfile << username << endl;
    outfile << password << endl;
    outfile.close();

    outfile.open(username.c_str());
    outfile << endl;
    outfile.close();
    

    
}

void ServerInterface::deleteFile(string filename) {
    remove(filename.c_str());
}