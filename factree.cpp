#include<bits/stdc++.h>
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
long long int  printDivisors(long long int n) 
{ 
    // Note that this loop runs till square root
    long long int count=0;
    long long int mod = 1000000007; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                count = count+1; 
  
            else // Otherwise print both 
                count = count+2; 
        } 
    } 
    //cout<<count<<endl;
    return count%mod;
} 

// A function to print the path between 
// the given pair of nodes. 
long long int printPath(vector<int> stack, int a[]) 
{ 
	int i; 
    long long int pro=1;
	for (i = 0; i < (int)stack.size() - 1; 
		i++) { 
            //cout << stack[i] << " -> ";
		     pro = pro*a[stack[i]]; 
	} 
    //cout << stack[i];
	pro = (pro*a[stack[i]]);
    //cout<<pro<<endl; 
    return pro;
} 

// An utility function to do 
// DFS of graph recursively 
// from a given vertex x.
void DFS(vector<int> v[], 
		bool vis[], 
		int x, 
		int y, 
		vector<int> stack,int a[]) 
{ 
	stack.push_back(x);  
    long long int res;
	if (x == y) { 
		// print the path and return on 
		// reaching the destination node 
		res = printPath(stack,a);
        cout<<printDivisors(res);
		return; 
	} 
	vis[x] = true; 

	// A flag variable to keep track 
	// if backtracking is taking place 
	int flag = 0; 
	if (!v[x].empty()) { 
		for (int j = 0; j < v[x].size(); j++) { 
			// if the node is not visited 
			if (vis[v[x][j]] == false) { 
				DFS(v, vis, v[x][j], y, stack,a); 
				flag = 1; 
			} 
		} 
	} 
	if (flag == 0) { 

		// If backtracking is taking 
		// place then pop 
		stack.pop_back(); 
	} 
} 
// A utility function to initialise 
// visited for the node and call 
// DFS function for a given vertex x. 
void DFSCall(int x, 
			int y, 
			vector<int> v[], 
			int n, 
			vector<int> stack,int a[]) 
{ 
	// visited array 
	bool vis[n + 1]; 

	memset(vis, false, sizeof(vis)); 
	// DFS function call 
	DFS(v, vis, x, y, stack,a);
     
} 

// Driver Code 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n+1];
        vector<int> v[n+1], stack;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x;
            cin>>y;
            addEdge(v, x, y);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            DFSCall(x, y, v, n, stack,a);
            cout<<endl;
        }
    }
}