#include <bits/stdc++.h> 
using namespace std;
int n;
int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};
bool visited[500][500];
map<int,int>adj;
int main(){
  cin >> n;
  int arr[n][n]; 
  int right =0;
  queue<pair<int,int>>qi;
  qi.push(make_pair(0,0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> arr[i][j];
      right = max(right,arr[i][j]);
    }
  }
  right++;
  int left = 0,curr,curri,currj,currcount = 0,indcount = 0,recent,prevright, prevleft;
  bool found = false;
  while (left <= right){
    curr = (right+left)/2;
    prevright = right;
    prevleft = left;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (!visited[i][j]){
          currcount = 0;
          qi.push(make_pair(i,j));
          currcount++;
          visited[i][j] = true;
          while (qi.size() > 0){
            curri = qi.front().first;currj = qi.front().second;
            qi.pop();
            for (int i = 0; i < 4; i++){
              if (curri+di[i] >= 0 && curri+di[i] < n && currj+dj[i] < n && currj+dj[i] >= 0){
                if (!visited[curri+di[i]][currj+dj[i]] && abs(arr[curri][currj] - arr[curri+di[i]][currj+dj[i]]) <= curr){
                  visited[curri+di[i]][currj+dj[i]] = true;
                  currcount++;
                  qi.push(make_pair(curri+di[i],currj+dj[i]));
                }
              }
            }
          }

          indcount = max(indcount,currcount);
        }
      }
    }
    if (left < 0){
      break;
    }
    if (indcount >= (n*n+1)/2){
      recent = curr;
      right = curr+1;
    }
    else{
      left = curr-1;
    }


    if (right == prevright && left == prevleft){
      break;
    }

    indcount = 0;
    for (int i = 0; i  <n; i++){
      for (int j = 0; j < n; j++){
        visited[i][j] = false;
      }
    }
  }
  cout << recent << endl;
}
