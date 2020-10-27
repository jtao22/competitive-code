#include <bits/stdc++.h> 
using namespace std;

int n,x;
int first[7] = {10000000,10000000,100000000,100000000,10000000,100000000,1000000000};
int last[7];
int main()
{
  freopen("div7.in","r",stdin);
  freopen("div7.out","w",stdout);
  cin >> n;
  first[0] = 0;
  int currpsum =0;
  for (int i = 0; i < n;i++){
    cin >> x;
    currpsum+=x;
    currpsum%=7;
    last[currpsum] = i;
    first[currpsum] = min(i,first[currpsum]);
  }
  int best = 0;
  for (int i = 0; i < 7; i++){
    if (first[i] < n && last[i]-first[i] > best){
      best = last[i]-first[i];
    }
  }
  cout << best << endl;
}
