#include <bits/stdc++.h> 
using namespace std;
int di[4] = {0,0,1,-1};
int dj[4] = {-1,1,0,0};
int room[101][101];
bool lighton[101][101];
int n,m,x,y,a,b;
pair <int,int> pii;
pair <int,int> pii2;
int main(){
  //freopen("lightson.in","r",stdin);
  //freopen("lightson.out","w",stdout);
  int curri, currj;
  map<pair<int,int>,vector <pair<int,int>>> check;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    pii = make_pair(x,y);
    cin >> a >> b;
    pii2 = make_pair(a,b);
    check[pii].push_back(pii2);
  }
  int count = 1;
  room[1][1] = count;
  lighton[1][1] = true;
  queue<int>qi;
  queue<int>qj;
  qi.push(1);
  qj.push(1);
  while (qi.size() > 0){
    curri = qi.front();
    currj = qj.front();
    qi.pop();
    qj.pop();
    pii = make_pair(curri,currj);
    for (int i = 0; i < check[pii].size(); i++){
      if (!lighton[check[pii][i].first][check[pii][i].second]){
        lighton[check[pii][i].first][check[pii][i].second] = true;
        count++;
      }
    }
    for (int i = 0; i < 4; i++){
      if (curri+di[i] > 0 && currj+dj[i] > 0 && curri+dj[i] <= n && currj+dj[i] <= n){
        if (lighton[curri+di[i]][currj+dj[i]] && room[curri+di[i]][currj+dj[i]] == 0){
          room[curri+di[i]][currj+dj[i]] = 1;
          qi.push(curri+di[i]);
          qj.push(currj+dj[i]);
        }
      }
    }
  }
  cout << count+1 << endl;
}
