/**
 * 22-04-06
 * BOJ 2581 소수
 * 에라토스테네스
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test1 {
  static int N, M;
  static boolean[] p;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    M = Integer.parseInt(br.readLine());
    N = Integer.parseInt(br.readLine());

    p = new boolean[N+1];

    isPrime();

    int sum = 0;
    int mn = -1;
    boolean f = false;

    for(int i=M; i<=N; i++){
      if(!p[i]){
        sum += i;
        if(mn==-1) mn = i;
        f = true;
      }
    }

    if(f) System.out.println(sum + "\n" + mn);
    else System.out.println(mn);

  }

  static void isPrime(){
    p[1] = true;
    for(int i=2; i*i<=N; i++){
      if(p[i]) continue;

      for(int j=i*i; j<=N; j+=i){
        p[j] = true;
      }
    }
  }

}
