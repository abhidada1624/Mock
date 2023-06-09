#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        string key;
        node *next;
        node(string k){
            this->key = k;
            this->next = NULL;
        }
        friend class grap;
};

class grap{
    public:
        node **arr;
        int size;
        grap(int n){
            this->size = n;
            this->arr = new node *[size];
            for (int i = 0; i < size;i++){
                arr[i] = NULL;
            }
        }

        int searchindex(node*n){
            for (int i = 0;i<size;i++){
                if(arr[i]==n){
                    return i;
                }
            }
            return -1;
        }

        node*searchkey(string s){
            for (int i = 0; i < size;i++){
                if(arr[i]->key==s){
                    return arr[i];
                }
            }
            return NULL;
        }




        void getelemtes(){
            cout << "Enter landmarks : " << endl;
            for (int i = 0; i < size;i++){
                string k;
                cin >> k;
                node *temp = new node(k);
                arr[i] = temp;
            }
            for (int i = 0; i < size;i++){
                 int n;
                 string k;
                 cout << "How many elements are adjacent to : " << arr[i]->key << endl;
                 cin >> n;

                 for (int j = 0; j < n; j++)
                 {
                     cout << "\nEnter adjacent no." << j + 1 << endl;
                     cin >> k;
                     node *temp = new node(k);
                     node *tem = arr[i];
                     while(tem->next){
                         tem = tem->next;
                     }
                     tem->next = temp;
                }
            }
        }

        void bfs(string s){
            bool visited[size] = {false};
            queue<node *> q;
            node *Start = searchkey(s);
            q.push(Start);
            visited[searchindex(Start)] = true;
            while(!q.empty()){
                node *temp = q.front();
                cout << temp->key << " ";
                q.pop();
                temp = temp->next;
                while(temp){
                if(visited[searchindex(searchkey(temp->key))]==false){
                     visited[searchindex(searchkey(temp->key))] = true;
                     q.push(searchkey(temp->key));
                }
                temp = temp->next;
                }
            }
        }

          void dfs(string s){
            bool visited[size] = {false};
            stack<node *> q;
            node *Start = searchkey(s);
            q.push(Start);
            visited[searchindex(Start)] = true;
            while(!q.empty()){
                node *temp = q.top();
                cout << temp->key << " ";
                q.pop();
                temp = temp->next;
                while(temp){
                if(visited[searchindex(searchkey(temp->key))]==false){
                     visited[searchindex(searchkey(temp->key))] = true;
                     q.push(searchkey(temp->key));
                }
                temp = temp->next;
                }
            }
        }

        void print(){
            for (int i = 0; i < size;i++){
                cout << i << arr[i]->key << " -> ";
                node *temp = arr[i]->next;
                while(temp){
                    if(temp->next==NULL){
                     cout << temp->key << " ";
                    }
                    else{
                     cout << temp->key << " ";
                    }
                    temp = temp->next;
                }
            }
        }


};


int main(){
        int n;
        cout << "\nEnter how many Landmarks ? " << endl;
        cin >> n;
        grap obj(n);
        int ch = -1;
        string bf, df;
        while(ch){
            cout << "1.Create Graph " << endl;
            cout << "2.Print Graph" << endl;
            cout << "3.DFS traversal " << endl;
            cout << "4.BFS Traversal " << endl;
            cout << "5.exit" << endl;
            cout << "Enter your choice ?" << endl;
            cin >> ch;
            switch(ch){
                case 1:
                obj.getelemtes();
                break;
                case 2:
                obj.print();
                break;
                case 3: 
                cout << "Enter starting node ?" << endl;
                cin >> bf;
                obj.bfs(bf);
                break;
                case 4:
                 cout << "Enter starting node ?" << endl;
                cin >> df;
                obj.dfs(df);
                break;
                case 5:
                exit(0);
                break;
                default:
                break;
            }
        }
}