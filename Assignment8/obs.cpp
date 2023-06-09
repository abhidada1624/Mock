#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        node *left;
        node *right;
        int data;
        int val;
        node(int d){
            this->data = d;
            this->val = val;
            this->left=NULL;
            this->right = NULL;
        }
        friend class obst;
};

class obj{
    public:
        int rt;
        int wt;
        obj(){
            this->rt = -1;
            this->wt = -1;
        }
};
class obst{
    public:
        obj arr[50][50];
        int *keys;
        int *freq;
        int size;
        node *root;
        obst(int n){
            this->root = NULL;
            this->size = n;
            this->keys = new int[size];
            this->freq = new int[size];
        }

        void getelements(){
            cout << "\nEnter keys in sorted order : " << endl;
            for (int i = 0; i < size;i++){
                cout<<"\nEnter keys :"<<endl;
                cin >> keys[i];
                cout << "\nEnter Frequencies : " << endl;
                cin >> freq[i];
            }
        }

        int getfreq(int i,int j, int f[]){
            int sum = 0;
            for (int k = i; k <= j;k++){
                sum += f[k];
            }
            return sum;
        }

        node*insert(node*root,int key){
            if(root==NULL){
                root = new node(key);
                return root;
            }
            else if(root->data >key){
                root->left = insert(root->left, key);
            }
            else{
                root->right = insert(root->right, key);
            }
            return root;
        }

        void addnode(int k){
            root = insert(root, k);
        }
        void maketree(int i,int j,int k[]){
            if(i>j){
                return;
            }
            if(i==j){
                addnode(keys[i]);
                return;
            }
            if(i<j){
                addnode(keys[arr[i][j].rt]);
                maketree(i, arr[i][j].rt - 1, keys);
                maketree(arr[i][j].rt + 1, j, keys);
            }
            return;
        }

        void inorder(node*r){
            if(r==NULL){
                return;
            }
            inorder(r->left);
            cout << r->data<< " ";
            inorder(r->right);
        }

        void buildtree(){
            maketree(0, size - 1, keys);
        }

        int cost(int i,int j,int f[]){
            if(i>j){
                return 0;
            }
            if(i==j){
                arr[i][j].rt=i;
                arr[i][j].wt = f[i];
            }
            if(arr[i][j].wt!=-1){
                return arr[i][j].wt;
            }
            int weight = getfreq(i, j, freq);
            int val = 9999;
            int nodee = 0;
            for (int k = i; k <=j;k++){
                int m = cost(i, k - 1, freq) + cost(k + 1, j, freq);
                if(val>m){
                    val = m;
                    nodee = k;
                }
            }
            arr[i][j].wt = weight + val;
            arr[i][j].rt = nodee;
            return arr[i][j].wt;
        }
        void optcost(){
            int ans = cost(0, size - 1, freq);
            cout << "\nThe minimum cost is : " << ans << endl;
        }
};



int main(){
        obst obj(3);
        obj.getelements();
        obj.optcost();
        obj.buildtree();
        obj.inorder(obj.root);
        return 0;
}