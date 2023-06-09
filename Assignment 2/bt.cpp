#include<iostream>
#include<stack>
#include<queue>
using namespace std;


class node{
    public:
        node *left;
        node *right;
        int data;
        node(int d){
            this->left = NULL;
            this->right = NULL;
            this->data = d;
        }
        node(){
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
        node*copytree(node*&root){
            node *copy = new node(root->data);
            copy->left = copytree(root->left);
            copy->right = copytree(root->right);
            return copy;
        }

        node*operator==(node*root){
            root = copytree(root);
            return root;
        }


// ****************************************** R E C U R S I V E ******************************************************

        node*insert(node*&root){
            int d;
            char ch;
            cout << "\nEnter data ? " << endl;
            cin >> d;
            root = new node(d);
            cout << "Do you want left of " << d << endl;
            cin >> ch;
            if(ch=='y'|| ch=='Y'){
                cout << "Enter left of : " << d << endl;
                root->left = insert(root->left);
            }
            cout << "Do you want Right of " << d << endl;
            cin >> ch;
            if(ch=='y'|| ch=='Y'){
                cout << "Enter Right of : " << d << endl;
                root->right = insert(root->right);
            }
            return root;
        }

        void inorder(node*&root){
            if(root==NULL){
                return;
            }
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }

        void preorder(node*&root){
            if(root==NULL){
                return;
            }
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }

        void postorder(node*&root){
            if(root==NULL){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }

        int height(node*&root){
            if(root==NULL){
                return 0;
            }
            int l = height(root->left);
            int r = height(root->right);
            int ans = 1 + max(l, r);
            return ans;
        }

        int leafrecc(node*&root){
            if(root==NULL){
                return 0;
            }
            if(root->left==NULL && root->right==NULL){
                return 1;
            }
            int l = leafrecc(root->left);
            int r = leafrecc(root->right);
            return l + r;
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

        int internalnode(node*&root){
            if(root==NULL ||(root->left==NULL && root->right==NULL)){
                return 0;
            }
            int l = internalnode(root->left);
            int r = internalnode(root->right);
            return l + r + 1;
        }









// ************************************ I T E R A T I V E ***********************************************************


        int leafnodes(node*&root){
            queue<node *> q;
            q.push(root);
            int cnt = 0;
            while(!q.empty()){
                node *temp = q.front();
                q.pop();
                if(temp->left==NULL && temp->right==NULL){
                    cnt++;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            return cnt;
        }

        int internalnode_iter(node*&root){
            queue<node*>q;
            q.push(root);
            int cnt = 0;
            while(!q.empty()){
                node *temp = q.front();
                q.pop();
                if( (temp->left!=NULL || temp->right!=NULL) || (temp->left!=NULL && temp->right!=NULL) ){
                    cnt++;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

            }

            return cnt;
        }

        void inorder_iter(node*&root){
            stack<node *> st;
             node *temp = root;
          //  st.push(temp);
            while(!st.empty() || temp!=NULL){
                while(temp!=NULL){
                    st.push(temp);
                    temp = temp->left;
                }
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
        }


        void preorder_iter(node*&root){
            stack<node *> st;
            st.push(root);
            while(!st.empty()){
                node *temp = st.top();
                st.pop();
                cout << temp->data << " ";
                if(temp->right){
                    st.push(temp->right);
                }
                if(temp->left){
                    st.push(temp->left);
                }
            }
        }

        void postorder_iter(node*&root){

            stack<node *> st;
            stack<int> s;
            st.push(root);
            while(!st.empty()){
                node *temp = st.top();
                st.pop();
                s.push(temp->data);
                if(temp->left){
                    st.push(temp ->left);
                }
                if(temp->right){
                    st.push(temp->right);
                }
            }
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
        }


int internalnodes_iterr(node *root)
{
    queue<node *> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if ((temp->left != NULL && temp->right != NULL) || (temp->left==NULL && temp->right!=NULL) || (temp->left!=NULL && temp->right==NULL))
        {
            count++;
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return count-1;
}


void levelorder(node*&root){
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


};


int main(){
        node obj;
        node *root = NULL;
        obj.insert(root);
        cout << "preorder : ";
     //   obj.postorder_iter(root);
        cout<<endl;
        obj.levelorder(root);
        cout <<"\n"<< obj.internalnodes_iterr(root);
        // obj.swap(root);
        // cout << "\nAfter swap : ";
        // obj.inorder_iter(root);
       
        // cout << "\nPostorder :";
        // obj.postorder(root);
        // cout << "\nPreorder : ";
        // obj.preorder(root);
        // cout << "\nHeight : ";
        // cout << obj.height(root);
        // cout << "\nLeaf nodes Iterative : ";
        // cout << obj.leafnodes(root);
        // cout<<"\nLeaf Nodes Recursive : ";
        // cout << obj.leafrecc(root);
}