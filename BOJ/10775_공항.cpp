/**
 * @file 10775.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 10775 공항 / 분리 집합
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int G, P;
int arr[100005];
int parent[100005];

int findParent(int x){
  if(parent[x] == x) return x;
  return parent[x] = findParent(parent[x]);
}

void unite(int a, int b){
  a = findParent(a);
  b = findParent(b);

  parent[a] = b;
}

int main(){
  cin >> G >> P;
  for(int i=1; i<=P; i++){
    cin >> arr[i];
  }

  for(int i=1; i<=G; i++){
    parent[i] = i;
  }

  int ans = 0;
  for(int i=1; i<=P; i++){
    int cur = findParent(arr[i]);

    if(cur == 0) break;
    else{
      unite(cur, cur - 1);
      ans++;
    }
  }

  cout << ans;
}