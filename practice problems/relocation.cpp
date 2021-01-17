#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,k,a,b,l,x,currd,currn,tempn,tempd, best = INT_MAX;
vector<pii>adj[10005];
int dist[5][10005];
int marketlist[5];
bool ismarket[10005];
int perm[5];
void dja (int start){
  priority_queue <pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0,marketlist[start]));
  while(!pq.empty()){
    currn = pq.top().second; currd = pq.top().first;
    pq.pop(); 
    if(dist[start][currn] <= currd){
      continue;
    }
      dist[start][currn] = currd;
      for (int i = 0; i < adj[currn].size(); i++){
        tempn = adj[currn][i].second;
        tempd = adj[currn][i].first + currd;    
        if(tempd < dist[start][tempn]){
          pq.push(make_pair(tempd,tempn));
        }
      }
  }
}
int main(){
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++){
    cin >> marketlist[i];marketlist[i]--;
    perm[i] = i;
    ismarket[marketlist[i]] = true;
  }
  for (int i = 0; i < m; i++){
    cin >> a >> b >> l;
    adj[--a].push_back(make_pair(l,--b));
    adj[b].push_back(make_pair(l,a));
  }
  for(int i = 0; i < k; i++){
    for (int j = 0; j < n; j++){
      dist[i][j] = INT_MAX;
    }
    dja(i);
  }
  do{
    int total = INT_MAX;
    for (int i = 0; i < n; i++){ 
      if(!ismarket[i]){
        total = min(total, dist[perm[0]][i] + dist[perm[k-1]][i]);
      }
    }
    for (int i = 1; i < k; i++){
      total += dist[perm[i-1]][marketlist[perm[i]]];
    } 
    best = min(best, total);
  }while(next_permutation(perm, perm+k));
  cout << best << endl;
}