/**
 * 200926
 * BOJ 1254 팰린드롬 만들기
 * 구현
 * */

#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;

    int len = str.length();
    int res = 0;

    for(int i=0; i<len-1; i++){

        if(str[i]==str[len-1]){ // 1) 앞뒤 같으면
            int left = i;
            int right = len-1;

            for(int j=0; j<(len-i)/2; j++){ // loop 몇번인지
                if(str[left]==str[right]){  // 2) 같으면 한칸씩 줄임
                    left++;
                    right--;
                }
                else{
                    res++;
                    break;
                }
            }

            if(left>=right) break;
        }
        else res++;
    }

    cout << len + res << '\n';
    return 0;
}