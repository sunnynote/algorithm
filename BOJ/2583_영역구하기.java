/**
 * 22-02-12
 * BOJ 2583 영역 구하기
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test{

    static int N, M, K;
    static int[][] arr;
    static int[][] chk;
    static int cnt;

    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};

    static ArrayList<Integer> res;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[N+1][M+1];
        chk = new int[N+1][M+1];

        res = new ArrayList<>();

        for (int i=0; i<K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            for (int j=x; j<a; j++) {
                for (int k=y; k<b; k++) {
                    arr[j][k] = 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) {
                if(arr[i][j]==0 && chk[i][j]==0) {
                    ans++;
                    cnt = 0;
                    bfs(i, j);
                    res.add(cnt);
                }
            }
        }

        Collections.sort(res);

        System.out.println(ans);
        for(int i=0; i<res.size(); i++)
            System.out.print(res.get(i) + " ");
        System.out.println();
    }

    static void bfs(int x, int y){
        Queue<Info> q = new LinkedList<>();
        q.add(new Info(x, y));
        chk[x][y] = ++cnt;

        while(!q.isEmpty()){
            x = q.peek().x;
            y = q.poll().y;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<M){
                    if(arr[nx][ny]==0 && chk[nx][ny]==0){
                        q.add(new Info(nx, ny));
                        chk[nx][ny] = ++cnt;
                    }
                }
            }
        }
    }
}

class Info{
    int x, y;
    Info(int x, int y){
        this.x = x;
        this.y = y;
    }
}
