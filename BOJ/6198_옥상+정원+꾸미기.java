/**
 * 21-12-02
 * BOJ 6198 옥상 정원 꾸미기
 * STACK
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class p6198 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long ans = 0;

        Stack<Integer> st = new Stack<>();

        for(int i=0; i<N; i++){
            int cur = Integer.parseInt(br.readLine());

            while(!st.isEmpty() && st.peek() <= cur){
                st.pop();
            }

            ans += st.size();
            st.push(cur);
        }

        System.out.println(ans);
    }
}