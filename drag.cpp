#include<bits/stdc++.h>
using namespace std;
struct Edge {
	int src, dest, weight;
};

// class to represent a graph object
class Graph
{
	public:
	// construct a vector of vectors of Edge to represent an adjacency list
	vector<vector<Edge>> adjList;

	// Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<Edge>
		adjList.resize(N);

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			int src = edge.src;
			int dest = edge.dest;
			int weight = edge.weight;

			adjList[src].push_back({src, dest, weight});
			//adjList[dest].push_back({dest, src, weight});
		}
	}
};

// BFS Node
struct Node
{
	// current vertex number and cost of current path
	int vertex, weight;

	// set of nodes visited so far in current path
	set<int> s;
};

// Perform BFS on graph g starting from vertex v
int modifiedBFS(Graph const &g, int src, int k)
{
	// create a queue used to do BFS
	queue<Node> q;

	// add source vertex to set and push it into the queue
	set<int> vertices;
	vertices.insert(0);
	q.push({src, 0, vertices});

	// stores maximum-cost of path from source
	int maxCost = INT_MIN;

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue
		Node node = q.front();
		q.pop();

		int v = node.vertex;
		int cost = node.weight;
		vertices = node.s;

		// if destination is reached and BFS depth is equal to m
		// update minimum cost calculated so far
		if (cost > k)
			maxCost = max(maxCost, cost);

		// do for every adjacent edge of v
		for (Edge edge : g.adjList[v])
		{
			// check for cycle
			if (vertices.find(edge.dest) == vertices.end())
			{
				// add current node into the path
				set<int> s = vertices;
				s.insert(edge.dest);

				// push every vertex (discovered or undiscovered) into
				// the queue with cost equal to (cost of parent + weight
				// of current edge)
				q.push( {edge.dest, cost + edge.weight, s} );
			}
		}
	}

	// return max-cost
	return maxCost;
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector<Edge> edges;
    int h[n+1],a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(h[i]>h[j])
            {
                edges[i]={i,j,a[j]};
            }
        }
    }
    Graph g(edges, n);
    while(q--)
    {
        int f,b,c;
        cin>>f>>b>>c;
        if(f==1)
        {
            a[b]=c;
        }
        else
        {
            if(b!=c)
            {
                if(h[b]<h[c])
                {
                    cout<<-1<<endl;
                }
                else
                {
                   /* int sor=b;
                    int des=c;
                    if(sor>des)
                    {
                        for(int i=b-1;i>=c;i--)
                        {

                        }
                    }
                    else
                    {
                        for(int i=b+1;i<=c;i++)
                        {

                        }
                    }*/
                    int maxCost = modifiedBFS(g, b, a[b]);

	                if (maxCost != INT_MIN)
		                cout<<maxCost<<endl;
	                else
                        cout<<-1<<endl;                    
                }
            }
            else
            {
                cout<<h[b]<<endl;
            }
            
        }
        
    }
}