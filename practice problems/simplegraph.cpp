#include <bits/stdc++.h> 
using namespace std;
queue<int> q[100001];
int connected[100001];
int main(){
  int n,m; cin >> n >> m; int a,b,curr,count = 0;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    if (a == 1 || b == 1){
      count++;
    }
    //q[a].push(b);
    //q[b].push(a);
  }
  /*
  int size; queue<int>qu;qu.push(1);
  while (qu.size() > 0){
    curr = qu.front();
    qu.pop();
    size = q[curr].size();
    for (int i = 0; i  < size; i++){
      if (connected[q[curr].front()] == 0){
        cout << curr << " " << q[curr].front() << endl;
        connected[q[curr].front()] = 1;
        qu.push(q[curr].front());
        count++;
      }
      q[curr].pop();
    }
  }
  */
  cout << count << endl;
}