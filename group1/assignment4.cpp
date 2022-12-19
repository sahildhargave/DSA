//impementation of stack

/*
Title  :-  Write a C++ program to implement the following data structures and its operations using linked list:
i) Stack ii) Queue.

Author  :-  Sahil Dhargave

*/




#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
struct Node *top = NULL;
void push(int val)
{
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}
void pop()
{
	if (top == NULL)
		cout << "Stack Underflow" << endl;
	else
	{
		cout << "The popped element is " << top->data << endl;
		top = top->next;
	}
}
void display()
{
	struct Node *ptr;
	if (top == NULL)
		cout << "stack is empty";
	else
	{
		ptr = top;

		cout << "Stack elements are: ";
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}
int main()
{
	int ch, val;
	cout << "1) Push in stack" << endl;
	cout << "2) Pop from stack" << endl;
	cout << "3) Display stack" << endl;
	cout << "4) Exit" << endl;
	do
	{
		cout << "Enter choice: " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "Enter value to be pushed:" << endl;
			cin >> val;
			push(val);
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 3:
		{
			display();
			break;
		}
		case 4:
		{
			cout << "Exit" << endl;
			break;
		}
		default:
		{
			cout << "Invalid Choice" << endl;
		}
		}
	} while (ch != 4);
	return 0;
}


//Input
//implementation of queue


#include <iostream>
	using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;
void Insert()
{
	int val;
	cout << "Insert the element in queue : " << endl;
	cin >> val;
	if (rear == NULL)
	{
		rear = (struct node *)malloc(sizeof(struct node));
		rear->next = NULL;
		rear->data = val;
		front = rear;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node));
		rear->next = temp;
		temp->data = val;
		temp->next = NULL;
		rear = temp;
	}
}
void Delete()
{
	temp = front;
	if (front == NULL)
	{
		cout << "Underflow" << endl;
		return;
	}
	else if (temp->next != NULL)
	{
		temp = temp->next;
		cout << "Element deleted from queue is : " << front->data << endl;
		free(front);
		front = temp;
	}
	else
	{
		cout << "Element deleted from queue is : " << front->data << endl;
		free(front);
		front = NULL;
		rear = NULL;
	}
}
void Display()
{
	temp = front;
	if ((front == NULL) && (rear == NULL))
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Queue elements are: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	int ch;
	cout << "1) Insert element to queue" << endl;
	cout << "2) Delete element from queue" << endl;
	cout << "3) Display all the elements of queue" << endl;
	cout << "4) Exit" << endl;
	do
	{
		cout << "Enter your choice : " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Display();
			break;
		case 4:
			cout << "Exit" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (ch != 4);
	return 0;
}
