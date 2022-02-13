import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test{

    static int N;
    static int[] arr;
    static boolean[] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        chk = new boolean[20 * 100000 + 1];

        solve(0, 0);

        boolean f = false;
        int idx = 0;
        while(true){
            if(f) break;

            if(chk[idx++]){
                System.out.println(idx);
                f = true;
            }
        }
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