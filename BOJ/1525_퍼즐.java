/**
 * 22-02-11
 * BOJ 1525 퍼즐
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test{

    static int N = 3;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {-1, 1, 0, 0};
    static StringBuilder num;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        num = new StringBuilder();

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());

            for(int j=0; j<N; j++){
                String tmp = st.nextToken();

                if(tmp.equals("0"))
                    num.append("9");
                else
                    num.append(tmp);
            }
        }

        System.out.println(bfs());
    }

    static int bfs(){
        Queue<String> q = new LinkedList<>();
        Map<String, Integer> m = new HashMap<>();

        q.add(num.toString());
        m.put(num.toString(), 0);

        while(!q.isEmpty()){
            String cur = q.poll();

            if(cur.equals("123456789")) return m.get(cur);

            int loc = cur.indexOf("9");
            int x = loc / 3;
            int y = loc % 3;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int res = nx*3 + ny;

                if(0<=nx && nx<N && 0<=ny && ny<N){
                    StringBuilder next = new StringBuilder(cur);
                    char tmp = next.charAt(res);

                    next.setCharAt(loc, tmp);
                    next.setCharAt(res, '9');

                    String nx_num = next.toString();

                    if(!m.containsKey(nx_num)){
                        q.add(nx_num);
                        m.put(nx_num, m.get(cur) + 1);
                    }
                }
            }
        }
        return -1;
    }
}
