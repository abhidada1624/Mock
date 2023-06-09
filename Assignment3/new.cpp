#include<iostream>
using namespace std;

class node{
	public:
	node*left;
	node *right;
	int data;
	bool lthread;
	bool rthread;
	node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
		this->lthread = true;
		this->rthread = true;
	}
	node(){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->lthread = true;
		this->rthread = true;
	}
	friend class tbt;
};

class tbt{
	public:
		node *root;
		tbt(){
		this->root = NULL;
		}
		void insert(int key){
			if(root==NULL){
				node *temp = new node(key);
				root = temp;
				return;
			}
			node *temp = new node(key);
			node *curr = root;
			while(curr!=NULL){
				if(curr->data > key){
					if(curr->lthread==false){
						curr = curr->left;
					}
					else{
						curr->lthread = false;
						temp->right = curr;
						temp->left = curr->left;
						curr->left = temp;
						return;
					}
				}
				else if(curr->data < key){
					if(curr->rthread==false){
						curr = curr->right;
					}
					else{
						curr->rthread = false;
						temp->left = curr;
						temp->right = curr->right;
						curr->right = temp;
						return;
					}
				}
				
			}
		}

		node*leftmost(node*rooot){
			if(rooot==NULL){
				return NULL;
			}
			while(rooot->left!=NULL){
				if(rooot->lthread) {
					return rooot;
				}
				rooot = rooot->left;
			}
			return rooot;
		}

		void inorder(){
			if(root==NULL){
				cout << "\nEmpty tree : " << endl;
				return;
			}
			node *temp = leftmost(root->left);
			while(temp!=NULL){
				cout << temp->data << " ";
				if(temp->rthread){
					temp = temp->right;
				}
				else{
					temp = leftmost(temp->right);
				}
			}
		}


		void del(int key){
			node*temp = root;
			node *par = NULL;
			while(temp->data!=key){
				par = temp;
				if(temp->data > key){
					if(!temp->lthread){
						temp = temp->left;
					}
					else{
						cout << "\nNode not found " << endl;
						return;
					}

				}
				else if(temp->data < key){
						if(!temp->rthread){
						temp = temp->right;
					}
					else{
						cout << "\nNode not found " << endl;
						return;
					}

				}
			}

			// 0 childe
			if(temp->lthread && temp->rthread){
				if(par==NULL){
					root = NULL;
					return;
				}
				cout << "\nBoth child absent : " << endl;
				if(par->data > temp->data){
					par->left = temp->left;
					par->lthread = true;
					delete temp;
				}
				else{
					par->right = temp->right;
					par->rthread = true;
					delete temp;
				}
			}

			// left child

			else if(!temp->lthread &&  temp->rthread){

				cout << "\nOnly left child present : " << endl;
				node *need = temp->left;
				while(need->rthread==false){
					need = need->right;
				}
				need->right = temp->right;
				if(par==NULL){
					root = temp->left;
				}
				else if(par->data > temp->data){
					par->left = temp->left;
				}
				else{
					par->right = temp->left;
				}
				delete temp;

			}

			// right child
			else if(temp->lthread && !temp->rthread){
				cout << "\nOnly left child present : " << endl;
				node *need = temp->right;
				while(need->lthread==false){
					need = need->left;
				}
				need->left = temp->left;
				if(par==NULL){
					root = temp->right;
				}
				else if(par->data > temp->data){
					par->left = temp->right;
				}
				else{
					par->right = temp->right;
				}
				delete temp;
			}


			// both child present

			else{
				cout << "\nBoth child is present ; " << endl;
				node *pred = temp->left;
				node *succ = temp->right;
				while(pred->rthread==false){
					pred = pred->right;
				}
				while(succ->lthread==false){
					succ = succ->left;
				}

				if(par==NULL){
					root = temp->left;
				}
				else{
					if(par->data < temp->data){
						par->right = temp->left;
					}
					else{
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


int main(){
		tbt obj;
		obj.insert(9);
		obj.insert(3);
		obj.insert(14);
		obj.insert(7);
		obj.insert(6);
		obj.insert(4);
		obj.insert(1);
		obj.inorder();
		cout << endl;
		obj.del(3);
		obj.inorder();
}



