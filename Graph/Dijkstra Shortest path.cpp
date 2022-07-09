#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,src;
    cin>>n>>m>>src;

    vector<vector<pair<int,int>>> adj(n);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dis(n,INT_MAX);
    
    set<pair<int,int>> s;
    
    dis[src]=0;
    s.insert({src,0});
    
    while(!s.empty()){
        auto temp = *(s.begin());
       
        int node=temp.first;
        int d=temp.second;
         s.erase(s.begin());
        
        for(auto i: adj[node]){
            if(dis[i.first] > d + i.second){
                
                auto f= s.find({i.first , dis[i.first]});
                if(f!=s.end()) s.erase({i.first , dis[i.first]});
                
                dis[i.first]=d+i.second;
                s.insert({i.first,dis[i.first]});
                
            }
        }
    }

    for(auto i: dis){
        cout<<i<<" ";
    }

}