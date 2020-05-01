#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> v1;
vector <pair<string, int> > v2;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    v1.push_back(".");
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
    
        v1.push_back(s);
        v2.push_back(make_pair(s, i));
    }

    sort(v2.begin(), v2.end());

    for(int i=1; i<=M; i++){
        string s;
        cin >> s;

        // 숫자로 들어오면 이름 출력
        if('0'<=s[0] && s[0]<='9')
            cout << v1[ stoi(s) ] << '\n';

        // 이름 들어오면 숫자 출력
        else{
            int left = 0;
            int right = N-1;

            while(left<=right){
                int mid = (left+right)/2;

                if(v2[mid].first == s){
                    cout << v2[mid].second << '\n';
                    break;
                }
                else if(v2[mid].first < s)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

    }

    return 0;
}
