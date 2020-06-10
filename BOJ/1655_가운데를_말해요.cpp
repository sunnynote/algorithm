/**
 * 200610
 * 1655 가운데를 말해요
 * Priority_queue & Heap
 * */
#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    priority_queue <int> pqLeft, pqRight;
    int x;

    for(int i=1; i<=N; i++){
        cin >> x;
        
        if(pqLeft.size() == pqRight.size())
            pqLeft.push(x);
        else
            pqRight.push(-x);
        
        if(!pqLeft.empty() && !pqRight.empty() && pqLeft.top()>-pqRight.top()){

            int lPush = -pqRight.top();
            int rPush = pqLeft.top();
            pqLeft.pop();
            pqRight.pop();

            pqLeft.push(lPush);
            pqRight.push(-rPush);
        }

        cout << pqLeft.top() << '\n';
    }
    
    return 0;
}
