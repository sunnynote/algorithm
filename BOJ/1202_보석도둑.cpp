#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int bag[300010];
pair<int,int> jewel[300010];
priority_queue <int> pq;

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> jewel[i].first >> jewel[i].second;
    for(int i=0; i<K; i++)
        cin >> bag[i];

    sort(jewel, jewel+N); // 보석 오름차순
    sort(bag, bag+K); // 가방 오름차순

    long long ans = 0;
    int idx = 0;
    
    // 가방 크기만큼 반복
    for(int i=0; i<K; i++){

        // 가능한 보석 갯수만큼 && 가방 안에 들어갈 수 있는 무게
        while(idx<N && jewel[idx].first<=bag[i]){
            pq.push(jewel[idx].second);
            idx++;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}