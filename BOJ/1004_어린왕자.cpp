#include <iostream>
using namespace std;

bool dist(int pointX, int pointY, int x, int y, int r){
    int d = (pointX-x)*(pointX-x) + (pointY-y)*(pointY-y);
    
    if(d < r*r) return true;
    return false;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int sx, sy, ex, ey;
        int N;

        cin >> sx >> sy >> ex >> ey;
        cin >> N;
        
        int ans = 0;
        for(int i=0; i<N; i++){
            int x, y, r;
            cin >> x >> y >> r;
            
            bool d1 = dist(sx, sy, x, y, r);
            bool d2 = dist(ex, ey, x, y, r);

            if( (!d1 && d2) || (d1 && !d2))  ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}
