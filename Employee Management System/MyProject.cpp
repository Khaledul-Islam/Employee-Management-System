#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>
#include<algorithm>

using namespace std;

class bank
{
    char name[50],position[50];
    int salary,id;
public:
    int account_create();                                   //////
    int show_account()  const;                              ///THIS IS CLASS
    void modify_account();                                  //////
    int return_id() const;
};


int bank::return_id() const
{
	return id;
}


void bank::modify_account()
{
    cout<<"\n\n\tModify Bank Account Employee Name : ";
    cin.ignore();
	cin.getline(name,50);                                               //////
    cout<<"\n\n\tModify Bank Account Employee ID : ";                   ///MODIFY FORM FROM USER
    cin>>id;                                                            //////
    cout<<"\n\n\tModify Bank Account Employee Position : ";
    cin>>position;
    cout<<"\n\n\tModify Bank Account Employee Salary : ";
    cin>>salary;

}

int bank::show_account() const
{                                                                                       //////
    cout<<setw(20)<<name<<setw(20)<<id<<setw(20)<<position<<setw(20)<<salary<<endl; 
	return 0;///SHOW FUNCTION
}                                                                                       //////

int bank::account_create()
{
    cout<<endl;
    cout<<"Enter the name of Employee : ";
    cin.ignore();
	cin.getline(name,50);
	cout<<endl;
    cout<<"Enter the ID of Employee :";
    cin>>id;                                                //////
    cout<<endl;                                             ///ACCOUNT CREATE FORM FROM USER
    cout<<"Enter the Position of Employee :";               //////
    cin.ignore();
	cin.getline(position,50);
    cout<<endl;
    cout<<"Enter the Salary of Employee :";
    cin>>salary;
    cout<<endl;
    cout<<"\n\n\tYour Account Created..";
    cout<<"\n\n\tPress Enter To Return Main Menu.";
    return 0;

}


void intro();
void design();
void case_show();                                           //////
void write_account();                                       ///ITS USER DEFINE FUNCTION
void display_all();                                         //////
void edit_account(int n);
void delete_account(int);


int main()
{
    int c;
    int num;
    do
    {
        system("cls");
        intro();
        display_all();
        case_show();
        cin>>c;
        cout<<endl<<endl;
        switch(c)
        {
        case 1:
            write_account();
            break;
        case 2:
            cout<<"\n\n\tEnter The ID NO. : "; cin>>num;                    //////
            cout<<endl;                                                     ///IT IS MAIN FUNCTION
            edit_account(num);                                              //////
            break;
        case 3:
            cout<<"\n\n\tEnter The ID No. : "; cin>>num;
			delete_account(num);
			break;
        case 0:
            return 0;
            break;
        default:
            cout<<"Invalid choice ";
        }
        cout<<endl;
        cout<<"Press enter to continue... ";
        cin.get();
        cin.ignore();
    }while(c<=3);
return 0;
}


void delete_account(int n)
{
	bank m;
	ifstream inFile;
	ofstream outFile;
	inFile.open("bank.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";                            //////
	}                                                                                        ///DELETE ACCOUNT FROM FILE
	outFile.open("Temp.dat",ios::binary);                                                    //////
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(bank)))
	{
		if(m.return_id()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&m), sizeof(bank));
		}
	}
	inFile.close();
	outFile.close();
	remove("bank.dat");
	rename("Temp.dat","bank.dat");
	cout<<"\n\n\tRecord Deleted ..";
    cout<<"\n\nPress Enter To Return Main Menu.";
}


void edit_account(int n)
{
	bool found=false;
	bank m;
	fstream File;
	File.open("bank.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)                                              //////
	{                                                                               ///EDIT ACCOUNT FROM FILE
		File.read(reinterpret_cast<char *> (&m), sizeof(bank));                     //////
		if(m.return_id()==n)
		{
			m.show_account();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			m.modify_account();
			int pos=(-1)*static_cast<int>(sizeof(bank));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&m), sizeof(bank));
			cout<<"\n\n\t Record Updated";
			cout<<"\n\n\tPress Enter To Return Main Menu.";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";
}


void display_all()
{
	bank m;
	ifstream inFile;
	inFile.open("bank.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	cout<<"\t\t\t\tALL ACCOUNT HOLDER LIST\n\n";                                    //////
	design();                                                                       ///DISPLAYING ALL ACCOUNT FROM FILE
                                                                                    //////
	while(inFile.read(reinterpret_cast<char *> (&m), sizeof(bank)))
	{
		m.show_account();

	}
	inFile.close();
}
void write_account()
{
	bank m;
	ofstream outFile;
	outFile.open("bank.dat",ios::binary|ios::app);                              //////
	m.account_create();                                                         ///CREATE ACCOUNT IN FILE
	outFile.write(reinterpret_cast<char *> (&m), sizeof(bank));                 //////
	outFile.close();
}

void case_show()
{
    cout<<endl<<"\t- : Menu - ";
    cout<<endl<<"----------------------------";              //////
    cout<<endl<<"Create account           : 1";             ///CASE SHOW
    cout<<endl<<"Modify Account           : 2";             /////
    cout<<endl<<"Delete Account           : 3";
    cout<<endl<<"Exit from Program        : 0";
    cout<<endl<<"Enter Your Choice        : ";
}

void design()
{
    cout<<"\t\t==============================================================="<<endl;             //////
    cout<<"\t\tName"<<setw(20)<<"ID"<<setw(20)<<"Position"<<setw(20)<<"Salary "<<endl;             ///DESIGN
    cout<<"\t\t==============================================================="<<endl<<endl;       //////
}

void intro()
{
    cout<<"\n\n\t\t\t\t\t\t SHUVO \n\n"<<endl;                                                      //////
    cout<<"\t\tINTERNATIONAL UNIVERSITY OF BUSSINESS AGRICULTURE AND TECHNOLOGY \n\n\n\n\n";        ///INTRO
                                                                                                    //////
}

