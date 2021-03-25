#include<bits/stdc++.h>
using namespace std;
class Graph 
{ 
    int V; // No. of vertices in graph 
    list<int> *adj; // Pointer to an array containing adjacency lists 
  
    // A recursive function used by printAllPaths() 
    void printAllPathsUtil(int,int , int , bool [], int [], int &,int []); 
    void printAllPathsUtil1(int,int , int , bool [], int [], int &,int []); 
  
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v); 
    void printAllPaths(int s, int d,int a[]);
    void printAllPaths1(int s, int d,int a[]); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); // Add v to u’s list. 
} 

void Graph::printAllPaths1(int s, int d,int a[]) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
  
    // Create an array to store paths 
    int *path = new int[V]; 
    int path_index = 0; // Initialize path[] as empty 
  
    // Initialize all vertices as not visited 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    printAllPathsUtil1(s,s, d, visited, path, path_index,a); 
} 
long int maxsum=0;  
// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil1(int s,int u, int d, bool visited[], 
                            int path[], int &path_index,int a[]) 
{ 
    // Mark the current node and store it in path[] 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    // If current vertex is same as destination, then print 
    // current path[] 
    long int sum=0;
    if (u == d) 
    { 
        for (int i = 0; i<path_index; i++) 
        {
            //cout<<path[i]<<" ";
            if((path[i]>=s && path[i]<=d) /*&& (path[i]>=s && path[i]<=d)*/)
            {
                //cout<<path[i]<<" ";
                sum=sum+a[path[i]];
            }
            else
            {
                sum=0;
                break;
            }
        } 
        //cout<<endl;
        if(sum>maxsum)
        {
            maxsum=sum;
            //cout<<maxsum<<endl;
        } 
          
    } 
    else // If current vertex is not destination 
    { 
        // Recur for all the vertices adjacent to current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil1(s,*i, d, visited, path, path_index,a); 
    } 
  
    // Remove current vertex from path[] and mark it as unvisited 
    path_index--; 
    visited[u] = false; 
}  
// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(int s, int d,int a[]) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
  
    // Create an array to store paths 
    int *path = new int[V]; 
    int path_index = 0; // Initialize path[] as empty 
  
    // Initialize all vertices as not visited 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    printAllPathsUtil(s,s, d, visited, path, path_index,a); 
} 
//long int maxsum=0;  
// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil(int s,int u, int d, bool visited[], 
                            int path[], int &path_index,int a[]) 
{ 
    // Mark the current node and store it in path[] 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    // If current vertex is same as destination, then print 
    // current path[] 
    long int sum=0;
    if (u == d) 
    { 
        for (int i = 0; i<path_index; i++) 
        {
            //cout<<path[i]<<" ";
            if((path[i]<=s && path[i]>=d) /*&& (path[i]>=s && path[i]<=d)*/)
            {
                //cout<<path[i]<<" ";
                sum=sum+a[path[i]];
            }
            else
            {
                sum=0;
                break;
            }
        } 
        //cout<<endl;
        if(sum>maxsum)
        {
            maxsum=sum;
            //cout<<maxsum<<endl;
        } 
          
    } 
    else // If current vertex is not destination 
    { 
        // Recur for all the vertices adjacent to current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(s,*i, d, visited, path, path_index,a); 
    } 
  
    // Remove current vertex from path[] and mark it as unvisited 
    path_index--; 
    visited[u] = false; 
} 
int main()
{
    int n,q;
    cin>>n>>q;
    //vector<Edge> edges;
    Graph g(n);
    int h[100000],a[100000];
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
                g.addEdge(i,j);
            }
        }
    }
    while(q--)
    {
        int f,b,c;
        cin>>f>>b>>c;
        if(f==1)
        {
            a[b-1]=c;
        }
        else if(f==2)
        {
            if(b!=c)
            {
                    /*if(b>c)
                    {
                        for(int i=b-1;i>=c-1;i--)
                        {
                            for(int j=b-1;j>=c-1;j--)
                            {
                                if(h[i]>h[j])
                                {
                                    g.addEdge(i,j);
                                }
                            }
                        }
                    }*/
                    if(h[b-1]>h[c-1] && b>c)
                    {
                    g.printAllPaths(b-1, c-1,a);
                    int* i1; 
                    i1 = max_element(h+c-1,h+b-1); 
                    if(maxsum!=0 && *i1<h[b-1])
                    {
                        cout<<maxsum<<endl;
                        maxsum=0;
                    }
                    else
                    {
                        //cout<<"hi";
                        cout<<-1<<endl;
                    }
                    }
                    else if(h[b-1]>h[c-1] && b<c )
                    {
                        g.printAllPaths1(b-1, c-1,a);
                        int* i1; 
                        i1 = max_element(h+(b),h+(c)); 
                        if(maxsum!=0 && *i1<h[b-1])
                        {
                        cout<<maxsum<<endl;
                        maxsum=0;
                        }
                        else
                        {
                        cout<<-1<<endl;
                        }
                    }
                    else
                    {
                        cout<<-1<<endl;
                    }
            }
            else
            {
                cout<<h[b-1]<<endl;
            }
        }
        
    }
    return 0;
}