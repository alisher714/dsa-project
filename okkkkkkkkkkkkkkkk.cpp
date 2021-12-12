#include<iostream>
#include<conio.h>


using namespace std;

class Library
{
	private :
		struct Node
		{
			int id;
			string author,publisher, name;
			Node *next_add;
		};
	public:
		Node *head=NULL;
		
		void menu();
		void insert();	
		void search();
		void update();
		void del();
		void sort();
		void show();
};

void Library::menu()
{
	p:
		system("cls");
		int choice;
		cout<<"\n\n\t\t=================================";
		cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
		cout<<"\n\n\t\t=================================";
		cout<<"\n\t\t 1. Enter New Record";
		cout<<"\n\t\t 2. Search Record";
		cout<<"\n\t\t 3. Update Record";
		cout<<"\n\t\t 4. Delete Record";
		cout<<"\n\t\t 5. Show all Record";
		cout<<"\n\t\t 6. Exit";
		cout<<"\n\n\t\tEnter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insert();
				break;
			
			case 2:
				search();
				break;
			
			case 3:
				update();
				break;
			
			case 4:
				del();
				break;
				
			case 5:
				sort();
				show();
				break;
			
			case 6:
				exit(0);
				break;
			
			default :
				cout<<"\n\nyou entered incorrect command try again....";						
		}
		getch();
		goto p;
}
void Library::insert()
{
	system("cls");
		cout<<"\n\n\t\t=================================";
		cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
		cout<<"\n\n\t\t=================================";
		
		Node *new_node = new Node;
		cout<<"\n\t\tBook ID : ";
		cin>>new_node -> id;
		cout<<"\n\t\tName : ";
		cin>>new_node -> name;
		cout<<"\n\t\tAuthor Name : ";
		cin>>new_node ->author;
		cout<<"\n\t\tPublisher Name : ";
		cin>>new_node -> publisher;
		
		new_node -> next_add = NULL;
		if(head ==NULL)
		{
			head = new_node;
		}
		else
		{
			Node *ptr =head;
			while(ptr-> next_add!=NULL)
			{
				ptr = ptr -> next_add;
			}
			ptr -> next_add = new_node;
		}
		cout<<"\n\n\t\tNew Book Inserted Successfully....";
		
}

void Library::search()
{
	system("cls");
	int t_id, found=0;
	cout<<"\n\n\t\t=================================";
	cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
	cout<<"\n\n\t\t=================================";	
	if(head == NULL)
	{
		cout<<"\n\t\t List is Empty...!";
	}
	else
	{
		cout<<"\n\t\tEnter Book ID : ";
		cin>>t_id;
		Node *ptr = head;
		while(ptr!= NULL)
		{
			if(t_id==ptr -> id)
			{
				system("cls");
				cout<<"\n\n\t\t=================================";
				cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
				cout<<"\n\n\t\t=================================";
				cout<<"\n\n\t\tBook ID : "<<ptr -> id;
				cout<<"\n\n\t\tBook Name : "<<ptr -> name;
				cout<<"\n\n\t\tAuthor Name : "<<ptr -> author;
				cout<<"\n\n\t\tPublisher Name : "<<ptr -> publisher;
				found++;	
			}
			ptr = ptr -> next_add;
		}
		if(found == 0)
		{
			cout<<"\n\t\tBook ID is INVALID....";
		}
	}
}

void Library::update()
{
	system("cls");
	int t_id, found=0;
	cout<<"\n\n\t\t=================================";
	cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
	cout<<"\n\n\t\t=================================";	
	if(head == NULL)
	{
		cout<<"\n\t\t List is Empty...!";
	}
	else
	{
		cout<<"\n\t\tEnter Book ID : ";
		cin>>t_id;
		Node *ptr = head;
		while(ptr!= NULL)
		{
			if(t_id==ptr -> id)
			{
				system("cls");
				cout<<"\n\n\t\t=================================";
				cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
				cout<<"\n\n\t\t=================================";
				cout<<"\n\n\t\tBook ID : ";
				cin>>ptr -> id;
				cout<<"\n\n\t\tBook Name : ";
				cin>>ptr -> name;
				cout<<"\n\n\t\tAuthor Name : ";
				cin>>ptr -> author;
				cout<<"\n\n\t\tPublisher Name : ";
				cin>>ptr -> publisher;
				found++;
				cout<<"\n\t\tBook Added Successfully....";
				found++;	
			}
			ptr = ptr -> next_add;
		}
		if(found == 0)
		{
			cout<<"\n\t\tBook ID is INVALID....";
		}
	}
}

void Library::del()
{
	system("cls");
	int t_id, found=0;
	cout<<"\n\n\t\t=================================";
	cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
	cout<<"\n\n\t\t=================================";
	if(head == NULL)
	{
		cout<<"\n\n\t\tlist is empty...";	
	}
	else
	{	
		cout<<"\n\t\tEnter Book ID : ";
		cin>>t_id;
		if(t_id==head -> id)
		{
			Node *ptr = head;
			head = head -> next_add;
			delete(ptr);
			cout<<"\n\n\t\tDelete book Successfully...";
			found++;
		}
		else
		{
			Node *pre = head ;
			Node *ptr = head ;
			while(ptr != NULL)
			{
				if(t_id == ptr->id)
				{
					pre -> next_add= ptr-> next_add;
					delete(ptr);
					cout<<"\n\n\t\tDeleted successfully...";
					found++;
					break;
				}
				pre = ptr;
				ptr = ptr -> next_add;
			}
		}
		if(found == 0)
		{
			cout<<"\n\n\t\tID NOT FOUND...";
		}
	}
}

void Library::sort()
{
	int count = 0, t_id;
	string t_name, t_author, t_publisher;
	if (head == NULL)
	{
		cout<<"\n\nlist is empty...";
		menu();
	}
	Node *ptr =head;
	while(ptr!=NULL)
	{
		count++;
		ptr= ptr-> next_add;
	}
	for(int i=1;i<=count; i++)
	{
		Node *ptr=head;
		for(int j=1; j<count; j++)
		{
			if (ptr->id > ptr ->next_add->id)
			{
				t_id = ptr -> id;
				t_name = ptr -> name;
				t_author = ptr -> author; 
				t_publisher = ptr -> publisher;
				
				ptr ->id = ptr ->next_add->id;
				ptr ->name = ptr ->next_add->name;
				ptr ->author = ptr ->next_add->author;
				ptr ->publisher = ptr ->next_add->publisher;
				
				ptr ->next_add->id = t_id;
				ptr ->next_add->name = t_name;
				ptr ->next_add->author = t_author;
				ptr ->next_add->publisher = t_publisher;
			}
			ptr= ptr-> next_add;
		}
	}
}

void Library::show()
{
	system("cls");
	cout<<"\n\n\t\t=================================";
	cout<<"\n\n\t\t====LIBRARY MANAGEMENT SYSTEM====";
	cout<<"\n\n\t\t=================================";	
		Node *ptr = head;
		while(ptr!= NULL)
		{
				cout<<"\n\n\t\tBook ID : "<<ptr -> id;
				cout<<"\n\n\t\tBook Name : "<<ptr -> name;
				cout<<"\n\n\t\tAuthor Name : "<<ptr -> author;
				cout<<"\n\n\t\tPublisher Name : "<<ptr -> publisher;
				cout<<"\n\n=====================================================";
			ptr = ptr -> next_add;
		}
}



int main()
{
	Library obj1;
	obj1.menu();
	
	return 0;
}
