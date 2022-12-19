/*
Title  :  Write a C++ program to construct a binary search tree and perform insertion, deletion, searching of a node and
	its traversal.

Author  : Sahil Dhargave

*/

#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

struct node *newnode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

struct node *insert(struct node *node, int data)
{
	if (node == NULL)
	{
		return newnode(data);
	}
	if (data < node->data)
	{
		node->left = insert(node->left, data);
	}
	else
	{
		node->right = insert(node->right, data);
	}
	return node;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << "-->";
		inorder(root->right);
	}
}
int search(struct node *root, int data)
{
	int flag = 0;
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		flag = 1;
		return flag;
	}
	if (data < root->data)
	{
		search(root->left, data);
		flag = 1;
		return flag;
	}
	if (data > root->data)
	{

		search(root->right, data);
		flag = 1;
		return flag;
	}
}

int main()
{
	int choice, ch, key, flag;
	struct node *root = NULL;
	do
	{

		cout << "\n----BINARY SEARCH TREE OPERATIONS----";
		cout << "\n1.Insert Node\n2.Display All Nodes(Inorder Traversal\n3.Search Node\n4.Delete Node\n5.Exit";
		cout << "\nEnter Your Choice :";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n Enter Value of node:";
			cin >> key;
			root = insert(root, key);
			break;
		case 2:
			cout << "\nInorder Traversal...";
			inorder(root);
			break;
		case 3:
			cout << "\nEnter Node Value to search:";
			cin >> key;
			flag = search(root, key);
			if (flag == 1)
			{
				cout << "\nNode Value Found..";
			}
			else
			{
				cout << "\nData Not Found..";
			}
			break;
		case 4:

			break;
		case 5:

			break;
		}
		cout << "\nDo You Want to continue press 1:";
		cin >> choice;
	} while (choice == 1);

	return 0;
}
