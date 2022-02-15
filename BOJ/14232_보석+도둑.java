/**
 * 22-02-15
 * BOJ 14232 보석 도둑
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class test {

    static long N;
    static ArrayList<Long> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Long.parseLong(br.readLine());
        arr = new ArrayList<>();

        solve();

        System.out.println(arr.size());
        for(int i=0; i<arr.size(); i++)
            System.out.print(arr.get(i) + " ");
    }

    static void solve(){
        long tmp = N;

        for(long i=2; i*i<=N; i++) {
            while (tmp%i==0) {

                if (tmp % i == 0) {
                    tmp /= i;
                    arr.add(i);
                }
            }
        }

        if(tmp!=1) arr.add(tmp);
    }
}