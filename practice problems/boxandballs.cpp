#include <bits/stdc++.h> 
using namespace std;
int box[100001];
bool pot[100001];
int main(){
  int n,q,a,b;
  cin >> n >> q;
  pot[1] = true;
  for (int i = 1; i <= n; i++){
    box[i] = 1;
  }
  for (int i = 0; i < q; i++){
    cin >> a >> b;
    box[a]--;box[b]++;
    if (pot[a]){
      if (box[a] == 0){pot[a] = false;}
      pot[b] = true;
    }
    
  }
  int count = 0;
  for (int i = 1; i <= n; i++){
    if (box[i] > 0 && pot[i]){
      count++;
    }
  }
  cout << count << endl;
}