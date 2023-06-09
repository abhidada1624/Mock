#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node{
    public:
    node*left;
    node *right;
    int data;
    node(int d){
        this->data = d;
        this-> left = NULL;
        this->right = NULL;
    }
    node(){
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }

    node*insertatbst(node*&root,int d){
        if(root==NULL){
            root = new node(d);
            return root;
        }
        else if(root->data > d){
            root->left = insertatbst(root->left, d);
        }
        else{
            root->right = insertatbst(root->right, d);
        }
        return root;
    }

    void getelments(node*&root){
        int d;
        cout << "\nEnter data " << endl;
        cin>>d;
        while(d!=-1){
            root = insertatbst(root, d);
            cin >> d;
        }
    }

    void inorder(node*&root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout << root->data<<" ";
        inorder(root->right);
    }

    int height(node*&root){
        if(root==NULL){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        int ans = max(l, r);
        return ans+1;
    }

    int minimum(node*&root){
        node*temp = root;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp->data;
    }

    void levelorderdisplay(node*&root){
        queue<node *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node *temp = q.front();
            q.pop();
            if(temp==NULL){
                cout << endl;
                if(!q.empty()){
                q.push(NULL);
                }
            }
            else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void search(node*&root,int d){
    if(root->data==d){
        cout << "\nThe given Number is present in the tree !!! " << endl;
    }
    else if(root->data >d){
        search(root->left,d);
    }
    else if(root->data < d){
        search(root->right, d);
    }
    else{
        cout << "\nNot found !!! " << endl;
        }
    

}

node*deletenode(node*&root,int d){
    if(root==NULL){
        return NULL;
    }
    if(root->data==d){
        // 0 node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 node left
        if(root->left!=NULL && root->right==NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        // 1 node right

         if(root->left==NULL && root->right!=NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 node
        if(root->left!=NULL && root->right!=NULL){
            int mini = minimum(root->right);
            root->data = mini;
            root->right = deletenode(root->right, mini);
            return root;
        }

    }

    else if(root->data>d){
        root->left = deletenode(root->left, d);
    }
    else{
        root->right = deletenode(root->right, d);
    }
    return root;
}

void swap(node*&root){
    if(root==NULL){
        return;
    }
    swap(root->left);
    swap(root->right);
    node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

}

};


int main(){
int d;
node obj;
node *root = NULL;
obj.getelments(root);
//obj.inorder(root);
//cout << "The Levelorder display is : " << endl;
cout << "\n BEFORE  : " << endl;
obj.levelorderdisplay(root);

cout << endl;
while(true){
cout << "Enter to search ? "
     << endl;

cin >> d;
obj.search(root, d);}
// cout << "\nAfter swapping : " << endl;
// obj.swap(root);
// obj.levelorderdisplay(root);

// cout << "\nThe height is : " << obj.height(root);
}