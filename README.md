# Medicode #
This is a project for Spring 2019 Software Process course.
The scope of the project is a small hospital management program with user defined roles.
The roles are as following: admin, healthcare affiliate, medical staff, and patients.

## Requirements ##
* g++
* bash

## Usage ##
```
make
./project 
```
When first used, the program needs to be populated with users by the admin.
Affiliates must exist as users before you can call them in the request functions. 

## New Users ##
The initial username and password is admin admin. From there, you can create users 
of different types with whatever names and passwords you desire. Note that each
type of user can execute different functions. No user type can execute all functions.

## Appointments ##
When creating an appointment it will ask for a date. Enter "4_22_2019".
The system was designed to allow any date to be entered, but there must be a 
template file for the day with the times listed. Each time is on a line, and 
the next line is OPEN if the time is avaiable. A patient name will appear on
the next line if the time is already taken.

## Records ##
When creating a generic record, enter TestRecord as the record type. Any
template can be created and called. The format is to simply have each line
be a new question for the record. 
