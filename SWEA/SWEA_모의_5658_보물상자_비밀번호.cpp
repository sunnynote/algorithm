#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[7];
vector <int> v;

int main(){
    int T;
    cin >> T;
    for (int test_case=1; test_case<=T; test_case++){
        int N, K;
        cin >> N >> K;

        string str;
        cin >> str;

        int k = str.length() / 4; // 각 변
        int t = k; // 한 변에 적혀진 숫자 갯수
        int sum = 0;

        while (t--){
            for (int i=0; i<4; i++) { // 네 변 돌린다

                // 10진수 변환
                for (int j=0; j<k; j++) {
                    if ( str[(k*i) + j] >= 'A') // 10이상
                        a[j] = str[(k*i) + j] - 'A' + 10;
                    else // 10이하
                        a[j] = str[(k*i) + j] - '0';

                    int mul = pow(16, k-j-1); //16^(k-j-1)
                    a[j] *= mul;
                    sum += a[j];
                }

                // 변환된 수 벡터에 삽입
                v.push_back(sum);

                sum = 0;
                memset(a, 0, sizeof(a));
            }

            // 회전
            char tmp = str[str.size() - 1];
            for (int i = str.size()-2; i>=0; i--)
                str[i+1] = str[i];
            str[0] = tmp;
        }

        sort(v.begin(), v.end());
        
        // 중복 제거
        for (int i=0; i<v.size()-1; i++) {
            if (v[i] == v[i+1]) {
                for (int j=i+1; j<v.size()-1; j++)
                    v[j] = v[j+1];
                v.pop_back();
            }
        }

        //거꾸로 세서 출력
        cout << "#" << test_case << ' ' << v[v.size()-K] << '\n'; 
        v.clear();
    }

    return 0;
}