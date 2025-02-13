#include<iostream>
#include<windows.h>
#include<fstream>
#include<regex> //for pattern matching
#include<string>
#include<sstream>
#include<algorithm>  //for transform
#include<cctype>    //for lowercase
#include<iomanip>
using namespace std;

// brief   Validates a password based on a specific pattern.
	bool valid_password(const string& pass_wrd)
	  {
	  	regex pass(R"(^[a-zA-Z0-9]{3}[^a-zA-Z0-9]{1}\d{2}$)");
	  	return regex_match(pass_wrd,pass);
	  }
	  
// brief   Validates a date of birth based on a specific pattern.
	bool valid_date(const string& dob_date)
	  {
	  	regex bd(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
	  	return regex_match(dob_date,bd);
	  }
	  
//brief   Validates an email based on a specific pattern.
	bool valid_email(const string& eml)
	  {
	  	regex email(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
	  	return regex_match(eml,email);
	  }
	  
// brief   Validates a contact based on a specific pattern.
	bool isValidContactnumber(const string& contact)
   {
 	regex pattern(R"(^(\+977-)?(\d{10}|\d{3}-\d{3}-\d{4})$)");
 	return regex_match(contact,pattern);
    }

// brief   Validates a post add date and expire  based on a specific pattern.
    bool valid_date(const string& ad_Posted,const string& ad_Expired)
	  {
	  	regex bd(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
	  	return regex_match(ad_Posted, bd) && regex_match(ad_Expired, bd);
	  }
	  
// brief   Validates a room type based on a specific pattern.
bool valid_room_type(const string& room_type) {
    regex room_regex(R"((single|[1-9]\BHK|[1-9]bhk))");
    return regex_match(room_type,room_regex);
}

// Sets the console text color based on the given color code 
void setColor(int color)
    {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    }
 

class sign_up{
	protected:
		string full_name; // full_name of sign_up person 
		char user_name[100]; //user_name of sign_up person
		char password[100]; //user password 
		string date; //date of birth of sign_up person 
		string email_address;//email address of sign_up person 
//		string rec_question; // Recovery question for password reset
//		string rec_answer;   // Recovery answer for password reset
		int earn; // Stores the role (1 for Home_owner, 2 for Customer)
	public:
		sign_up() // Default constructor initializing member variables
		 {
		 	full_name="";
			strcpy(user_name,"");
			strcpy(password,""); 
			date="";
			email_address="";
//			rec_question="";
//		    rec_answer="";
		 }
		// Parameterized constructor to initialize sign-up details.
		sign_up(string f_name, const char* u_name, const char* pass, string dob, string eml_add )
		 {
		    full_name=f_name;
			strcpy(user_name, u_name);
            strcpy(password, pass);
			date=dob;
			email_address=eml_add;
//			rec_question=ques;
//		    rec_answer=ans;
		 }
		// Saves user details to a file based on role (Home_owner or Customer)
		void saveToFile() 
		{
			cout<<"\n\n\t\t\t\t\t1:Home_owner"<<endl;
			cout<<"\t\t\t\t\t2:Customer"<<endl;
	        cout<<"\t\t\t\t\tPlease select:";
	        cin>>earn;
	        if(earn==1) // If user selects Home_owner, save to "houseowner.txt"
	        {
		        fstream signup_file;
			 	signup_file.open("houseowner.txt",ios::out|ios::app);
			 	if(signup_file.is_open())
			 	   {
			 	   	signup_file<<"\t\t\t\t\tInformation of Home_owner"<<endl;
			 	   	signup_file<<"\t\t\t\t\tHouse_owner_name:"<<full_name<<endl;
			 	   	signup_file<<"\t\t\t\t\tuser_name:"<<user_name<<endl;
			 	   	signup_file<<"\t\t\t\t\tpassword:"<<password<<endl;
			 	   	signup_file<<"\t\t\t\t\tDate of brith:"<<date<<endl;
			 	   	signup_file<<"\t\t\t\t\tE_mail address:"<<email_address<<endl;
//			 	   	signup_file<<"\t\t\t\t\tRecovery question:"<<rec_question<<endl;
//		            signup_file<<"\t\t\t\t\tRecovery answer:"<<rec_answer<<endl<<endl;
			 	   	system("cls");
			 	   	cout<<"\t\t\t\t\tSIGNUP sucessflly!!!";
			 	   	Sleep(2000);
			 	   	system("cls");
					signup_file.close();
				    }
				else
				  {
				  	cout<<"\t\t\t\t\tfile not created !!";
				  }	
			}
			else if(earn==2)  // If user selects Customer, save to "customer.txt"
			{
			    fstream signup_file;
			 	signup_file.open("customer.txt",ios::out|ios::app);
			 	if(signup_file.is_open())
			   {
				 	signup_file<<"\t\t\t\t\tInformation of Customer"<<endl;
				 	signup_file<<"\t\t\t\t\tCustomer_name:"<<full_name<<endl;
				 	signup_file<<"\t\t\t\t\tuser_name:"<<user_name<<endl;
				 	signup_file<<"\t\t\t\t\tpassword:"<<password<<endl;
				 	signup_file<<"\t\t\t\t\tDate of brith:"<<date<<endl;
				 	signup_file<<"\t\t\t\t\tE_mail address:"<<email_address<<endl;
//				    signup_file<<"\t\t\t\t\tRecovery question:"<<rec_question<<endl;
//		            signup_file<<"\t\t\t\t\tRecovery answer:"<<rec_answer<<endl<<endl;
				 	system("cls");
				 	cout<<"\t\t\t\t\tSIGNUP sucessflly!!!";
				 	Sleep(2000);
			 	   	system("cls");
					signup_file.close();
			    }
				else
				  {
				  	cout<<"\t\t\t\t\tfile not created !!";
				  }	
			}
			 
		}
};

// Handles user login by verifying credentials from stored files
class login:public sign_up{
	private:
		string m_user_name;
		string m_password;
	public:
		login(string u_name,string psd )
		 {
		 	m_user_name=u_name; 
		 	m_password=psd;
		 }
		string lg_in()
		{
		int flag = 0;
        string userRole = "";
        // Check in houseowner.txt
        ifstream house_file("houseowner.txt", ios::in);
        if (house_file.is_open()) {
            string file_user, file_password, line;
            while (getline(house_file, line)) {
                if (line.find("user_name:") != string::npos) {
                    file_user = line.substr(line.find(":") + 1);
                }
                if (line.find("password:") != string::npos) {
                    file_password = line.substr(line.find(":") + 1);
                }
                if (file_user == m_user_name && file_password == m_password) {
                    flag = 1;
                    userRole = "homeowner"; // Identify as homeowner
                    break;
                }
            }
            house_file.close();
        }
        // Check in customer.txt if not found in houseowner.txt
        if (flag == 0) {
            ifstream customer_file("customer.txt", ios::in);
            if (customer_file.is_open()) {
                string file_user, file_password, line;
                while (getline(customer_file, line)) {
                    if (line.find("user_name:") != string::npos) {
                        file_user = line.substr(line.find(":") + 1);
                    }
                    if (line.find("password:") != string::npos) {
                        file_password = line.substr(line.find(":") + 1);
                    }
                    if (file_user == m_user_name && file_password == m_password) {
                        flag = 1;
                        userRole = "customer"; // Identify as customer
                        break;
                    }
                }
                customer_file.close();
            }
        }

        if (flag == 0) {
            return "Invalid username or password!";
        } else {
            return userRole; // Return the role (homeowner or customer)
        }
    }
};



//class forget_dat:public sign_up{
//	private:
//		string sct_qn;
//		string sct_ans;
//	public:
//		forget_dat(string qn,string ans)
//		 {
//		 	sct_qn=qn;
//		 	sct_ans=ans;
//		 }
//		void recover()
//		{
//        cout << "\n\n\t\t\t\t\t1:Home_owner" << endl;
//        cout << "\t\t\t\t\t2:Customer" << endl;
//        cout << "\n\t\t\t\t\tPlease select: ";
//        cin >> earn;
//        cin.ignore(); // To handle the newline character from cin
//
//        string file_name = (earn == 1) ? "houseowner.txt" : "customer.txt";
//
//        ifstream s_file(file_name);
//        if (!s_file.is_open())
//		 {
//            cout << "\t\t\t\t\tError: Unable to open file!" << endl;
//            return;
//        }
//
//        string file_user, file_password, s_qn,s_ans;
//        bool question_matched=false;
//        bool answer_matched=false;
//
//        string line;
//        while (getline(s_file, line)) {
//            if (line.find("Recovery question:") != string::npos) 
//			{
//                s_qn= line.substr(line.find(":") + 1);
//                s_qn.erase(0, s_qn.find_first_not_of(" \t")); // Trim spaces
//
//                if (s_qn == sct_qn)
//				 {
//                    question_matched = true;
//                    continue; // Move forward to get username and password
//                }
//            }
//            if (question_matched && line.find("Recovery answer:") != string::npos) 
//			{
//                s_ans= line.substr(line.find(":") + 1);
//                s_ans.erase(0, s_ans.find_first_not_of(" \t")); // Trim spaces
//                
//                if (s_ans== sct_ans)
//				 {
//                    answer_matched= true;
//                    continue; // Move forward to get username and password
//                }
//                else
//                {
//                	question_matched=false;
//				}
//            }
//
//
//            if (answer_matched && line.find("user_name:") != string::npos) 
//			{
//                file_user = line.substr(line.find(":") + 1);
//                file_user.erase(0, file_user.find_first_not_of(" \t"));
//            }
//
//            if (answer_matched && line.find("password:") != string::npos) 
//			{
//                file_password = line.substr(line.find(":") + 1);
//                file_password.erase(0, file_password.find_first_not_of(" \t"));
//
//                // Print details and break once username and password are found
//                cout << "\n\t\t\t\t\tUsername: " << file_user << endl;
//                cout << "\t\t\t\t\tPassword: " << file_password << endl;
//                break;
//            }
//        }
//        if (!question_matched || answer_matched)
//		{
//            cout << "\t\t\t\t\tInvalid security question or answer!" << endl;
//        }
//	}
//};

// Manages house owner details, stores property listings, and displays rental information
class house_owner{
	protected:
		int home_no;
		int floor_no;
		string house_ow_name;
		string location;
		string tol_name;
		string m_rent; 
		string contact_no;
		string room_type;
		string negotiable;
		string ad_posted;  
		string ad_expired;
		string furnishing;
		string room_size;
		string booked;
	public:
		house_owner(int x,int y,string owner,string lct,string tl_name,string rent,string ct_no,string rm_typ,string nego,string pst,string exp,string furn,string rm_no)
		 	{
		 	 	home_no=x;
			    floor_no=y;
				house_ow_name=owner;
				location=lct;
				tol_name=tl_name;
				m_rent=rent; 
				contact_no=ct_no;
				room_type=rm_typ;
				negotiable=nego;
				ad_posted=pst;
				ad_expired=exp;
				furnishing=furn;
				room_size=rm_no;
				booked="no";
			}	
		void display()
		 {
		 	ofstream landlord;
		 	landlord.open("land.txt",ios::out | ios::app);
		 	if(!landlord.is_open())
		 	 {
		 	 	cout<<"file not opended sucessfully";
			  }
			else
		     {
//				landlord<<"\n\nInformtation of Room"<<endl;
				landlord<<home_no<<endl
			    <<floor_no<<endl
				<<house_ow_name<<endl
				<<location<<endl
				<<tol_name<<endl
				<<m_rent<<endl 
				<<contact_no<<endl
				<<room_type<<endl
				<<negotiable<<endl
				<<ad_posted<<endl
				<<ad_expired<<endl
				<<furnishing<<endl
				<<room_size<<endl
				<<booked<<endl
				<< "------------------------" << endl;
			 }
			landlord.close();
		 }
		void show()
		 {
		 	ifstream show_detail;
		 	show_detail.open("land.txt",ios::in);
		 	if(!show_detail.is_open())
		 	 {
		 	 	cout<<"sorry file not opended sucessfully";
			  }
			else
			{
			 	setColor(5);
			 	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------\n";
				cout <<"\n----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                string  houseNo, floorNo,houseOwner,location , tollName ,rnt, contactNo, roomType , negotiable , adPosted,adExpired,furnishing,roomSize;
                while (getline(show_detail, houseNo) && getline(show_detail, floorNo) &&
                getline(show_detail, houseOwner) && getline(show_detail, location) &&
                getline(show_detail, tollName) && getline(show_detail, rnt) &&
                getline(show_detail, contactNo) && getline(show_detail, roomType) &&
                getline(show_detail, negotiable) && getline(show_detail, adPosted) &&
                getline(show_detail, adExpired) && getline(show_detail, furnishing) &&
                getline(show_detail, roomSize)) 
			    // Print the parsed data
			    cout <<left<<setw(10)<<"House_No:    "<<houseNo<<"\n"
				 <<setw(15)<<"Floor_No:    "<<floorNo<<"\n"
				 <<setw(15)<<"House_ow_Name:    "<<houseOwner<<"\n"
				 <<setw(15)<<"Location:    "<<location<<"\n"
				 <<setw(15)<<"Toll_Name:   "<<tollName<<"\n"
				 <<setw(15)<<"Monthly_rent:    "<<rnt<<"\n"
				 <<setw(15)<<"Contact_No:    "<<contactNo<<"\n"
				 <<setw(15)<<"Room_Type:    "<<roomType<<"\n"
				 <<setw(15)<<"Negotiable:    "<<negotiable<<"\n"
				 <<setw(15)<<"Ad_Posted:    "<<adPosted<<"\n" 
				 <<setw(15)<<"Ad_Expired:    "<<adExpired<<"\n"
				 <<setw(15)<<"Furnishing:    "<<furnishing<<"\n"
				 <<setw(15)<<"Size_of_Room:    "<<roomSize<<"\n"<<"\n";
			     cout<<"\n";
				}
			show_detail.close();
		}
};


// Handles room booking by updating rental data and saving bookings
class book_room {
public:
    void book(const string& customer_name) {
        ifstream input("land.txt");  // Read data from land file
        if (!input.is_open()) {
            cout << "Error: Unable to open file!" << endl;
            return;
        }

        ofstream temp("temp.txt");  // Store updated data
        if (!temp.is_open()) {
            cout << "Error: Unable to create a temporary file!" << endl;
            input.close();
            return;
        }

        ofstream booking_file("bookings.txt", ios::app);  // Append to bookings file
        if (!booking_file.is_open()) {
            cout << "Error: Unable to create bookings file!" << endl;
            input.close();
            temp.close();
            return;
        }

        string house_no, house_loc, floor_no, rent;
        cout << "\nEnter House No: ";
        cin >> house_no;
        cout << "Enter Floor No: ";
        cin >> floor_no;
        cout << "Enter House location: ";
        cin.ignore();
        getline(cin, house_loc);
        cout << "Enter Price (Monthly Rent): ";
        cin >> rent;

        // Variables to store file data
        string file_house_no, file_floor_no, file_owner, file_location, file_toll, file_rent,
            file_contact, file_room_type, file_negotiable, file_posted, file_expired,
            file_furnishing, file_size, file_is_booked, separator;

        bool found = false, is_booked = false;
        string booked_details; // Stores booking details to print later

        while (getline(input, file_house_no) &&
               getline(input, file_floor_no) &&
               getline(input, file_owner) &&
               getline(input, file_location) &&
               getline(input, file_toll) &&
               getline(input, file_rent) &&
               getline(input, file_contact) &&
               getline(input, file_room_type) &&
               getline(input, file_negotiable) &&
               getline(input, file_posted) &&
               getline(input, file_expired) &&
               getline(input, file_furnishing) &&
               getline(input, file_size) &&
               getline(input, file_is_booked) &&
               getline(input, separator)) {

            if (file_house_no == house_no && file_floor_no == floor_no && file_location == house_loc && file_rent == rent) {
                found = true;

                if (file_is_booked == "Yes") {
                    is_booked = true;
                } else {
                    file_is_booked = "Yes"; // Mark room as booked
                    
                    // Store booking details for later printing
                    booked_details = "Customer: " + customer_name + "\n" +
                                     "House No: " + house_no + "\n" +
                                     "Floor No: " + floor_no + "\n" +
                                     "Location: " + house_loc + "\n" +
                                     "Rent: " + rent + "\n" +
                                     "------------------------\n";

                    // Write booking details to the bookings file
                    booking_file << booked_details;
                }
            }

            // Write data to temp file
            temp << file_house_no << endl;
            temp << file_floor_no << endl;
            temp << file_owner << endl;
            temp << file_location << endl;
            temp << file_toll << endl;
            temp << file_rent << endl;
            temp << file_contact << endl;
            temp << file_room_type << endl;
            temp << file_negotiable << endl;
            temp << file_posted << endl;
            temp << file_expired << endl;
            temp << file_furnishing << endl;
            temp << file_size << endl;
            temp << file_is_booked << endl;
            temp << "------------------------" << endl;
        }

        input.close();
        temp.close();
        booking_file.close();

        if (!found) {
            cout << "\nNo matching room found!\n";
            remove("temp.txt");
            return;
        }

        if (is_booked) {
            cout << "\nRoom is already booked!\n";
            remove("temp.txt");
            return;
        }

        remove("land.txt");
        rename("temp.txt", "land.txt");

        // Print booking details after successful booking
        cout << "\nBooking Successful!\n";
        cout << "Booking Details:\n";
        cout << "------------------------\n";
        cout << booked_details;
    }
};

int main()
{
	// Main menu for Home Rental Service, handling user sign-up, login, password recovery, and property management
	system("cls");
    setColor(7);
	cout<<"\n\n\t\t\t\t\t==============WELCOME TO ==================="<<endl;
	cout<<"\t\t\t\t\t==========HOME RENTAL SERVICE============"<<endl;
	cout<<"\t\t\t\t\t1:SIGN_up"<<endl;
	cout<<"\t\t\t\t\t2:LOGIN"<<endl;
	//cout<<"\t\t\t\t\t3:FORGET PASSWORD"<<endl;
	cout<<"\t\t\t\t\t3:EXIT";
	int opt;
	setColor(3);
	cout<<"\n\t\t\t\t\tPlease choose option:";
	cin>>opt;
	switch(opt)
	{
	 	case 1:
	 		{
	 			string fl_name,db,eml_address,recover_qn,recover_ans; 
			 	char usr_name[100],pass_wrd[100];
			 	system("cls");
				cout<<"\n\n\t\t\t\t\tFill_up the form"<<endl;
				cin.ignore();
				cout<<"\t\t\t\t\tFull name:";
				getline(cin,fl_name);
				cout<<"\t\t\t\t\tUser name:";
				cin.getline(usr_name,100);
				while(true)
				 	{
				 		cout<<"\t\t\t\t\tPassword:";
				 	    cin.getline(pass_wrd,100);
				 	    if(valid_password(pass_wrd))
				 	         {
				 	         	break;
							  }
							else
							 {
							 	cout<<"\t\t\t\t\tpassword format not match!!\n";
							 }		
					}
				while(true)
				    {
				        cout<<"\t\t\t\t\tEnter dob(dd/mm/yyyy):";
						getline(cin,db);
						if(valid_date(db))
						 {
						 	break;
						 }
					    else
						 {
						 	cout<<"\t\t\t\t\tInvalid dob format!!\n";
						 }	
				    }
				while(true)
					{
						cout<<"\t\t\t\t\tEmail address:";
				 	    getline(cin,eml_address);
				 	    if(valid_email(eml_address))
				 	     {
				 	     	break;
						  }
						else
						 {
						 	cout<<"\t\t\t\t\tInvalid email address!!\n";
						 }	
				    }
//				cout<<"\t\t\t\t\tRecovery Question?:";
//				getline(cin,recover_qn);
//				cout<<"\t\t\t\t\tRecovery Answer?:";
//				getline(cin,recover_ans);
				sign_up obj_1(fl_name, usr_name, pass_wrd, db, eml_address);
				obj_1.saveToFile();
				main();
			    break;
			 }
		case 2:
		   {
		    	system("cls");
				cout<<"\n\t\t\t\t\t=======Login==============\n";
				char usr_name[100],pass_wrd[100];
				string user_type;
				cin.ignore();
				cout<<"\t\t\t\t\tEnter the user name:";
				cin.getline(usr_name,100);
				cout<<"\t\t\t\t\tEnter the password:";
				cin.getline(pass_wrd,100);
				login obj_2(usr_name,pass_wrd);
			    string result=obj_2.lg_in();
			    cout<<result;
			    int hm_no,flr_no;
				string house_ow_nm,loc,toll,rent,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size;
			    if (result == "Invalid username or password!")
				 {
                    cout << "\n\t\t\t\t\t" <<result;
                    Sleep(2000);
                    system("cls");
                    main(); // Return to the main menu
                 }
			    else if(result=="homeowner")
			    {
				    setColor(5);
				    system("cls");
					cout << "\n\n\t\t\t\t\t======================================================================" << endl;
					cout << "\t\t\t\t\t                       PROPERTY DETAILS ENTRY FORM                   " << endl;
					cout << "\t\t\t\t\t======================================================================" << endl;
					cout << " \t\t\t\t\t Welcome, House Owner!                                              " << endl;
					cout << " \t\t\t\t\t Please provide accurate details about your property to ensure      " << endl;
					cout << " \t\t\t\t\t your listing attracts the right customers.                         " << endl;
					cout << "\t\t\t\t\t======================================================================" << endl;
					cout<<"\t\t\t\t\tEnter home_no:";
					cin>>hm_no;
					cout<<"\t\t\t\t\tEnter floor no:";
					cin>>flr_no;
					cin.ignore();
					cout<<"\t\t\t\t\tEnter house_owner_name:";
					getline(cin,house_ow_nm);
					cout<<"\t\t\t\t\tEnter location:";
					getline(cin,loc);
					cout<<"\t\t\t\t\tEnter toll name:";
					getline(cin,toll);
					cout<<"\t\t\t\t\tEnter monthly rent:";
					getline(cin,rent);
					while(true)
						{
							cout<<"\t\t\t\t\tEnter contact_number:";
							getline(cin,contact);
							if(isValidContactnumber(contact))
								{
								 	break;
								}
							else
								{
									cout<<"\t\t\t\t\tInvalid number format\n";
								}
						}
					while(true)
						{
							cout<<"\t\t\t\t\tEnter room type:";
							getline(cin,room_tp);
							if (valid_room_type(room_tp))
							    {
							     	break;
								}
							else
								{
								 	cout<<"\t\t\t\t\tInvalid format";
								}	
						}
					while(true)
						{
							cout<<"\t\t\t\t\tEnter ad post date(dd/mm/yyyy):";
							getline(cin,ad_pst);
							cout<<"\t\t\t\t\tEnter ex post date(dd/mm/yyyy):";
							getline(cin,ad_exp);
							if(valid_date(ad_pst,ad_exp))
							 	{
							 	 	break;
							    }
							else
								{
									cout<<"\t\t\t\t\tInvalid format\n";	
								}
						}
						cout<<"\t\t\t\t\tEnter negotiable or not:";
						getline(cin,neg);
						cout<<"\t\t\t\t\tEnter status of furnishing:";
						getline(cin,furn);
						cout<<"\t\t\t\t\tEnter room size:";
						getline(cin,rm_size);
						house_owner obj1(hm_no,flr_no,house_ow_nm,loc,toll,rent,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size);
						obj1.display();
						cout << "\n\t\t\t\t\t======================================================================" << endl;
					    cout << " \t\t\t\t\t Thank you! Your property details have been successfully recorded.  " << endl;
					    cout << "\t\t\t\t\t======================================================================" << endl;
					    Sleep(2000);
					    system("cls");
						main();
					}
					else if(result=="customer")
					{
						system("cls");
						cout << "\n\n\t\t\t\t\t======================================================================" << endl;
					    cout << "   \t\t\t\t\t                    WELCOME TO HOME RENTAL SERVICE                 " << endl;
					    cout << "\t\t\t\t\t======================================================================" << endl;
					    cout << " \t\t\t\t\t Your one-stop solution to finding the perfect rental property.      " << endl;
					    cout << " \t\t\t\t\t Browse through the latest listings and connect directly with         " << endl;
					    cout << "  \t\t\t\t\tproperty owners for hassle-free rentals.                            " << endl;
					    cout << "\t\t\t\t\t======================================================================" << endl;
						house_owner obj1(hm_no,flr_no,house_ow_nm,loc,toll,rent,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size);
						obj1.show();
				     	// Get the customer's name for booking
                        string customer_name = usr_name; // Assuming the username is the customer's name
                        book_room br;
                        br.book(customer_name);
                        Sleep(40000);
						main();	
						break;
					}
				}	
//	    case 3:
//	    	{
//	    		setColor(1);
//				system("cls");
//				cin.ignore();
//				string question,answer;
//			    cout<<"\t\t\t\t\tRecovery Question?:";
//				getline(cin,question);
//				cout<<"\t\t\t\t\tRecovery Answer?:";
//				getline(cin,answer);
//				forget_dat obj3(question,answer);
//				obj3.recover();
//				Sleep(3000);
//				main();
//			    break;
//			}
	    default:
	    	{
	    		exit(0);
	            break;
			}
    }
  return 0;
}
