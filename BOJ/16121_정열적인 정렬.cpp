/**
 * @file 16121_정열적인 정렬.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 16121 정열적인 정렬
 * @version 0.1
 * @date 2023-05-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;

  int arr[500001];
  
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }

  sort(arr, arr+N);

  for(int i=0; i<N; i++){
    cout << arr[i] << " ";
  }
}