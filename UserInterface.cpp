#include "UserInterface.h"
#include "ServerInterface.h"
#include "Controller.h"

void UserInterface::displayMenu() {	
	string dummy;
	string names;
	string bannerMsg;
	string filename;
	bool done = false;
	bool taken = false;
	ifstream infile, readFile;
	ofstream outfile;
	string input;
	loggedIn = false;
	
	cout << "===========================================================" << endl;
	cout << "|                         MediCode                        |" << endl;
	cout << "===========================================================" << endl << endl;
	
	while (1){
		login();
		
		cout << "Welcome to MediCode, " + user << endl << endl;
		
		while (loggedIn)
		{
			if (level > 0 && level < 3) {
				cout << "Create Record (a) " << endl;
			}

			if (level < 3) {
				cout << "Create Appointment (b)" << endl;
			}

			if (level == 2) {
				cout << "Create Employee Schedule (c)" << endl;
			}

			if (level == 1) {
				cout << "Create Visit Form (d)" << endl;
			}

			if (level == 2) {
				cout << "Create New User (e)" << endl;
				cout << "Delete User (f)" << endl;
			}

			if (level == 1) {
				cout << "Request Prescription (g)" << endl;
				cout << "Request Specialist (h)" << endl;
				cout << "Request Lab Work (i)" << endl;
			}


			cout << "View Record (j)" << endl;

			if (level == 3) {
				cout << "Complete Service (k)" << endl;
			}
			cout << "Log Out (l)" << endl;
			cout << endl;
			cout << "Choose an option: ";
			cin >> input;
			getline(cin, dummy);
			selectOption(input, done);
		}
	}
}

//	The selectOption method takes the input from the user and executes the respective function.
void UserInterface::selectOption(string input, bool& done)
	{
		char choice = 'z';
		string validResponse = "aAbBcCDdeEfFgGhHiIjJkKlL";
		
		if (input.size() == 1 && validResponse.find(input) != string::npos)
		{
			choice = input.at(0);
		}

		switch (choice)
		{		
			case 'A':
			case 'a':
			{
                CreateRecordController crc = CreateRecordController();

                crc.start();
				break;
			}

			case 'B':
			case 'b':
			{
				CreateAppointmentController cac = CreateAppointmentController();

                cac.start();
				break;
			}

			case 'C':
			case 'c':
			{
				CreateScheduleController csc = CreateScheduleController();

                csc.start();
				break;
			}

			case 'D':
			case 'd':
			{
				CreateVisitController cvc = CreateVisitController();

                cvc.start();
				break;
			}

			case 'E':
			case 'e':
			{
				CreateUserController cuc = CreateUserController();

                cuc.start();
				break;
			}

			case 'F':
			case 'f':
			{
				DeleteUserController duc = DeleteUserController();

                duc.start();
				break;
			}

			case 'G':
			case 'g':
			{
				RequestPrescriptionController rpc = RequestPrescriptionController();

                rpc.start();
				break;
			}

			case 'H':
			case 'h':
			{
				RequestSpecialistController rsc = RequestSpecialistController();

                rsc.start();
				break;
			}

			case 'I':
			case 'i':
			{
				RequestLabWorkController rlc = RequestLabWorkController();

                rlc.start();
				break;
			}

			case 'J':
			case 'j':
			{
				ViewRecordController vrc = ViewRecordController();
                vrc.start(level, user);
				break;
			}

			case 'K':
			case 'k':
			{
				CompleteServiceController csc = CompleteServiceController();

                csc.start(user);
				break;
			}

			case 'L':
			case 'l':
			{
				loggedIn = false;
				level = 4;

				cout << "Goodbye, " + user + "!" << endl;
				break;
			}

			default:
			{
			cout << "\nPlease enter a valid response.\n\n";
			}
	     }
	}	

void UserInterface::login() {
	string dummy;
	string password;
	string filename;
	bool taken = false;
	ifstream infile, readFile;
	ofstream outfile;
	string input;
	level = 4;
	ServerInterface SI;

	while(!loggedIn) {

		cout << "Please enter name: ";
		getline(cin, user);

		cout << "Please enter password: ";
		cin >> password;
		getline(cin, dummy);
		
		level = SI.verifyUser(user, password);

		if (level < 4) {
			loggedIn = true;
		}
	}


}

void UserInterface::display(string msg) {
	cout << msg << endl;
}

string UserInterface::read() {
	string response;
	getline(cin, response);
	cout << endl;
	return response;
}
