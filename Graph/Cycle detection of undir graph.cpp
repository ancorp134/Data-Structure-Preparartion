#include<bits/stdc++.h>
using namespace std;



bool cycleDFS(int node,int par,vector<bool>& vis ,vector<vector<int>>& adj){
        vis[node]=true;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                if(cycleDFS(i,node,vis,adj)) return true;
            }
            else if(vis[i] && par!=i) return true; 
        }
        return false;
    }

// BFS Approach
bool cycleBFS(int i,vector<bool>& vis ,vector<vector<int>>& adj ){
        queue<pair<int,int>> q;
        q.push(make_pair(i,-1));
        vis[i]=true;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto v:adj[node]){
                if(!vis[v]){
                    q.push(make_pair(v,node));
                    vis[v]=true;
                }
                else if(vis[v] && par!=v) {
                    return true;
                }
            }
        }
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
        adj[v].push_back(u);
    }
    
    vector<bool> vis(n+1,false);

    int flag=0;

    for(int i=0;i<=n;i++){
        if(!vis[i]){
            if(cycleDFS(i,-1,vis,adj)) flag=1;
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";
    
} 