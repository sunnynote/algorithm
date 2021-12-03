/**
 * 21-12-03
 * BOJ 14467 소가 길을 건너간 이유1
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p14467 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[10+2];

        int ans = 0;

        for(int i=1; i<=10; i++)
            arr[i] = -1;

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(arr[a]!=-1 && arr[a]!=b) ans++;
            arr[a] = b;
        }

        System.out.println(ans);
    }
}