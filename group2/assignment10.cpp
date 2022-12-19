/*
Title  :-Write a C++ program to implement a doubly linked list and perform operations such as insert, delete, display and
search element from it.

Author :- SAHIL DHARGAVE

*/

#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
} *head, *newnode, *tail, *temp;

void Insert_at_beg();
void Insert_at_end();
void Insert_at_pos();
void Create_linked_list();
void Display_linked_list();
void Search();

int cnt;

int main()
{
	cout << "\n# Doubly Linked List # " << endl;

	head = NULL;
	tail = NULL;

	int ch;

	do
	{
		cout << "\n# Operations Menu: " << endl;
		cout << "1.Create linked list" << endl;
		cout << "2.Display linked list" << endl;
		cout << "3.Insert at beginning" << endl;
		cout << "4.Insert at end" << endl;
		cout << "5.Insert at specific position" << endl;
		cout << "6.Search Element" << endl;
		cout << "0.Exit" << endl;

		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{

		case 1:
			Create_linked_list();
			break;

		case 2:
			Display_linked_list();
			break;

		case 3:
			Insert_at_beg();

			break;

		case 4:
			Insert_at_end();
			break;

		case 5:
			Insert_at_pos();
			break;

		case 6:
			Search();
			break;

		case 0:
			goto end;
			break;

		default:
			cout << "Incorrect Choice!" << endl;
			break;
		}
	} while (1);

end:
	cout << "\n* You are exit!\n"
		 << endl;
	return 0;
}

void Insert_at_beg()
{
	newnode = new (nothrow) struct node;
	cout << "\n* Insert node at the beginning: " << endl;
	cout << "Enter the newnode data: ";
	cin >> newnode->data;
	newnode->next = head;
	newnode->prev = head;
	head = newnode;
	cnt++;
	cout << "Node Inserted successfully.." << endl;
}

void Insert_at_end()
{
	newnode = new (nothrow) struct node;
	cout << "\n* Insert node at the end: " << endl;
	cout << "Enter the newnode data: ";
	cin >> newnode->data;
	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
	newnode->next = NULL;
	cnt++;
	cout << "Node Inserted successfully.." << endl;
}

// ** Generalised Insertion **
void Insert_at_pos()
{
	int pos, i = 1;
	newnode = new (nothrow) struct node;
	cout << "\n* Insert node at specific position: " << endl;
	cout << "Enter the position: ";
	cin >> pos;
	if (pos < 1 || pos > (cnt + 1))
	{
		cout << "Invalid position!" << endl;
	}
	else
	{
		cout << "Enter the newnode data: ";
		cin >> newnode->data;
		temp = head;
		if (head == NULL)
		{
			head = newnode;
			newnode->next = NULL;
		}
		else
		{
			while (i < (pos - 1))
			{
				temp = temp->next;
				i++;
			}
			if (pos = !1)
			{
				newnode->next = head;
				head = newnode;
			}
			else
			{
				newnode->next = temp->next;
				temp->next = newnode;
			}
			cnt++;
			cout << "Node Inserted successfully.." << endl;
		}
	}
}

void Display_linked_list()
{
	if (head == NULL)
	{
		cout << "\n# Display Linked List: " << endl;
		cout << "The list is empty!" << endl;
	}
	else
	{
		cout << "\n# Display Linked List: " << endl;
		temp = head;
		int i = 1;
		cout << "  Node\tData" << endl;
		while (temp != NULL)
		{
			cout << "  " << left << setw(8) << i;
			cout << left << setw(10) << temp->data << endl;
			temp = temp->next;
			i++;
		}
		cout << "\n* Number of nodes =  " << cnt << endl;
		cout << endl;
	}
}
void Create_linked_list()
{

	cout << "\n# Create Linked List: " << endl;
	int choice, i = 1;
	while (choice)
	{
		newnode = new (nothrow) struct node;
		cout << "\nEnter the node-" << i << " data: ";
		cin >> newnode->data;
		newnode->next = NULL;
		newnode->prev = NULL;
		if (head == NULL)
		{
			head = tail = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		cout << "Do you want to continue? (1.Yes 0.No) : ";
		cin >> choice;
		i++;
	}
}
void Search()
{
	int data, flag = 0, i;
	temp = head;
	cout << "\n# Search: " << endl;
	if (head == NULL)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		cout << "Enter data to be searched: ";
		cin >> data;
		for (i = 0; i < cnt; i++)
		{
			if (data == temp->data)
			{
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if (flag == 0)
		{
			cout << "* Data not found!" << endl;
		}
		else
		{
			cout << "\n # Display Data: " << endl;
			cout << "  Node\tData" << endl;
			cout << "  " << left << setw(8) << (i + 1);
			cout << left << setw(10) << data << endl;
			cout << "* Data found at node " << (i + 1) << endl;
		}
	}
}
