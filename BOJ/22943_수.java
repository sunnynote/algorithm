/**
 * 22-03-11
 * BOJ 22943 수
 * 소수, DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test2 {
  static int K, M;
  static boolean[] chk = new boolean[10];
  static int MX = 1;
  static int MN = 1;
  static boolean[] prime_arr = new boolean[100001]; // false = prime
  static boolean[] chk1 = new boolean[200001];
  static boolean[] chk2 = new boolean[200001];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    K = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for(int i=1; i<=K; i++){
      MX *= 10;
      MN *= 10;
    }
    MN /= 10;

    want_prime();

    // 1)
    for(int i=2; i<MX-1; i++){
      if(prime_arr[i]) continue;

      for(int j=i+1; j<MX; j++)
        if(!prime_arr[i] && !prime_arr[j])
          chk1[i + j] = true;
    }

    // 2)
    for(int i=2; i<MX; i++){
      if(prime_arr[i]) continue;

      for(int j=i; j<MX; j++){
        if(!prime_arr[i] && !prime_arr[j]) {
          long tmp = (long)i * (long)j;
          if(tmp >= (long)MX) break;
          chk2[i * j] = true;
        }
      }
    }

    int ret = dfs(0, 0, 0);
    System.out.println(ret);
  }

  static int dfs(int idx, int cnt, int val){
    if(cnt==K){
      if(val < MN || val >= MX) return 0;

      if(chk1[val] && div(val)){
        return 1;
      }
      return 0;
    }

    int ret = 0;
    for(int i=idx; i<10; i++){
      if(chk[i]) continue;

      chk[i] = true;
      ret += dfs(idx, cnt+1, val*10 + i);
      chk[i] = false;
    }

    return ret;
  }

  static boolean div(int val){
    while(true){
      if(val % M == 0){
        val /= M;
      }
      else {
        break;
      }
    }
    return chk2[val];
  }

  static void want_prime(){
    for(int i=2; i*i<MX; i++){
      if(prime_arr[i]) continue;

      for(int j=i*i; j<MX; j+=i){
        prime_arr[j] = true;
      }
    }
  }
}