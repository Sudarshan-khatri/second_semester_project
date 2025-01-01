#include<iostream>
#include<windows.h>
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
			string value;
			cout<<"\n\n1:Home_owner"<<endl;
			cout<<"2:Customer"<<endl;
		    cout<<"\nPlease select:";
		    cin>>earn;
			if (earn==1)
			   {
				 	int flag=0;
				 	ifstream s_file;
				 	s_file.open("houseowner.txt",ios::in);
				 	if(s_file.is_open())
				 	{ 
				 	 	string s_user,line;
				 	    while(getline(s_file,line))
				 	     {
		  	 	            if(line.find("Security_key:")!=string::npos)
		  	 	             {
		  	 	             	s_user=line.substr(line.find(":")+1);
							 } 
							if(s_user==sct_key)
							{	
							   flag=1;
							   value+=line+"/n";
							}
							else if(flag==0)
							 {
							 	value+=line+"/n";
							 }
			         	}
			    	}
			    	else
					{
			    		cout<<"file not opended ,sorry!!";
					}
			    if(flag==1)
			     {
			     	cout<<value;
				 }
				else
				{
					cout<<"sorry";
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
		Sleep(2000);
		system("cls");
		main();
	}
	else if(opt==3)
	{
		system("cls");
		cin.ignore();
	    string s_ans;
		cout<<"What is your pet's name?";
		getline(cin,s_ans);
		forget_dat obj3(s_ans);
		obj3.recover();	
	}
 return 0;
 }






