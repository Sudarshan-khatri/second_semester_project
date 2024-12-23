/*################==HOUSE RENTAL SERVICE==####################

Part 1:
The first step of this system is to signup new account in system as the specific role as broker or as 
customer .In this system signup is main entrance point to use this software. */
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>  //for transform
#include<cctype>  //for lowercase
#include<iomanip>
using namespace std;
class sign_up{
	protected:
		string full_name; // full_name of sign_up person 
		string user_name; //user_name of sign_up person 
		int day,month,year; //date of birth of sign_up person 
		string email_address;//email address of sign_up person 
	public:
		sign_up(string f_name,string u_name,int x,int y,int z,string eml_add)
		 {
		 	full_name=f_name;
		 	user_name=u_name;
		 	day=x;
		 	month=y;
		 	year=z;
		 	email_address=eml_add;
		 }
		void sinup()
		 {
		 	fstream signup_file;
		 	signup_file.open("first.txt",ios::out|ios::app);
		 	if(signup_file.is_open())
		 	   {
		 	   	signup_file<<"Information of Broker:"<<endl;
		 	   	signup_file<<"Broker_name:"<<full_name<<endl;
		 	   	signup_file<<"Broker_user_name:"<<user_name<<endl;
		 	   	signup_file<<"Date of brith:"<<day<<"//"<<month<<"//"<<year<<endl;
		 	   	signup_file<<"E_mail address:"<<email_address<<endl;
				}
		 	
		 }
};
int main()
{
	string fl_name,usr_name,eml_address;
	int d,m,y;
	string earn;
	cout<<"Pick: Broker or Customer!:";
	getline(cin,earn);
	//convet the earn to lowercase
	transform(earn.begin(), earn.end(), earn.begin(), ::tolower);
	if(earn=="broker")
	 {  
	    cout<<"===DETAIL INFROMATION OF BROKER==="<<endl;
	 	cout<<"Full name:";
	 	getline(cin,fl_name);
	 	cout<<"User name:";
	 	getline(cin,usr_name);
	 	cout<<"Enter dob(dd/mm/yyyy):";
	 	cin>>d;
		cin>>m;
		cin>>y;
	 	cout<<"Email address:";
	 	getline(cin,eml_address);
	 	sign_up  sign_obj_1(fl_name,usr_name,d,m,y,eml_address);
	 	sign_obj_1.sinup();
	 }
	return 0;
}
