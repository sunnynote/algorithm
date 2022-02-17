/**
 * 22-02-17
 * BOJ 4889 안정적인 문자열
 * STACK
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class test {
    static int ans;
    static int cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String str = br.readLine();
            if(str.charAt(0)=='-') break;

            solve(str);

            System.out.println(++cnt + ". " + ans);
        }
    }

    static void solve(String s){
        ans = 0;
        Stack<Character> st = new Stack<>();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='{')
                st.push(s.charAt(i));
            else{
                if(!st.isEmpty() && st.peek()=='{')
                    st.pop();
                else
                    st.push(s.charAt(i));
            }
        }

        if(st.size()==0){
            ans = st.size();
        }
        else{
            while(!st.isEmpty()){
                ans++;

                if(!st.isEmpty() && st.peek()=='{'){
                    st.pop();

                    if(!st.isEmpty() && st.peek()=='}') {
                        ans++;
                    }

                    st.pop();
                }
                else{
                    st.pop();
                    st.pop();
                }
            }
        }
    }
}