#include <bits/stdc++.h> 
using namespace std;

int main(){
  //freopen("bcount.in","r",stdin);
  //freopen("bcount.out","w",stdout);
  int n,x,q,beg,end; cin >> n >> q; int count[4] = {0,0,0,0},h[n+2], g[n+2], j[n+2];h[0] = 0; g[0]=0; j[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> x;
    count[x]++;
    h[i] = count[1]; g[i] = count[2]; j[i] = count[3];
  }
  h[n+1] = count[1]; g[n+1] = count[2]; j[n+1] = count[3];
  for (int i = 0; i < q; i++){
    cin >> beg >> end;
    beg--;
    cout << h[end]-h[beg] << " " << g[end]-g[beg] << " " << j[end]-j[beg] << endl;
  }
}