#include<iostream>
#include<fstream>
#include<regex> //for pattern matching
#include<string>
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
class sign_up{
	protected:
		string full_name; // full_name of sign_up person 
		string user_name; //user_name of sign_up person
		string password; //user password 
		string date; //date of birth of sign_up person 
		string email_address;//email address of sign_up person 
	public:
		sign_up()
		 {
		 	full_name="";
			user_name="";
			password=""; 
			date="";
			email_address="";
		 }
		sign_up(string f_name, string u_name, string pass, string dob, string eml_add)
		 {
		    full_name=f_name;
			user_name=u_name;
			password=pass; 
			date=dob;
			email_address=eml_add;
		 }
		void saveToFile() 
		{ 
		    
};
int main()
{
	string fl_name,usr_name,pass_wrd,db,eml_address;
	cout<<"Full name:";
	getline(cin,fl_name);
	cout<<"User name:";
	getline(cin,usr_name);
	while(true)
	 	{
	 		cout<<"Password:";
	 	    getline(cin,pass_wrd);
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
	sign_up obj_1(fl_name, usr_name, pass_wrd, db, eml_address);
	obj_1.saveToFile();
    return 0;
}




