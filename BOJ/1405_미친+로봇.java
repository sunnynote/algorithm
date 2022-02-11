import java.util.Scanner;

/**
 * 22-02-11
 * BOJ 1405 미친 로봇
 */

public class test2{

    static int N;
    static double[] arr;
    static boolean[][] chk;
    static double ans;

    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        arr = new double[4];
        chk = new boolean[29][29];
        ans = 0.0;

        for(int i=0; i<4; i++){
            arr[i] = sc.nextInt();
            arr[i] *= 0.01;
        }

        chk[14][14] = true;
        dfs(14, 14, 0, 1.0);

        System.out.println(ans);
    }

    static void dfs(int x, int y, int cnt, double val){
        if(cnt==N){
            ans += val;
            return;
        }

//        chk[x][y] =true;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(chk[nx][ny]) continue;

            chk[nx][ny] = true;
            dfs(nx, ny, cnt+1, val*arr[i]);
            chk[nx][ny] = false;
        }
    }
}