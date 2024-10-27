// Dijkstra Algorithm

// You are given a directed or undirected weighted graph with  
// $n$  vertices and  
// $m$  edges. The weights of all edges are non-negative. You are also given a starting vertex  
// $s$ . This article discusses finding the lengths of the shortest paths from a starting vertex  
// $s$  to all other vertices, and output the shortest paths themselves.

// This problem is also called single-source shortest paths problem.
#include<bits/stdc++.h>
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}