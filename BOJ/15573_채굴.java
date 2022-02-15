/**
 * 22-02-15
 * BOJ 15573 채굴
 * 우선순위 큐
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class test {

    static int N, M, K;
    static int[][] map;
    static boolean[][] chk;
    static int mx;
    static int cnt;
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[N+1][M+1];
        chk = new boolean[N+1][M+1];
        mx = -1;
        cnt = 0;

        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        bfs();

        System.out.println(mx);
    }

    static void bfs(){
        PriorityQueue<Info> q = new PriorityQueue<>();

        for(int j=0; j<M; j++) {
            q.add(new Info(-map[0][j], 0, j));
            chk[0][j] = true;
        }

        for(int i=1; i<N; i++){
            q.add(new Info(-map[i][0], i, 0));
            q.add(new Info(-map[i][M-1], i, M-1));
            chk[i][0] = true;
            chk[i][M-1] = true;
        }

        while(!q.isEmpty()){
            int cost = -q.peek().cost;
            int x = q.peek().x;
            int y = q.poll().y;
            cnt++;

            if(mx < cost) mx = cost;
            if(cnt>=K) return;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<M){
                    if(chk[nx][ny]) continue;

                    chk[nx][ny] = true;
                    q.add(new Info(-map[nx][ny], nx, ny));
                }
            }
        }
    }
}

class Info implements Comparable<Info>{
    int cost, x, y;
    Info(int cost, int x, int y){
        this.cost = cost;
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Info i){
        return this.cost <= i.cost ? 1 : -1;
    }
}