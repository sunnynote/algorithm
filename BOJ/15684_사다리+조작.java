/**
 * 22-02-18
 * BOJ 15684 사다리 조작
 * DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {

    static int N, M, H;
    static boolean[][] arr;
    static int ans;
    static int ladder;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        arr = new boolean[30+1][10+1];
        ans = Integer.MAX_VALUE;
        ladder = 0;

        for(int i=0; i<M; i++){
            int x, y;
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            arr[x][y] = true;
        }

        for(int i=0; i<=3; i++){
            ladder = i;
            solve(0, 0);
        }

        if(ans==Integer.MAX_VALUE) ans = -1;
        System.out.println(ans);
    }

    static void solve(int idx, int cnt){
        if(cnt > 3)
            return;

        if(cnt==ladder){
            if(chk())
                ans = Math.min(ans, cnt);
            return;
        }

        for(int i=idx; i<=H; i++){
            for(int j=1; j<N; j++){
                if(arr[i][j] || arr[i][j-1] || arr[i][j+1])
                    continue;

                arr[i][j] = true;
                solve(i, cnt+1);
                arr[i][j] = false;
            }

        }
    }

    static boolean chk(){
        for(int i=1; i<=N; i++){
            int cur = i;

            for(int j=1; j<=H; j++){
                if(arr[j][cur])
                    cur++;
                else if(arr[j][cur-1])
                    cur--;
            }

            if(i != cur) return false;
        }

        return true;
    }
}