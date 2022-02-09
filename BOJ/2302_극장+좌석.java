/**
 * 22-02-09
 * BOJ 2302 극장좌석
 * DP
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int[] arr = new int[N+1];
        int ans = 1;

        // make
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2; i<=N; i++)
            arr[i] = arr[i-1] + arr[i-2];

        int x = 0;
        int cur = 0;
        for(int i=0; i<M; i++){
            x = Integer.parseInt(br.readLine());
            ans *= arr[x - cur - 1];
            cur = x;
        }

        ans *= arr[N-x];
        System.out.println(ans);
    }
}