#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,k,a,b,temp;

int main(){
  cin >> n >> m;
  int qf[n+1];
  for (int i = 1; i <= n; i++){
    qf[i] = i;
  }
  for (int i = 1; i <= m; i++){
    cin >> a >> b;
    if(qf[b] == b){
      qf[a] = b;
    }
    else{
      temp = qf[b];
      while(true){
        temp = qf[temp];
        if (qf[temp] == temp){
          qf[a] = temp;
          break;
        }
      }
    }
  }
}
