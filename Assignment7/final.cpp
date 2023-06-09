#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>

class graph{
    public:
        unordered_map<int, list<int>> adj;
        vector<pair<int, edge>> G;
        vector<pair<int, edge>> T;
        int *parent;
        graph(int vk){
            parent = new int[vk];
            for (int i = 0; i < 5;i++){
                parent[i] = i;
            }
            G.clear();
            T.clear();
        }
        int findset(int i){
            if(i==parent[i]){
                return i;
            }
            else{
                return findset(parent[i]);
            }
        }

        void addwt(int u,int v,int w){
            G.push_back(make_pair(w, edge(u, v)));
        }
        void unionn(int u, int v){
            parent[u] = parent[v];
        }

        void kruskal(){
            int utemp;
            int vtemp;
            sort(G.begin(),G.end());
            for (int i = 0; i < G.size();i++){
                utemp = findset(G[i].second.first);
                vtemp = findset(G[i].second.second);
                if(utemp!=vtemp){
                    T.push_back(G[i]);
                    unionn(utemp, vtemp);
                }
            }
        }

        void printt(){
            cout<<"\nEdge \t "<<"Weight"<<endl;
            for (int i = 0; i < T.size();i++){
                cout << T[i].second.first << "-" << T[i].second.second << "\t" << T[i].first << endl;
            }

        }
        

        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int minkey(int key[5], bool mst[5]){
            int min = INT_MAX;
            int minnode;
            for (int i = 0; i < 5;i++){
                if(mst[i]==false && key[i]<min){
                    min = key[i];
                    minnode = i;
                }
            }
            return minnode;
        }

        void printmst(int parent[],int grap[5][5]){
            cout << "Edge \t Weight :" << endl;
            for (int i = 1;i<5;i++){
                cout << parent[i] << "-" << i << "\t" << grap[i][parent[i]] << endl;
            }
        }

        void prims(int grap[5][5]){
            int key[5];
            bool mst[5];
            int parent[5];
            for (int i = 0; i < 5;i++){
                key[i] = INT_MAX;
                mst[i] = false;
            }
            key[0] = 0;
            parent[0] = -1;
            for (int count = 0; count < 5;count++){
                int u = minkey(key, mst);
                mst[u] = true;
                for (int v = 0;v<5;v++){
                    if(grap[u][v] && mst[v]==false && key[v]>grap[u][v]){
                        key[v] = grap[u][v];
                        parent[v] = u;
                    }
                }
            }
            printmst(parent, grap);
        }
};


int main(){
    graph obj(5);
    int arr[5][5];
    int store[5][5];
    for (int i = 0; i < 5;i++){
            for (int j = 0; j < 5;j++){
                cin >> arr[i][j];
                store[i][j] = arr[i][j];
            }
    }
    for (int i = 0;i<5;i++){
            for (int j = 0; j < 5;j++){
                if(arr[i][j]!=0){
                    if(arr[j][i]!=0){
                        obj.addEdge(i, j);
                        obj.addwt(i, j,arr[i][j]);
                        arr[j][i] = 0;
                    }
                }
                arr[i][j] = store[i][j];
            }
    }

    int ch =-1;
    while(ch){
            cout << "***** M E N U *****" << endl;
            cout<<"1.Prims"<<endl;
            cout << "2.Kruskal" << endl;
            cout << "\nEnter your choice : ";
            cin>>ch;
            switch (ch)
            {
            case 1:
                obj.prims(arr);
                break;
            case 2:
            obj.kruskal();
            obj.printt();
            break;

            default:
                break;
            }
    }
}