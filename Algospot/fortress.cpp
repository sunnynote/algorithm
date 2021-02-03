/**
 * 21-02-03
 * 요새
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int longest;

struct Info{
    int x, y, r;
};
Info arr[102];

struct Tree{
    vector <Tree*> children;
};

int heightCalc(Tree* root){ // root를 루트로 하는 서브트리의 높이 반환
    vector <int> h;

    for(int i=0; i<root->children.size(); i++)
        h.push_back(heightCalc(root->children[i]));

    if(h.empty()) return 0;

    sort(h.begin(), h.end());

    if(h.size() >= 2)
        longest = max(longest, h[h.size()-2] + h[h.size()-1] + 2);

    return h.back() + 1;
}

int solve(Tree* root){
    longest = 0;
    int ret = heightCalc(root);

    return max(longest, ret);
}

int sqr(int x){
    return x * x;
}

int sqrDist(int a, int b){
    return sqr(arr[a].x - arr[b].x) + sqr(arr[a].y - arr[b].y);
}

bool enclose(int a, int b){ // a가 b를 포함하는지
    return arr[a].r > arr[b].r 
        && sqrDist(a, b) < sqr(arr[a].r - arr[b].r);
}

bool isChild(int parent, int child){ // 
    if(!enclose(parent, child))
        return false;

    for(int i=0; i<N; i++){
        if(i != parent && i != child
            && enclose(parent, i) && enclose(i, child) )
            return false;
    }

    return true;
}

Tree* makeTree(int root){ // root를 루트로 하는 트리 만들기
    Tree* ret = new Tree();

    for(int i=0; i<N; i++)
        if(isChild(root, i))
            ret -> children.push_back(makeTree(i));

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int C;
    cin >> C;
    while(C--){
        cin >> N;

        int x, y, r;
        for(int i=0; i<N; i++){
            cin >> x >> y >> r;
            arr[i] = {x, y, r};
        }

        Tree* t = makeTree(0);
        cout << solve(t) << '\n';
    }

    return 0;
}

