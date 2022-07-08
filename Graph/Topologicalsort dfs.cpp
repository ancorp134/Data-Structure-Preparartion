#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& res, vector<bool>& vis,vector<vector<int>>& adj){
    vis[node]=true;
    

    for(auto i:adj[node]){
        if(!vis[i]) dfs(i,res,vis,adj);
    }
    res.push_back(node);
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        
    }

    vector<int> res;

    vector<bool> vis(n,false);
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,res,vis,adj);
        }
    }
    reverse(res.begin(),res.end());
    for(auto i:res){
        cout<<i<<" ";
    }
}