/**
 * 200610
 * 2607 비슷한 단어
 * 브루트 포스
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int arr[30];
int compare[30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;
    int len = s.length();
    for(int i=0; i<len; i++)
        arr[s[i]-'A']++;

    int ans = 0;
    for(int i=2; i<=N; i++){
        for(int j=0; j<26; j++) compare[j]=0;

        cin >> s;
        int compLen = s.length();

        for(int j=0; j<compLen; j++)
            compare[s[j]-'A']++;
        
        int cnt = 0;
        for(int j=0; j<26; j++)
            if(arr[j]!=compare[j]) cnt++;
        
        if(cnt==0 || cnt==1){
            if(abs(len-compLen)==0 || abs(len-compLen)==1) ans++;
        }
        else if(cnt==2){
            if(abs(len-compLen)==0 || abs(len-compLen)==1){
                bool flag = true;
                for(int j=0; j<26; j++){
                    if(arr[j]!=compare[j])
                        if(abs(arr[j]-compare[j]) != 1)
                            flag = false;
                }

                if(flag) ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
