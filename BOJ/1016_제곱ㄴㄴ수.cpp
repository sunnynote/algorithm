#include <iostream>
using namespace std;

long long mn, mx;
long long arr[1000010];
int ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> mn >> mx;

    // mn ~ mx 탐색한다
    for(long long i=2; i*i<=mx; i++){

        // 나누어 떨어지지 않으면 ㄴㄴ수
        long long cur = mn / (i*i);
        if(mn % (i*i) != 0) cur++;


        while(cur*(i*i) <= mx){
            arr[cur*(i*i) - mn] = 1;
            cur++;
        }
    }

    // count
    for(int i=0; i<=mx-mn; i++)
        if(arr[i]==0) ans++;

    cout << ans <<'\n';
    return 0;
}
