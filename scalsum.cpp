// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// An utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> v[],
             int x,
             int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
vector<int> res1;
vector<int> res2;
// A function to print the path between
// the given pair of nodes.
void printPath(vector<int> &stack1)
{
    int i;
    for (i = 0; i < (int)stack1.size() - 1;
         i++)
    {
        res1.push_back(stack1[i]);
    }
    res1.push_back(stack1[i]);
}
void printPath1(vector<int> &stack2)
{
    int i;
    for (i = 0; i < (int)stack2.size() - 1;
         i++)
    {
        res2.push_back(stack2[i]);
    }
    res2.push_back(stack2[i]);
}
// An utility function to do
// DFS of graph recursively
// from a given vertex x.
void DFS(vector<int> v[],
         bool vis[],
         int x,
         int y,
         vector<int> &stack1)
{
    stack1.push_back(x);
    if (x == y)
    {

        // print the path and return on
        // reaching the destination node
        printPath(stack1);
        return;
    }
    vis[x] = true;

    // if backtracking is taking place
    if (!v[x].empty())
    {
        for (int j = 0; j < v[x].size(); j++)
        {
            // if the node is not visited
            if (vis[v[x][j]] == false)
                DFS(v, vis, v[x][j], y, stack1);
        }
    }

    stack1.pop_back();
}

// A utility function to initialise
// visited for the node and call
// DFS function for a given vertex x.
void DFSCall(int x,
             int y,
             vector<int> v[],
             int n,
             vector<int> &stack1)
{
    // visited array
    bool vis[n + 1];

    memset(vis, false, sizeof(vis));

    // DFS function call
    DFS(v, vis, x, y, stack1);
}
//            kjhgfdfghjk ////////////

void DFS1(vector<int> v[],
          bool vis[],
          int x,
          int y,
          vector<int> &stack2)
{
    stack2.push_back(x);
    if (x == y)
    {

        // print the path and return on
        // reaching the destination node
        printPath1(stack2);
        return;
    }
    vis[x] = true;

    // if backtracking is taking place
    if (!v[x].empty())
    {
        for (int j = 0; j < v[x].size(); j++)
        {
            // if the node is not visited
            if (vis[v[x][j]] == false)
                DFS1(v, vis, v[x][j], y, stack2);
        }
    }

    stack2.pop_back();
}

// A utility function to initialise
// visited for the node and call
// DFS function for a given vertex x.
void DFSCall1(int x,
              int y,
              vector<int> v[],
              int n,
              vector<int> &stack2)
{
    // visited array
    bool vis[n + 1];

    memset(vis, false, sizeof(vis));

    // DFS function call
    DFS1(v, vis, x, y, stack2);
}
// Driver Code
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v[n];

    // Vertex numbers should be from 1 to 9.
    for (int i = 0; i < n - 1; i++)
    {
        int u, y;
        cin >> u >> y;
        u--;
        y--;
        addEdge(v, u, y);
    }
    long long int mod = 4294967296;
    // Function Call
    while (q--)
    {
        vector<int> stack1, stack2;
        int x, y;
        cin >> x;
        cin >> y;
        x--;
        y--;
        DFSCall(0, x, v, n, stack1);
        DFSCall1(0, y, v, n, stack2);
        long long int res = 0;
        for (int i = 0; i < res1.size(); i++)
        {
            //cout << res << "    ";
            res = res + ((a[res1[i]] % mod) * (a[res2[i]] % mod) % mod);
            res = res % mod;
        }
        cout << res << endl;
        res1.clear();
        res2.clear();
    }
    return 0;
}
