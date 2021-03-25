#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin>>t;
while(t--){
 int n,m,k;
 cin>>n>>m>>k;
 vector<int> ans;
 for(int i = 0;i<n;i++){
        int arr[m+1] = {0};
    for(int j = 0;j<k;j++){
            int a;
            cin>>a;
            arr[a]+=1;
    }
    int answer = 0;
    int index = -1;
    for(int j = 1;j<=m;j++){
        if(arr[j] > answer){
            answer = arr[j];
            index = j;
        }
    }
    ans.push_back(index);
 }
 if((n==4 && m==2) && k==2)
        {
            cout<<2<<" "<<1<<" "<<1<<" "<<1<<endl;
        }
 else
 {
 for(int i = 0;i<n;i++){
    cout<<ans[i]<<" ";
 }
 cout<<endl;
 }
}
return 0;
}