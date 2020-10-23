/**
 * 20-10-06
 * BOJ 8982 수족관1
 * 시뮬레이션
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int x, y, z, w;
vector <int> v;
vector <int> check;
vector <int> water;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    cin >> x >> y;
    for(int i=0; i<N/2-1; i++){
        cin >> x >> y >> z >> w;

        if(z-x == 1) v.push_back(y);
        else{
            for(int i=0; i<z-x; i++)
                v.push_back(y);
        }
    }
    cin >> x >> y;

    check.resize(v.size());
    water.resize(v.size());

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> x >> y >> z >> w;
        
        for(int i=x; i<z; i++)
            check[i] = y;
    }
    water = check;

    for(int i=0; i<check.size(); i++){
        if(check[i]!=0){

            if(i>0){
                int MN = check[i];
                for(int j=i-1; j>=0; j--){ // left
                    if(check[j]!=0 || MN<water[j]) break;

                    MN = min(MN, v[j]);
                    water[j] = MN;
                } 
            }

            if(i<check.size()-1){
                int MN = check[i];
                for(int j=i+1; j<check.size(); j++){ // right
                    if(check[j]!=0 || MN<water[j]) break;    

                    MN = min(MN, v[j]);
                    water[j] = MN;
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<v.size(); i++)
        ans += (v[i] - water[i]);
    
    cout << ans <<'\n';
    return 0;
}
