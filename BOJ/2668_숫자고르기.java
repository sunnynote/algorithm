/**
 * 22-02-25
 * BOJ 2668 숫자고르기
 * 사이클 찾기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class test {
  static int N;
  static int[] arr;
  static boolean[] chk;
  static ArrayList<Integer> list;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    arr = new int[N+1];
    chk = new boolean[N+1];
    list = new ArrayList<>();

    for(int i=1; i<=N; i++)
      arr[i] = Integer.parseInt(br.readLine());


    for(int i=1; i<=N; i++) {
      chk[i] = true;
      dfs(i, i);
      chk[i] = false;
    }

    Collections.sort(list);

    System.out.println(list.size());

    for(int i=0; i<list.size(); i++)
      System.out.println(list.get(i));
   }

  static void dfs(int idx, int res){
    if(arr[idx]==res)
      list.add(res);

    if(!chk[arr[idx]]){
      chk[arr[idx]] = true;
      dfs(arr[idx], res);
      chk[arr[idx]] = false;
    }
  }
}