import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class p1916 {

    static int N, M;
    static ArrayList<Info>[] adj;
    static int[] dist;
    static final int INF = 987654321;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        adj = new ArrayList[N+1];
        dist = new int[N+1];

        for(int i=1; i<=N; i++){
            dist[i] = INF;
            adj[i] = new ArrayList<>();
        }

        int x, y, cost;
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            x =  Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());
            adj[x].add(new Info(y, cost));
        }

        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        solve(start);
        System.out.println(dist[end]);
    }

    public static void solve(int start){
        PriorityQueue<Info> q = new PriorityQueue<>();
        q.add(new Info(start, 0));
        dist[start] = 0;

        while(!q.isEmpty()){
            Info info = q.poll();
            int x = info.x;
            int cost = info.cost; 

            if(dist[x] < cost) continue;

            for(int i=0; i<adj[x].size(); i++){
                int nx = adj[x].get(i).x;
                int d = cost + adj[x].get(i).cost;

                if(dist[nx] > d){
                    dist[nx] = d;
                    q.add(new Info(nx, d));
                }
            }
        }
    }

    public static class Info implements Comparable<Info>{
        int x, cost;
        public Info(int x, int cost){
            this.x = x;
            this.cost = cost;
        }

        @Override
        public int compareTo(Info i){
            return cost - i.cost;
        }
    }
}
