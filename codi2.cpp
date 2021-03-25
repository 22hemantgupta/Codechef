#include <bits/stdc++.h>
using namespace std;

// Here 10000 is maximum number of nodes in
// given tree.
int diameter[100001];

// The Function to do bfs traversal.
// It uses iterative approach to do bfs
// bfsUtil()
int bfs(int init, vector<int> arr[], int n)
{
    // Initializing queue
    queue<int> q;
    q.push(init);

    int visited[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        diameter[i] = 0;
    }

    // Pushing each node in queue
    q.push(init);

    // Mark the traversed node visited
    visited[init] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < arr[u].size(); i++)
        {
            if (visited[arr[u][i]] == 0)
            {
                visited[arr[u][i]] = 1;

                // Considering weight of edges equal to 1
                diameter[arr[u][i]] += diameter[u] + 1;
                q.push(arr[u][i]);
            }
        }
    }

    // return index of max value in diameter
    return int(max_element(diameter + 1,
                           diameter + n + 1) -
               diameter);
}

int findDiameter(vector<int> arr[], int n)
{
    int init = bfs(1, arr, n);
    int val = bfs(init, arr, n);
    return diameter[val];
}

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // Input number of nodes
        int n;
        cin >> n;

        vector<int> arr[n + 1];

        // Input nodes in adjacency list
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        int x = findDiameter(arr, n);
        if (x % 2 == 0)
        {
            cout << x / 2 << endl;
        }
        else
        {
            x = x / 2 + 1;
            cout << x << endl;
        }
    }
    return 0;
}