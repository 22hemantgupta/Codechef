#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        int a[n+1];
        int d[m][2];
        int b[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        for(int j=0;j<m;j++)
        {
            cin>>d[j][0]>>d[j][1];
        }
        pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = a[i]; 
        arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    sort(arrPos, arrPos + n); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
        if(m==0)
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}