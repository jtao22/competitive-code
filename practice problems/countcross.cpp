#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,k,r,r1,r2,c1,c2;
int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};
bool broke[101][101][101][101];
int visited[101][101];
int counts[10201];

int main(){
  freopen("countcross.in","r",stdin);
  freopen("countcross.out","w",stdout);
  cin >> n >> k >> r;
  for (int i = 0; i < r; i++){
    cin >> r1 >> c1 >> r2 >> c2;
    broke[r1][c1][r2][c2] = true;
    broke[r2][c2][r1][c1] = true;
  }
  queue<pii>q;
  int count = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if(!visited[i][j]){
        count++;
        q.push({i,j});
        visited[i][j] = count;
        while(!q.empty()){
           r1 = q.front().first, c1 = q.front().second;
           q.pop();
           for (int k = 0; k < 4; k++){
             r2 = r1+di[k];c2 = c1+dj[k];
             if(r2 > 0 && c2 > 0 && r2 <= n && c2 <= n && visited[r2][c2] == 0 && !broke[r1][c1][r2][c2]){
               visited[r2][c2] = count;
               q.push({r2,c2});
             }
           }
        }
      }
    }
  }
    for (int i = 0; i < k; i++){
      cin >> r1 >> c1;
      counts[visited[r1][c1]]++;
    }
    int ans = 0;
    for (int i = 1; i <= count; i++){
      for (int j = i+1; j <= count; j++){
        ans+=counts[i]*counts[j];
      }
    }
    cout << ans << endl;
}