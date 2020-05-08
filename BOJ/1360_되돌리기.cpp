#include <iostream>
using namespace std;

int a[102][3];
char b[102]; //str

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string str; 
        char ch; int nn;
        int t;
        cin >> str;

        if(str=="type") {
            cin >> ch >> t;
            a[i][0] = 1;
            b[i] = ch;
        }
        else {
            cin >> nn >> t;
            a[i][0] = 2;
            a[i][1] = nn;
        }

        a[i][2] = t;
    }

    for(int i=N-1; i>=0; i--){
        if(a[i][0]==2){
            int term = a[i][2]-a[i][1];

            for(int j=i-1; j>=0; j--){
                if(term <= a[j][2]) a[j][0]=0;
                else break;
            } 
        }
    }

    for(int i=0; i<N; i++)
        if(a[i][0] == 1) cout << b[i];
        
    return 0;
}