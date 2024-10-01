//BFS Algorithm 
// TC -> O(n+m) : n = vertices and m = edges
vector<vector<int>> adj; // adjacency list

int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n); // visited array
vector<int> d(n), p(n); // d[] = path length array,  p[] = array of parents

q.push(s); // pushing source in queue
used[s] = true;

p[s] = -1 

while(!q.empty()){
  int v = q.front();
  q.pop();
  for (int u: adj[v]){
    if(!used[u]){
      used[u] = true;
      q.push(u);
      d[u] = d[v] + 1;
      p[u] = v;
    }
  }
}

// Logic for finding the shortest path
if(!used[u]){
  cout<<"No path";
}
else{
  vector<int> path;
  for(int v = u; v != -1; v = p[v]){
    path.push_back(v);
  }
  reverse(path.begin(), path.end());
  cout<< "path";
  for(int v: path){
    cout<<v<<" ";
  }
}