#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	node *left;
	node *right;
	int data;
	bool lthread;
	bool rthread;
	node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
		this->lthread = true;
		this->rthread = true;
	}
	node()
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->lthread = true;
		this->rthread = true;
	}
	friend class tbt;
};

class tbt
{
public:
	node *root;
	tbt()
	{
		this->root = NULL;
	}
	void insert(int key)
	{
		if (root == NULL)
		{
			node *temp = new node(key);
			root = temp;
			return;
		}
		node *temp = new node(key);
		node *curr = root;
		while (curr != NULL)
		{
			if (curr->data > key)
			{
				if (curr->lthread == false)
				{
					curr = curr->left;
				}
				else
				{
					curr->lthread = false;
					temp->right = curr;
					temp->left = curr->left;
					curr->left = temp;
					return;
				}
			}
			else if (curr->data < key)
			{
				if (curr->rthread == false)
				{
					curr = curr->right;
				}
				else
				{
					curr->rthread = false;
					temp->left = curr;
					temp->right = curr->right;
					curr->right = temp;
					return;
				}
			}
			else
			{
				cout << "\nNode is already present " << endl;
				return;
			}
		}
	}

	node *leftmost(node*temp)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		while (temp->left != NULL)
		{
			if (temp->lthread)
			{
				return temp;
			}
			temp = temp->left;
		}
		return temp;
	}

	void inorder()
	{
		node *temp = leftmost(root);
		while (temp != NULL)
		{
			cout << temp->data << " ";
			if (temp->rthread)
			{
				temp = temp->right;
			}
			else
			{
				temp = leftmost(temp->right);
			}
		}
	}

	void deletion(int key)
	{
		node *temp = root;
		node *par = NULL;
		while (temp->data != key)
		{
			par = temp;
			if (temp->data > key)
			{
				if (temp->lthread == false)
				{
					temp = temp->left;
				}
				else
				{
					cout << "\nNode is not present : " << endl;
					return;
				}
			}
			else if (temp->data < key)
			{
				if (temp->rthread == false)
				{
					temp = temp->right;
				}
				else
				{
					cout << "\nNode is not present : " << endl;
					return;
				}
			}
		}

		// 0 child
		if (temp->lthread && temp->rthread)
		{
			cout << "\nleaf node" << endl;
			if (par == NULL)
			{
				root = NULL;
				return;
			}
			if (par->data > temp->data)
			{
				par->left = temp->left;
				par->lthread = true;
				delete temp;
			}
			else
			{
				par->right = temp->right;
				par->rthread = true;
				delete temp;
			}
		}
		// left child
		else if (!temp->lthread && temp->rthread)
		{
			cout << "\nLeft child present" << endl;
			node *need = temp->left;
			while (need->rthread==false)
			{
				need = need->right;
			}
			need->right = temp->right;
			if (par == NULL)
			{
				root = temp->left;
			}
			else if (par->data > temp->data)
			{
				par->left = temp->left;
			}
			else
			{
				par->right = temp->left;
			}
			delete temp;
		}

		else if (temp->lthread && !temp->rthread)
		{
			cout << "\nRight child present" << endl;
			node *need = temp->right;
			while (need->lthread==false)
			{
				need = need->left;
			}
			need->left = temp->left;
			if (par == NULL)
			{
				root = temp->right;
			}
			else if (par->data > temp->data)
			{
				par->left = temp->right;
			}
			else
			{
				par->right = temp->right;
			}
			delete temp;
		}
		else
		{
			
			cout << "Both child is present : " << endl;
			node *pred = temp->left;
			node *succ = temp->right;
			while (pred->right ==false)
			{
				pred = pred->right;
			}
			while (succ->left ==false)
			{
				succ = succ->left;
			}

			if (par == NULL)
			{
				root = temp->left;
			}
			else
			{
				if (par->data < temp->data)
				{
					par->right = temp->left;
				}
				else
				{
					par->left = temp->left;
				}
			}
			pred->right = temp->right;
			pred->rthread = false;
			succ->left = pred;
			delete temp;
		}
	}
};

int main()
{
	tbt obj;
	obj.insert(3);
	obj.insert(4);
	obj.insert(5);
	obj.insert(6);
	obj.insert(1);
	//obj.insert(2);
	obj.insert(0);
	obj.inorder();
	obj.deletion(1);
	cout << endl;
	obj.inorder();
}