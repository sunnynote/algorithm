/**
 * 22-02-01
 * BOJ 16928 뱀과 사다리 게임
 * BFS
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class p16928{

    static int map[] = new int[101];
    static int danger[] = new int[101];
    static boolean chk[] = new boolean[101];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // input
        for(int i=0; i<N+M; i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            danger[a] = b;
        }

        func();

        System.out.println(map[100]);
    }

    static void func(){
        Queue<Integer> queue = new LinkedList<>();

        queue.add(1);
        map[1] = 0;
        chk[1] = true;

        while(!queue.isEmpty()){
            int x = queue.poll();

            if(x==100) return;

            for(int i=1; i<=6; i++){
                int nx = x + i;

                if(nx>100 || chk[nx]) continue;

                chk[nx] = true;

                if(danger[nx]==0){
                    queue.add(nx);
                    map[nx] = map[x] + 1;
                }
                else{
                    nx = danger[nx];

                    if(!chk[nx]){
                        chk[nx] = true;
                        queue.add(nx);
                        map[nx] = map[x] + 1;
                    }
                }
            }
        }
    }
}