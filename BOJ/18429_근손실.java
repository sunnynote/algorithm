/**
 * 23-08-17
 * BOJ 18429 근손실
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㅇ {

  static int N, K, ans = 0;
  static int[] arr;
  static boolean[] chk;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());

    arr = new int[N];
    chk = new boolean[N];

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    func(0, 500);

    System.out.println(ans);
  }

  public static void func(int cnt, int cur){
    if(cur < 500) return;

    if(cnt == N){
      ans++;
      return;
    }

    for(int i=0; i<N; i++){
      if(chk[i]) continue;

      chk[i] = true;
      func(cnt+1, cur + arr[i] - K);
      chk[i] = false;
    }
  }
}
