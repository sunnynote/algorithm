/**
 * 22-02-05
 * BOJ 1253 좋다
 * 투포인터
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int ans = 0;

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);

        for(int i=0; i<N; i++){
            int target = arr[i];

            int l = 0;
            int r = N-1;

            while(l < r){
                int sum = arr[l] + arr[r];

                if(sum==target){
                    if(l != i && r != i){
                        ans++;
                        break;
                    }
                    else if(l==i) l++;
                    else if(r==i) r--;
                }
                else if(sum < target) l++;
                else r--;
            }
        }

        System.out.println(ans);
    }
}