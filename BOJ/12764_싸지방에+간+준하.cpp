#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Info{
    int s, e;
};

int N;
vector <pair<int,int> > v;
priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
priority_queue <int, vector<int>, greater<int> > com;
int arr[100005];
int ans = -1;

int mx(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){

    cin >> N;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int idx = 0;

    for(int i=0; i<N; i++){
        
        while(!pq.empty() && v[i].first >= pq.top().first){
            com.push(pq.top().second);
            pq.pop();
        }

        if(com.empty()){
            pq.push({v[i].second, idx});
            arr[idx++]++;
        }
        else{
            int nx = com.top();
            com.pop();

            pq.push({v[i].second, nx});
            arr[nx]++;
        }

        ans = mx(ans, pq.size());
    }

    cout << ans << '\n';
    for(int i=0; i<ans; i++){
        cout << arr[i] << ' ';
    }
}