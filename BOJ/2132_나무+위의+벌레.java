/**
 * 22-02-10
 * BOJ 2132 나무 위의 벌레
 * DFS
 */

import java.io.*;
import java.util.*;

public class test {

    static int N;
    static int[] cost;
    static ArrayList<Integer>[] adj;
    static ArrayList<Integer> starts;
    static ArrayList<Info> ends;
    static int mxLen, mxVal;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        cost = new int[N+1];
        adj = new ArrayList[N+1];
        starts = new ArrayList<>();
        ends = new ArrayList<>();

        for(int i=1; i<=N; i++)
            adj[i] = new ArrayList<>();

        // input
        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=N; i++)
            cost[i] = Integer.parseInt(st.nextToken());

        for(int i=1; i<N; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            adj[a].add(b);
            adj[b].add(a);
        }

        // 멀리 있는 점 구하기
        mxLen = 0;
        dfs(1, 1, cost[1]);

        // 다른 끝점 찾으면서 값 갱신
        mxVal = 0;
        for(int i=0; i<starts.size(); i++)
            solve(starts.get(i), starts.get(i), cost[starts.get(i)], starts.get(i));

        Collections.sort(ends, (o1, o2) -> (o1.from - o2.from));

        for(int i=0; i<ends.size(); i++){
            System.out.println(ends.get(i).from + " " + ends.get(i).to);
        }

        System.out.println(mxVal + " " + ends.get(0).from);
    }

    static void dfs(int cur, int prev, int len){
        if(mxLen < len){
            mxLen = len;

            starts.clear();
            starts.add(cur);
        }
        else if(mxLen == len){
            starts.add(cur);
        }

        for(int i=0; i<adj[cur].size(); i++){
            if(adj[cur].get(i) == prev) continue;

            dfs(adj[cur].get(i), cur, len + cost[adj[cur].get(i)]);
        }
    }

    static void solve(int cur, int prev, int val, int origin){
        if(mxVal < val){
            mxVal = val;

            ends.clear();
            if(origin < cur)
                ends.add(new Info(origin, cur));
            else
                ends.add(new Info(cur, origin));
        }
        else if(mxVal == val){
            if(origin < cur)
                ends.add(new Info(origin, cur));
            else
                ends.add(new Info(cur, origin));
        }

        for(int i=0; i<adj[cur].size(); i++){
            if(adj[cur].get(i) == prev) continue;

            solve(adj[cur].get(i), cur,val + cost[adj[cur].get(i)], origin);
        }
    }
}

class Info{
    int from, to;

    Info(int from, int to){
        this.from = from;
        this.to = to;
    }
}