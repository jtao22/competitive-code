#include<bits/stdc++.h> 
using namespace std;
//declare any global variables
int n; // number of nodes in graph
int g; // adj list representing graph
vector <int> graph[1000000];
int neighbors[1000000];
bool visited[1000000]; // visited array
void dfs (int at){
  if (visited[at]){
    return;
  }
  visited[at] = true;
  // visit all neighbors and then dfs(neighbors);
  

}
int main(){

}
