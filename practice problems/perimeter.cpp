#include <bits/stdc++.h> 
using namespace std;

bool hay[102][102];
bool visited[102][102];
int p = 0,n,x,y;
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void dfs(int i, int j)
{
  if (hay[i][j]) { 
    p++; 
    return; 
  }
  if (visited[i][j]){ 
    return;
  }
  visited[i][j] = true;
  for (int itr= 0; itr < 4; itr++){
    if (i+di[itr] >= 0 && i+di[itr] <= 101 && j+dj[itr] >= 0 && j+dj[itr] < 102){
      dfs(i+di[itr],j+dj[itr]);
    }
  }
}

int main()
{  
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x >> y;
    hay[x][y] = true;
  }
  dfs(0,0);
  cout << p << endl;
}