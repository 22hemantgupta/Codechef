#include <bits/stdc++.h>
using namespace std;
int minKey(int key[], bool mstSet[], int V)
{
    // Initialize min value
    int min = INT_MIN, max_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] > min)
            min = key[v], max_index = v;

    return max_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int V, vector<vector<int>> graph)
{
    int ans = 0;
    //cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        //cout<<parent[i]<<" - "<<i<<" \t"<<
        ans += graph[i][parent[i]];
    }
    cout << ans;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int V, vector<vector<int>> graph)
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MIN, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] > key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, V, graph);
}

int main()
{
    int V, d;
    cin >> V >> d;
    int a[V + 1][d + 1];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> a[i][j];
        }
    }
    long long int ans = 0;
    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int sum = 0;
            for (int k = 0; k < d; k++)
            {
                sum = sum + abs(a[i][k] - a[j][k]);
            }
            graph[i][j] = sum;
            //cout << sum << " ";
        }
    }
    primMST(V, graph);
    //cout << ans;
    return 0;
}