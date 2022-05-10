#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
string ans = "";

void solve(){
  sort(arr, arr+3);

  if(arr[0] == 60 && arr[0] == arr[1] && arr[1] == arr[2]){
    ans = "Equilateral";
  }
  else if(arr[0] + arr[1] + arr[2] == 180){
    if(arr[0] == arr[1] || arr[1] == arr[2]){
      ans = "Isosceles";
    }
    else{
      ans = "Scalene";
    }
  }
  else{
    ans = "Error";
  }

  cout << ans;
}

void input(){
  cin >> arr[0] >> arr[1] >> arr[2];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}