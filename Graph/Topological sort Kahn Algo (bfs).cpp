#include<bits/stdc++.h>
using namespace std;



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
    vector<int> indegree(n,0);
    
    for(auto i:adj){
        for(auto j: i) indegree[j]++;
    }

    queue<int> q;

    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);

        for(auto i:adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }

    for(auto i:res){
        cout<<i<<" ";
    }
}