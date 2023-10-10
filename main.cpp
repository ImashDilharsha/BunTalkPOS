#include<iostream>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<windows.h>
#include <string>
#include <limits>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

void buy_breakfast_id();
//Intro
void intro_id()
{
system("color E1");
	cout << "\n\n\n\n" <<endl;


	cout << "           G@@@&&@@&G. Y@@@P   #@@@ B@@@@Y Y@@@7              G&&@@@@@@@^  Y@@@@@7   .&@@#.    7@@@^.Y@@@B!  " <<endl;
	cout << "           B@@&   &@@5 Y@@@5   G@@@ B@@@@@^7@@@?              ^^!G@@@!^^  J@@#Y@@&^  .&@@#     J@@@Y#@@#?    " <<endl;
	cout << "           B@@&Y5G@@B~ J@@@5   5@@& #@@&B@P~@@@J                 G@@@^   ?@@@7 #@@B. .&@@B     Y@@@@@@Y.     " <<endl;
	cout << "           #@@@?  J@@#J?@@@5   B@@B #@@&!&@Y&@@Y                 B@@@~  7@@@@GG&@@@5 :&@@P     P@@@&@@G!     " <<endl;
	cout << "           &@@@7  J&@@57@@@&P5P@@@P &@@@^?@&@@@P                 #@@@! !@@@@?7?J&@@@?:@@@BJ5GB^G@@@77&@@B7.  " <<endl;
	cout << "           B#&&&&@@#BG! !JP#@@@#P7. &@&&~ P@&&#5                 #@&&7 JPB&5    ?BGG5^B###&&&@7G#BB! ^B&#G?  " <<endl;


	cout << ""<<endl;


    //Display time for the intro
	int a;
	for(a=0; a<1000000; a++)
	{
		cout << "";
	}


	//Loading screen
    int b;
    for(b=0; b<10; b++){

        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
        Sleep(20);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        Sleep(20);
    }


}

//Login for the system
void login_id()
{
    string username = "";
    string password = "";
    char ch;
    int loginAttempts = 3; // Number of login attempts allowed

    while (loginAttempts > 0)
    {
        cout << "\nPlease Wait\n\n";
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << "\n                                                        LOGIN \n";
        cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
        cout << "                                                 Enter Username: ";
        cin >> username;
        cout << "                                                 Enter Password: ";
        ch = _getch();
        while (ch != 13)
        {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if (username == "admin" && password == "admin")
        {
            cout << "  "<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "\n\n                                              Access Granted as an Admin!\n";
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("PAUSE");
            system("CLS");
            break; // Successful login, exit the loop
        }
        else if (username == "staffid" && password == "staffid")
        {
            cout << "  "<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "\n\n                                             Access Granted as a Staff Member!\n";
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("PAUSE");
            system("CLS");
            break; // Successful login, exit the loop
        }
        else
        {
            cout << "\n\nAccess Aborted...\nPlease Try Again\n\n";
            loginAttempts--;

            if (loginAttempts > 0)
            {
                cout << "Remaining login attempts: " << loginAttempts << endl;
            }
            else
            {
                cout << "You have exceeded the maximum number of login attempts. Access blocked.\n";
                break; // Block access after all login attempts are used
            }

            system("PAUSE");
            system("CLS");
        }
    }
}

//Table reservation function - validated
bool isValidContact(const string& contact) {
    // Check if contact contains exactly 10 digits
    return (contact.size() == 10 && contact.find_first_not_of("0123456789") == string::npos);
}

bool isValidDate(const string& date) {
    // Check if the date has the format MM/DD/YYYY
    if (date.length() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;

    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    return (month >= 1 && month <= 12 && day >= 1 && day <= 31 && year >= 1900);
}

bool isValidTime(const string& time) {
    // Check if the time has the format HH:MM
    if (time.length() != 5) return false;
    if (time[2] != ':') return false;

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59);
}

void makeReservationID() {
    system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(70) << "Table Reservation" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;

    string name, contact, date, time;

    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, name);

    do {
        cout << "Enter Contact Number (10 digits): ";
        getline(cin, contact);
    } while (!isValidContact(contact));

    do {
        cout << "Enter Reservation Date (MM/DD/YYYY): ";
        getline(cin, date);
    } while (!isValidDate(date));

    do {
        cout << "Enter Reservation Time (HH:MM): ";
        getline(cin, time);
    } while (!isValidTime(time));

    // Store reservation details
    ofstream reservationFile("reservations.txt", ios::app);

    if (!reservationFile) {
        cerr << "Error opening the reservation file." << endl;
        return;
    }

    reservationFile << "Name: " << name << endl;
    reservationFile << "Contact Number: " << contact << endl;
    reservationFile << "Date: " << date << endl;
    reservationFile << "Time: " << time << endl << endl;

    reservationFile.close();

    cout << "\nReservation Successful! Your table has been reserved.\n" << endl;
    system("PAUSE");
}

// Collecting customer feedback
bool isNotBlank(const string& text) {
    // Check if the text contains blank
    for (char c : text) {
        if (!isspace(c)) {
            return true;
        }
    }
    return false;
}

void collectFeedbackID() {
    system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(70) << "Customer Feedback" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;

    string name, contact, feedback;

    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, name);

    do {
        cout << "Enter Contact Number (10 digits): ";
        getline(cin, contact);
    } while (!isValidContact(contact));

    do {
        cout << "Enter Your Feedback:\n";
        getline(cin, feedback);
    } while (!isNotBlank(feedback));

    // Store feedback details in a text file
    ofstream feedbackFile("feedback.txt", ios::app);

    if (!feedbackFile) {
        cerr << "Error opening the feedback file." << endl;
        return;
    }

    feedbackFile << "Name: " << name << endl;
    feedbackFile << "Contact Number: " << contact << endl;
    feedbackFile << "Feedback:\n" << feedback << endl << endl;

    feedbackFile.close();

    cout << "\nThank you for your feedback!\n" << endl;
    system("PAUSE");
}

void displaySpecialsAndPromotionsID() {
    system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(70) << "Specials and Promotions" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;

    ifstream specialsFile("specials.txt");
    string line;

    if (specialsFile.is_open()) {
        while (getline(specialsFile, line)) {
            cout << "                                      - " << line << endl;
        }
        specialsFile.close();
    } else {
        cout << "Unable to open specials.txt." << endl;
    }

    cout << "\nPress any key to return to the main menu..." << endl;
    _getch(); // Wait for a key press
}

//Main menu controllings
void mainmenu()
{
main_menu:
	system("cls");

		cout << "\n\n"<<endl;
		cout << "       ____________________           ____________________           ____________________   "<<endl;
		cout << "      |                    |         |                    |         |                    |  "<<endl;
		cout << "      |  Cashier Services  |         |   Manager- Log in  |         |   Compay Details   |  "<<endl;
		cout << "      |____________________|         |____________________|         |____________________|  "<<endl;
		cout << "             Press 1                        Press 2                        Press 3 \n\n"     <<endl;



		cout << "                                      ____________________    "      <<endl;
		cout << "                                     |                    |   "      <<endl;
		cout << "                                     |        Exit        |   "      <<endl;
		cout << "                                     |____________________|   "      <<endl;
		cout << "                                            Press 4  \n\n"           <<endl;
		char button1;
		cout << "Press Your Choice : ";
		cin >> button1;

		switch(button1)
		{
			//breakfast-menu-----------------------------------------------------------------------------------------------------------------------------------
			case'1':

				customer_service:
				system("cls");
					cout<<"\n------------------------------------------------------------------------------------------------------------------------"<< endl;
			   	 	cout <<setw(70)<< "Breakfast - Menu"<< endl;
			 		cout<<"------------------------------------------------------------------------------------------------------------------------\n"<< endl;
					cout << "                                                     1 .Price List "<<endl;
					cout << "                                                     2 .Buy Breakfast Items "<<endl;
					cout << "                                                     3 .Help  "<<endl;
					cout << "                                                     4 .Goto back  "<<endl;
					cout << "                                                     5 .Exit  "<<endl;
                    cout << "                                                     6 .Register Customer  "<<endl;
                    cout << "                                                     7 .Table Reservation  "<<endl;
                    cout << "                                                     8 .Customer Feedback  "<<endl;
                    cout << "                                                     9 .Specials & Promotions  \n\n"<<endl;

					char button2;
					cout << "                                                      ~~Select Option~~  ";
					cin>> button2;
					system("cls");

				switch(button2)//customer service
				{
					case'1': //prices
					 goto price_list;
						break;

					case'2'://buy breakfast
						cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  						cout <<setw(70)<< "Buy Breakfast"<<endl;
 						cout<<"------------------------------------------------------------------------------------------------------------------------\n\n"<< endl;
						cout<<"####  QUICK  HELPER ####\n"<<endl;
						cout<<" * Fist Enter Customer Name"<<endl;
						cout<<" * Secondly, Enter The Number of Item You Want\n "<<endl;
						cout<<" * thirdly, Enter The Amount you want\n "<<endl;
						cout<<" * IF You Stop The Ur Transact, Press 0\n"<<endl;

						system("pause");
						system("cls");
						buy_breakfast_id();
						break;

					case'3':// customer help

						system("cls");
						cout<<"\n\n#### HELP Customer ####\n"<<endl;
						cout<<"  1 How to get the price list\n "<<endl;
						cout<<"\t* select price list and you can see price list\n\n"<<endl;
						cout<<"  2 How to buy Breakfast item  \n "<<endl;
						cout<<"\t*Fist Enter Your Name"<<endl;
						cout<<"\t* Secondly, Enter The Number of Food item You Want\n "<<endl;
						cout<<"\t* thirdly, Enter The Amount you want\n "<<endl;
						cout<<"\t*Enter 0 after the end of the purchase\n"<<endl;
						system("pause");
						system("cls");
						goto customer_service;

						break;

					case'4'://goto back
						goto main_menu;

					case'5'://exit
						exit (0);

                    case'6'://registration
                        {    string name, birthday, regMonth;

                        // Get customer details
                        cout << "Enter customer name: ";
                        cin.ignore(); // Clear the input buffer
                        getline(cin, name);
                        cout << "Enter customer birthday (MM/DD/YYYY): ";
                        getline(cin, birthday);
                        cout << "Enter registration month (e.g., January): ";
                        getline(cin, regMonth);

                        // Open the text file in append mode
                        ofstream file("customer_details.txt", ios::app);

                        // Check if the file is open
                        if (!file.is_open()) {
                        cout << "Error opening file." << endl;
                        return;
                        }

                        // Write customer details to the file
                        file << "Name: " << name << endl;
                        file << "Birthday: " << birthday << endl;
                        file << "Registration Month: " << regMonth << endl;
                        file << "------------------------" << endl;

                        // Close the file
                        file.close();

                        cout << "Customer details saved to customer_details.txt" << endl;
                            }

                    case'7':
                        {
                        // Handle Table Reservation
                        makeReservationID();
                        break;
                        }

                    case'8':
                        {
                        // Collect Customer Feedback
                        collectFeedbackID();
                        break;
                        }

                    case'9':
                        {
                        // today offers
                        displaySpecialsAndPromotionsID();
                        break;
                        }

					default :
						system("cls");
						goto customer_service;
				}
				break;


            //manager login-------------------------------------------------------------------------------------------------------------------------------------
			case'2':
				system("cls");
			login:{


				//user name and password
				cout<<"  "<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"  "<<endl;
				cout<<"                                         Please  enter your user name And Password to continue..."<<"\n"<<"\n";
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"  "<<endl;
				cout<<setw(25)<<"                                                    Username :";
				string user;
				cin>>user;

						cout<<"\n";
						string pass ="";
						char ch;
						cout<<setw(26)<< "                                                    Password : ";
						ch = _getch();
						while(ch !=13)
						{
							pass.push_back(ch);
							cout << '*';
							ch = _getch();
						}

							if (pass=="admin"&&user=="admin")
							{
							goto manager_service;

							}else{
								cout<< "                                        invalid User Name or Password";
								system("cls");
								cout<< "\n "<<"                                                 **invalid User Name or Password**"<<endl;
								goto login;
							}



		   			}
		   			break;

			   //company details
			case'3':
				system("cls");
				cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  						cout <<setw(70)<< "Company Details"<<endl;
 						cout<<"------------------------------------------------------------------------------------------------------------------------\n\n"<< endl;
						cout<<"\tCompany name    : Bun Talk\n"<<endl;
						cout<<"\tOwner           : Mr.Imash Dilharsha\n"<<endl;
						cout<<"\tEmail           : info@buntalk.com\n"<<endl;
						cout<<"\tContact Number  : 037-8964523\n"<<endl;
						cout<<"\tFax Number      : 037-8564278\n"<<endl;
						cout<<"\tAdress          : BunTalk, \n\t\t\t  1st floor - Shopping Complex, \n\t\t\t  Kurunegala.\n\n"<<endl;



				system("pause");
				system("cls");
				goto main_menu;
				break;



			case'4':
				system("cls");
					exit(0);
			default :
				system("cls");
				goto main_menu;
				break;
		}

manager_service:
system("cls");
								//manager services
								cout<<"\n------------------------------------------------------------------------------------------------------------------------"<< endl;
						   	 	cout <<setw(70)<< "Manager Service"<< endl;
						 		cout<<"------------------------------------------------------------------------------------------------------------------------\n"<< endl;
								cout << "                                                       1 .Update Items "<<endl;
								cout << "                                                       2 .Sales Details "<<endl;
								cout << "                                                       3 .Help  "<<endl;
								cout << "                                                       4 .Goto back  "<<endl;
                                cout << "                                                       5 .Review Customer Feedback  "<<endl;
                                cout << "                                                       6 .Manage Suppliers  "<<endl;
								cout << "                                                       7 .Exit  \n\n"<<endl;

								char button3;
								cout << "                                                       ~~Select Option~~  ";
								cin>> button3;

								switch(button3)
								{
								case'1': //update item
								system("cls");
								goto update_item;
								break;

								case'2'://sales details
								goto sales_details;
								break;

								case'3'://help

														system("cls");
														cout<<"\n\n#### HELP Manager ####\n"<<endl;
														cout<<"  1 How to Update Item List\n "<<endl;
														cout<<"\t* Goto Update Item"<<endl;
														cout<<"\t* Fist Enter Amount of Item Update"<<endl;
														cout<<"\t* Enter New Item "<<endl;
														cout<<"\t* Enter Item Price\n\n"<<endl;

														cout<<"  2 How Check Employee Salary \n "<<endl;
														cout<<"\t*Goto Employee Salary\n\n"<<endl;


														cout<<"  1 How to Update Item List\n "<<endl;
														cout<<"\t* Goto Update Item"<<endl;
														cout<<"\t* Fist Enter Amount of Employee"<<endl;
														cout<<"\t* Secondly, Enter Your Name "<<endl;
														cout<<"\t* Thirdly, Other Details\n\n"<<endl;


														system("pause");
														system("cls");
														goto manager_service;

														break;

								case'4'://goto back
								goto main_menu;
								break;

								case'5'://See customer feedback
								{
                                    ifstream feedbackFile("feedback.txt"); // Open the feedback file for reading

                                    if (!feedbackFile.is_open()) {
                                    cout << "Error: Unable to open feedback file." << endl;
                                    return;
                                }

                                    string line;
                                    while (getline(feedbackFile, line)) {
                                    if (line.find("Name:") != string::npos) {
                                    cout << "Name: " << line.substr(line.find(":") + 2) << endl;
                                    } else if (line.find("Contact Number:") != string::npos) {
                                        cout << "Contact Number: " << line.substr(line.find(":") + 2) << endl;
                                    } else if (line.find("Feedback:") != string::npos) {
                                    cout << "Feedback: " << endl;
                                    // Continue reading lines until an empty line is encountered
                                    while (getline(feedbackFile, line) && !line.empty()) {
                                    cout << line << endl;
                                    }
                                    cout << endl;
                                }
                            }

                            feedbackFile.close(); // Close the feedback file
                            }
								exit(0);


								case'6'://Managing suppliers
                                int supplierChoice;
                                cout << "\n                                                   Supplier Management Menu:" << endl;
                                cout << "                                                        1. View Suppliers" << endl;
                                cout << "                                                        2. Add Supplier" << endl;
                                cout << "                                                        3. Go back" << endl;
                                cout << "" << endl;
                                cout << "                                                       Enter your choice: ";
                                cin >> supplierChoice;

                                switch (supplierChoice) {
                                    case 1:
                                        // View Suppliers
                                        {
                                        ifstream supplierFile("suppliers.txt"); // Open the supplier file for reading

                                        if (!supplierFile.is_open()) {
                                            cout << "Error: Unable to open suppliers file." << endl;
                                            return;
                                        }

                                        string line;
                                        while (getline(supplierFile, line)) {
                                            cout << line << endl;
                                        }

                                        supplierFile.close(); // Close the supplier file
                                        }
                                        break;


                                    case 2:
                                        // Add Supplier
                                        {
                                        ofstream supplierFile("suppliers.txt", ios::app); // Open the supplier file for appending

                                        if (!supplierFile.is_open()) {
                                            cout << "Error: Unable to open suppliers file for writing." << endl;
                                            return;
                                        }

                                        string supplierName, contactPerson, contactNumber, email, address;

                                        cout << "Enter Supplier Name: ";
                                        cin.ignore();
                                        getline(cin, supplierName);

                                        cout << "Enter Contact Person: ";
                                        getline(cin, contactPerson);

                                        cout << "Enter Contact Number: ";
                                        getline(cin, contactNumber);

                                        cout << "Enter Email: ";
                                        getline(cin, email);

                                        cout << "Enter Address: ";
                                        getline(cin, address);

                                        supplierFile << "Supplier Name: " << supplierName << endl;
                                        supplierFile << "Contact Person: " << contactPerson << endl;
                                        supplierFile << "Contact Number: " << contactNumber << endl;
                                        supplierFile << "Email: " << email << endl;
                                        supplierFile << "Address: " << address << endl << endl;

                                        cout << "Supplier information added successfully!" << endl;

                                        supplierFile.close(); // Close the supplier file
                                    }
                                        break;

                                    case 3:
                                        // Go back
                                        break;
                                    default:
                                        cout << "Invalid choice. Please enter a valid option." << endl;
                                        break;
                                }
                                break;
								exit(0);

								case'7'://exit
								system("cls");
								exit(0);

								default:
									goto manager_service;

								}



//update item
    update_item:
	{
						struct food_i
									{
										string food_item;
										double food_price;

										};

					cout<<"\n------------------------------------------------------------------------------------------------------------------------"<< endl;
			   	 	cout <<setw(70)<< "Add Details of Item"<< endl;
			 		cout<<"------------------------------------------------------------------------------------------------------------------------"<< endl;

				int j, m;

				cout <<setw(40)<< "First Enter The Number OF Item Needed   : ";
				cin >> m ;


				food_i food[m];

				for  (j=0; j<m ;j++){

				cout << "\n   ~~~ Enter details of " << j+1 << " Item ~~~"<<endl;


				cout <<setw(30)<< "Enter Item    : ";
				cin >> food[j].food_item ;

				cout <<setw(30) << "Input Price  : Rs";
				cin >> food[j].food_price;


				ifstream file("pricelist.txt");
				string content;
				string line;

				while(getline(file,line)){
					content+=line +"\n";

				}
				file.close();


					ofstream mf;
					mf.open("pricelist.txt");
					mf << content;



					mf<<setw(15)<< food[j].food_item <<setw(13)<<"Rs"<<food[j].food_price <<".00"<<endl;
					mf.close();
			}
					goto manager_service;

				//update Item End
	}

	//Price menu of the BunTalk
    price_list:
	{
		cout<<"\n\n"<<endl;
 		 cout<<"------------------------------------------------------------------------------------------------------------------------\n"<< endl;
  		  cout <<setw(70)<< "Price Menu"<<endl;
 		cout<<"\n------------------------------------------------------------------------------------------------------------------------\n\n"<< endl;

 		cout <<setw(8)<< "              Item" <<setw(25)<<"     Price (Rs)"  <<"\n"<<endl;



			ifstream file("pricelist.txt");
			string content;
			string line;

			while(getline(file,line))


				 cout<<line<<"\n";
				file.close();
			 cout<<"\n------------------------------------------------------------------------------------------------------------------------\n\n";


     			system("pause");

				system("cls");
				goto customer_service;
	}

	sales_details: //Sales Details
{
	system("cls");
	cout<<"\n"<<endl;
  cout<<"------------------------------------------------------------------------------------------------------------------------"<< endl;
    cout <<setw(70)<< "Details of Sales"<<endl;
 cout<<"------------------------------------------------------------------------------------------------------------------------\n\n"<< endl;





 cout <<setw(13)<< "Name" <<setw(25)<<"Item"  <<setw(15)<<"Price"<<setw(12)<<"Amoun"<<setw(15)<<"Net Total"<<setw(10)<<"Total"<<"\n"<<endl;




	ifstream file("customerdata.txt");
	string content;
	string line;

	while(getline(file,line))


		 cout<<line<<"\n";
		file.close();
	 cout<<"\n------------------------------------------------------------------------------------------------------------------------\n\n";

	 system("pause");
	 system("cls");
	 goto manager_service;
}

	//see item list end
	exit(0);

}

void processCreditCardPayment() {
    string cardNumber;
    string cardHolderName;
    string expirationDate;
    string cvv;

    // Validate Credit Card Number (16 digits)
    do {
        cout << "                                               Enter Credit Card Number (16 digits): ";
        cin.ignore(); // Ignore any remaining newline characters
        getline(cin, cardNumber);

        if (cardNumber.length() != 16 || strtol(cardNumber.c_str(), nullptr, 10) == 0) {
            cout << "                                               Invalid card number. Please enter 16 digits." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (cardNumber.length() != 16);

    cout << "                                               Enter Cardholder Name: ";
    getline(cin, cardHolderName);

    // Validate Expiration Date (MM/YY format)
    do {
        cout << "                                               Enter Expiration Date (MM/YY): ";
        getline(cin, expirationDate);

        if (expirationDate.length() != 5 ||
            expirationDate[2] != '/' ||
            !isdigit(expirationDate[0]) || !isdigit(expirationDate[1]) ||
            !isdigit(expirationDate[3]) || !isdigit(expirationDate[4])) {
            cout << "                                               Invalid expiration date format. Please use MM/YY format (e.g., 12/23)." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (expirationDate.length() != 5 ||
             expirationDate[2] != '/' ||
             !isdigit(expirationDate[0]) || !isdigit(expirationDate[1]) ||
             !isdigit(expirationDate[3]) || !isdigit(expirationDate[4]));

    // Validate CVV (3 digits)
    do {
        cout << "                                               Enter CVV (3 digits): ";
        getline(cin, cvv);

        if (cvv.length() != 3 || !isdigit(cvv[0]) || !isdigit(cvv[1]) || !isdigit(cvv[2])) {
            cout << "                                               Invalid CVV. Please enter 3 digits." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (cvv.length() != 3 || !isdigit(cvv[0]) || !isdigit(cvv[1]) || !isdigit(cvv[2]));

    // Display the entered card details.
    cout << "\n                                                 Processing Credit Card Payment...\n";
    cout << "                                                   Card Number: " << cardNumber << endl;
    cout << "                                                   Cardholder Name: " << cardHolderName << endl;
    cout << "                                                   Expiration Date: " << expirationDate << endl;
    cout << "                                                   CVV: " << cvv << endl;
    cout << "                                                   Payment Successful !" << endl;
}

void processDebitCardPayment() {
    string cardNumber;
    string cardHolderName;
    string expirationDate;
    string cvv;

    // Validate Debit Card Number (16 digits)
    do {
        cout << "                                               Enter Debit Card Number (16 digits): ";
        cin.ignore(); // Ignore any remaining newline characters
        getline(cin, cardNumber);

        if (cardNumber.length() != 16 || strtol(cardNumber.c_str(), nullptr, 10) == 0) {
            cout << "                                               Invalid card number. Please enter 16 digits." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (cardNumber.length() != 16);

    cout << "                                               Enter Cardholder Name: ";
    getline(cin, cardHolderName);

    // Validate Expiration Date (MM/YY format)
    do {
        cout << "                                               Enter Expiration Date (MM/YY): ";
        getline(cin, expirationDate);

        if (expirationDate.length() != 5 ||
            expirationDate[2] != '/' ||
            !isdigit(expirationDate[0]) || !isdigit(expirationDate[1]) ||
            !isdigit(expirationDate[3]) || !isdigit(expirationDate[4])) {
            cout << "                                               Invalid expiration date format. Please use MM/YY format (e.g., 12/23)." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (expirationDate.length() != 5 ||
             expirationDate[2] != '/' ||
             !isdigit(expirationDate[0]) || !isdigit(expirationDate[1]) ||
             !isdigit(expirationDate[3]) || !isdigit(expirationDate[4]));

    // Validate CVV (3 digits)
    do {
        cout << "                                               Enter CVV (3 digits): ";
        getline(cin, cvv);

        if (cvv.length() != 3 || !isdigit(cvv[0]) || !isdigit(cvv[1]) || !isdigit(cvv[2])) {
            cout << "                                               Invalid CVV. Please enter 3 digits." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
    } while (cvv.length() != 3 || !isdigit(cvv[0]) || !isdigit(cvv[1]) || !isdigit(cvv[2]));

    // Display the entered card details.
    cout << "\n                                                 Processing Debit Card Payment...\n";
    cout << "                                                   Card Number: " << cardNumber << endl;
    cout << "                                                   Cardholder Name: " << cardHolderName << endl;
    cout << "                                                   Expiration Date: " << expirationDate << endl;
    cout << "                                                   CVV: " << cvv << endl;
    cout << "                                                   Payment Successful !" << endl;
}



void processCashPayment(float totalAmount) {
    float cashPaid;

    cout << "                                                   Enter Cash Amount Paid: Rs ";
    cin >> cashPaid;

    if (cashPaid < totalAmount) {
        cout << "                                                   Insufficient cash. Please provide the full amount." << endl;
    } else {
        float change = cashPaid - totalAmount;
        cout << "                                                   Payment successful!\n";
        cout << "                                                   Change: Rs " << fixed << setprecision(2) << change << endl;
    }
}

// Function to print text with an intro animation effect
void typewriterPrint(const string& text) {
    for (char c : text) {
        cout << c << flush;
        clock_t start_time = clock();
        while ((clock() - start_time) / CLOCKS_PER_SEC < 0.9); // Adjust the delay as needed
    }
    cout << endl;
}

void orderWithUberEatsID() {
    typewriterPrint("Ordering with UberEats...");
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    // Simulate redirection to UberEats for payment
    typewriterPrint("Redirecting to UberEats for payment...");
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    // confirmation message
    typewriterPrint("Order confirmed! Payment completed on UberEats.");
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
}

void paymentt_ID(){
    int paymentMethod;

    float total = 1200.0;

    // Display payment method options
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "                                                    Select Payment Method:\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"  "<<endl;
    cout<<"  "<<endl;
    cout << "                                                       1. Credit Card\n";
    cout << "                                                       2. Cash\n";
    cout << "                                                       3. Debit Card\n";
    cout << "                                                       4. UberEats\n";
    cout<<"  "<<endl;
    cout<<"  "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"  "<<endl;

    // Get user's payment method choice
    cout << "                                                 Enter your choice (1/2/3/4): ";
    cin >> paymentMethod;

    switch (paymentMethod) {
        case 1:
            // Credit Card Payment
            processCreditCardPayment();
            break;
        case 2:
            // Cash Payment
            processCashPayment(total);
            break;
        case 3:
            // Debit Card Payment
            processDebitCardPayment();
            break;
        case 4:
            // Order and pay with UberEats
            orderWithUberEatsID();
            break;
        default:
            cout << "Invalid choice. Please select a valid payment method.\n";
            break;
    }
}

void buy_breakfast_id() //buy breakfast
{


		cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
  		cout <<setw(70)<< "Buy Breakfast"<<endl;
 		cout<<"------------------------------------------------------------------------------------------------------------------------"<< endl;


  		cout <<setw(20)<< "Details of Item\n"<<endl;
  		cout <<"   NO:"<<setw(15)<<"Item"<<setw(14)<<"Price"<<endl;
 		cout <<setw(2)<<"   1   "<<setw(30)<<"Chicken Burger       Rs  400.00"<<endl;
 		cout <<setw(2)<<"   2   "<<setw(30)<<"Mutton Burger       Rs  450.00"<<endl;
 		cout <<setw(2)<<"   3   "<<setw(30)<<"Jumbo Hotdog       Rs  250.00"<<endl;
 		cout <<setw(2)<<"   4   "<<setw(30)<<"Chicken Samosa       Rs 150.00"<<endl;
 		cout <<setw(2)<<"   5   "<<setw(30)<<"Salmon Samosa       Rs  100.00"<<endl;
        cout <<setw(2)<<"   6   "<<setw(30)<<"Chicken Shavarma       Rs  650.00"<<endl;
 		cout <<setw(2)<<"   7   "<<setw(30)<<"Choco Brownie       Rs  300.00"<<endl;
 		cout <<setw(2)<<"   8   "<<setw(30)<<"Choco Lavacake       Rs  150.00"<<endl;
 		cout <<setw(2)<<"   9   "<<setw(30)<<"Chicken Sandwich       Rs 250.00"<<endl;
 		cout <<setw(2)<<"   10   "<<setw(30)<<"Cheese Sandwich       Rs  250.00"<<endl;
 		cout <<setw(2)<<"   11   "<<setw(30)<<"Parata       Rs  40.00"<<endl;
 		cout <<setw(2)<<"   12   "<<setw(30)<<"Egg Bun       Rs  100.00"<<endl;
 		cout <<setw(2)<<"   13   "<<setw(30)<<"Choco Donut       Rs  180.00"<<endl;
 		cout <<setw(2)<<"   14   "<<setw(30)<<"Choco Muffin       Rs 160.00"<<endl;
 		cout <<setw(2)<<"   15   "<<setw(30)<<"Chicken Pizza Slice       Rs  300.00"<<endl;
 		cout <<setw(2)<<"   16   "<<setw(30)<<"Saussage Pizza Slice       Rs  250.00"<<endl;
 		cout <<setw(2)<<"   17   "<<setw(30)<<"Seafood Pizza Slice       Rs  300.00"<<endl;
 		cout <<setw(2)<<"   18   "<<setw(30)<<"Iclair       Rs  180.00"<<endl;
 		cout <<setw(2)<<"   19   "<<setw(30)<<"Cupcake       Rs 150.00"<<endl;
 		cout <<setw(2)<<"   20   "<<setw(30)<<"Garlic Bread       Rs  250.00"<<endl;
 		cout <<setw(2)<<"   21   "<<setw(30)<<"Croissant       Rs  200.00"<<endl;


double total=0;

struct buy_breakfast
	{
		string name;
		string item;
		int amount;
		double price;
		double ntotal;
	};

int i,n=100;
buy_breakfast food[n];

string name1;
	cout <<"\n"<<setw(30)<< "Enter Your Name    : ";
	cin >> name1 ;
	cout<<"\t\t\t\t ~~~Enter 0 after the end of the purchase~~~~"<<endl;
for  (i=0; i<n ;i++){


	cout <<setw(30) << "Input Type of Item  : ";
	cin >> food[i].item;

	if(food[i].item=="0") {goto total_salary;	}



	cout <<setw(30) << "input Amount : ";
	cin >> food[i].amount ;
	cout<<"\n"<<endl;

	{
		if(food[i].item=="1"){
			food[i].price =400;
		}else if(food[i].item=="2"){
			food[i].price=450;
		}else if(food[i].item=="3"){
			food[i].price=250;
		}else if(food[i].item=="4"){
			food[i].price=150;
		}else if(food[i].item=="5"){
			food[i].price=100;
		}else if(food[i].item=="6"){
			food[i].price=650;
		}else if(food[i].item=="7"){
			food[i].price=300;
		}else if(food[i].item=="8"){
			food[i].price=150;
		}else if(food[i].item=="9"){
			food[i].price=250;
		}else if(food[i].item=="10"){
			food[i].price=250;
		}else if(food[i].item=="11"){
			food[i].price=40;
		}else if(food[i].item=="12"){
			food[i].price=100;
		}else if(food[i].item=="13"){
			food[i].price=180;
		}else if(food[i].item=="14"){
			food[i].price=160;
		}else if(food[i].item=="15"){
			food[i].price=300;
		}else if(food[i].item=="16"){
			food[i].price=250;
		}else if(food[i].item=="17"){
			food[i].price=300;
		}else if(food[i].item=="18"){
			food[i].price=180;
		}else if(food[i].item=="19"){
			food[i].price=150;
		}else if(food[i].item=="20"){
			food[i].price=250;
		}else if(food[i].item=="21"){
			food[i].price=200;
		}
	}
	{
		if(food[i].item=="1"){
			food[i].item="Chicken Burger";
		}else if(food[i].item=="2"){
			food[i].item="Mutton Burger";
		}else if(food[i].item=="3"){
			food[i].item="Jumbo Hotdog";
		}else if(food[i].item=="4"){
			food[i].item="Chicken Samosa";
		}else if(food[i].item=="5"){
			food[i].item="Salmon Samosa";
		}else if(food[i].item=="6"){
			food[i].item="Chicken Shavarma";
		}else if(food[i].item=="7"){
			food[i].item="Choco Brownie";
		}else if(food[i].item=="8"){
			food[i].item="Choco Lavacake";
		}else if(food[i].item=="9"){
			food[i].item="Chicken Sandwich";
		}else if(food[i].item=="10"){
			food[i].item="Cheese Sandwich";
		}else if(food[i].item=="11"){
			food[i].item="Parata";
		}else if(food[i].item=="12"){
			food[i].item="Egg Bun";
		}else if(food[i].item=="13"){
			food[i].item="Choco Donut";
		}else if(food[i].item=="14"){
			food[i].item="Choco Muffin";
		}else if(food[i].item=="15"){
			food[i].item="Chicken Pizza Slice";
		}else if(food[i].item=="16"){
			food[i].item="Saussage Pizza Slice";
		}else if(food[i].item=="17"){
			food[i].item="Seafood Pizza Slice";
		}else if(food[i].item=="18"){
			food[i].item="Iclair";
		}else if(food[i].item=="19"){
			food[i].item="Cupcake";
		}else if(food[i].item=="20"){
			food[i].item="Garlic Bread";
		}else if(food[i].item=="21"){
			food[i].item="Croissant";
		}

	}
	food[i].ntotal=food[i].price*food[i].amount;
	total=total+food[i].ntotal;




	//start file and save sale detailsa
	ifstream file("customerdata.txt");
	string content;
	string line;

	while(getline(file,line)){
		content+=line +"\n";

	}
	file.close();


		ofstream mf;
		mf.open("customerdata.txt");
		mf << content;


		mf<<setw(15)<<name1;

		mf<<setw(25)<<food[i].item<<setw(9)<<"Rs"<<setw(3)<<food[i].price<<".00"<<setw(8)<<"x"<<food[i].amount<<setw(10)<<"Rs"<<setw(4)<<food[i].ntotal<<".00"<<endl;
		mf.close();
		//end file and save sale detailsa

		//start create bill
		ifstream file2("bill.txt");
	string content2;
	string line2;

	while(getline(file2,line2)){
		content2+=line2 +"\n";

	}
	file.close();
		ofstream mf1;
		mf1.open("bill.txt");
		mf1 << content2;
		mf1<<setw(19)<<food[i].item<<setw(5)<<food[i].price<<".00"<<setw(5)<<"x"<<food[i].amount<<setw(10)<<"Rs"<<setw(4)<<food[i].ntotal<<".00"<<endl;
		mf1.close();




}

//total salary print text file
total_salary:
{
ifstream file("customerdata.txt");
	string content;
	string line;

	while(getline(file,line)){
		content+=line +"\n";
	}
	file.close();

		ofstream mf;
		mf.open("customerdata.txt");
		mf << content;

		mf<<setw(85)<<"___________Rs"<<setw(4)<<total<<".00\n"<<endl;
		mf.close();
		//end total salary print text file

}


//print bill
{
	system("cls");
cout<<"\n____________________________________________________________________________________________________________\n"<<endl;
cout<<"@@@@@@@@@    @@@@    @@@@  @@@@@@   @@@@               @@@@@@@@@@@   @@@@@    @@@      @@@@     @@@@@"<<endl;
cout<<"@@@@@@@@@@   @@@@    @@@@  @@@@@@   @@@@               @@@@@@@@@@@  @@@@@@@   @@@      @@@@   @@@@" <<endl;
cout<<"@@@    @@@@  @@@@    @@@@  @@@@@@   @@@@                  @@@@     @@@  @@@   @@@      @@@  @@@@"<<endl;
cout<<"@@@@@@@@@@@  @@@@    @@@@  @@@@ @@  @@@@                  @@@@    @@@   @@@   @@@      @@@@@@@@         "<<endl;
cout<<"@@@=   @@@@@ @@@@    @@@@  @@@@ @@@  @@@                  @@@@   @@@@@@@@@@   @@@      @@@@  @@@@"<<endl;
cout<<"@@@#    @@@@ @@@@    @@@@  @@@@   @@ @@@                  @@@@  #@@@@@@@@@@   @@@@@@@  @@@@@  @@@@@@"<<endl;
cout<<"@@@@@@@@@@@   @@@@@@@@@    @@@@    @@@@@                  @@@@ @@@@    @@@@@  @@@@@@@  @@@@@   @@@@@"<<endl;
cout<<"____________________________________________________________________________________________________________"<<endl;
cout<<" "<<endl;
cout<<"1st Floor - New Shopping Complex, Puttalam Road, Kurunegala\n"<<endl;
cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
cout<<" Customer Name: "<<name1<<"\n"<<endl;

	ifstream file3("bill.txt");
	string content3;
	string line3;

	while(getline(file3,line3))


		 cout<<line3<<"\n";
		file3.close();

cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"\t\t     Total "<<setw(17)<<"Rs "<<total<<".00"<< endl;
cout<<"------------------------------------------------------------------------------------------------------------"<<endl;

cout<<"_____________________________________________________________________________________________________________\n"<<endl;

		///open bill end

		//cout<<"\n\n\n\n\n\n\t\t\t\tThanks for getting our service"<<endl;

		//clear bill text file data
		std::ofstream ofs;
		ofs.open("bill.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		system("pause");
		system("cls");

	}


	cout<<"\n\n\n\n\n\n\t\t\t\tContinue to checkout"<<endl;


		int a;
	for(a=0; a<10000000; a++)
	{

		cout << "";

	}
	system("cls");
	paymentt_ID();
	exit(0);

}

int main(int argc, char** argv)
{
    intro_id();
    login_id();
    mainmenu();

    return 0;
}
