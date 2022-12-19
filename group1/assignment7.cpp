/*
Title :   Write a C++ program for the implementation of BFS and DFS for a given graph
Author  :- Sahil Dhargave
*/

#include <iostream>
using namespace std;
class Stack
{
public:
	int a[100];
	int top = 0;
	void push(int n);
	int pop();
} s;
class Queue
{
public:
	int a[100];
	int rear = -1, front = -1;
	void insert(int k);
	int remove();
} q;
class graph
{
public:
	int n;
	int count = 0;
	int v[100];

	int status[100];
	int adj[100][100];
	graph();
	void DFS(int);
	void BFS(int);
};
graph::graph()
{
	cout << "Enter number of vertices:";
	cin >> n;
	cout << "Enter values of vertices :";
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		status[i] = 0;
	}
	cout << "Enter Adjacancy Marix :";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
		}
	}
}
void graph::BFS(int first)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (v[i] == first)
		{
			status[i] = 1;
			break;
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (adj[i][j] == 1)
		{
			if (status[j] != 1)
			{
				q.insert(v[j]);
				status[j] = 1;
			}
		}
	}
	int y = q.remove();
	cout << y << " ";
	count++;
	if (count < n)
	{
		first = q.a[q.front];
		BFS(first);
	}
}
void graph::DFS(int first)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (v[i] == first)
		{
			status[i] = 1;
			break;
		}
	}
	int y = s.pop();
	cout << y << " ";
	count++;
	for (int j = 0; j < n; j++)
	{
		if (adj[i][j] == 1)
		{

			if (status[j] != 1)
			{
				s.push(v[j]);
				status[j] = 1;
			}
		}
	}

	if (count < n)
	{
		first = s.a[s.top - 1];
		DFS(first);
	}
}
void Queue::insert(int k)
{
	if (front == -1 && rear == -1)
	{
		front++;
	}
	rear++;
	a[rear] = k;
}
int Queue::remove()
{
	front++;
	return a[front - 1];
}
void Stack::push(int n)
{
	a[top] = n;
	top++;
}
int Stack::pop()
{
	top--;
	return a[top];
}
int main()
{
	graph g;
	int x;
	int op;
	while (true)
	{
		cout << "\n1.BFS\t2.DFS\t3.Exit\n";
		cout << "Select an option:";
		cin >> op;
		switch (op)
		{

		case 1:
			cout << "Enter First vertex:";
			cin >> x;
			q.insert(x);
			g.count = 0;
			g.BFS(x);
			for (int k = 0; k < g.n; k++)
			{
				g.status[k] = 0;
			}
			break;
		case 2:
			cout << "Enter First vertex:";
			cin >> x;
			s.push(x);
			g.count = 0;
			g.DFS(x);
			for (int k = 0; k < g.n; k++)
			{
				g.status[k] = 0;
			}
			break;
		case 3:
			exit(1);
		default:
			cout << "Select proper statement \n";
		}
	}
}
