//Controller Parent Class

#include <string>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Controller {
    public:
        virtual void start() = 0;
    protected:
        //string recordType;
        string patient;
        string affiliate;
        bool request = false;
        //int numLines;
        //string* record;
        virtual bool requestInfo() = 0;
        void requestTemplate(string);
        void sendRecord(string, string);
        virtual void requestSave(string*, int);
        void readRecord(string);
        void writeRecord(string*, int);
};

class CreateRecordController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();

};

class CreateAppointmentController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();
        void requestTemplate(string);
        void writeRecord(string*, int, string);

};

class CreateScheduleController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();

};

class CreateVisitController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();

};

class CreateUserController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();

};

class DeleteUserController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();
        void requestTemplate(string);
        void writeRecord(string*, int, string);

};

class RequestPrescriptionController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();
        void requestSave(string*, int);

};

class RequestLabWorkController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();
        void requestSave(string*, int);

};

class RequestSpecialistController : public Controller {
    public:
        void start();
    protected:
        bool requestInfo();
        void requestSave(string*, int);

};

class ViewRecordController : public Controller {
    public:
        void start();
        void start(int, string);
    protected:
        int level;
        bool requestInfo();
        void requestTemplate(string);
        void writeRecord(string*, int, string);

};

class CompleteServiceController : public Controller {
    public:
        void start();
        void start(string);
    protected:
        bool requestInfo();
        bool requestInfo(string);
        void requestTemplate(string);
        void writeRecord(string*, int, string);

};