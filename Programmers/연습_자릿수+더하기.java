/**
* 22-11-08
* Programmers 연습 - 자릿수 더하기
*/

public class Solution {
    public int solution(int n) {
        int answer = 0;

        while(n > 0){
            answer += n % 10;
            n /= 10;
        }

        return answer;
    }
}