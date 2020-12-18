#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;

int main(){
  freopen("shuffle.in","r",stdin);
  freopen("shuffle.out","w",stdout);
  cin >> n; int shift[n+1],num[n+1],count;
  bool has[n+1]; bool repeat = false;
  for (int i = 1; i <= n; i++){
    cin >> shift[i];
    num[i] = 1;
    has[i] = true;
  }
  while(true){
    for (int i = 1; i <= n; i++){
      if(num[i] > 0){
        num[i]--;
        num[shift[i]]++;
      }
    }
    repeat = true;count = n;
    for (int i = 1; i <= n; i++){
      if(num[i] == 0){
        count--;
        if (has[i]){
          has[i] = false;
          repeat = false;
        }
      }
      else{
        num[i] = 1;
      }
    }
    if (repeat){
      cout << count << endl;
      break;
    }
  }
}