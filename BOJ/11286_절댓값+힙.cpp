#include <iostream>
#include <queue>
using namespace std;

struct info{
    int x;
    bool flag;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    priority_queue <pair<int, bool> > pq;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;

        if(x!=0){
            if(x>0)
                pq.push(make_pair(-x, false));
            else
                pq.push(make_pair(x, true));
        }
        else{
            if(!pq.empty()){
                if(pq.top().second==true){
                    cout << pq.top().first << '\n';
                    pq.pop();
                }
                else{
                    cout << -pq.top().first << '\n';
                    pq.pop();
                }                
            }
            else
                cout << 0 << '\n';
        }
    }
    return 0;
}
