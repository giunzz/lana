#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
const long long inf = 1000000000000000LL; 
long long dist[MAX_N];
vector <pair <int, int> > adj[MAX_N]; 
bool mark[MAX_N]; 
int n;
long long a, b; 

void createGraph() {
  for (int i = 0; i < MAX_N; i++) {
    adj[i].clear();
    dist[i] = inf;
    mark[i] = false;  
  }
  queue <int> myqueue;
  myqueue.push(0);
  mark[0] = true; 
  while (!myqueue.empty()) {
    int u = myqueue.front(); 
    myqueue.pop(); 
    int v = u + 1; 
    if (v <= n) {                                
      adj[u].push_back(make_pair(v, a)); 
      if (mark[v] == false) {
        mark[v] = true; 
        myqueue.push(v); 
      }
    }
    v = 2 * u; 
    if (v <= n && v != u) {                     
      adj[u].push_back(make_pair(v, b));
      if (mark[v] == false) {
        mark[v] = true; 
        myqueue.push(v); 
      }  
    }
  }
}

void Dijkstra() {
  priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > pq; 
  pq.push(make_pair(0LL, 0));
  dist[0] = 0;
  while (!pq.empty()) {
    pair <long long, int> t = pq.top(); 
    pq.pop(); 
    int u = t.second; 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, int> pr = adj[u][i];
      if (pr.second + dist[u] < dist[pr.first]) {
        dist[pr.first] = pr.second + dist[u]; 
        pq.push(make_pair(dist[pr.first], pr.first)); 
      }
    }
  } 
}

int main () {
  freopen("SC5.INP", "r", stdin);
  freopen("SC5.OUT", "w", stdout); 
  int test; 
  cin >> test;         
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> a >> b;
    createGraph();
    Dijkstra();
    cout << dist[n] << endl;     
  }
  return 0; 
}