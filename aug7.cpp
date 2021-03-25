// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;
// A utility function to add an edge in an
// undirected graph.
void DFSUtil(vector<int> adj[], int v, bool visited[], int av, int b[], int p[], int res[], int d)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    //cout << v << " ";
    if (av >= b[v] && res[v] == -1)
    {
        b[v] = 0;
        res[v] = d;
        //cout << d << " ";
    }
    else
    {
        b[v] = b[v] - av;
    }
    // Recur for all the vertices adjacent
    // to this vertex
    //list<int>::iterator h;
    for (auto h = adj[v].begin(); h != adj[v].end(); ++h)
        if (!visited[*h])
            DFSUtil(adj, *h, visited, av, b, p, res, d);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
/*void DFS(int v,int a[],int b[],int c[]) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 1; i <= V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited,a,b,c); 
}*/
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
/*void printGraph(vector<int> adj[], int V)
{
    for (int v = 1; v <= V; ++v)
    {
        //cout << "\n Adjacency list of vertex "
            // << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        //printf("\n");
    }
}
*/
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V;
        cin >> V;
        int n = V;
        vector<int> adj[V + 1];
        for (int i = 1; i < V; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(adj, u, v);
        }
        int a[V + 1], b[V + 1], p[V + 1];
        for (int i = 1; i <= V; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= V; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= V; i++)
        {
            cin >> b[i];
        }
        int res[n + 1];
        for (int i = 1; i <= n; i++)
        {
            res[i] = -1;
        }
        int d = 0;
        for (int i = 1; i <= V; i++)
        {
            bool *visited = new bool[V + 1];
            for (int j = 1; j <= i; j++)
            {
                visited[p[j]] = true;
            }
            for (int j = i + 1; j <= V; j++)
                visited[p[j]] = false;

            // Call the recursive helper function
            // to print DFS traversal
            //cout << b[p[i]] << " ";
            d++;
            int av = a[p[i]];
            DFSUtil(adj, p[i], visited, av, b, p, res, d);
            //cout << b[p[i]] << " ";
            /*if (b[p[i]] == 0 && res[p[i]] == -1)
                res[p[i]] = d;*/
            /*else
            {
                res[p[i]] = -1;
            }
            /*for (int j = 1; j <= V; j++)
            {
                if (b[j] == 0)
                    res[j] = d;
                else
                {
                    res[j]=0
                }
            }*/
        }
        for (int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
        //printGraph(adj, V);
    }
    return 0;
}
