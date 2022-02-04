/**
 * 22-02-04
 * BOJ 15661 링크와 스타트
 * dfs
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test{

    static int N, ans;
    static int[][] arr;
    static boolean[] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        chk = new boolean[N];
        ans = Integer.MAX_VALUE;

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int j=0; j<N; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=1; i<N; i++)
            dfs(i,1,0);

        System.out.println(ans);
    }

    public static void dfs(int n, int idx, int cnt){
        if(cnt==n){
            int val = score();
            if(ans > val) ans = val;
        }

        for(int i=idx; i<N; i++){
            if(chk[i]) continue;

            chk[i] = true;
            dfs(n, i, cnt+1);
            chk[i] = false;
        }
    }

    public static int score(){
        int start = 0;
        int link = 0;

        for(int i=0; i<N-1; i++){
            for(int j=i+1; j<N; j++){
                if(chk[i] && chk[j]){
                    start += (arr[i][j] + arr[j][i]);
                }
                else if(!chk[i] && !chk[j]){
                    link += (arr[i][j] + arr[j][i]);
                }
            }
        }

        return Math.abs(start - link);
    }
}