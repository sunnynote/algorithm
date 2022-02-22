/**
 * 22-02-22
 * BOJ 3665 최종순위
 * 위상정렬
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test {
  static int N, M;
  static int[] lastYear;
  static int[] ind;
  static int[][] mat;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int T = Integer.parseInt(br.readLine());

    for(int t=0; t<T; t++){
      N = Integer.parseInt(br.readLine());
      lastYear = new int[N+1];
      ind = new int[N+1];
      mat = new int[N+1][N+1];

      st = new StringTokenizer(br.readLine());
      for(int i=1; i<=N; i++){
        lastYear[i] = Integer.parseInt(st.nextToken());
      }

      for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
          mat[lastYear[i]][lastYear[j]] = 1;
          ind[lastYear[j]]++;
        }
      }

      M = Integer.parseInt(br.readLine());

      for(int i=0; i<M; i++){
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        if(mat[x][y]==1){
          mat[x][y] = 0;
          mat[y][x] = 1;
          ind[x]++;
          ind[y]--;
        }
        else{
          mat[x][y] = 1;
          mat[y][x] = 0;
          ind[x]--;
          ind[y]++;
        }
      }

      LinkedList<Integer> q = new LinkedList<>();
      ArrayList<Integer> list = new ArrayList<>();

      for(int i=1; i<=N; i++){
        if(ind[i]==0)
          q.add(i);
      }

      boolean f = true;

      while(!q.isEmpty()){
        if(q.size()>1){
          f = false;
          break;
        }

        int x = q.poll();
        list.add(x);

        for(int i=1; i<=N; i++){
          if(mat[x][i]==1)
            if(--ind[i]==0)
              q.add(i);
        }
      }

      if(!f){
        System.out.println("?");
      }
      else if(list.size()==N){
        for(int i=0; i<N; i++)
          System.out.print(list.get(i) + " ");
        System.out.println();
      }
      else
        System.out.println("IMPOSSIBLE");
    }
  }
}