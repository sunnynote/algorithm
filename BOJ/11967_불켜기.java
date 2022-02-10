/**
 * 22-02-09
 * 11967 불켜기
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class test2 {

    static int N;
    static int M;
    static ArrayList<Info>[][] map;
    static int[][] light;
    static boolean[][] chk;
    static boolean[][] avail;
    static int ans = 0;

    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new ArrayList[N+1][N+1];
        light = new int[N+1][N+1];
        chk = new boolean[N+1][N+1];
        avail = new boolean[N+1][N+1];

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                map[i][j] = new ArrayList<>();

        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            map[x][y].add(new Info(a,b));
        }

        bfs();

        System.out.println(ans);
    }

    static void bfs(){
        Queue<Info> q = new LinkedList<>();
        q.add(new Info(0,0));

        light[0][0] = ++ans;
        chk[0][0] = true;

        while(!q.isEmpty()){
            int x = q.peek().x;
            int y = q.poll().y;

            // 이동 가능한 지 확인
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<N){
                    if(!avail[nx][ny])
                        avail[nx][ny] = true;
                }
            }

            // 불 켠다
            for(int i=0; i<map[x][y].size(); i++){
                int onX = map[x][y].get(i).x;
                int onY = map[x][y].get(i).y;

                if(light[onX][onY]==0)
                    light[onX][onY] = ++ans;
                if(avail[onX][onY] && !chk[onX][onY]){
                    chk[onX][onY] = true;
                    q.add(new Info(onX, onY));
                }
            }

            // 이동한다
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<N){
                    if(chk[nx][ny]) continue;

                    if(light[nx][ny]>0 && avail[nx][ny]){
                        q.add(new Info(nx,ny));
                        chk[nx][ny] = true;
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