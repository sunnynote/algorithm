/**
 * 22-02-12
 * BOJ 1038 감소하는 수
 * 브루트포스
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test{

    static int N;
    static Queue<Long> q;
    static ArrayList<Long> arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        q = new LinkedList<>();
        arr = new ArrayList<>();

        solve();

        Collections.sort(arr);

        if(1023 <= N)
            System.out.println(-1);
        else
            System.out.println(arr.get(N));
    }

    static void solve() {
        for (long i=0; i<=9; i++) {
            q.add(i);
            arr.add(i);
        }

        int idx = 9;

        while (idx <= N) {
            if (q.isEmpty()) return;

            long num = q.poll();

            for (int i = 0; i <= 9; i++) {
                if (num % 10 > i) {
                    long tmp = num * 10 + i;
                    q.add(tmp);
                    arr.add(tmp);
                    idx++;
                }
            }
        }
    }
}