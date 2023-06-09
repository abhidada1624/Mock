#include<bits/stdc++.h>
using namespace std;
class prims{
    public:
    prims(){}
    unordered_map<int, list<int>> adj;
    void addEdge(int u,int v){
         adj[u].push_back(v);
        adj[v].push_back(u);
       
    }

    int minkey(int key[],bool mst[]){
        int min = INT_MAX;
        int minnode;
        for (int i = 0; i < 5;i++){
            if(key[i]<min && mst[i]==false){
                min = key[i];
                minnode = i;
            }
        }

        return minnode;
    }

    void printmst(int parent[],int graph[5][5]){
        for (int i = 1; i < 5;i++){
            cout  << parent[i] << " - "<< i << " \t " << graph[i][parent[i]]<<endl;
        }
    }

    void primss(int grap[5][5]){
        int key[5];
        bool mst[5];
        int parent[5];

        for (int i = 0; i < 5;i++)
        {
            mst[i] = false;
            key[i] = INT_MAX;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < 4;count++){
            int u = minkey(key, mst);
            mst[u] = true;
            for (int v = 0; v < 5;v++){
                if(grap[u][v] && key[v]>grap[u][v] && mst[v]==false){
                    key[v] = grap[u][v];
                    parent[v] = u;
                }
            }
        }
        printmst(parent, grap);
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
};


int main(){
    prims obj;
    int ch = -1;
    int grap[5][5];
    int store[5][5];
    
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> grap[i][j];
                store[i][j] = grap[i][j];
            }
        }

    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5;j++)
        {
            if(grap[i][j]!=0){
                if(grap[j][i]!=0){
                    obj.addEdge(i, j);
                    grap[j][i] = 0;
                }
                
            }
            grap[i][j] = store[i][j];
        }
    }

    cout << "\nAdjacency list : " << endl;
    obj.show();
    cout << "Minimum cost ? " << endl;
    obj.primss(grap);
}