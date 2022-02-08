/**
 * 22-02-08
 * BOJ 1747 소수&팰린드롬
 * 소수, 투포인터
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test{
    static int N;
    static boolean[] prime_arr;
    static int MX = 1003001 + 2;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        prime_arr = new boolean[MX+2];

        make_prime();

        for(int i=N; i<=MX; i++){
            if(!prime_arr[i] && is_pal(i)){
                System.out.println(i);
                break;
            }
        }
    }

    static void make_prime(){
        prime_arr[1] = true;

        for(int i=2; i*i<=MX; i++){
            if(prime_arr[i]) continue;

            for(int j=i*i; j<=MX; j+=i)
                prime_arr[j] = true;
        }
    }

    static boolean is_pal(int n){
        String s = Integer.toString(n);

        int l = 0;
        int r = s.length()-1;

        boolean flag = true;

        while(l < r){
            if(s.charAt(l)!=s.charAt(r)) {
                flag = false;
                break;
            }
            l++;
            r--;
        }

        if(flag) return true;
        return false;
    }
}