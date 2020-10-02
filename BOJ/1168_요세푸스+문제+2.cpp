/**
 * 20-10-02
 * BOJ 1168 요세푸스 문제 2
 * */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector <int> v;
    for(int i=1; i<=N; i++)
        v.push_back(i);
    
    int cur = -1;
    int res = N;
    
    cout << "<";
    for(int i=1; i<=N; i++){
        cur = (cur+K) % res;
        cout << v[cur];

        v.erase(v.begin()+cur);
        cur--; res--;

        if(i!=N) cout << ", ";
        else cout << ">\n";
    }

    return 0;
}
