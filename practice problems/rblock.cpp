#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,a,b,c;
int adj[101][101];
vector<int>past[101];
int mindist(int dist[], bool tf[]){
	int min=INT_MAX,ind;           
	for(int i = 1; i <= n; i++){
		if(!tf[i] && dist[i] <= min){
			min=dist[i];
			ind=i;
		}
	}
	return ind;
}
int dja(int adj[101][101]) {
	int dist[n+1],x;                         
	bool tf[n+1]; 
	for(int i = 1; i <= n; i++){
      dist[i] = INT_MAX; tf[i] = false;	
  }   
  past[1].push_back(1);
  dist[1] = 0; 
	for(int i = 1; i <= n; i++){
		x = mindist(dist,tf);
		tf[x]=true;
		for(int i = 1; i <= n; i++){
			if(!tf[i] && adj[x][i] != 0 && dist[x]!=INT_MAX && dist[x]+adj[x][i]<dist[i]){
				dist[i]=dist[x]+adj[x][i];
        past[i].clear();
        for (int j = 0; j < past[x].size(); j++){
          past[i].push_back(past[x][j]);
        }
        past[i].push_back(i);
      }
		}
	}
  return dist[n];
}
int main(){
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    adj[a][b] = c;
    adj[b][a] = c;
  }
  int original = dja(adj),top = 0;
  vector<int>best;
  for (int i = 0; i < past[n].size(); i++){
    best.push_back(past[n][i]);
  }
  for (int i = 0; i < best.size()-1; i++){
    adj[best[i]][best[i+1]]*=2;
    adj[best[i+1]][best[i]]*=2;
    top = max(top,dja(adj)-original);
    adj[best[i]][best[i+1]]/=2;
    adj[best[i+1]][best[i]]/=2;
  }
  cout << top << endl;
}
  //freopen("rblock.in","r",stdin);
  //freopen("rblock.out","w",stdout);