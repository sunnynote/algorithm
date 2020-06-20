/**
 * 200619
 * BOJ 4386
 * MST : Union_find
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
pair <double, double> arr[105];

struct Info{
    double dist;
    int from, to;
};

vector <Info> v;
int parent[105];

bool cmp(const Info &d1, const Info &d2){
    if(d1.dist<d2.dist)
        return true;
    return false;
}

int findParent(int a){
    if(a==parent[a]) return a;
    return parent[a]=findParent(parent[a]);
}

bool isSame(int a, int b){
    return findParent(a)==findParent(b);
}

void unite(int A, int B){
    A = findParent(A);
    B = findParent(B);

    if(A==B) return;
    if(A>B) swap(A,B);

    parent[A] = B;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i].first >> arr[i].second;
    
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            double d = sqrt(pow((arr[i].first - arr[j].first), 2)
                        + pow((arr[i].second - arr[j].second), 2));
            v.push_back( {d, i, j} );
        }
    }

    sort(v.begin(), v.end(), cmp);

    double ans = 0;
    int cnt = 0; 
    for(int i=0; i<N; i++)
        parent[i] = i;

    for(int i=0; i<v.size(); i++){
        double D = v[i].dist;
        int A = v[i].from;
        int B = v[i].to;
        
        if(!isSame(A, B)){
            ans += D;
            cnt++;
            unite(A, B);
        }

        if(cnt>=N-1) break;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}
