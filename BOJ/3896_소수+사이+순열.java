/**
 * 22-03-02
 * BOJ 3896 소수 사이 수열
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
  static int MX = 1300000;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());

    boolean[] prime = new boolean[MX];

    for(int i=2; i*i<MX; i++){
      if(prime[i]) continue;
      for(int j=i*i; j<MX; j+=i)
        prime[j] = true;
    }

    while(true){
      if(T==0) break;

      int N = Integer.parseInt(br.readLine());
      int l = N, r = N;

      while(true){
        if(!prime[l]) break;
        l--;
      }

      while(true){
        if(!prime[r]) break;
        r++;
      }

      System.out.println(r - l);
      T--;
    }
  }
}