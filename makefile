project: MediCode.o UserInterface.o  Controller.o ServerInterface.o
	g++ -o project MediCode.o UserInterface.o  Controller.o ServerInterface.o

MediCode.o: MediCode.cpp UserInterface.h
	g++ -c MediCode.cpp

UserInterface.o: UserInterface.cpp UserInterface.h ServerInterface.h
	g++ -c UserInterface.cpp

 Controller.o:  Controller.cpp  Controller.h ServerInterface.h
	g++ -c  Controller.cpp

ServerInterface.o: ServerInterface.cpp ServerInterface.h
	g++ -c ServerInterface.cpp