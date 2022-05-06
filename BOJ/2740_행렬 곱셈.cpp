/**
 * @file 2740.Cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2740 행렬 곱셈 / 구현
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

int N1, N2, M1, M2;
int arr1[102][102];
int arr2[102][102];
int res[102][102];

void solve(){
  for(int i=0; i<N1; i++){
    for(int j=0; j<M2; j++){

      for(int k=0; k<N2; k++){
        res[i][j] += (arr1[i][k] * arr2[k][j]);
      }

      cout << res[i][j] <<' ';
    } cout << '\n';
  }
}

void input(){
  cin >> N1 >> M1;

  for(int i=0; i<N1; i++){
    for(int j=0; j<M1; j++){
      cin >> arr1[i][j];
    }
  }

  cin >> N2 >> M2;

  for(int i=0; i<N2; i++){
    for(int j=0; j<M2; j++){
      cin >> arr2[i][j];
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}