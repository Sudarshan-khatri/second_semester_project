#include<iostream>
#include<windows.h>
#include<fstream>
#include<regex> //for pattern matching
#include<string>
#include <cstdlib> // For rand and srand
#include<sstream>
#include<algorithm>  //for transform
#include<cctype>    //for lowercase
#include<iomanip>
using namespace std;
    string generateUserID() 
	{
    srand(time(0)); 
    int randomID = 1000 + rand() % 9000; // Random 4-digit number (1000 to 9999)
    string userID = "USER" + to_string(randomID); // Prefix with "USER"
    return userID;
    }
	bool valid_password(const string& pass_wrd)
	  {
	  	regex pass(R"(^[a-zA-Z0-9]{3}[^a-zA-Z0-9]{1}\d{2}$)");
	  	return regex_match(pass_wrd,pass);
	  }
	bool valid_date(const string& dob_date)
	  {
	  	regex bd(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
	  	return regex_match(dob_date,bd);
	  }
	bool valid_email(const string& eml)
	  {
	  	regex email(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
	  	return regex_match(eml,email);
	  }
	bool isValidContactnumber(const string& contact)
   {
 	regex pattern(R"(^(\+977-)?(\d{10}|\d{3}-\d{3}-\d{4})$)");
 	return regex_match(contact,pattern);
    }
    bool valid_date(const string& ad_Posted,const string& ad_Expired)
	  {
	  	regex bd(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
	  	return regex_match(ad_Posted, bd) && regex_match(ad_Expired, bd);
	  }
bool valid_room_type(const string& room_type) {
    regex room_regex(R"((single|[1-9]\BHK|[1-9]bhk))");
    return regex_match(room_type,room_regex);
}

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
		string s_question;
		int earn;
	public:
		sign_up()
		 {
		 	full_name="";
			strcpy(user_name,"");
			strcpy(password,""); 
			date="";
			email_address="";
			s_question="";
		 }
		sign_up(string f_name, const char* u_name, const char* pass, string dob, string eml_add ,string s_quest)
		 {
		    full_name=f_name;
			strcpy(user_name, u_name);
            strcpy(password, pass);
			date=dob;
			email_address=eml_add;
			s_question=s_quest;
		 }
		void saveToFile() 
		{
			cout<<"\n\n\t\t\t\t\t1:Home_owner"<<endl;
			cout<<"\t\t\t\t\t2:Customer"<<endl;
	        cout<<"\t\t\t\t\t\nPlease select:";
	        cin>>earn;
	        if(earn==1)
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
			 	   	signup_file<<"\t\t\t\t\tSecurity_key:"<<s_question<<endl<<endl;
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
			else if(earn==2)
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
				 	signup_file<<"\t\t\t\t\tSecurity key:"<<s_question<<endl<<endl;
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
		int opt;
		cout<<"\n\n\t\t\t\t\t1:Home_owner"<<endl;
		cout<<"\t\t\t\t\t2:Customer"<<endl;
	    cout<<"\n\t\t\t\t\tPlease select:";
	    cin>>opt;
		if (opt==1)
		 {
		 	int flag=0;
		 	ifstream l_file;
		 	l_file.open("houseowner.txt",ios::in);
		 	if(l_file.is_open())
		 	 { 
		 	 	string file_user,file_password,Sct_key,line;
		 	    while(getline(l_file,line))
		 	     {
  	 	            if(line.find("user_name:")!=string::npos)
  	 	             {
  	 	             	file_user=line.substr(line.find(":")+1);
						}
					if(line.find("password:")!=string::npos)
  	 	             {
  	 	             	file_password=line.substr(line.find(":")+1);
						}
					if(line.find("Security key:")!=string::npos)
  	 	             {
  	 	             	Sct_key=line.substr(line.find(":")+1);
					 }
					
					if(file_user==m_user_name && file_password==m_password)
					  {
		 	         	flag=1;
		 	         	break;
					  }
				  }
				l_file.close();
		     }
			else
			 {
			 	return "\t\t\t\t\tSorry, the file could not be opened!";
			 }
				if(flag==0)
				 {
				 	return "Invalid user_name or password";
				 }
				else
				 {
				    return "Login sucessfully !!!!";
				 }
			  }	
		else if(opt==2)
		{
		 int flag=0;
		 	ifstream l_file;
		 	l_file.open("customer.txt",ios::in);
		 	if(l_file.is_open())
		 	 { 
		 	 	string file_user,file_password,line;
		 	    while(getline(l_file,line))
		 	     {
  	 	            if(line.find("user_name:")!=string::npos)
  	 	             {
  	 	             	file_user=line.substr(line.find(":")+1);
						}
					if(line.find("password:")!=string::npos)
  	 	             {
  	 	             	file_password=line.substr(line.find(":")+1);
						}
					if(file_user==m_user_name && file_password==m_password)
					  {
		 	         	flag=1;
		 	         	break;
					  }
				  }
				l_file.close();
		     }
			else
			 {
			 	return "\t\t\t\t\tSorry, the file could not be opened!";
			 }
				if(flag==0)
				 {
				    return "\t\t\t\t\tInvlaid user_name or password";
				 }
				else
				 {
				    return "Login sucessfully !!!!";
				 }
			}
	}		  
};
class forget_dat:public sign_up{
	private:
		string sct_key;
	public:
		forget_dat(string fgt)
		 {
		 	sct_key=fgt;
		 }
		void recover()
		{
				cout<<"\n\n\t\t\t\t\t1:Home_owner"<<endl;
				cout<<"\t\t\t\t\t2:Customer"<<endl;
			    cout<<"\n\t\t\t\t\tPlease select:";
			    cin>>earn;
				if (earn==1)
				{
				int flag=0;
				ifstream s_file;
				string file_user,file_password,s_key,line;
			 	s_file.open("houseowner.txt",ios::in);
			 	if(s_file.is_open())
			 	 { 
			 	    while(getline(s_file,line))
			 	     {
			 	     	if(line.find("Security key:")!=string::npos)
	  	 	             {
	  	 	             	s_key=line.substr(line.find(":")+1);
	  	 	             	if(line.find("user_name:")!=string::npos)
			  	 	            {
			  	 	             	file_user=line.substr(line.find(":")+1);
			  	 	             	cout<<endl<<file_user<<endl;
								}
							if(line.find("password:")!=string::npos)
			  	 	            {
			  	 	             	file_password=line.substr(line.find(":")+1);
			  	 	             	cout<<file_password<<endl;
								}
	  	 	             	if(s_key==sct_key)
						    {
						    	cout <<"\nUsername: " << file_user << endl;
                                cout <<"Password: " << file_password << endl;
                                flag = 1; 
                                break;
						    }
						}
					  }
			     s_file.close();
			    if (flag == 0)
			    {
                 cout <<"\t\t\t\t\tNo matching record found for the provided security key!" << endl;
                }
            }
	         else 
			{
                cout <<"\t\t\t\t\tInvalid selection!" << endl;
            }
			}
		}
};
class house_owner{
	protected:
		int home_no;
		int floor_no;
		string house_ow_name;
		string location;
		string tol_name; 
		string contact_no;
		string room_type;
		string negotiable;
		string ad_posted;  
		string ad_expired;
		string furnishing;
		string room_size;
	public:
		house_owner(int x,int y,string owner,string lct,string tl_name,string ct_no,string rm_typ,string nego,string pst,string exp,string furn,string rm_no)
		 	{
		 	 	home_no=x;
			    floor_no=y;
				house_ow_name=owner;
				location=lct;
				tol_name=tl_name; 
				contact_no=ct_no;
				room_type=rm_typ;
				negotiable=nego;
				ad_posted=pst;
				ad_expired=exp;
				furnishing=furn;
				room_size=rm_no;
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
				landlord<<home_no<<endl;
			    landlord<<floor_no<<endl;
				landlord<<house_ow_name<<endl;
				landlord<<location<<endl;
				landlord<<tol_name<<endl; 
				landlord<<contact_no<<endl;
				landlord<<room_type<<endl;
				landlord<<negotiable<<endl;
				landlord<<ad_posted<<endl;
				landlord<<ad_expired<<endl;
				landlord<<furnishing<<endl;
				landlord<<room_size<<endl<<endl;
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
			 	setColor(4);
			 	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------\n";
			 	cout<<left<<setw(10)<<"House_No"
				 <<setw(10)<<"Floor_No"
				 <<setw(15)<<"House_ow_Name"
				 <<setw(12)<<"Location"
				 <<setw(10)<<"Toll_Name"
				 <<setw(14)<<"Contact_No"
				 <<setw(13)<<"Room_Type"
				 <<setw(12)<<"Negotiable"
				 <<setw(11)<<"Ad_Posted"
				 <<setw(12)<<"Ad_Expired"
				 <<setw(15)<<"Furnishing"
				 <<setw(12)<<"Size_of_Room";
				cout <<"\n----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			    string line;
			    while (getline(show_detail, line))
				 { // Read file line by line
			        stringstream ss(line); // Use a stringstream to parse the line
			        string houseNo, floorNo, houseOwner, location, tollName, contactNo, roomType, negotiable, adPosted, adExpired, furnishing, roomSize;
			
			        // Assuming data is separated by tabs or spaces
			        ss >> houseNo >> floorNo >> houseOwner >> location >> tollName >> contactNo
			           >> roomType >> negotiable >> adPosted >> adExpired >> furnishing >> roomSize;
			
			        // Print the parsed data
			    cout <<left<<setw(10)<< houseNo
				 <<setw(10)<<floorNo
				 <<setw(15)<< houseOwner
				 <<setw(12)<<location
				 <<setw(10)<<tollName
				 <<setw(14)<< contactNo
				 <<setw(13)<< roomType 
				 <<setw(12)<< negotiable
				 <<setw(11)<< adPosted 
				 <<setw(12)<<adExpired
				 <<setw(15)<<furnishing
				 <<setw(12)<< roomSize;
			     cout<<"\n";
				 }
		 }
	}
};
class book_room:public house_owner{
	private:
		string room_type;
		string r_location;
		int r_floor;	
	public:
//		book_room(string r_tp,string r_l,int r_f)
//		 {
//		 	room_type=r_tp;
//		 	r_location=r_l;
//		 	r_floor=r_f;
//		 }
//		void book()
//		{
//		 	fstream s_detail;
//		 	s_detail.open("land.txt",ios::in ||ios::on);
//		 	if(!show_detail.is_open())
//		 	 {
//		 	 	cout<<"sorry file not opended sucessfully";
//			  }
//			else
//			{
//			 string detais; 
//	         while(getline(s_detail,details))
//	          
//		    }
//		}	
};
int main()
{
    setColor(7);
	cout<<"\n\n\t\t\t\t\t==============WELCOME TO ==================="<<endl;
	cout<<"\t\t\t\t\t==========HOME RENTAL SERVICE============"<<endl;
	cout<<"\t\t\t\t\t1:SIGN_up"<<endl;
	cout<<"\t\t\t\t\t2:LOGIN"<<endl;
	cout<<"\t\t\t\t\t3:FORGET PASSWORD"<<endl;
	cout<<"\t\t\t\t\t4:EXIT";
	int opt;
	setColor(3);
	cout<<"\n\t\t\t\t\tPlease choose option:";
	cin>>opt;
	if(opt==1)
	{
	 	string fl_name,db,eml_address,recover_qn; 
	 	char usr_name[100],pass_wrd[100];
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
		 cout<<"\t\t\t\t\tWhat is your pet's name?";
		 getline(cin,recover_qn);
		 sign_up obj_1(fl_name, usr_name, pass_wrd, db, eml_address,recover_qn);
		 obj_1.saveToFile();
		 main();
	}
	else if (opt==2)
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
    if(result=="Login sucessfully !!!!")
    {
	    int hm_no,flr_no;
		string house_ow_nm,loc,toll,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size;
		setColor(5);
		cout<<"\t\t\t\t\tEnter user type (customer/homeowner):";
		cin.ignore();
		getline(cin, user_type);
		transform(user_type.begin(), user_type.end(), user_type.begin(), ::tolower);
		if(user_type=="homeowner")
		{
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
			cout<<"\t\t\t\t\tEnter house_owner_name:";
			cin>>house_ow_nm;
			cout<<"\t\t\t\t\tEnter location:";
			cin.ignore();
			getline(cin,loc);
			cout<<"\t\t\t\t\tEnter toll name:";
			getline(cin,toll);
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
				 	if( valid_date(ad_pst,ad_exp))
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
			house_owner obj1(hm_no,flr_no,house_ow_nm,loc,toll,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size);
			obj1.display();
			cout << "\n\t\t\t\t\t======================================================================" << endl;
		    cout << " \t\t\t\t\t Thank you! Your property details have been successfully recorded.  " << endl;
		    cout << "\t\t\t\t\t======================================================================" << endl;
			main();
		}
		else if(user_type=="customer")
		{
			system("cls");
			cout << "\n\n\t\t\t\t\t======================================================================" << endl;
		    cout << "   \t\t\t\t\t                    WELCOME TO HOME RENTAL SERVICE                 " << endl;
		    cout << "\t\t\t\t\t======================================================================" << endl;
		    cout << " \t\t\t\t\t Your one-stop solution to finding the perfect rental property.      " << endl;
		    cout << " \t\t\t\t\t Browse through the latest listings and connect directly with         " << endl;
		    cout << "  \t\t\t\t\tproperty owners for hassle-free rentals.                            " << endl;
		    cout << "\t\t\t\t\t======================================================================" << endl;
			house_owner obj1(hm_no,flr_no,house_ow_nm,loc,toll,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size);
			obj1.show();
			main();	
		}
	}
}
	else if(opt==3)
	{
		setColor(1);
		system("cls");
		cin.ignore();
	    string s_ans;
		cout<<"\t\t\t\t\tWhat is your pet's name?:";
		getline(cin,s_ans);
		forget_dat obj3(s_ans);
		obj3.recover();	
		main();
	}
  return 0;
}
