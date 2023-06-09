#include<iostream>
using namespace std;

class node{
    public:
    node*left;
    node*right;
    int data;
    bool lthread;
    bool rthread;
    node(){
        this->left = NULL;
        this->right = NULL;
        this->data = data;
        this->lthread = true;
        this->rthread = true;
    }
    node(int d){
        this->left = NULL;
        this->right = NULL;
        this->data = d;
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
        }
        node *curr = root;
        node *temp = new node(key);
        while(curr!=NULL){
                if(curr->data > key){
                    if(curr->lthread==false){
                        curr = curr->left;
                    }
                    else{
                        curr->lthread = false;
                        temp->left = curr->left;
                        temp->right = curr;
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
                        temp->right = curr->right;
                        temp->left = curr;
                        curr->right = temp;
                        return;
                    }
                }

                // else{
                //     cout << "\nDuplicate entry" << endl;
                //     return;
                // }
        }
    }

    node*leftmost(node*&rooot){
        if(rooot==NULL){
                return NULL;
        }
        node *temp = rooot;
        while(temp->lthread==false){
            if(temp->lthread){
                    return temp;
            }
            temp = temp->left;
        }
        return temp;
    }

    void inorder(){
        if(root==NULL){
            cout<<"\nTree is empty"<<endl;
        }
        node *temp = leftmost(root);
        while (temp!=NULL)
        {
            cout << temp->data << " ";
            if(temp->rthread){
                    temp = temp->right;
            }
            else{
                    temp = leftmost(temp->right);
            }
        }
        
    }
};


int main(){
    tbt obj;
    obj.insert(34);
    obj.insert(12);
    obj.insert(45);
  
    obj.inorder();
    return 0;
}