#include <bits/stdc++.h> 

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> distance(vertices,INT_MAX);

    set<pair<int,int>> sp;  

    distance[source]=0;

    sp.insert(make_pair(0,source));

    while(!sp.empty()){

        auto top=*(sp.begin());

        int nodedist=top.first;
        int topNode=top.second;

        sp.erase(sp.begin());

        for(auto neighbour:adj[topNode]){
            if(nodedist+neighbour.second<distance[neighbour.first]){
                auto record=sp.find(make_pair(distance[neighbour.first],neighbour.first));

                if(record!=sp.end()){
                    sp.erase(record);
                }
                distance[neighbour.first]=nodedist+neighbour.second;

                sp.insert(make_pair(nodedist+neighbour.second,neighbour.first));
            }
        }
    }



    return distance;
}
