/**
 * 200711
 * BOJ 2841 외계인의 기타 연주
 * stack
 * */

#include <iostream>
#include <stack>
using namespace std;

int N, P;
stack <int> st[7];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> P;

    int num, fret;
    int ans = 0;
    
    for(int i=1; i<=N; i++){
        cin >> num >> fret;

        if(st[num].empty()){
            st[num].push(fret);
            ans++;
        }
        
        else{
            if(st[num].top()==fret) continue;

            if(st[num].top()<fret){
                st[num].push(fret);
                ans++;
            }
            else{
                while(1){
                    if(st[num].empty() || st[num].top()<fret){
                        st[num].push(fret);
                        ans++;
                    }
                    else{
                        if(st[num].top()>fret){
                            st[num].pop();
                            ans++;
                        }
                        else break;
                    }
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
