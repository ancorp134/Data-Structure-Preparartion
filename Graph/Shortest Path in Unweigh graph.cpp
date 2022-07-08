#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,s,d;
    cin>>n>>m>>s>>d;

    vector<vector<int>> adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n,false);
    vector<int> par(n);

    queue<int> q;

    q.push(s);
    vis[s]=true;
    par[s]=-1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto i:adj[node]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                par[i]=node;
            }
        }
    }
    
    vector<int> res;

    int curr=d;
    res.push_back(d);

    while(curr!=s){
        curr=par[curr];
        res.push_back(curr);
    }

    reverse(res.begin(),res.end());

    for(auto i: res){
        cout<<i<<" ";
    }
}