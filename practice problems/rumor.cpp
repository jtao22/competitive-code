#include <bits/stdc++.h> 
using namespace std;
int cost[100000]; int f[100000];
long long ans=0;
int root(int i){
	if (f[i]==i){return i;}
	return f[i]=root(f[i]);
} 
void adj(int i,int j){
	int ri=root(i),rj=root(j);
	if (ri == rj){ return;}
	else if (cost[ri] > cost[rj]){f[ri] = rj;}
	else {f[rj] = ri;}
} 
int main(){
  int n,m,x,y;cin >> n >> m;
	for (int i = 1; i <= n; i++){
    cin >> cost[i];
		f[i]=i;
	}
	for (int i = 0; i < m ;i++){
		cin >> x >> y;
		adj(x,y);
	}
	for (int i=1;i<=n;i++){
		if (f[i] == i){ 
      ans+=cost[i];
    }
  }
	cout << ans << endl;
}
