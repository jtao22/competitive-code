//quickfind
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int n,m,k,a,b;
int qf[10000001];

int main(){
  cin >> n >> m >> k;
  
  for (int i = 1; i <= m; i++){
    cin >> a >> b;
    if (qf[a] == 0 && qf[b] == 0){
      qf[a] = i;
      qf[b] = i;
    }
    else{
      if(qf[a] == 0){
        qf[a] = qf[b];
      }
      else if (qf[b] == 0){
        qf[b] = qf[a];
      }
      else if (qf[a] != qf[b]){
        for (int j = 1; j <= n; j++){
          if(qf[j] == qf[a] || qf[j] == qf[b]){
            qf[j] = i;
          }
        }
      }
    }
  }
  for (int i = 0; i < k; i++){
    cin >> a >> b;
    if(qf[a] == qf[b]){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}
