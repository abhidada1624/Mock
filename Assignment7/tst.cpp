#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>

// 0 5 0 0 2
// 5 0 4 6 0
// 0 4 0 8 7
// 0 6 8 0 9
// 2 0 7 9 0

class graph{
    public:

    graph(){}
    vector<pair<int, edge>> G;
    vector < pair<int, edge>>T;
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

    void unionset(int u, int v){
        parent[u] = parent[v];
    }
    void addwt(int u, int v, int w){
        G.push_back(make_pair(w, edge(u, v)));
    }
    void kruskal(){
        int utemp;
        int vtemp;
        sort(G.begin(), G.end());
        for (int i = 0; i < 5;i++){
            utemp = findset(G[i].second.first);
            vtemp = findset(G[i].second.second);
            if(utemp!=vtemp){
                T.push_back(G[i]);
                unionset(utemp, vtemp);
            }
        }
    }

    void printt(){
        cout << "Edge :-"<< "\tweight" << endl;

        for (int i = 0; i < 5;i++){
            cout << T[i].second.first << "-" << T[i].second.second << "\t" << T[i].first<<endl;
        }
    }

    unordered_map<int,list<int>>adj;
    void addedge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void show(){
        for(auto it:adj){
            cout << it.first << "->";
            for(auto i:it.second){
                cout << i << ",";
            }
            cout << endl;
        }
    }
    int minkey(int parent[], bool mst[]){
        int minnode;
        int min = INT_MAX;
        for (int i = 0; i < 5;i++){
            if(parent[i]<min && mst[i]==false){
                min = parent[i];
                minnode = i;
            }
        }
        return minnode;
    }

     void printmst(int parent[],int graph[5][5]){
        cout<<"Edge\tweight:"<<endl;
        for (int i = 1; i < 5;i++){
            cout << parent[i] << "-" << i << "\t" << graph[i][parent[i]] << endl;
        }
    }

    void prims(int graph[5][5]){
        int key[5];
        bool mst[5];
        int parent[5];
        for (int i = 0;i<5;i++){
            mst[i] = false;
            key[i] = INT_MAX;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < 4;count++){
            int u = minkey(parent, mst);
            mst[u] = true;
            for (int v = 0;v<5;v++){
                if(graph[u][v] && mst[v]==false && graph[u][v] <key[v]){
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
        printmst(parent, graph);
    }
};


int main(){
    graph g(5);
    int arr[5][5];
    int store[5][5];
    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5;j++){
            cin>>arr[i][j];
            store[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5;j++){
            if(arr[i][j]!=0){
                if(arr[j][i]!=0){
                    g.addedge(i, j);
                    g.addwt(i, j, arr[i][j]);
                    arr[j][i] = 0;
                }
            }
            arr[i][j] = store[i][j];
        }
    }

    cout << endl;
    g.prims(arr);
    cout << endl;
    g.kruskal();
    g.printt();
}