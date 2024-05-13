#include<bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bye     return 0; 
const int       MAX = 2e5+7; 
const int       mod = 1e9+7; 
#define left st,(st+en)/2,node<<1
#define right (st+en)/2+1,en,(node<<1)+1
ll n,q;
ll seg[MAX*4],lazy[MAX*4];
void init(int st,int en,int node)
{
    if(st==en) 
    {
        seg[node] = 0;
        lazy[node] = 0;
        return;
    }
    init(left);
    init(right);
    seg[node] = (seg[node<<1]&seg[(node<<1)+1]);
    
}
void update(int st,int en,int node,int l,int r,ll value)
{
    if(l>en||r<st) return;
    if(l<=st && en<=r)
    {
        lazy[node]|=value;
        seg[node]|=value;
        return;
    }
    update(left,l,r,value);
    update(right,l,r,value);
    seg[node] = ((seg[node<<1]&seg[(node<<1)+1])|lazy[node]);
}
ll query(int st,int en,int node,int l,int r)
{
    if(l>en||r<st) return ((ll)1<<32)-1;
    if(l<=st && en<=r)
    {
        return seg[node];
    }
    else
    {
        ll q1 = query(left,l,r);
        ll q2 = query(right,l,r);
        return ((q1&q2)|lazy[node]);
    }
}
int main()  
{ 
    fast
    cin>>n>>q;
    init(0,n-1,1);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r,value;
            cin>>l>>r>>value;
            update(0,n-1,1,l,r-1,value);
            //O(LogN)
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<query(0,n-1,1,l,r-1)<<endl;
            //O(LogN)
        }
    }
    bye
}
//https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C
