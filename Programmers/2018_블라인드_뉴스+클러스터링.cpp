#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s1, string s2) {
    int answer = 0;

    vector <string> vStr1;
    vector <string> vStr2;

    for(int i=0; i<s1.size()-1; i++){
        string data="  ";
        if( (('A'<=s1[i] && s1[i]<='Z') || ('a'<=s1[i] && s1[i]<='z'))
            && (('A'<=s1[i+1] && s1[i+1]<='Z') || ('a'<=s1[i+1] && s1[i+1]<='z')) ){
                data[0] = toupper(s1[i]);
                data[1] = toupper(s1[i+1]);
                vStr1.push_back(data);
        }
    }

    for(int i=0; i<s2.size()-1; i++){
        string data="  ";
        if( (('A'<=s2[i] && s2[i]<='Z') || ('a'<=s2[i] && s2[i]<='z'))
            && (('A'<=s2[i+1] && s2[i+1]<='Z') || ('a'<=s2[i+1] && s2[i+1]<='z')) ){
                data[0] = toupper(s2[i]);
                data[1] = toupper(s2[i+1]);
                vStr2.push_back(data);
        }
    }

    if(vStr1.size()==0 && vStr2.size()==0) return 65536;

    int all_cnt = vStr1.size() + vStr2.size();
    int same_cnt = 0;

    for(int i=0; i<vStr2.size(); i++){

        for(int j=0; j<vStr1.size(); j++){
            if( (vStr2[i][0]==vStr1[j][0]) && (vStr2[i][1]==vStr1[j][1]) ){
                same_cnt++;
                vStr1[j]="";
                break; // 일치하면 다음 문자로
            }
        }
    }

    // 합집합 = A + B - (교집합)
    all_cnt = all_cnt - same_cnt;

    answer = ((float)same_cnt / (float)all_cnt) * 65536;

    return answer;
}

// int main(){
//     string str1, str2;
//     getline(cin, str1);
//     getline(cin, str2);

//     cout << solution(str1, str2);
// }