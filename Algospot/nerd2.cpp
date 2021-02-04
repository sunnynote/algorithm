/**
 * 21-02-05
 * 너드 인가, 너드가 아닌가? 2
 * 이진 탐색 트리
 * */

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N;
map <int, int> info;

void removeDominated(int x, int y){
    map<int, int>:: iterator it = info.lower_bound(x);

    if(it==info.begin()) return;

    it--;
    while(1){
        if(it->second > y) break;
        if(it==info.begin()){
            info.erase(it);
            break;
        }
        else{
            map<int,int>::iterator jt = it;
            jt--;
            info.erase(it);
            it = jt;
        }
    }
}

bool isDominated(int x, int y){
    map<int, int>:: iterator it = info.lower_bound(x);
    
    if(it==info.end()) return false;
    if(y < it->second) return true;
    return false;
}

int solve(int x, int y){
    if(isDominated(x, y)) return info.size();

    removeDominated(x, y);
    info[x] = y;

    return info.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;
    while(TC--){
        info.clear();
        int ans = 0;

        cin >> N;

        int x, y;
        for(int i=0; i<N; i++){
            cin >> x >> y;
            ans += solve(x, y);
        }

        cout << ans << '\n';   
    }

    return 0;
}