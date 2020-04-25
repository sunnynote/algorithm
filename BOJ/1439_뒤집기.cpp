#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt = 1;
    for(int i=0; i<s.size()-1; i++){
        if( s[i] != s[i+1]) cnt++;
    }

    int ans;
    if(cnt==1) ans = 0;
    else if(cnt==2 || cnt==3) ans = 1;
    else ans = cnt/2;

    cout << ans;
    return 0;
}