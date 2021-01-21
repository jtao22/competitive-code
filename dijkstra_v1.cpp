#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,a,b,c;
int adj[101][101];
int mindist(int dist[], bool tf[]){
	int min=INT_MAX,ind;           
	for(int i = 0; i < n; i++){
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
  dist[1] = 0; 
	for(int i = 1; i <= n; i++){
		x = mindist(dist,tf);
		tf[x]=true;
		for(int i = 1; i <= n; i++){
			if(!tf[i] && adj[m][i] && dist[m]!=INT_MAX && dist[x]+adj[x][i]<dist[i]){
				dist[i]=dist[x]+adj[x][i];
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
  dja(adj);
}
