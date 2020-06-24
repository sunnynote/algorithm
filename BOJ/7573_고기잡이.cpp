/**
 * 200624
 * BOJ 7573 고기잡이
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, L ,M;
pair<int,int> fish[105];

int ans = -1;

void netting(int X, int Y){
    for(int len=1; len<L/2; len++){
        int H = len;
        int W = L/2 - H;

        int cnt = 0;
        for(int i=1; i<=M; i++){
            int x = fish[i].first;
            int y = fish[i].second;

            if(X<=x && x<=X+H && Y<=y && y<=Y+W) cnt++;
            ans = max(ans, cnt);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L >> M;
    for(int i=1; i<=M; i++){
        int x, y;
        cin >> x >> y;
        fish[i].first = x; 
        fish[i].second = y;
    }
    
    for(int i=1; i<=M; i++)
        for(int j=1; j<=M; j++)
            netting(fish[i].first, fish[j].second);

    cout << ans;
    return 0;
}
