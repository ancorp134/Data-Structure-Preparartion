#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& vis ,stack<int>& st, vector<vector<pair<int,int>>>& adj ){
    vis[node]=true;

    for(auto i:adj[node]){
        if(!vis[i.first]){
            dfs(i.first,vis,st,adj);
        }
    }

    st.push(node);
}

int main(){
    int n,m,s;
    cin>>n>>m>>s;

    vector<vector<pair<int,int>>> adj(n);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
    }

    vector<bool> vis(n,false);
    stack<int> st;

    // finding valid topological sort
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

    vector<int> dis(n,INT_MAX);

    dis[s]=0;

    while(!st.empty()){
        
        int node=st.top();
        st.pop();

        if(dis[node]!=INT_MAX){

            for(auto i: adj[node]){
                dis[i.first] = min(dis[i.first],dis[node]+ i.second);
            }

        }
    }

    for(auto i:dis){
        cout<<i<<" ";
    }

}