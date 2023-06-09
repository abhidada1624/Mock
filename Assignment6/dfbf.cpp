
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
class node
{
    string name;
    node *link;
    friend class Graph;

public:
    node(string s)
    {
        this->name = s;
        this->link = NULL;
    }
};

class Graph
{
    int size;
    node **arr;

public:
    Graph(int n)
    {
        this->size = n;
        arr = new node *[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
    }

    node *SearchNode(string s)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i]->name == s)
            {
                return arr[i];
            }
        }
        return NULL;
    }

    int SearchIndex(node *n)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == n)
            {
                return i;
            }
        }
        return -1;
    }

    void CreateGraph()
    {
        cout << "Enter the landmarks : " << endl;
        for (int i = 0; i < size; i++)
        {
            string ver_name;
            cout << "Enter the name of landmark no." << i + 1 << " : ";
            cin >> ver_name;
            node *newnode = new node(ver_name);
            arr[i] = newnode;
        }
        for (int i = 0; i < size; i++)
        {
            int n;
            cout << "Enter the no. of adjacent landmarks to " << arr[i]->name << " : ";
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                string name1;
                cout << "Enter the name of adjacent landmark no." << j + 1 << " : ";
                cin >> name1;
                node *newd = new node(name1);
                node *temp = arr[i];
                while (temp->link)
                {
                    temp = temp->link;
                }
                temp->link = newd;
            }
        }
    }

    void PrintGraph()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " : " << arr[i]->name << " ->";
            node *temp = arr[i]->link;
            while (temp)
            {
                if (temp->link == NULL)
                {
                    cout << temp->name << " ";
                }
                else
                {
                    cout << temp->name << " ";
                }

                temp = temp->link;
            }
            cout << endl;
        }
    }

    void BFS(string ver)
    {
        cout << "BFS : ";
        bool visited[size] = {false};
        queue<node *> q;
        node *start = SearchNode(ver);
        visited[SearchIndex(start)] = true;
        q.push(start);
        while (!q.empty())
        {
            node *temp = q.front();
            cout << temp->name << " ";
            q.pop();
            temp = temp->link;
            while (temp)
            {
                if (visited[SearchIndex(SearchNode(temp->name))] == false)
                {
                    visited[SearchIndex(SearchNode(temp->name))] = true;
                    q.push(SearchNode(temp->name));
                }
                temp = temp->link;
            }
        }
    }

    void DFS(string ver)
    {
        bool visited[size] = {false};
        stack<node *> st;
        node *start = SearchNode(ver);
        visited[SearchIndex(start)] = true;
        st.push(start);
        while (!st.empty())
        {
            node *temp = st.top();
            st.pop();
            cout << temp->name << " ";
            temp = temp->link;
            while (temp)
            {
                if (visited[SearchIndex(SearchNode(temp->name))] == false)
                {
                    visited[SearchIndex(SearchNode(temp->name))] = true;
                    st.push(SearchNode(temp->name));
                }
                temp = temp->link;
            }
        }
    }
};

int main()
{
    int n;
    string s;
    cout << "Enter the no. of landmarks : ";
    cin >> n;
    Graph g(n);
    while (true)
    {
        cout << endl;
        cout << "Choose the option " << endl;
        cout << "1. Create a Graph " << endl;
        cout << "2. Print Graph " << endl;
        cout << "3. BFS " << endl;
        cout << "4. DFS " << endl;
        cout << "5. Exit " << endl;
        int opt;
        cout << "Enter the option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            g.CreateGraph();
            break;
        case 2:
            g.PrintGraph();
            break;
        case 3:

            cout << "Enter the starting point : ";
            cin >> s;
            g.BFS(s);
            break;

        case 4:
            cout << "Enter the starting point : ";
            cin >> s;
            g.DFS(s);
            break;

        case 5:
            cout << endl;
            return 0;
        }
    }
}
