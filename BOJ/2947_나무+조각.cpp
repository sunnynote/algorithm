/**
 * @file 2947.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2947 나무 조각 / 구현
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int main(){
  int arr[5];

  for(int i=0; i<5; i++){
    cin >> arr[i];
  }

  for(int i=0; i<4; i++){
    bool f = false;
    if(arr[i] > arr[i+1]){
      int tmp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = tmp;
      f = true;
    }
    if(f){
      for(int j=0; j<5; j++){
        cout << arr[j] <<' ';
      } cout << '\n';
    }
  }

  bool f = true;
  for(int i=0; i<4; i++){
    if(arr[i] > arr[i+1]) f = false;
  }
}