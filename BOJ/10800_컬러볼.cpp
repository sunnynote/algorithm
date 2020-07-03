/**
 * 200702
 * BOJ 10800 컬러볼
 * 구현
 * */

#include <iostream>
#include <vector>
using namespace std;

struct Info{
    int idx, color, size;
};
vector <Info> ball;

int N;
int tot=0; // 같은 크기
int sum[200005]; // 같은 색깔 모은 합
int ans[200005];

bool cmp(const Info &b1, const Info &b2){
    if(b1.size < b2.size) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        ball.push_back({i, x, y});
    }

    sort(ball.begin(), ball.end(), cmp);

    for(int i=0; i<N; i++){
        int cur = i; // 마지막으로 잡을 수 있는 공의 인덱스

        while( cur<N && ball[i].size==ball[cur].size ){
            cur++;
        }

        for(int j=i; j<cur; j++){
            ans[ball[j].idx] = tot - sum[ball[j].color]; 
        }

        for(int j=i; j<cur; j++){
            tot += ball[j].size; // 현재 총 합
            sum[ball[j].color] += ball[j].size; // 색깔 별 누적 합
        }

        i = cur - 1;
    }

    for(int i=0; i<N; i++)
        cout << ans[i] << '\n';

    return 0;
}