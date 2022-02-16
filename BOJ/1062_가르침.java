/**
 * 22-02-17
 * BOJ 1062 가르침
 * DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {

    static int N, K;
    static String[] str;
    static boolean[] chk;
    static int ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        str = new String[N];
        chk = new boolean[26];

        for(int i=0; i<N; i++) {
            str[i] = br.readLine();
        }

        if(K>=5){
            K -= 5;
            chk['a'-'a'] = true;
            chk['n'-'a'] = true;
            chk['t'-'a'] = true;
            chk['i'-'a'] = true;
            chk['c'-'a'] = true;

            solve(0, 0);
        }
        else if(K==26){
            ans = N;
        }
        else {
            ans = 0;
        }

        System.out.println(ans);
    }

    static void solve(int idx, int cnt){
        if(cnt==K){
            ans = Math.max(ans, func());
            return;
        }

        for(int i=idx; i<26; i++){
            if(chk[i]) continue;

            chk[i] = true;
            solve(i, cnt+1);
            chk[i] = false;
        }
    }

    static int func(){
        int val = 0;

        for(int i=0; i<N; i++){
            boolean f = true;

            for(int j=4; j<str[i].length()-4; j++){
                char c = str[i].charAt(j);

                if(!chk[c-'a']){
                    f = false;
                    break;
                }
            }

            if(f) val++;
        }
        return val;
    }
}