#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;
 
int n,q;
int h[200111];
llong a[200111];
 
vector<int> st;
vector<int> Tree[2][200111];
bool root[2][200111];
 
int inCtr[2];
int inVal[2][200111];
int lastIn[2][200111];
int parent[2][200111];
 
llong IT[2][800111];
int LEAFOFFSET;
 
bool isChild(int t, int vp, int vc)
{
    return inVal[t][vc] >= inVal[t][vp] && inVal[t][vc] <= lastIn[t][vp];
}
 
void recUpd(int t, int ver, int L, int R, int l, int r, llong val)
{
    if (L >= l && R <= r)
    {
        IT[t][ver] += val;
        return;
    }
    else if (L > r || R < l)
        return;
    else
    {
        recUpd(t, 2*ver, L, (L+R)/2, l, r, val);
        recUpd(t, 2*ver+1, (L+R)/2+1, R, l, r, val);
    }
}
 
void updVal(int t, int node, llong val)
{
    int L = inVal[t][node];
    int R = lastIn[t][node];
 
    recUpd(t, 1, 1, LEAFOFFSET+1, L, R, val);
}
 
llong rootPath(int t, int node)
{
    if (node == 0)
        return 0LL;
 
    int ind = inVal[t][node] + LEAFOFFSET;
    llong ans = 0;
 
    while(ind > 0)
    {
        ans += IT[t][ind];
        ind /= 2;
    }
 
    return ans;
}
 
void flattenTree(int t, int ver)
{
    int i;
 
    inCtr[t]++;
    inVal[t][ver] = inCtr[t];
 
    for (i=0;i<Tree[t][ver].size();i++)
    {
        parent[t][ Tree[t][ver][i] ] = ver;
        flattenTree(t, Tree[t][ver][i]);
    }
 
    lastIn[t][ver] = inCtr[t];
}
 
int main()
{
    int i,j;
 
    scanf("%d %d", &n, &q);
 
    for (i=1;i<=n;i++)
    {
        scanf("%d", &h[i]);
    }
 
    for (i=1;i<=n;i++)
    {
        scanf("%lld", &a[i]);
    }
 
    LEAFOFFSET = 1;
    while(LEAFOFFSET < n)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;
 
    for (i=1;i<=n;i++)
    {
        while(!st.empty() && h[st.back()] <= h[i])
            st.pop_back();
 
        if (!st.empty())
            Tree[0][st.back()].push_back(i);
        else
            root[0][i] = true;
 
        st.push_back(i);
    }
 
    st.clear();
    for (i=n;i>=1;i--)
    {
        while(!st.empty() && h[st.back()] <= h[i])
            st.pop_back();
 
        if (!st.empty())
            Tree[1][st.back()].push_back(i);
        else
            root[1][i] = true;
 
        st.push_back(i);
    }
 
    for (i=1;i<=n;i++)
    {
        if (root[0][i])
            flattenTree(0, i);
 
        if (root[1][i])
            flattenTree(1, i);
    }
 
    for (i=1;i<=n;i++)
    {
        updVal(0, i, a[i]);
        updVal(1, i, a[i]);
    }
 
    for (i=1;i<=q;i++)
    {
        int cm, v, k;
 
        scanf("%d %d %d", &cm, &v, &k);
 
        if (cm == 1)
        {
            int change = k - a[v];
            updVal(0, v, change);
            updVal(1, v, change);
            a[v] = k;
        }
        else
        {
            int t = 0;
            if (v > k)
                t = 1;
 
            if (!isChild(t, v, k))
                printf("-1\n");
            else
                printf("%lld\n", rootPath(t, k) - rootPath(t, parent[t][v]));
        }
 
    }
}