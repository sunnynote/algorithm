/**
 * @file 1535.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1535 안녕 / DP
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

pair<int,int> arr[21];
int d[21][101];

int mx(int a, int b){
  if(a > b) return a;
  return b;
}

int main(){
  int N;
  cin >> N;

  for(int i=1; i<=N; i++){ // 잃는 체력
    cin >> arr[i].first;
  }

  for(int i=1; i<=N; i++){ // 얻는 기쁨
    cin >> arr[i].second;
  }

  for(int i=1; i<=N; i++){
    int hp = arr[i].first;
    int mp = arr[i].second;

    for(int j=0; j<=100; j++){
      if(j - hp > 0){
        d[i][j] = mx(d[i-1][j-hp] + mp, d[i-1][j]);
      }
      else{
        d[i][j] = d[i-1][j];
      }
    }
  }

  // for(int i=1; i<=N; i++){
  //   for(int j=0; j<=M; j++){

  //   }
  // }
  cout << d[N][100] << '\n';

}