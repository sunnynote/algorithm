/**
 * 21-10-27
 * Programmers
 * 2021 인턴십
 * 숫자 문자열과 영단어
 * */
#include <string>
using namespace std;

string num_str[11] = {"zero", "one", "two", "three", "four", 
                      "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;

    for(int i=0; i<s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            answer = answer*10 + (s[i]-'0');
        } 
        else {
            for(int j=0; j<=9; j++){

                bool f = true;
                int tmp_i = i;

                for(int k=0; k<num_str[j].size(); k++){
                    if(num_str[j][k] != s[tmp_i++]){
                        f = false;
                        break;
                    }
                }

                if(f) {
                    i += (num_str[j].size() - 1);
                    answer = answer * 10 + j;
                    break;
                }
            }
        }
    }

    return answer;
}