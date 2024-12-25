/*################==HOUSE RENTAL SERVICE==####################

Part 1:
The first step of this system is to signup new account in system as the specific role as broker or as 
customer .In this system signup is main entrance point to use this software. */
#include<iostream>
#include<fstream>
#include<regex> //for pattern matching
#include<string>
#include<algorithm>  //for transform
#include<cctype>  //for lowercase
#include<iomanip>
using namespace std;
class sign_up{
	protected:
		string full_name; // full_name of sign_up person 
		string user_name; //user_name of sign_up person
		string password; //user password 
		int date; //date of birth of sign_up person 
		string email_address;//email address of sign_up person 
	public:
		sign_up()
		 {
		 	full_name="";
			user_name="";
			password=""; 
			date=0;
			email_address="";
		 }
		sign_up(string f_name, string u_name, string pass, int dob, string eml_add)
		 {
		    full_name=f_name;
			user_name=u_name;
			password=pass; 
			date=dob;
			email_address=eml_add;
		 }
		void saveToFile() 
		{
		 	fstream signup_file;
		 	signup_file.open("first.txt",ios::out|ios::app);
		 	if(signup_file.is_open())
		 	   {
		 	   	signup_file<<"Information of Broker:"<<endl;
		 	   	signup_file<<"Broker_name:"<<full_name<<endl;
		 	   	signup_file<<"user_name:"<<user_name<<endl;
		 	   	signup_file<<"password:"<<password<<endl;
		 	   	signup_file<<"Date of brith:"<<date<<endl;
		 	   	signup_file<<"E_mail address:"<<email_address<<endl;
				signup_file.close();
			    }
			else
			  {
			  	cout<<"file not created !!";
			  }
	    }
		public:
		    bool valid_password(const string& pass)
		     {
		     	regex p(R"(^[a-zA-Z0-9]{3}[^a-zA-Z0-9]{1}\d{2}$));
		    	return regex_match(pass,p);
			 }
//		 	bool valid_dob(const string& db_pattern)
//			{
//			 	regex dp(R"(\b(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}\b)");
//			 	return regex_match(db_pattern,dp);
//			}
		    bool valid_eml(const string& eml)
		    {
			  	regex email_pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
			  	return regex_match(eml,email_pattern);
		    }
};
int main()
{
	string fl_name,usr_name,pass_wrd,eml_address;
	string db;
	string earn;
	cout<<"Pick: home_owner or Customer!:";
	getline(cin,earn);
	//convet the earn to lowercase
	transform(earn.begin(), earn.end(), earn.begin(), ::tolower);
	//create a object for class signup
	sign_up obj1;
	if(earn=="home_owner")
	{  
	    cout << "===DETAIL INFORMATION OF " << earn << "===" << endl;
	 	cout<<"Full name:";
	 	getline(cin,fl_name);
	 	cout<<"User name:";
	 	getline(cin,usr_name);
	 	while(true)
	 		{
	 			cout<<"Password:";
	 	        getline(cin,pass_wrd);
	 	        if(obj1.valid_password(pass_wrd))
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
			if(obj1.valid_dob(db))
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
	 	    if(obj1.valid_eml(eml_address))
	 	     {
	 	     	break;
			  }
			else
			 {
			 	cout<<"Invalid email address!!\n";
			 }	
		}
    }
return 0;
}




