/**
 * 22-02-05
 * BOJ 2473 세 용액
 * 투포인터, 정렬
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        long[] arr = new long[N];
        long[] ans = new long[3];
        long mn = Long.MAX_VALUE;

        st = new StringTokenizer(br.readLine());

        for(int i=0; i<N; i++)
            arr[i] = Long.parseLong(st.nextToken());

        Arrays.sort(arr);

        for(int i=0; i<N-2; i++){
            int l = i+1;
            int r = N-1;

            while(l < r){
                long sum = arr[i] + arr[l] + arr[r];
                if(mn > Math.abs(sum)){
                    mn = Math.abs(sum);
                    ans[0] = arr[i];
                    ans[1] = arr[l];
                    ans[2] = arr[r];
                }

                if(sum==0) break;
                else if(sum < 0) l++;
                else r--;
            }
        }

        System.out.println(ans[0] + " " + ans[1] + " " + ans[2]);
    }
}
