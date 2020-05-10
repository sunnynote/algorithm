#include <iostream>
#include <cstring>
using namespace std;

int ans = 0;
int N, X;
int arr[22][22];
int sero_a[22][22];
bool check[22];

void func(int a[22][22]){

    for(int i=0; i<N; i++){
        memset(check, 0, sizeof(check));

        bool flag = true;
        for(int j=0; j<N-1; j++){     

            if(a[i][j]>a[i][j+1]){ //down
                if(a[i][j]-a[i][j+1] != 1 || j+X >= N){
                    cout << 1 << ' ' << j;
                    flag = false;
                    break;
                }

                check[j+1]=true;
                for(int k=1; k<X; k++){
                    if(a[i][(j+1)]!=a[i][(j+1)+k]){
                        cout << 2 << ' '<< j;
                        flag=false;
                        break;
                    }
                    check[j+1+k]=true;
                }
            }

            else if(a[i][j]<a[i][j+1]){ //up
            // cout << "aj, aj+1 " << a[j] << ' ' << a[j+1] << '\n';
                if(a[i][j+1]-a[i][j] != 1 || j-(X-1) < 0){
                    cout << 3 <<' ' << j << '\n';
                    flag=false;
                    break;
                }

                check[j]=true;
                for(int k=1; k<X; k++){
                    if(a[i][j]!=a[i][j-k] || check[j-k]){
                        cout << 4 << ' ' << j;
                        flag=false;
                        break;
                    }
                    check[j-k]=true;
                }
            }

        }
cout << "[i,flag] " << i << ' ' << flag << '\n';
        if(flag) ans++;
    }
}

int main(int argc, char** argv){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        ans = 0;

        cin >> N >> X;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
                sero_a[j][i] = arr[i][j];
            }

        func(arr);
        cout << '\n';
        func(sero_a);
        
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
