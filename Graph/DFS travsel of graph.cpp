#include<bits/stdc++.h>
using namespace std;


void DFS(int node,vector<bool>& vis,vector<vector<int>>& adj, vector<int>& DFSAns){
    DFSAns.push_back(node);
    vis[node]=true;
    auto temp=adj[node];
    for(auto i:temp){
        if(!vis[i]){
            DFS(i,vis,adj,DFSAns);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> DFSAns;
    vector<bool> vis(n+1,false);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            DFS(i,vis,adj,DFSAns);
        }
    }

    for(auto i:DFSAns){
        cout<<i<<" ";
    }

}