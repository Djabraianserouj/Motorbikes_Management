# Motorbikes_Management
Task

You are supposed to realize a program for the management of motorbikes in C++.

Initial Situation

You are responsible for the management of motorcycles. Since all procedures are currently recorded on paper, you are to create a motorcycle management program.

The employee shall be able to manage the customers and make reservations of the motorbikes. The customer can only reserve one motorcycle at a time. There are 4 motorbikes to choose from Suzuki Bandit, Honda TransAlp, BMW F 650 GS and Kawasaki ZZR1400. Make sure that a motorbike is not reserved twice. When making the reservation, the customer has to enter hisher name, first name, address (street, postal code, city), year of birth, telephone number and whether heshe has a Class A driving license. If heshe does not hold an A driving licence, no motorcycle can be reserved. Once the motorcycle has been handed over, the reservation for this customer will be cancelled. The data record is removed from the linked list.

Every time a motorcycle is booked or canceled, the file should be written.

The program must at least meet the following requirements

Customer management

Enter data. The data has to be collected via istream () operator overloading. Output all customer data. The output has to be done via ostream () operator overloading.

Management of the reservations

make a reservation hand over the motorbike (with the customer's first and last name)

File management

The data records should be saved in a linked list.

The current status of the reservations should be written to the reservations.txt file. If the file does not yet exist, it should be created. Otherwise the data should be overwritten.

When the program is started, the file has to be read and the linked list (if there are data records) has to be filled with the data.

The management of customers has to be dynamic. If necessary, respective (error) Messages are to be displayed.. Use comments in the source code to document your program.
