#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,x,a,b,junc;
int pos,temp,currpipe,tempcapacity; pii cost;
vector<int>junction[501];
int latency[501], capacity[501],fastest[501];
queue<pii>t;
queue<int>currj;
pii pipes[501];

int main(){
  freopen("mroute.in","r",stdin);
  freopen("mroute.out","w",stdout);
  cin >> n >> m >> x;
  for (int i = 1; i <= m; i++){
    cin >> a >> b >> latency[i] >> capacity[i];
    pipes[i] = make_pair(a,b);
    junction[a].push_back(i);
    junction[b].push_back(i);
  }
  for(int i = 2; i <= n; i++){
    fastest[i] = INT_MAX;
  }
  fastest[1] = 0;
  currj.push(1);
  t.push(make_pair(0,INT_MAX));
  while(!currj.empty()){
    pos = currj.front(); currj.pop(); 
    cost = t.front(); t.pop();
    for(int i = 0; i < junction[pos].size(); i++){
      currpipe = junction[pos][i];
      if(pipes[currpipe].first == pos){
        temp = pipes[currpipe].second;
      }
      else{
        temp = pipes[currpipe].first;
      }
      tempcapacity = min(cost.second,capacity[currpipe]);
      if(fastest[temp] > cost.first+latency[currpipe]+ x/(tempcapacity)){
        fastest[temp] = cost.first+latency[currpipe]+ x/(tempcapacity);
        currj.push(temp);
        t.push(make_pair(cost.first+latency[currpipe],tempcapacity));
      }
    }
  }
  cout << fastest[n];
}
