/**
 * 22-04-21
 * BOJ 2056 작업
 * 위상정렬
 */

import java.io.*;
import java.util.*;

public class test6 {
  static int N;
  static int[] arr;
  static int[] ind;
  static int[] ans;
  static ArrayList<Integer>[] adj;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st =  new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    arr = new int[N + 1];
    ind = new int[N + 1];
    ans = new int[N + 1];
    adj = new ArrayList[N + 1];

    for(int i=1; i<=N; i++){
      adj[i] = new ArrayList<>();
    }

    for(int i=1; i<=N; i++){
      st = new StringTokenizer(br.readLine());

      arr[i] = Integer.parseInt(st.nextToken());
      int K = Integer.parseInt(st.nextToken());

      for(int k=0; k<K; k++){
        int x = Integer.parseInt(st.nextToken());
        adj[i].add(x);
        ind[x]++;
      }
    } // input end

    LinkedList <Integer> q = new LinkedList<>();

    for(int i=1; i<=N; i++){
      ans[i] = arr[i];
      if(ind[i] == 0){
        q.add(i);
      }
    }

    while(!q.isEmpty()){
      int x = q.poll();

      for(int i=0; i<adj[x].size(); i++){
        int nx = adj[x].get(i);
        ind[nx]--;
        if(ind[nx] == 0){
          q.add(nx);
        }

        ans[nx] = Math.max(ans[nx], ans[x] + arr[nx]);
      }
    }

    int t = 0;
    for(int i=1; i<=N; i++){
      t = Math.max(t, ans[i]);
    }

    System.out.println(t);
  }
}