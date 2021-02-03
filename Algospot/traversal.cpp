/**
 * 21-02-03
 * 트리 순회 순서 변경
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& v, int a, int b){
    return vector<int>(v.begin()+a, v.begin()+b);
}

void solve(const vector<int>& preOrder, const vector<int>& inOrder){

    if(preOrder.empty()) return;

    int N = preOrder.size(); // 트리에 포함된 노드의 수
    int root = preOrder[0];

    /**
     * 왼쪽 서브 트리 크기
     * 중위 탐색에서 루트의 위치를 찾는다
     **/
    int L = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();
    // const int R = N - 1 - L;

    solve(slice(preOrder, 1, L+1), slice(inOrder, 0, L));
    solve(slice(preOrder, L+1, N), slice(inOrder, L+1, N));

    cout << root << ' ';
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector <int> preOrder;
        vector <int> inOrder;
        int node;

        // preorder
        for(int i=0; i<N; i++){
            cin >> node;
            preOrder.push_back(node);
        }

        // inorder
        for(int i=0; i<N; i++){
            cin >> node;
            inOrder.push_back(node);
        }

        solve(preOrder, inOrder);
        cout << '\n';
    }

    return 0;
}