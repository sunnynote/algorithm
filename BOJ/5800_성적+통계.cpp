/**
 * @file 5800.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 5800 성적 통계 / 구현
 * @version 0.1
 * @date 2022-04-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int K;
  cin >> K;
  
  for(int i=1; i<=K; i++){
    int mn = 101;
    int mx = -1;
    
    int N;
    cin >> N;
    int arr[55];
    for(int j=0; j<N; j++){
      cin >> arr[j];
      if(arr[j] < mn) mn = arr[j];
      if(arr[j] > mx) mx = arr[j];
    }

    sort(arr, arr+N);
  
    int val = -1;
    for(int j=1; j<N; j++){
      if(val < arr[j] - arr[j-1]) val = arr[j] - arr[j-1];
    }

    cout << "Class " << i << '\n';
    cout << "Max " << mx << ", Min " << mn << ", Largest gap " << val << '\n';
  }
}