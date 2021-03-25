#include <bits/stdc++.h>
using namespace std;
#define NIL -1
list<int> *adj;
void APUtil(int u, bool visited[], int disc[],
            int low[], int parent[], bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;

    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i; // v is current adjacent of u

        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // u is an articulation point in following cases

            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
                ap[u] = true;

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
                ap[u] = true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}
vector<int> res;
void AP(int V)
{
    //cout << "ap";
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; // To store articulation points

    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    // Now ap[] contains articulation points, print them
    vector<int> v1;
    for (int i = 0; i < V; i++)
    {
        if (ap[i] == true)
        {
            v1.push_back(i);
            //cout << i << " ";
            list<int>::iterator j;
            //list<int>::iterator i;
            for (j = adj[i].begin(); j != adj[i].end(); ++j)
            {
                res.push_back(*j);
            }
        }
    }
    vector<int> diff;
    std::set_difference(v1.begin(), v1.end(), res.begin(), res.end(),
                        std::inserter(diff, diff.begin()));
    res.erase(unique(res.begin(), res.end()), res.end());
    sort(res.begin(), res.end());

    //return res;
}
int main()
{
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    adj = new list<int>[n];
    //adj = convert(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    // vector<bool> v;
    AP(n);
    /*  vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == true)
        //cout << i << " ";
        {
            //list<int>::iterator j;
            for (int j = 0; j < adj[i].size(); ++j)
            {
                res.push_back(adj[i][j]);
            }
        }
    }*/
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}