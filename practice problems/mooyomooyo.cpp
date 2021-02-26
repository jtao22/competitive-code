#include <bits/stdc++.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,k;
string s;
int arr[101][11];
int temp[101][11];
bool visited[101][11];
void drop(){
  int count;
  for (int i = 0; i < 10; i++){
    count = 0;
    for (int j = n-1; j >= 0; j--){
      if(arr[j][i] == 0){
        count++;
      }
      else{
        temp[j+count][i] = arr[j][i];
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 10; j++){
      arr[i][j] = temp[i][j];
      temp[i][j] = 0;
    }
  }
}

int main(){
  freopen("mooyomooyo.in","r",stdin);
  freopen("mooyomooyo.out","w",stdout);
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> s;
    for (int j = 0; j < 10; j++){
      arr[i][j] = s[j]-'0';
    }
  }
  queue<pii>q;
  bool can = true; int currval,ci,cj,ti,tj,count,tot=0;
  while(can){
    can = false;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 10; j++){
        visited[i][j] = false;
      }
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 10; j++){
        tot++;
        if(!visited[i][j] && arr[i][j] != 0){
          q.push(make_pair(i,j));
          vector<pii>remove;
          remove.push_back(make_pair(i,j));
          currval = arr[i][j];
          visited[i][j] = true;
          count = 1;
          while(!q.empty()){
            ci = q.front().first; cj = q.front().second; q.pop();
            for (int k = 0; k < 4; k++){
              ti = ci+di[k]; tj = cj+dj[k];
              if(ti < n && ti >= 0 && tj < 10 && tj >= 0 && !visited[ti][tj] && arr[ti][tj] == currval){
                visited[ti][tj] = true;
                q.push(make_pair(ti,tj));
                remove.push_back(make_pair(ti,tj));
                count++;
              }
            }
          }
          if(count>=k){
            can = true;
            for (int k = 0; k < remove.size(); k++){
              arr[remove[k].first][remove[k].second] = 0;
            }
          }
        }
      }
    }
    drop(); 
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 10; j++){
      cout << arr[i][j];
    }
    cout << "" << endl;
  }
}
