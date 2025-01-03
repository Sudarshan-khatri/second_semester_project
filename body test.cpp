#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<regex>
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
				landlord<<"\n\nInformtation of Room"<<endl;
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
			 	cout<<"\n\nHouse_No\tFloor_No\t\tHouse_ow_Name\tLocation\tToll_Name\tContact_No\tRoom_Type\tNegotiable\tAd_Posted\tAd_Expired\tFurnishing\tSize_of_Room"<<endl;
			    string line;
			    while (getline(show_detail, line))
				 { // Read file line by line
			        stringstream ss(line); // Use a stringstream to parse the line
			        string houseNo, floorNo, houseOwner, location, tollName, contactNo, roomType, negotiable, adPosted, adExpired, furnishing, roomSize;
			
			        // Assuming data is separated by tabs or spaces
			        ss >> houseNo >> floorNo >> houseOwner >> location >> tollName >> contactNo
			           >> roomType >> negotiable >> adPosted >> adExpired >> furnishing >> roomSize;
			
			        // Print the parsed data
			        cout << houseNo << "\t" << floorNo << "\t" << houseOwner << "\t" << location << "\t"
			             << tollName << "\t" << contactNo << "\t" << roomType << "\t" << negotiable << "\t"
			             << adPosted << "\t" << adExpired << "\t" << furnishing << "\t" << roomSize << endl;
				 }
			}
		 }
};
int main()
{
	int hm_no,flr_no;
	string house_ow_nm,loc,toll,contact,room_tp,neg,ad_pst,ad_exp,furn,rm_size;
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
	obj1.show();
	return 0;
}
