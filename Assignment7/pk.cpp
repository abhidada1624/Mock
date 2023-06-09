#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define edge pair<int, int>
#define V 5



class graph{
    public:
        int d;
        unordered_map<int, list<int>> adj;
        graph()
        {
           // this->d = d;
    }


        vector<pair<int, edge> > G;  // graph
          vector<pair<int, edge> > T;  // mst
          int *parent;
          int Vk;  // number of vertices/nodes in graph
           public:
          graph(int Vk);
          void AddWeightedEdge(int u, int v, int w);
          int find_set(int i);
          void union_set(int u, int v);
          void kruskal();
          void print();





    void addedge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
    }

    void show(){
            vector<int> tatpurta;
            for (auto i : adj)
            {
                cout << i.first << "->";
                for (auto it : i.second)
                {
                    cout << it << "   ";
                }
                cout << endl;
        }
    }

    int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
	} 
};

graph::graph(int Vk) {
  parent = new int[Vk];
  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++){
    parent[i] = i;
  }
  G.clear();
  T.clear();
}


void graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int graph::find_set(int i) {

  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);
      union_set(uRep, vRep);
    }
  }
}
void graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  int cnt = 0;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cnt += T[i].first;
    cout << endl;
  }
  cout << "\nTotal cost : " << cnt << endl;
}
















int main() {
graph g(5);
int graphh[V][V];
int ch = -1;

cout << "\nEnter 5 edges weight row-wise" << endl;
for (int i = 0; i < V;i++){
   // cout << " Enter 5 Edges : " << endl;
    for (int j = 0; j < V;j++){
        cin >> graphh[i][j];
    }
}

int prev[V][V];
for (int i = 0; i < V;i++){
    for (int j = 0; j < V;j++){
        prev[i][j] = graphh[i][j];
    }
}

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (graphh[i][j] != 0)
            {
                if (graphh[j][i] != 0)
                {
                    g.addedge(i, j);
                    g.AddWeightedEdge(i, j, graphh[i][j]);
                    graphh[j][i] = 0;
                }
            }
            graphh[i][j] = prev[i][j];
        }

    }



while(ch){
    cout << " \n~~~~~~~ M E N U ~~~~~~ " << endl;
    cout << "1. Print adjacency list " << endl;
    cout << "2. print adjacency matrix " << endl;
    cout << "3. print minimum spanning tree (prims) " << endl;
    cout << "4. print minimum spanning tree(kruskal)" << endl;
    cout << "5. Break" << endl;
    cout << "\n Enter your choice : " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
            g.show();
            break;
    case 2:
            cout << "\nThe adjacency matrix is : " << endl<<endl;
            cout << " ";
            cout << endl;
            cout << " ";
            for (int i = 0; i < V;i++){
                cout <<i << " ";
            }
            cout << endl;
                  cout << "___________________________"<<endl;
            for (int i = 0; i < V; i++)
            {
                cout << i << "->";

                for (int j = 0; j < V; j++)
                {
                    cout << graphh[i][j] << " ";
                }
                cout << " ";
                cout << endl;
                }
            break;
    case 3:
            cout << "\n The minimum spannig tree with prims algorithm is " << endl;
            g.primMST(graphh);
            break;
    case 4:
    	cout<<"\n The minimum spanning tree  with kruskal algorithm is "<<endl;
    	g.kruskal();
    	g.print();
    	break;

            default:
                break;
    }
}
// 0 2 0 6 0
// 2 0 3 5 5
// 0 3 0 0 7
// 6 5 0 0 5
// 0 5 7 5 0
        // g.addedge(u, v);
        // }
        // cout << "printing graph" << endl;
        // g.show();

        // Print the solution

    g.show();

    return 0;
 }