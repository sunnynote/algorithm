/**
 * 22-02-07
 * 20207 달력
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] h = new int[365+3];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());

            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());

            for(int j=left; j<=right; j++)
                h[j]++;
        }

        int ans = 0;
        int x = 0;
        int y = 0;

        for(int i=1; i<=366; i++){
            if(h[i]==0){
                ans += x * y;
                x = 0;
                y = 0;
            }
            else{
                x += 1;
                y = Math.max(y, h[i]);
            }
            if(i==364||i==365)System.out.println(x + " " + y + " " + ans);
        }

        System.out.println(ans);
    }
}