#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
long n,curri,currj,tempi,tempj,s=0,p=0,bests=0,bestp = 0,tp;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
bool visited[1000][1000];
bool iscream[1000][1000];
char c;
vector<pii>v;
queue<pii>q;

int main(){
  freopen("perimeter.in","r",stdin);
  freopen("perimeter.out","w",stdout);
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c;
      if (c == '#'){
        iscream[i][j] = true;
        v.push_back(make_pair(i,j));
        if (q.empty()){
          q.push(make_pair(i,j));
          visited[i][j] = true;
        }
      }
      else{
        iscream[i][j] = false;
      }
    }
  }
  while (!q.empty()){
    curri = q.front().first; currj = q.front().second;
    q.pop();
    s++;
    tp=4;
    for (int i = 0; i < 4; i++){
      tempi = curri+di[i]; tempj = currj+dj[i];
      if (tempi < n && tempi >= 0 && tempj < n && tempj >= 0){
        if(iscream[tempi][tempj]){
          tp--;
          if(!visited[tempi][tempj]){
          q.push(make_pair(tempi,tempj));
          visited[tempi][tempj] = true;
          }
        }
      }
    }
    p+=tp;
    if(q.empty()){
      for (int i = 0; i < v.size(); i++){
        if(!visited[v[i].first][v[i].second]){
          q.push(v[i]);
          visited[v[i].first][v[i].second] = true;
          break;
        }
      }
      if (s > bests){
        bests = s;
        bestp = p;
      }
      else if (s == bests){
        bestp = min(p, bestp);
      }
    p = 0;
    s = 0;
    }
  }
  cout << bests << " " << bestp << endl;
}