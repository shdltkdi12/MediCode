MediCode Medical Information Management System

By: The C Team
Team Leader - Tyler Robins (tjr0023)
Analyst - Nikolai Klotchkov (nzk0016)
Architect - Isaiah Roh (izr0007)
Designer - Zack Smith (zts0011)
Quality Assurance Engineer - Yifu Hu (yzh0062)
Prototype Designer - Jm McGuire (jmm0122)

To run this program, type 

make

./project 

in the linux command line.

The initial username and password is admin admin. From there, you can create users 
of different types with whatever names and passwords you desire. Note that each
type of user can execute different functions. No user type can execute all functions.

When creating an appointment it will ask for a date. Enter "4_22_2019".
The system was designed to allow any date to be entered, but there must be a 
template file for the day with the times listed. Each time is on a line, and 
the next line is OPEN if the time is avaiable. A patient name will appear on
the next line if the time is already taken.

When creating a generic record, enter TestRecord as the record type. Any
template can be created and called. The format is to simply have each line
be a new question for the record. 

Affiliates must exist as users before you can call them in the request functions. 




