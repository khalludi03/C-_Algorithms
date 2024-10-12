#include<bits/stdc++.h>
using namespace std;
const int MAX =1e5; 
int parent[MAX];
int size_[MAX];
void make_set(int v)
{
    parent[v] = v;
    size_[v] = 1;
}
int find_set(int v)
{
    if(v==parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(size_[a]<size_[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        size_[a]+=size_[b];
    }
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    vector<pair<int,pair<int,int>>> edg;
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edg.push_back({w,{u,v}});
    }
    sort(edg.begin(),edg.end());
    for(int i=0;i<=node;i++)
        make_set(i);
    int total_weight=0;    
    for(auto it:edg)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(find_set(u)==find_set(v))
        {
            continue;
        }
        union_sets(u,v);
        total_weight+=w;
    }    
    cout<<total_weight<<endl;
    return 0;
}
