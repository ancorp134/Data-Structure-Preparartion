#include<bits/stdc++.h>
using namespace std;



bool cycleDFS(int node,int par,vector<bool>& vis,vector<bool>& dfsvis ,vector<vector<int>>& adj){
         vis[node]=true;
        dfsvis[node]=true;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                if(cycleDFS(i,node,vis,dfsvis,adj)) return true;
            }
            else if(vis[i] && dfsvis[i]){
                return true;
            }
        }
        dfsvis[node]=false;
        return false;
    }



int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    while(m--){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        
    }
    
    vector<bool> vis(n+1,false);
    vector<bool> dfsvis(n+1,false); // in case of dfs;

    int flag=0;

    for(int i=0;i<=n;i++){
        if(!vis[i]){
            if(cycleDFS(i,-1,vis,dfsvis,adj)) flag=1;
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";
    
} 
