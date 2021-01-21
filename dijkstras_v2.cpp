#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
pii curr;
int n, m, x,y,l;
vector<pii> adj[100];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[100];


int main() {
  int start = 0;
  cin >> n >> m; 
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> l;
    adj[x].push_back(pii(l, y));
    adj[y].push_back(pii(l, x));
  }
  for (int i = 0; i < n; i++) {
    dist[i] = -1;
  }
  pq.push(pii(start, 0));
  while (!pq.empty()) {
    curr = pq.top();
    pq.pop();
    if(dist[curr.second] != -1) {
      continue;
    }
    dist[curr.second] = curr.first;
    for (pii j : adj[curr.second]) {
      if (dist[j.second] == -1) {
        pq.push(pii(curr.first+j.first, j.second));
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << dist[i] << endl;
  }
}