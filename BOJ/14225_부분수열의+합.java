/**
 * 22-02-13
 * BOJ 14225 부분수열의 합
 * 재귀
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test{

    static int N;
    static int[] arr;
    static boolean[] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        chk = new boolean[20 * 100000 + 1];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        solve(0, 0);

        int idx = 1;
        while(chk[idx]){
            idx++;
        }

        System.out.println(idx);
    }

    static void solve(int cnt, int sum) {
        if (cnt == N) {
            chk[sum] = true;
            return;
        }

        solve(cnt + 1, sum);
        solve(cnt + 1, sum + arr[cnt]);
    }
}