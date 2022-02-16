/**
 * 22-02-17
 * BOJ 16137 견우와 직녀
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
    static int[][] map;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};

    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N+1][N+1];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());

            for(int j=0; j<N; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        impossible_chk();

        solve();

        System.out.println(ans);
    }

    static void impossible_chk(){

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                boolean f_up_down = false;
                boolean f_left_right = false;

                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(0<=nx && nx<N && 0<=ny && ny<N){
                        if(map[i][j]!=0 || map[nx][ny]!=0) continue;

                        if(k==0 || k==1)
                            f_up_down = true;
                        if(k==2 || k==3)
                            f_left_right = true;
                    }
                }

                if(f_up_down && f_left_right)
                    map[i][j] = -1;
            }
        }
    }

    static void solve(){
        for(int i=0; i<N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0)
                    bfs(i, j, true);
                else
                    bfs(i, j, false);
            }
        }
    }

    static void bfs(int target_x, int target_y, boolean f){
        int[][] tmp_map = new int[N+1][N+1];
        int[][] chk = new int[N+1][N+1];
        boolean[][] target = new boolean[N+1][N+1];

        for(int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                tmp_map[i][j] = map[i][j];
                chk[i][j] = Integer.MAX_VALUE;
                target[i][j] = false;
            }
        }
        if(f) tmp_map[target_x][target_y] = M;

        Queue<Info> q = new LinkedList<>();
        q.add(new Info(0,0));
        chk[0][0] = 0;

        while(!q.isEmpty()){
            int x = q.peek().x;
            int y = q.poll().y;

            if(x==N-1 && y==N-1) {
                ans = Math.min(ans, chk[N-1][N-1]);
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0<=nx && nx<N && 0<=ny && ny<N){
                    if(tmp_map[nx][ny]==0 || tmp_map[nx][ny]==-1) continue;
                    if(target[nx][ny]) continue;
                    if(tmp_map[x][y]>1 && tmp_map[nx][ny]>1) continue;

                    if(tmp_map[nx][ny]==1){
                        if(chk[nx][ny] > chk[x][y] + 1) {
                            chk[nx][ny] = chk[x][y] + 1;
                            q.add(new Info(nx, ny));
                        }
                    }

                    else if(tmp_map[nx][ny]>1){
                        if(chk[x][y] >= tmp_map[nx][ny]){

                            while(true){
                                if(chk[x][y]<tmp_map[nx][ny]) break;

                                if(f && nx==target_x && ny==target_y){
                                    tmp_map[nx][ny] += M;
                                }
                                else{
                                    tmp_map[nx][ny] += map[nx][ny];
                                }
                            }
                        }

                        if(chk[nx][ny] > tmp_map[nx][ny]) {
                            chk[nx][ny] = tmp_map[nx][ny];
                            q.add(new Info(nx, ny));
                        }
                    }

                    if(nx==target_x && ny==target_y)
                        target[nx][ny] = true;
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