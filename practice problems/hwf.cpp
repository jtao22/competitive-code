#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n,money; cin >> n >> money;
  int item[n];
  for (int i = 0;i < n; i++){
    cin >> item[i];
  }
  sort(item,item+n);
  int total=0,prevtotal,itr,minim;
  for (int i = 0; i <= n; i++){
    minim = 1000000000;
    for (int k = 0; k <= n-i;k++){
    for (int j = k; j < k+i; j++){
      total+= item[j]+i*(j-k+1);
    }
      minim = min(total,minim);
    total = 0;
    }
    if (minim > money){
      break;
    }
    itr = i;
    prevtotal = minim;
  }
  cout << itr << " " << prevtotal << endl;
}
