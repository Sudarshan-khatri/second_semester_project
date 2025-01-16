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
			cout<<"\n\n1:Home_owner"<<endl;
			cout<<"2:Customer"<<endl;
	        cout<<"\nPlease select:";
	        cin>>earn;
	        if(earn==1)
	        {
		        fstream signup_file;
			 	signup_file.open("houseowner.txt",ios::out|ios::app);
			 	if(signup_file.is_open())
			 	   {
			 	   	signup_file<<"Information of Home_owner"<<endl;
			 	   	signup_file<<"House_owner_name:"<<full_name<<endl;
			 	   	signup_file<<"user_name:"<<user_name<<endl;
			 	   	signup_file<<"password:"<<password<<endl;
			 	   	signup_file<<"Date of brith:"<<date<<endl;
			 	   	signup_file<<"E_mail address:"<<email_address<<endl;
			 	   	signup_file<<"Security_key:"<<s_question<<endl<<endl;
			 	   	system("cls");
			 	   	cout<<"SIGNUP sucessflly!!!";
			 	   	Sleep(2000);
			 	   	system("cls");
					signup_file.close();
				    }
				else
				  {
				  	cout<<"file not created !!";
				  }	
			}
			else if(earn==2)
			{
			    fstream signup_file;
			 	signup_file.open("customer.txt",ios::out|ios::app);
			 	if(signup_file.is_open())
			   {
				 	signup_file<<"Information of Customer"<<endl;
				 	signup_file<<"Customer_name:"<<full_name<<endl;
				 	signup_file<<"user_name:"<<user_name<<endl;
				 	signup_file<<"password:"<<password<<endl;
				 	signup_file<<"Date of brith:"<<date<<endl;
				 	signup_file<<"E_mail address:"<<email_address<<endl;
				 	signup_file<<"Security key:"<<s_question<<endl<<endl;
				 	system("cls");
				 	cout<<"SIGNUP sucessflly!!!";
				 	Sleep(2000);
			 	   	system("cls");
					signup_file.close();
			    }
				else
				  {
				  	cout<<"file not created !!";
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
		void lg_in()
		{
		int opt;
		cout<<"\n\n1:Home_owner"<<endl;
		cout<<"2:Customer"<<endl;
	    cout<<"\nPlease select:";
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
			 	cout<<"Sorry, the file could not be opened!";
			 	return;
			 }
				if(flag==0)
				 {
				 	cout<<"\nInvalid user_name or password";
				 }
				else
				 {
				    cout<<"\nLogin sucessfully!!!!!!!!!!!";
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
			 	cout<<"Sorry, the file could not be opened!";
			 	return;
			 }
				if(flag==0)
				 {
				 	cout<<"\nInvalid user_name or password";
				 }
				else
				 {
				    cout<<"\nLogin sucessfully!!!!!!!!!!!";
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
			cout<<"\n\n1:Home_owner"<<endl;
			cout<<"2:Customer"<<endl;
		    cout<<"\nPlease select:";
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
					if(line.find("user_name:")!=string::npos)
  	 	             {
  	 	             	file_user=line.substr(line.find(":")+1);
  	 	             	file_user.erase(remove_if(file_user.begin(), file_user.end(), ::isspace), file_user.end()); 
  	 	             	cout<<endl<<file_user<<endl;
						}
					if(line.find("password:")!=string::npos)
  	 	             {
  	 	             	file_password=line.substr(line.find(":")+1);
  	 	             	file_password.erase(remove_if(file_password.begin(),file_password.end(), ::isspace), file_password.end()); 
  	 	             	cout<<file_password<<endl;
						}
					if(line.find("Security key:")!=string::npos)
  	 	             {
  	 	             	s_key=line.substr(line.find(":")+1);
  	 	             	s_key.erase(remove_if(s_key.begin(),s_key.end(), ::isspace),s_key.end()); 
  	 	             	cout<<s_key;
					
					 }
					if(s_key==sct_key && !file_user.empty())
					  {
		 	         	flag=1;
		 	         	break;
					  }
				  }
				s_file.close();
		     }
			else
			 {
			 	cout<<"Sorry, the file could not be opened!";
			 	return;
			 }
				if(flag==1)
				 {
				 	cout<<"User_name:"<<file_user<<endl;
				    cout<<"User_password:"<<file_password<<endl;
				 	
				 }
				else
				 {
				    cout<<"\nInvalid security key";
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
//				 cout<<"\n";
				 }
		 }
	}
};
int main()
{
	cout<<"==============WELCOME TO ==================="<<endl;
	cout<<"==========HOME RENTAL SERVICE============"<<endl;
	cout<<"1:SIGN_up"<<endl;
	cout<<"2:LOGIN"<<endl;
	cout<<"3:FORGET PASSWORD"<<endl;
	cout<<"4:EXIT";
	int opt;
	cout<<"\n Please choose option:";
	cin>>opt;
	if(opt==1)
	{
	 	string fl_name,db,eml_address,recover_qn; 
	 	char usr_name[100],pass_wrd[100];
		cout<<"\n\nFill_up the form"<<endl;
		cin.ignore();
		cout<<"Full name:";
		getline(cin,fl_name);
		cout<<"User name:";
		cin.getline(usr_name,100);
		while(true)
		 	{
		 		cout<<"Password:";
		 	    cin.getline(pass_wrd,100);
		 	    if(valid_password(pass_wrd))
		 	         {
		 	         	break;
					  }
					else
					 {
					 	cout<<"password format not match!!\n";
					 }		
			}
		while(true)
		    {
		        cout<<"Enter dob(dd/mm/yyyy):";
				getline(cin,db);
				if(valid_date(db))
				 {
				 	break;
				 }
			    else
				 {
				 	cout<<"Invalid dob format!!\n";
				 }	
		    }
		while(true)
			{
				cout<<"Email address:";
		 	    getline(cin,eml_address);
		 	    if(valid_email(eml_address))
		 	     {
		 	     	break;
				  }
				else
				 {
				 	cout<<"Invalid email address!!\n";
				 }	
		    }
		 cout<<"What is your pet's name?";
		 getline(cin,recover_qn);
		 sign_up obj_1(fl_name, usr_name, pass_wrd, db, eml_address,recover_qn);
		 obj_1.saveToFile();
		 main();
	}
	else if (opt==2)
	{
		system("cls");
	    cout<<"\n=======Login==============\n";
		char usr_name[100],pass_wrd[100];
		cin.ignore();
		cout<<"Enter the user name:";
		cin.getline(usr_name,100);
		cout<<"Enter the password:";
		cin.getline(pass_wrd,100);
		login obj_2(usr_name,pass_wrd);
		obj_2.lg_in();
		int hm_no,flr_no;
	string house_ow_nm,loc,toll,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size;
	setColor(5);
	cout<<"Enter home_no:";
	cin>>hm_no;
	cout<<"Enter floor no:";
	cin>>flr_no;
	cout<<"Enter house_owner_name:";
	cin>>house_ow_nm;
	cout<<"Enter location:";
	cin.ignore();
	getline(cin,loc);
	cout<<"Enter toll name:";
	getline(cin,toll);
	while(true)
	 {
	 	cout<<"Enter contact_number:";
	 	getline(cin,contact);
	 	if(isValidContactnumber(contact))
	 	 {
	 	 	break;
		  }
		else
		 {
		 	cout<<"Invalid number format\n";
		 }
	 }
	cout<<"Enter room type:";
	getline(cin,room_tp);
	while(true)
	 {
	 	cout<<"Enter ad post date(dd/mm/yyyy):";
	 	getline(cin,ad_pst);
	 	cout<<"Enter ex post date(dd/mm/yyyy):";
	 	getline(cin,ad_exp);
	 	if( valid_date(ad_pst,ad_exp))
	 	 {
	 	 	break;
		  }
		else
			{
			  cout<<"Invalid format\n";	
			}
	 }
	cout<<"Enter negotiable or not:";
	getline(cin,neg);
	cout<<"Enter status of furnishing:";
	getline(cin,furn);
	cout<<"Enter room size:";
	getline(cin,rm_size);
	house_owner obj1(hm_no,flr_no,house_ow_nm,loc,toll,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size);
	obj1.display();
	system("cls");
	obj1.show();
		Sleep(2000);
		system("cls");
		main();
	}
	else if(opt==3)
	{
		system("cls");
		cin.ignore();
	    string s_ans;
		cout<<"What is your pet's name?:";
		getline(cin,s_ans);
		forget_dat obj3(s_ans);
		obj3.recover();	
		main();
	}
 return 0;
 }






