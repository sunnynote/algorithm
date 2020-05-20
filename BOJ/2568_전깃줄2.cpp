/**
 * 200519
 * BOJ 2568 전깃줄2
 * DP(LIS) 가장 긴 증가하는 부분 수열 
 *      + LIS 배열의 값 추적을 위한 이분탐색, trace 배열 이용
 * */

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N;
pair<int,int> a[100005]; //input
pair<int,int> trace[100005]; // A의 idx, 연결된 B의 idx

bool check[500005]; // 사용하지 않은 것 확인
int d[100005]; 
stack <int> st;

int _lower_bound(int start, int end, int key) {
    int mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (d[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}

int solution(){
    int idx = 0; // d

    d[0] = a[0].second;
    trace[0] = {0, a[0].first};

    for(int i=1; i<N; i++){
        if(d[idx] < a[i].second){
            d[++idx] = a[i].second;
            trace[i] = {idx, a[i].first};
        }
        else{
            int iidx = _lower_bound(0, idx, a[i].second) - 1;
            d[iidx] = a[i].second;
            trace[i] = {iidx, a[i].first};
        }
    }

    return idx+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i].first >> a[i].second;
        check[ a[i].first ] = true;
    }
    
    sort(a, a+N);

    int res = solution(); // 최장 수열 길이
    cout << N-res << '\n';

    // LIS 생성시 사용된 전깃줄 찾아(trace 이용) st에 push
    int num = res-1;
    for(int i=N-1; i>=0; i--){
        if(trace[i].first == num){
            st.push(trace[i].second);
            num--;
        }
    }
    
    // LIS에 사용된 전기줄 false로 바꾸기
    while(!st.empty()){
        check[st.top()]=false;
        st.pop();
    }

    // 남아있는 것이 사용하지 않은 전깃줄 번호
    for(int i=1; i<=500000; i++)
        if(check[i]) cout << i << '\n';

    return 0;
}