//**************************EMPLOYEE MANAGEMENT SYSTEM***************************//

#include<iostream.h>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
#include <ctime>
#include <dos.h>
#include<dos.h>
#include<conio.h>
#include<cstdio>
#include<fstream>

#define maximum 20

using namespace std;

//The General Class//
class person{
	protected:
		char name[25];
		char address[100];
		char nationality[20];
	public:
		void get_details(){
			cout<<"\nEnter name\n";
			cin>>name;			
			cout<<"\nEnter address\n";
			cin>>address;
			cout<<"\nEnter nationality\n";
			cin>>nationality;
		}
		void put_details(){
			cout<<"\n name:\t";
			cout<<name;
			cout<<"\n address:\t";
			cout<<address;
			cout<<"\n nationality:\t";
			cout<<nationality;
			cout<<"\n";
		}
};

//Employee class derived from person class//
class employee: public person{
		int empno;
	protected:		
		double salary;
		char startdate[10];
		int exp;
		int age;
		int associated_dno;
	public:
		//overriding
		void get_details(){
			cout<<"\nEnter name\n";
			cin>>name;
			cout<<"\nEnter Age  ";
  			cin>>age;
  			cout<<"\nEnter address\n";
			cin>>address;
			cout<<"\nEnter nationality\n";
			cin>>nationality;
			cout<<"\nEnter employee number\n ";
			cin>>empno;
			cout<<"\nEnter salary\n";
			cin>>salary;
			cout<<"\nEnter start date\n";
			cin>>startdate;
			cout<<"Years of Experience\n";
  			cin>>exp;
		}
		void put_details(){
			cout<<setw(13)<<empno;
  			cout<<setw(6)<<name;
			cout<<setw(15)<<address;
			cout<<setw(10)<<nationality;
  			cout<<setw(15)<<age;
   			cout<<setw(6)<<salary;
  			cout<<setw(15)<<startdate;
  			cout<<setw(10)<<exp;
  			cout<<endl;			
		}	
		int return_empno(){
			return empno;
			}
		void get_empno(){
			cout<<empno;
		}	
};
//Manager class derived from employee class//
class manager: public employee{
	protected:
		int mgssn;
	public:
		//overriding
		void get_details(){
			cout<<"\nEnter name\n";
			cin>>name;
			cout<<"\nEnter address\n";
			cin>>address;
			cout<<"\nEnter nationality\n";
			cin>>nationality;
			cout<<"\nEnter manager number\n ";
			cin>>mgssn;
			cout<<"\nEnter salary\n";
			cin>>salary;
			cout<<"\nEnter start date\n";
			cin>>startdate;
			cout<<"\nEnter term duration (in years)\n";
			cin>>exp;
		}
		void put_details(){
			cout<<setw(13)<<mgssn;
  			cout<<setw(6)<<name;
			cout<<setw(15)<<address;
			cout<<setw(10)<<nationality;
  			cout<<setw(15)<<age;
   			cout<<setw(6)<<salary;
  			cout<<setw(15)<<startdate;
  			cout<<setw(10)<<exp;
  			cout<<endl;					
		}
		void show_mgssn(){
			cout<<mgssn;
		}
		int return_mgssn(){
			return mgssn;
		}		
};

class project{
	
	protected:
		int pno;
		char name[25];
		char location[100];
		char startdate[10];
		float budget;
	public:
			void get_details(){
				cout<<"\nEnter project number\n";
				cin>>pno;
				cout<<"\nEnter project name\n";
				cin>>name;
				cout<<"\nEnter location\n";
				cin>>location;
				cout<<"\nEnter budget\n";
				cin>>budget;
				cout<<"\nEnter start date\n";
				cin>>startdate;
		}		
		void put_details(){
			cout<<setw(13)<<pno;
  			cout<<setw(6)<<name;
			cout<<setw(15)<<location;
			cout<<setw(10)<<budget;
  			cout<<setw(15)<<startdate;  			
		}
		void get_pno_name()
		{
			cout<<pno<<"\t";
			//puts(name);
			cout<<name;
			cout<<"\n";
		}
		int return_pno(){
			return pno;
		}		
		
};

class department{
	int dno;
	char dname[20];
	public:
			int project_id_handled[15];
			int mgssn;
			int array_of_empno[20];
			int n;
			void get_details(){
				
				cout<<"\nEnter depatment number\n";
				cin>>dno;
				cout<<"\nEnter department name\n";	
				cin>>dname;	
				cout<<"\nAssign the manager from the table above. Enter the respective manager ssn";
				cin>>mgssn;
				cout<<"\nEnter total number of employees under this department";
				cin>>n;
				cout<<"\nAssign the employees to work under this department. Enter the respective employee ssn";
				for(int i=0;i<n;i++)
					cin>>array_of_empno[i];		
			}
		void put_details(){
			cout<<"\n department number:\t"<<dno;
			cout<<"\n name:\t";
			cout<<dname;
			cout<<"\nThe manager id of the manager is:\t"<<mgssn<<"\n";
			cout<<"\n employee id of the employees working under this department are\n ";
			for(int i=0;i<n;i++){
				if(array_of_empno[i]!=0)
				cout<<array_of_empno[i]<<"\n";
				}
		}
};

class customer: public person{
	protected:
		int cust_id;
		int no_of_orders;
		
	public:
			char service_type[50];
			int payment;
			void get_details(){
			cout<<"\nEnter customer id\n ";
			cin>>cust_id;
			cout<<"\nEnter name\n";
			cin>>name;
			cout<<"\nEnter address\n";
			cin>>address;
			cout<<"\nEnter nationality\n";
			cin>>nationality;
		}
		void put_details(){
			cout<<"\n customer id:\t";
			cout<<cust_id;
			cout<<"\n name:\t";
			cout<<name;			
			cout<<"\n address:\t";
			cout<<address;
			cout<<"\n nationality:\t";
			cout<<nationality;
			cout<<"\n";
			cout<<"\nService type:\t";
			cout<<service_type;
			cout<<"\n";
			cout<<"\nPayment:\t";
			cout<<payment;
			cout<<"\n";
		}
		void make_order(){
			no_of_orders++;			
		}
};

employee e[maximum],e1;
manager m[maximum],m1;
project p[maximum],p1;
department d[maximum],d1;
customer c[maximum],c1;
int a, total_managers,total_projects,total_departments;
int k=0;
void menu();
void menu1();
void menu(){
	int option;	
	fstream file;
	do{	
		system("cls");
		cout<<"\n1.Make entry";
		cout<<"\n2.Display Employee details";
		cout<<"\n3.View Customer details";
		cout<<"\n4.Enter Department details";
		cout<<"\n5.Enter Project details";
		cout<<"\n6.Show Department details";
		cout<<"\n7.Show Project details";
		cout<<"\n8.Return back";
		cout<<"\nEnter your choice";
		cin>>option;
		switch(option){
						case 1: cout<<"\nIs the entry for manager or for normal employee? press 1 for employee, 2 otherwise";
								int n;
								cin>>n;
								switch(n){
										case 1: 
												file.open("employee.txt",ios::out|ios::app);
												if(!file){
													cout<<"\ncannot open file\n";
													break;
												}
												system("cls");
												cout<<"\nEnter the number of employees";
												cin>>a;
												for(int i=0;i<a;i++)
												{	e[i].get_details();
													file.write((char *) & e[i],sizeof(e[i]));
												}
												file.close();
												break;
										case 2: 
												file.open("manager.txt",ios::out|ios::app);
												if(!file){
													cout<<"\ncannot open file\n";
													break;
												}
												system("cls");
												cout<<"\nEnter the number of managers";
												cin>>total_managers;
												for(int i=0;i<total_managers;i++)
												{	m[i].get_details();
													file.write((char *) & m[i],sizeof(m[i]));
												}
												file.close();
												break;
							}
				        break;
						case 2: system("cls");
								cout<<"\nEmployee Details are\n\n";
								
								file.open("employee.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"	Emp_no    Name     Address     Nationality     Salary		Start date		Years(EXP)    "<<endl;
								while(true)
								{
										file.read((char *) & e1,sizeof(e1));
										if(file.eof()) break;
										e1.put_details();
								}
								file.close();
								cout<<"\n\n";
								cout<<"\nManager Details are\n\n";
								
								file.open("manager.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"	Mgr_no    Name     Address     Nationality     Salary		Start date		Years(EXP)    "<<endl;
								while(true)
								{
									file.read((char *) & m1,sizeof(m1));
									if(file.eof()) break;
									m1.put_details();
								}
								file.close();
								getch();
								break;
						case 3: system("cls");
								file.open("customer.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								while(true)
								{
									file.read((char *) & c1,sizeof(c1));
									if(file.eof()) break;
									c1.put_details();
								}
								file.close();
								getch();
								break;				
						case 4:	cout<<"\nEnter department details";
								cout<<"\nEmployee Details are\n\n";
								
								file.open("employee.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"	Emp_no    Name     Address     Nationality     Salary		Start date		Years(EXP)    "<<endl;
								while(true)
							
								{
										file.read((char *) & e1,sizeof(e1));
										if(file.eof()) break;
										e1.put_details();
								}
								file.close();
								cout<<"\n\n";
								cout<<"\nManager Details are\n\n";
								
								file.open("manager.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"	Mgr_no    Name     Address     Nationality     Salary		Start date		Years(EXP)    "<<endl;
								while(true)
								{
									file.read((char *) & m1,sizeof(m1));
									if(file.eof()) break;
									m1.put_details();
								}
								file.close();
								
								
								file.open("department.txt",ios::out|ios::app);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"\nEnter the number of departments";
								cin>>total_departments;
								for(int i=0;i<total_departments;i++){
									d[i].get_details();
									file.write((char *) & d[i],sizeof(d[i]));
								}
								file.close();
								break;				
						case 5:		
								
								file.open("project.txt",ios::out|ios::app);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"\nEnter the total number of projects handled by the company\n";			
								cin>>total_projects;
								for(int i=0;i<total_projects;i++)
								{
									p[i].get_details();	
									file.write((char *) & p[i],sizeof(p[i]));
								}
								file.close();
								break;
						case 6: 
								file.open("department.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"\nThe department details are\n";				
								while(true)
								{
									file.read((char *) & d1,sizeof(d1));
									if(file.eof()) break;
										d1.put_details();	
									}
								file.close();
								break;	
						case 7:
								file.open("project.txt",ios::in);
								if(!file){
									cout<<"\ncannot open file\n";
									break;
								}
								cout<<"\nThe project details are\n";	
							   cout<<"	p_no    Name     Location     Budget     Start date		    "<<endl;			
								while(true)
								{
									file.read((char *) & p1,sizeof(p1));
									if(file.eof()) break;
										p1.put_details();	
									}
								file.close();				
								break;
			}
				getch();
}while(option!=8);
menu1();
}

void menu1(){
		int option;
	int password;
	fstream file;	
	do{	
	system("cls");
	cout<<"\n";
	cout<<"\n*****************EMPLOYEE MANAGEMENT SYSTEM******************\n";
	cout<<"\n\nLogin as:\n\n";
	cout<<"\n1.Admin";
	cout<<"\n2.Customer";
	cout<<"\n3.Employee";
	cin>>option;
	switch(option){
		case 1: system("cls");
				cout<<"\nWelcome Administrator\n";
				cout<<"\nEnter password";
				cin>>password;
				if(password==1234)
					menu();
				else
					cout<<"\nAuthentication Failed\n";
				getch();
				break;
		case 2: system("cls");
				file.open("customer.txt",ios::out|ios::app);
				if(!file){
					cout<<"\ncannot open file\n";
					break;
				}
				int n;				
				int amount;
				cout<<"\nWelcome to the Company\n\nThese are the following services provided by us\n.Select your choice";
				cout<<"\n1.Help in final year projects";
				cout<<"\n2.Help in Consultancy";
				cout<<"\n3.Internship";
				cin>>n;
				switch(n){
					case 1: strncpy(c[k].service_type,"final_year_projects",sizeof(c[k].service_type));
							c[k].payment=12000;
					break;
					case 2: strncpy(c[k].service_type,"consultancy",sizeof(c[k].service_type));
							c[k].payment=1200000;
					break;
					case 3:strncpy(c[k].service_type,"internship",sizeof(c[k].service_type));
							c[k].payment=8000;
					break;
				}
				c[k].get_details();				
				c[k].payment=amount;
				c[k].put_details();
				file.write((char *) & c[k],sizeof(c[k]));
				file.close();
				k++;
				getch();
				break;
		case 3: system("cls");
				int m_ssn, e_ssn;
				cout<<"\nAre you manager or normal employee. press 1 for manager else 2 otherwise\n";
				cin>>n;
				switch(n){
					case 1: system("cls");
							file.open("manager.txt",ios::in);
							if(!file){
								cout<<"\ncannot open file\n";
								break;
							}
							cout<<"\nEnter manager ssn";
							cin>>m_ssn;
							while(true){
								file.read((char *) & m1,sizeof(m1));
								if(file.eof()) break;
								if(m1.return_mgssn()==m_ssn){
									cout<<"	Mgr_ssn    Name     Address     Nationality     Salary		Start date		Years(EXP)    "<<endl;
									m1.put_details();
									
								}
								else
									cout<<"\nRecord not found\n";
							}
							file.close();
							getch();
							break;
					case 2: system("cls");
							file.open("employee.txt",ios::in);
							if(!file){
								cout<<"\ncannot open file\n";
								break;
							}
							cout<<"\nEnter employee ssn";
							cin>>e_ssn;
							while(true){
								file.read((char *) & e1,sizeof(e1));
								if(file.eof()) break;
								if(e1.return_empno()==e_ssn){
									cout<<"	Emp_no    Name     Address     Nationality     Salary		Start date		Years(EXP)    "<<endl;
									e1.put_details();
									
								}								
							}
							file.close();
							break;
				}
				getch();
				break;
	}
}while(option!=4);
}
int main()
{
	menu1();
}


