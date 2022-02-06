/**
 * 22-02-07
 * BOJ 7576 토마토
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class test {

    static int N, M;
    static int[][] arr;
    static int[][] chk;

    static int[] dx = {0,1,-1,0};
    static int[] dy = {-1,0,0,1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        chk = new int[N][M];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine(), " ");

            for(int j=0; j<M; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                chk[i][j] = -1;
            }
        }

        bfs();

        boolean f = false;
        int ans = Integer.MIN_VALUE;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]==0 && chk[i][j]==-1){
                    f = true;
                }
                else{
                    if(ans < chk[i][j]){
                        ans = chk[i][j];
                    }
                }
            }
            if(f) break;
        }

        if(f) System.out.println(-1);
        else System.out.println(ans);
    }

    static void bfs(){
        Queue<Info> queue = new LinkedList<Info>();

        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(arr[i][j]==1) {
                    queue.add(new Info(i, j));
                    chk[i][j] = 0;
                }

        while(!queue.isEmpty()){
            Info info = queue.poll();

            for(int i=0; i<4; i++){
                int nx = info.x + dx[i];
                int ny = info.y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<M){
                    if(arr[nx][ny]==0 && chk[nx][ny]==-1){
                        chk[nx][ny] = chk[info.x][info.y] + 1;
                        queue.add(new Info(nx, ny));
                    }
                }
            }
        }
    }
}

class Info{
    int x;
    int y;

    Info(int x, int y){
        this.x = x;
        this.y = y;
    }
}