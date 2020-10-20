#include <bits/stdc++.h> 
using namespace std;

int main(){
  //freopen("cowdance.in","r",stdin);
 / freopen("cowdance.out","w",stdout);
  int n,tmax; cin >> n >> tmax;
  int time[n];
  int temp[n];
  for (int i = 0; i < n; i++){
    cin >> time[i];
    temp[i] = time[i];
  }
  bool works = true;
  for (int i = 1; i <= n; i++){
    works = true;
    for (int j = i; j < n; j++){
      sort(temp,temp+i);
      temp[0] += time[j];
      if (temp[0] > tmax){
        works = false;
        break;
      }
    }
    if (works){
      cout << i << endl;
      break;
    }
    for (int k = 0; k < n; k++){
      temp[k] = time[k];
    }
  }
}