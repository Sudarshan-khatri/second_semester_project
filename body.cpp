#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
#include<iomanip>
#include<windows.h>
using namespace std;
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
	return 0;
 }
