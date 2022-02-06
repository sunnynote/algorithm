/**
 * 22-02-07
 * BOJ 3687 성냥개비
 * DP
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class test {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int[] nums = {0, 0, 1, 7, 4, 2, 0, 8};
        long[] mnDP = new long[101];

        Arrays.fill(mnDP, Long.MAX_VALUE);

        mnDP[2] = 1;
        mnDP[3] = 7;
        mnDP[4] = 4;
        mnDP[5] = 2;
        mnDP[6] = 6;
        mnDP[7] = 8;
        mnDP[8] = 10;

        for(int i=9; i<=100; i++)
            for(int j=3; j<=7; j++)
                mnDP[i] = Math.min(mnDP[i], mnDP[i-j]*10 + nums[j]);

        for(int i=0; i<T; i++){
            int n = Integer.parseInt(br.readLine());

            // mn
            System.out.print(mnDP[n] + " ");

            // mx
            while(n > 0) {
                if (n % 2 == 0) {
                    System.out.print(1);
                    n -= 2;
                } else {
                    System.out.print(7);
                    n -= 3;
                }
            }

            System.out.println();
        }
    }
}