////////////////////////////////////////////////////////
//// Motorbike Management system - Serouj Djabraian ////
////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

class Customer
{
    friend class ListofCustomers;       //Linked list
private:
    string surname;
    string forname;
    string address;
    string birthday;
    string telephone;
    string bike;
    bool reservation;
    Customer *successor;
public:
    Customer (){};
    Customer (string s, string f, string a, string b, string t): surname(s),forname(f),address(a),birthday(b),telephone(t), reservation (false), successor (0) {};      //Constructor for case 1
    Customer (string s, string f, string a, string b, string t, string bi, bool reservation): surname(s),forname(f),address(a),birthday(b),telephone(t), bike (bi), reservation(true), successor (0) {};        //Constructor when reading from file
    Customer *get_next() {return successor;}
    string get_surname() {return surname;}
    string get_forname() {return forname;}
    string get_address() {return address;}
    string get_birthday() {return birthday;}
    string get_telephone() {return telephone;}
    string get_bike () {return bike;}
    void set_bike(string bb){bike=bb;}
    bool get_reservation () {return reservation;}
    bool set_reservation_true () {reservation=true;}
    bool set_reservation_false () {reservation=false;}

    friend ostream &operator<<(ostream &ostr, Customer &c);     //output data members of class Customer
    friend istream &operator>>(istream &istr, Customer &c);     //request data members for class Customer
};

ostream &operator<<(ostream &ostr, Customer &c)
{
    ostr << c.surname << "\t " << c.forname << "\t " << c.address << "\t " << c.birthday << "\t " << c.telephone << "\t " << c.bike;
    return ostr;
}

istream &operator>>(istream &istr, Customer &c)
{
    cout<< "First Name: ";
    cin>>c.surname;
    cout<< "Last Name: ";
    cin>>c.forname;
    cout<< "Address(Street/Postal Code/City): ";
    cin>>c.address;
    cout<< "Year of Birth: ";
    cin>>c.birthday;
    cout<< "Telephone Number: ";
    cin>>c.telephone;
    cout <<endl;

    return istr;
}

class Bike      //Class for the 4 available bikes where we can also determine their availability using bools
{
private:
    string bike1;
    string bike2;
    string bike3;
    string bike4;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
public:
    Bike(){};
    Bike (string bike1, string bike2, string bike3, string bike4): bike1(bike1), bike2(bike2), bike3(bike3), bike4(bike4), b1(true), b2(true), b3(true), b4(true){}
    void diplay_data() {cout<<bike1<< " " << bike2 << " " << bike3 << " "<< bike4;}
    string get_bike1() {return bike1;}
    string get_bike2() {return bike2;}
    string get_bike3() {return bike3;}
    string get_bike4() {return bike4;}
    bool get1() {return b1;}
    bool get2() {return b2;}
    bool get3() {return b3;}
    bool get4() {return b4;}
    bool reserve1() {b1=false;}
    bool reserve2() {b2=false;}
    bool reserve3() {b3=false;}
    bool reserve4() {b4=false;}
    bool return1() {b1=true;}
    bool return2() {b2=true;}
    bool return3() {b3=true;}
    bool return4() {b4=true;}
};

class ListofCustomers
{
private:
    Customer *head;
public:
    ListofCustomers() : head(0){}
    Customer *begin() {return head;}
    insert (Customer *n)
    {
        n->successor=head;
        head=n;
    }
    Customer *find (string text1, string text2)
    {
        Customer *np;
        for (np=begin();np!=0;np=np->get_next())
        {
            if (np->get_surname()==text1 && np->get_forname()==text2)
                return np;
        }
    }
};

ListofCustomers list;
void add();                         //Add a customer
void display();                     //Display all customers
void rent(string,string);           //Rent a bike for a customer
void handover(string, string);      //Return a rented bike from a customer
void initialize();                  //Initialize linked list objects from written file while reading

Bike b = Bike ("SuzukiBandit","HondaTransAlp","BMWF650GS","KawasakiZZR1400");

int main()
{
    ofstream filewriter;
    int selection;
    initialize();

    do
    {
        system("cls");

        cout << endl << "---- Motorbike Management System ----" << endl;
        cout << "1. Register a Customer" << endl;
        cout << "2. Display all Customer data" << endl;
        cout << "3. Rent a bike (By name)" << endl;
        cout << "4. Return a rented bike (By name)" << endl;
        cout << "0. Exit program" << endl;
        cout << endl << "> Make a selection [Return]: ";
        cin >> selection;
        cout << endl;

        switch (selection)
        {
            case 1:     //Create a customer
                {
                    add();
                    system("pause");
                    break;
                }

            case 2:     //Display all customer data
                {
                    display();
                    system("pause");
                    break;
                }

            case 3:     //Rent a bike by searching a customer's first and last name
                {
                    string surname, forname;
                    cout<< "First name: ";
                    cin>>surname;
                    cout<< "Last name: ";
                    cin>>forname;
                    rent(surname,forname);

                    system("pause");
                    break;
                }

            case 4:     //Return a bike by searching a customer's first and last name
                {
                    string surname, forname;
                    cout<< "First name: ";
                    cin>>surname;
                    cout<< "Last name: ";
                    cin>>forname;
                    handover(surname,forname);

                    system("pause");
                    break;
                }

            case 0:     //Write a file about currently reserved bikes and the customer's data and end the application
                {
                    filewriter.open("reservations.txt");
                    Customer *object;
                    if
                        (filewriter.good())
                    {
                        for (object=list.begin(); object != 0; object = object->get_next())
						{
						    if (object->get_bike()=="SuzukiBandit" || object->get_bike()=="HondaTransAlp" || object->get_bike()=="BMWF650GS" || object->get_bike()=="KawasakiZZR1400")
                            {
                                filewriter << object->get_surname() << " " << object->get_forname() << " " << object->get_address() << " " << object->get_birthday() << " " << object->get_telephone() << " " << object->get_bike() << endl;
                            }
						}
						if(list.begin()!=0)
                        {
                            cout << "List saved to file reservations.txt!" << endl;
                        }

					}
                    else
                    {
                        cout << "File reservations.txt cannot be opened. Old list remains." << endl;
                    }

                    cout << "Goodbye user!" << endl;
                    system("pause");
                    break;
                }

            default:
                {
                    cout << "Incorrect input!" << endl;
                    system("pause");
                    break;
                }
            }

        } while (selection != 0);
}

void add()
{
    Customer *object = new Customer ();
    cin >> *object;                         //Operator overloading
    list.insert(object);
    cout << "Customer registered!" << endl;
}

void display()
{
    Customer *object;
    cout<<"First name | Last name | Address | Year of Birth | Telephone Nb. | Bike Rented"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for (object=list.begin();object!=0;object=object->get_next())
    {
        cout<<*object<<endl;                //Operator overloading
    }
}

void rent(string text1, string text2)
{
    Customer *object;
    char inpt;
    int input;
    object=list.find(text1, text2);         //Search for the Customer by name
    if (object == 0)
    {
        cout<<"Person is not registered!"<<endl;
    }
    else
    {
        cout<<text1<<" "<<text2<<" is registered!"<<endl;
        cout<<"Do you have a class A license? [y] or [n]:";
        cin>>inpt;
        if (inpt =='y')                     //Accept only if the customer has a license
            {
                cout << "[1] "<<b.get_bike1() << endl;
                cout << "[2] "<<b.get_bike2() << endl;
                cout << "[3] "<<b.get_bike3() << endl;
                cout << "[4] "<<b.get_bike4() << endl;
                cout << "Which bike would you like to rent? ";
                cin >> input;
                if (input==1)
                    {
                        if (b.get1()==true && object->get_reservation()==false)
                        {
                            object->set_bike(b.get_bike1());                                //Set bike data of customer depending on the input
                            cout<<b.get_bike1()<<" has been successfully rented!"<<endl;
                            b.reserve1();                                                   //Update the availability of the bike with bool
                            object->set_reservation_true();                                 //Update the status of the customer if he has a reservation or not
                        }
                        else if (object->get_reservation()==true) { cout<<"You have already reserved a bike!"<<endl; }      //if the customer has already reserved a bike
                        else if (b.get1()==false) { cout<<"Bike is currently unavailable!"<<endl; }                         //if the bike is unavailable
                    }
                else if (input==2)
                    {
                        if (b.get2()==true && object->get_reservation()==false)
                        {
                            object->set_bike(b.get_bike2());
                            cout<<b.get_bike2()<<" has been successfully rented!"<<endl;
                            b.reserve2();
                            object->set_reservation_true();
                        }
                        else if (object->get_reservation()==true) { cout<<"You have already reserved a bike!"<<endl; }
                        else if (b.get2()==false) { cout<<"Bike is currently unavailable!"<<endl; }
                    }

                else if (input==3)
                    {
                        if (b.get3()==true && object->get_reservation()==false)
                        {
                            object->set_bike(b.get_bike3());
                            cout<<b.get_bike3()<<" has been successfully rented!"<<endl;
                            b.reserve3();
                            object->set_reservation_true();
                        }
                        else if (object->get_reservation()==true) { cout<<"You have already reserved a bike!"<<endl; }
                        else if (b.get3()==false) { cout<<"Bike is currently unavailable!"<<endl; }
                    }

                else if (input==4)
                    {
                        if (b.get4()==true && object->get_reservation()==false)
                        {
                            object->set_bike(b.get_bike4());
                            cout<<b.get_bike4()<<" has been successfully rented!"<<endl;
                            b.reserve4();
                            object->set_reservation_true();
                        }
                        else if (object->get_reservation()==true) { cout<<"You have already reserved a bike!"<<endl; }
                        else if (b.get4()==false) { cout<<"Bike is currently unavailable!"<<endl; }
                    }
            }
            else {cout<<"You need a class A license in order to rent a bike!"<<endl;}
    }
}

void handover (string text1, string text2)
{
    Customer *object;
    object=list.find(text1, text2);                 //Search for the Customer by name
    if (object == 0)
    {
        cout<<"Person is not registered!"<<endl;
    }
    else
    {
        if (object->get_bike()==b.get_bike1())      //Check for the bike that the customer has reserved
        {
            b.return1();                            //Update the status of the bike
            object->set_reservation_false();        //Update the status of the customer
            object->set_bike(" ");                  //Update the bike data member of the customer
            cout<< b.get_bike1() << " has been handed over successfully!"<<endl;
        }
        else if (object->get_bike()==b.get_bike2())
        {
            b.return2();
            object->set_reservation_false();
            object->set_bike(" ");
            cout<< b.get_bike2() << " has been handed over successfully!"<<endl;
        }
        else if (object->get_bike()==b.get_bike3())
        {
            b.return3();
            object->set_reservation_false();
            object->set_bike(" ");
            cout<< b.get_bike3() << " has been handed over successfully!"<<endl;
        }
        else if (object->get_bike()==b.get_bike4())
        {
            b.return4();
            object->set_reservation_false();
            object->set_bike(" ");
            cout<< b.get_bike4() << " has been handed over successfully!"<<endl;
        }
        else if (object->get_bike().empty()) { cout<<"A bike has not been rented yet!"<<endl; }
    }
}

void initialize()       //Read from the reservations.txt file and to get bike status and customer info
{
    string surname, forname, address;
    string birthday, telephone;
    string bike;
	Customer *object;
	ifstream filereader;
	filereader.open("reservations.txt");
	if(filereader.good())
    {
		while(filereader >> surname >> forname >> address >> birthday >> telephone >> bike)
    	{
    	    if (bike == b.get_bike1())
                {
                    b.reserve1();
                }
    	    else if (bike == b.get_bike2())
                {
                    b.reserve2();
                }
    	    else if (bike == b.get_bike3())
                {
                    b.reserve3();
                }
    	    else if (bike == b.get_bike4())
                {
                    b.reserve4();
                }

			object = new Customer(surname, forname, address, birthday, telephone, bike, true);
        	list.insert(object);
     	}
    }
    filereader.close();
}
