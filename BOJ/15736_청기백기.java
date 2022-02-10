/**
 * 22-02-10
 * BOJ 15736 청기백기
 * 수학
 */

import java.util.Scanner;

public class test {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        long idx = 1;
        long ans = 0;
        while(true){
            if(idx > N) break;

            if(idx * idx <= N)
                ans++;

            idx++;
        }
        System.out.println(ans);
    }
}