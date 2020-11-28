#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n; cin >> n;
  queue<int>q;
  q.push(n);
  int count = 0;
  while (q.size() > 0){
    for (int i = 0; i < q.size(); i++){
      if (q.front()*13/12 > q.front()){
        q.push(q.front()/4);
        q.push(q.front()/3);
        q.push(q.front()/2);
      }
      else{
        count+=q.front();
      }
      q.pop();
    }
  }
  cout << count << endl;
}