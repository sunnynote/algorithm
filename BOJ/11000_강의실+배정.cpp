
/**
 * 20-03-08
 * BOJ 11000 강의실 배정
 * */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Info{
    int x, y;
};

int N;
Info arr[200000];
priority_queue <int> pq;

bool cmp(Info &i1, Info &i2){
    if(i1.x == i2.x) return i1.y < i2.y;
    return i1.x < i2.x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> arr[i].x  >> arr[i].y;

    sort(arr, arr+N, cmp);

    pq.push(-arr[0].y);
    for(int i=1; i<N; i++){
        if(arr[i].x >= -pq.top())
            pq.pop();
        pq.push(-arr[i].y); 
        cout << pq.size() << ' ';
    } cout << '\n';

    cout << pq.size() << '\n';

    return 0;
}