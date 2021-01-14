#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long>pll;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,g,x,temp;
int groupsize[1000001];
vector<int>groups[1000001];
set<int>grouplist[1000001];
bool invited[1000001];
queue<int>q;
int main(){
  freopen("invite.in","r",stdin);
  freopen("invite.out","w",stdout);
  cin >> n >> g;
  for(int i = 0; i < g; i++){
    cin >> groupsize[i];
    for (int j = 0; j < groupsize[i]; j++){
      cin >> x;
      groups[x].push_back(i);
      grouplist[i].insert(x);
    }
  }
  q.push(1);
  while(!q.empty()){
    x = q.front(); q.pop();
    invited[x] = true;
    for (int i = 0; i < groups[x].size(); i++){
      temp = groups[x][i];
        if(grouplist[temp].find(x) != grouplist[temp].end()){
          groupsize[temp]--;
          grouplist[temp].erase(x);
          if(groupsize[temp] == 1){
            q.push(*grouplist[temp].begin());
          }
        }
    }
  }
  int count = 0;
  for (int i = 1; i <= n; i++){
    if (invited[i]){
      count++;
    }
  }
  cout << count << endl;
}
