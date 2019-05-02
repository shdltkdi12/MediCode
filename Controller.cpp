#include "Controller.h"
#include "UserInterface.h"
#include "ServerInterface.h"




void Controller::requestTemplate(string recordType) {
    ServerInterface SI;
    UserInterface UI;
    int numLines;

    numLines = SI.readSize(recordType);
    string* recordTemplate = SI.read(recordType);


    numLines = numLines*2;

    writeRecord(recordTemplate, numLines);

}


void Controller::sendRecord(string recordName, string recipient) {
    ServerInterface SI;
    SI.send(recordName, recipient);
}

void Controller::requestSave(string* record, int numLines) {
    ServerInterface SI;
    string recordName;

    recordName = SI.write(record, numLines, patient);
}

void Controller::readRecord(string recordName) {
    ServerInterface SI;
    UserInterface UI;
    int numLines;

    numLines = SI.readSize(recordName);
    string* record = SI.read(recordName);

    for (int i = 0; i < numLines; i++) {
        UI.display(record[i]);
    }

}
void Controller::writeRecord(string* recordTemplate, int numLines) {
    UserInterface UI;
    string temp;

    string* record = new string[numLines];
    int index = 0;

    for (int i = 0; i < numLines; i++) {
        record[i] = recordTemplate[index++];
        UI.display(record[i]);
        record[++i] = UI.read();
    }

    requestSave(record, numLines);
}


/*========================================
        Create Record Controller
========================================*/


void CreateRecordController::start() {
    bool found = false; 
    found = requestInfo();
}

bool CreateRecordController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;

    string request = "Patient Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Patient not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    timer = 2;
    request = "Record Type: ";
    UI.display(request);
    recordType = UI.read();

    found = SI.find(recordType);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Record type not found!\n";
            request += "Record Type: ";
            UI.display(request);
            patient = UI.read();
            recordType = SI.find(recordType);
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try different record type. Exiting.";
        }

    }

    if (found) {
        requestTemplate(recordType);
    }
    
    return found;
}

/*========================================
        Create Appointment Controller
========================================*/


void  CreateAppointmentController::start() {
    bool found = false; 
    found = requestInfo();
}

bool  CreateAppointmentController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;
    string date;

    string request = "Patient Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Patient not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    timer = 2;
    request = "Enter Date: ";
    UI.display(request);
    date = UI.read();
    



    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Date not found!\n";
            request += "Enter Date: ";
            UI.display(request);
            date = UI.read();
            found = SI.find(date);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Exiting.";
        }

    }


    if (found) {
        requestTemplate(date);
    }
    
    return found;
}

void CreateAppointmentController::requestTemplate(string date) {
    ServerInterface SI;
    UserInterface UI;
    int numLines;

    numLines = SI.readSize(date);
    string* recordTemplate = SI.read(date);

    writeRecord(recordTemplate, numLines, date);

}

void CreateAppointmentController::writeRecord(string* record, int numLines, string date) {
    UserInterface UI;
    ServerInterface SI;
    string time;

    int slot = 0;
    for (int i = 0; i < numLines - 1; i += 2) {

        if (record[i+1].compare("OPEN") == 0) {
           UI.display("[" + to_string(++slot) + "]");
           UI.display(record[i]); 
        }
    }


    UI.display("Please enter the desired time: ");
    time = UI.read();

    slot = 0;
    for (int i = 1; i < numLines; i += 2) {

        if (record[i].compare("OPEN") == 0) {
            slot++;
           if (slot == stoi(time)) {
                record[i] = patient;
           }
        }
    }
    

    SI.writeOver(record, numLines, date);
}

/*========================================
   Create Employee Schedule Controller
========================================*/
void CreateScheduleController::start() {
    bool found = false; 
    found = requestInfo();
}

bool CreateScheduleController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;

    string request = "Employee Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Employee not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    recordType = "EmployeeSchedule";
    if (found) {
        requestTemplate(recordType);
    }
    
    return found;
}

/*========================================
   Create Visit Form Controller
========================================*/
void CreateVisitController::start() {
    bool found = false; 
    found = requestInfo();
}

bool CreateVisitController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;

    string request = "Patient Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Patient not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    recordType = "VisitForm";
    if (found) {
        requestTemplate(recordType);
    }
    
    return found;
}

/*========================================
        Create User Controller
========================================*/
void CreateUserController::start() {
    bool found = false; 
    found = requestInfo();
}

bool CreateUserController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string username;
    string password;
    string status;

    string request = "User Name: ";
    UI.display(request);
    username = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (found) {
        while ((timer-- > 0) && found) {
            request = "ERROR: User already created!\n";
            request += "User Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (found) {
            request = "ERROR: Too many failed reqests. Users already created. Exiting.";
        }

    }

    request = "Password: ";
    UI.display(request);
    password = UI.read();

    request = "Patient, Medical, Admin, or Affiliate? ";
    UI.display(request);
    status = UI.read();

    if (status.compare("Patient") == 0) {
        found = true;
    }

    else if (status.compare("Medical") == 0) {
        found = true;
    }

    else if (status.compare("Admin") == 0) {
        found = true;
    }

    else if (status.compare("Affiliate") == 0) {
                found = true;
            }

    else {
        found = false;
    }

    timer = 2;

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Please spell EXACTLY!\n";
            request += "Patient, Medical, Admin, or Affiliate? ";
            UI.display(request);
            status = UI.read();
            
            if (status.compare("Patient") == 0) {
                found = true;
            }

            else if (status.compare("Medical") == 0) {
                found = true;
            }

            else if (status.compare("Admin") == 0) {
                found = true;
            }

            else if (status.compare("Affiliate") == 0) {
                found = true;
            }

            else {
                found = false;
            }
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    SI.addUser(username, password, status);
    
    return found;
}

/*========================================
        Delete User Controller
========================================*/


void DeleteUserController::start() {
    bool found = false; 
    found = requestInfo();
}

bool DeleteUserController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string user;

    string request = "User Name: ";
    UI.display(request);
    user = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(user);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: User not found!\n";
            request += "User Name: ";
            UI.display(request);
            patient = UI.read();
            user = SI.find(user);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. User does not exist. Exiting.";
        }

    }


    if (found) {
        requestTemplate(user);
    }
    
    return found;
}

void DeleteUserController::requestTemplate(string user) {
    ServerInterface SI;
    UserInterface UI;
    int numLines;

    numLines = SI.readSize(user);
    string* files = SI.read(user);

    for (int i = 0; i < numLines; i++) {
        SI.deleteFile(files[i]);
    }

    SI.deleteFile(user);

}

/*========================================
    Request Prescription Controller
========================================*/


void RequestPrescriptionController::start() {
    bool found = false; 
    found = requestInfo();
}

bool RequestPrescriptionController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;

    string request = "Patient Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Patient not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    timer = 2;
    request = "Affiliate Name: ";
    UI.display(request);
    affiliate = UI.read();

    found = SI.find(affiliate);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Affiliate not found!\n";
            request += "Affiliate Name: ";
            UI.display(request);
            affiliate = UI.read();
            found = SI.find(affiliate);
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try different record type. Exiting.";
        }

    }

    recordType = "Prescription";
    if (found) {
        requestTemplate(recordType);
    }
    
    return found;
}

void RequestPrescriptionController::requestSave(string* record, int numLines) {
    ServerInterface SI;
    string recordName;

    recordName = SI.write(record, numLines, patient);

    sendRecord(recordName, affiliate);
}

/*========================================
    Request Specialist Controller
========================================*/


void RequestSpecialistController::start() {
    bool found = false; 
    found = requestInfo();
}

bool RequestSpecialistController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;

    string request = "Patient Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Patient not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    timer = 2;
    request = "Affiliate Name: ";
    UI.display(request);
    affiliate = UI.read();

    found = SI.find(affiliate);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Affiliate not found!\n";
            request += "Affiliate Name: ";
            UI.display(request);
            affiliate = UI.read();
            found = SI.find(affiliate);
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try different record type. Exiting.";
        }

    }

    recordType = "Specialist";
    if (found) {
        requestTemplate(recordType);
    }
    
    return found;
}

void RequestSpecialistController::requestSave(string* record, int numLines) {
    ServerInterface SI;
    string recordName;

    recordName = SI.write(record, numLines, patient);

    sendRecord(recordName, affiliate);
}

/*========================================
    Request Lab Work Controller
========================================*/


void RequestLabWorkController::start() {
    bool found = false; 
    found = requestInfo();
}

bool RequestLabWorkController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;

    string request = "Patient Name: ";
    UI.display(request);
    patient = UI.read();

    bool found = false;
    int timer = 2;
    found = SI.find(patient);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Patient not found!\n";
            request += "Patient Name: ";
            UI.display(request);
            patient = UI.read();
            found = SI.find(patient);
            
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
        }

    }

    timer = 2;
    request = "Affiliate Name: ";
    UI.display(request);
    affiliate = UI.read();

    found = SI.find(affiliate);

    if (!found) {
        while ((timer-- > 0) && !found) {
            request = "ERROR: Affiliate not found!\n";
            request += "Affiliate Name: ";
            UI.display(request);
            affiliate = UI.read();
            found = SI.find(affiliate);
        }

        if (!found) {
            request = "ERROR: Too many failed reqests. Try different record type. Exiting.";
        }

    }

    recordType = "LabWork";
    if (found) {
        requestTemplate(recordType);
    }
    
    return found;
}

void RequestLabWorkController::requestSave(string* record, int numLines) {
    ServerInterface SI;
    string recordName;

    recordName = SI.write(record, numLines, patient);

    sendRecord(recordName, affiliate);
}

/*========================================
        View Record Controller
========================================*/

void  ViewRecordController::start() {
}

void  ViewRecordController::start(int levelIn, string userIn) {
    bool found = false; 
    level = levelIn;
    patient = userIn;

    found = requestInfo();
}

bool  ViewRecordController::requestInfo() {
    ServerInterface SI;
    UserInterface UI;
    string recordType;
    bool found = false;


    if (level > 0 && level < 3) {
        string request = "Patient Name: ";
        UI.display(request);
        patient = UI.read();

        int timer = 2;
        found = SI.find(patient);

        if (!found) {
            while ((timer-- > 0) && !found) {
                request = "ERROR: Patient not found!\n";
                request += "Patient Name: ";
                UI.display(request);
                patient = UI.read();
                found = SI.find(patient);
                
            }

            if (!found) {
                request = "ERROR: Too many failed reqests. Try adding patient. Exiting.";
            }

        }
    }

    else {
        found = true;
    }


    if (found) {
        requestTemplate(patient);
    }

    return found;
}

void ViewRecordController::requestTemplate(string record) {
    ServerInterface SI;
    UserInterface UI;
    int numLines;

    numLines = SI.readSize(record);
    string* recordTemplate = SI.read(record);

    writeRecord(recordTemplate, numLines, record);

}

void ViewRecordController::writeRecord(string* record, int numLines, string date) {
    UserInterface UI;
    ServerInterface SI;
    string recordName;

    int slot = 0;
    for (int i = 0; i < numLines; i++) {

        UI.display("[" + to_string(++slot) + "]");
        UI.display(record[i]); 
    }


    UI.display("Please enter the desired file: ");
    recordName = UI.read();

    recordName = record[stoi(recordName) - 1];

    numLines = SI.readSize(recordName);
    record = SI.read(recordName);

    slot = 0;
    for (int i = 0; i < numLines; i++) {
        UI.display(record[i]); 

    }

    if (level > 0 && level < 3) {
        string input;

        UI.display("Would you like to edit the file? y/n");
        input = UI.read();

        char choice = 'z';
		string validResponse = "yYnN";
		
		if (input.size() == 1 && validResponse.find(input) != string::npos)
		{
			choice = input.at(0);
		}

		switch (choice)
		{		
			case 'y':
			case 'Y':
			{
                slot = 0;
                for (int i = 0; i < numLines - 1; i += 2) {
                    UI.display("[" + to_string(++slot) + "]");
                    UI.display(record[i]); 
                    UI.display(record[i+1]);
                }

                UI.display("Please enter the number for the line to change: ");
                string lineChange = UI.read();

                UI.display(record[stoi(lineChange)*2 - 2]);
                string change = UI.read();
                record[stoi(lineChange)*2 - 1] = change;

                SI.writeOver(record, numLines, recordName);

				break;
			}

            case 'n':
            case 'N':
            {
                break;
            }


			default:
			{
			cout << "\nPlease enter a valid response.\n\n";
			}
	    }

    }


    

}

/*========================================
        Complete Service Controller
========================================*/

void  CompleteServiceController::start() {

}

void  CompleteServiceController::start(string user) {
    bool found = false; 
    found = requestInfo(user);
}

bool  CompleteServiceController::requestInfo() {
   
    return true;
}

bool  CompleteServiceController::requestInfo(string user) {
    ServerInterface SI;
    UserInterface UI;

    requestTemplate(user);

    
    return true;
}

void CompleteServiceController::requestTemplate(string user) {
    ServerInterface SI;
    UserInterface UI;
    int numLines;


    numLines = SI.readSize(user);
    string* recordTemplate = SI.read(user);

    writeRecord(recordTemplate, numLines, user);

}

void CompleteServiceController::writeRecord(string* record, int numLines, string user) {
    UserInterface UI;
    ServerInterface SI;
    string service;

    int slot = 0;
    for (int i = 0; i < numLines; i++) {
        if (record[i] != ""){
            UI.display("[" + to_string(++slot) + "]");
            UI.display(record[i]); 
        }
    }


    UI.display("Please enter the completed service: ");
    service = UI.read();

    slot = 0;
    for (int i = 1; i < numLines; i++) {
        if (record[i] != ""){
            slot++;
            if (slot == stoi(service)) {
                record[i] = "";
            }
        }
    }
    

    SI.writeOver(record, numLines, user);
}




