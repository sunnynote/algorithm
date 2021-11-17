/**
 * 21-11-17
 * BOJ 1411 비슷한 단어
 * 브루트포스
 * */
#include <iostream>
using namespace std;

int N;
string str[102];
int ans = 0;

void solve(){
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            string s1 = str[i];
            string s2 = str[j];

            bool f = true;
            int arr1[28], arr2[28];

            for(int k=0; k<26; k++){
                arr1[k] = -1;
                arr2[k] = -1;
            }

            for(int k=0; k<s1.size(); k++){
                int tmp1 = s1[k] - 'a';
                int tmp2 = s2[k] - 'a';

                if(arr1[tmp1]==-1 && arr2[tmp2]==-1){
                    arr1[tmp1] = tmp2;
                    arr2[tmp2] = tmp1;
                } else if(tmp1==arr2[tmp2] && tmp2==arr1[tmp1]){
                    continue;
                }
                else{
                    f = false; 
                    break;
                }
            }
            if(f) ans++;
        }
    }

    cout << ans << '\n';
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> str[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}