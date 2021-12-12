#include<iostream>
#include<fstream>
using namespace std;

struct data
{
	string name, cnic;
	int age;
};

int main()
{
	data d[3];
	for(int i=0; i<3; i++)
	{
	cout<<"Enter your Name : ";
	cin>>d[i].name;
	cout<<"Enter your Age : ";
	cin>>d[i].age;
	
	}
	ofstream m("data.txt",ios::app);
	m<<d[0].name<<endl;
	m<<d[0].age<<endl;
	m<<d[0].cnic<<endl;
	ofstream n("data.txt",ios::app);
	m<<d[1].name<<endl;
	m<<d[1].age<<endl;
	m<<d[1].cnic<<endl;
	ofstream p("data.txt",ios::app);
	m<<d[2].name<<endl;
	m<<d[2].age<<endl;
	m<<d[2].cnic<<endl;
	

//	ifstream n("data.txt");
//	getline(n, d1.name);
//	n>>d1.age;
//	n>>d1.cnic;
//	
//	cout<<d1.name<<"\n"<<d1.age<<"\n"<<d1.cnic;
	
	
	
	return 0;
}
