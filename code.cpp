#include <iostream>
#include <string>
#include <iomanip>//·«” Œœ«„ „ﬂ »…  ”«⁄œ ⁄·Ï  ‰ŸÌ„ «·ÃœÊ·
using namespace std;
//«·„ €Ì— «·⁄«·„Ì
int Max_User=30 , Ucount=0;
//· ⁄—Ì› ··œÊ«·(prototypes) «·
void mineMenu();
void addUser( int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []);
void display( int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []);
void UpdateUsage(int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []);
void deletUser(int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []);

int main(){
	int numberOfRoom [30],choise;
	string name_ofuser [30];
	double total_quot [30],consumed [30];
	
	do{
           mineMenu();
	       cin>>choise;
	       switch (choise)
	       {
		    case 1:{
	             cout <<"----------------------------------------------------------------------------------------"<<endl;
	             cout <<"|                                        Add New User                                  |"<<endl;
	             cout <<"----------------------------------------------------------------------------------------"<<endl;
	             addUser(numberOfRoom,name_ofuser,total_quot ,consumed);
	             break;
				 }
		    case 2:display(numberOfRoom,name_ofuser,total_quot ,consumed);
			     break;
            case 3: {
                 cout <<"----------------------------------------------------------------------------------------"<<endl;
	             cout <<"|                                        Usage of user                                  |"<<endl;
	             cout <<"----------------------------------------------------------------------------------------"<<endl;
	             UpdateUsage(numberOfRoom,name_ofuser,total_quot ,consumed);
	             break;
				 }
		    case 4 :{
	             cout <<"----------------------------------------------------------------------------------------"<<endl;
	             cout <<"|                                Delete Student Record                                  |"<<endl;
	             cout <<"----------------------------------------------------------------------------------------"<<endl;
	             deletUser(numberOfRoom,name_ofuser,total_quot ,consumed);
	             break;
				 }
		    default :
		  	     cout <<"Invalid option! Try again. "<<endl;
	       }
      }
	while(choise != 5);

}

void mineMenu(){
	    cout << "========================================================================================"<<endl;
	    cout << "|                                NETWORK CONTROL PANEL                                 |"<<endl;
	    cout << "========================================================================================"<<endl;
        cout << " Select Option [1-5] \n";
	    cout << " 1. Add New Student\n";
		cout << " 2. Display All Students & Status\n";
		cout << " 3. Update Internet Usage\n";
		cout << " 4. Delete Student Record\n";
		cout << " 5. Exit System\n";
}
void addUser( int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []){
	if (Ucount == Max_User)	cout << " Sorry , system is full";
	  else
	  {
	    cout << "Enter Student name     : ";
	    cin  >> name_ofuser [Ucount];
	    cout << "Enter Room number      : ";
	    cin  >> numberOfRoom [Ucount];
	    cout << "Enter Total  Quota(MB) : ";
	    cin  >> total_quot [Ucount];
	    consumed [Ucount]= 0;
		Ucount ++;
	    cout <<"Student registered Successfully \n"<<endl;
	  }
	char again;
	cout << "Enter 1 to add a new user \nor Press any key to return to Main Menu   ";
	cin  >> again;
	if (again =='1'){
	cout<<"____________________________________________________________________"<<endl;
			addUser(numberOfRoom,name_ofuser,total_quot ,consumed);}
}
void display( int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []){
	cout<<"|                                               Network Usage                                               |"<<endl;
	
	if (Ucount==0)cout<<" No students reqistered in the system.\n ";
	  else
	  {//ÿ»«⁄… —«” «·ÃœÊ·
	   cout << "_______________________________________________________________________________________________________"<<endl;
	   cout <<left<<setw(10)<<"ID"
		    <<setw(20)<<"Student Name"
		    <<setw(20)<<" Room"
		    <<setw(20)<<"Quota (MB)"
		    <<setw(20)<<"Used (MB)"
		    <<setw(20)<<"Network Status"<<endl;
	cout << "_______________________________________________________________________________________________________"<<endl;
	  }
	for(int i=0;i<Ucount;i++)//ÿ»«⁄… »Ì«‰«  «·ÃœÊ·
	  {
		string status= (consumed[i]>=total_quot[i])?"EXCEEDED!!" :"Active";//Ê«·« «–« «·‘—ÿ Œÿ««ÿ»⁄ «ﬂ Ì›
		cout <<left<<setw(10)<<(i+1)
			 <<setw(20)<<name_ofuser [i]
			 <<setw(20)<<numberOfRoom [i]
		     <<setw(20)<<total_quot [i]
			 <<setw(20)<<consumed [i]
			 <<setw(20)<<status;
			cout<<endl;
	  }
	cout << "_______________________________________________________________________________________________________"<<endl;
	char back;
	cout<<" Press any key to return to Main Menu ....  ";
	cin>>back;
}
void UpdateUsage(int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed [])
{
	string name_search ; 
	bool found =false;
	    cout << "Enter Student Name : ";
	    cin  >> name_search;
	 
		for(int i=0;i<=Ucount;i++)
		{
		      if(name_search == name_ofuser [i])
			  {
			     found =true;
			     cout << "_______________________________\n";
			     cout << "the student name   : "<< name_ofuser [i]<<endl;
		         cout << "the number of room : "<< numberOfRoom [i]<<"\nthe total quot :"<<total_quot [i]<<" MB";
		         cout << "\n current usage = "<<consumed [i]<<" MB";//«·ﬁ—«… «·Õ«·Ì…
		         cout << "\nEnter additional usage amount "<<" : ";//«Ÿ«›… «” Â·«ﬂ ÃœÌœ
		         double amount;
		         cin>>amount;
		         consumed [i]+=amount;//Ì÷Ì› «·ﬁ—«… «·ÃœÌœ… ··ﬁÌ„… «·«Ê·Ï 
		         double remaining=total_quot [i]-consumed [i];//ÌÕ”» «·ﬁÌ„… «·„Õœœ… ··„” Œœ„ ÊÌ‰ﬁ’ „‰Â« «·«” Â·«ﬂ «·ﬂ·Ì ··„” Œœ„ 
		         cout<<"the quot remining = ";
		            if(remaining<0)cout<<" 0 MB rimaining and EXCEEDED!!\n";
		               else cout<<remaining<<" MB and Active . \n"; 
			     cout << "_________________________________\n";
			     break;
			  }     
	   }
		    if (found==false) cout <<" Student "<<name_search<<" not found.\n";  
    cout<<"------------------------------------------------------------------------------------------------------"<<endl;
 }

void deletUser(int numberOfRoom [],string name_ofuser [], double total_quot [],double consumed []){
  string search_name ; 
  bool found = false;
   cout <<"Enter Student Name to delete: ";
   cin  >>search_name;
	for(int i=0;i<=Ucount;i++)
	{
		 if(search_name == name_ofuser [i])
	       {
			   found =true;
			   cout << "_______________________________\n";
		       cout << "The Student Name : "<<name_ofuser [i];
		       cout << "\nThe Number of Room : "<<numberOfRoom [i];
		       cout << "\nAre you sure you want to delete "<<name_ofuser [i]<<"(Y/N)"<<"\nEnter Y to delete and N to cancle ";
		         int pos=i;
		         char confirm;
		         cin>>confirm;
		            if (confirm=='Y')
					 {
			            for(int i =pos;i<Ucount-1;i++){
				          name_ofuser [i]=name_ofuser [i+1];
			              numberOfRoom [i] =numberOfRoom [i+1];
				          total_quot [i]=total_quot [i+1];
				          consumed [i]=consumed [i+1];
		                  }
						cout<<"Record deleted successfully.\n";
						  Ucount--;
		             }
		             else if (confirm=='N')cout<<" deletion cancelled.\n ";
		             else cout <<"invaild choise ,deletion cancelled. \n";   
	       }
	}
		 if (found==false) cout <<" Student "<<search_name<<" not found.\n";  ; 
	     cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    
	char again;
	cout<<"Enter 1 to delet a new user \nor Press any key to return to Main Menu   ";
	cin>>again;
	   if (again =='1')deletUser(numberOfRoom,name_ofuser,total_quot ,consumed);
	 
 }
