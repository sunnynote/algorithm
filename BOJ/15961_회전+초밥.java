/**
 * 22-03-13
 * BOJ 15961 회전 초밥
 * 슬라이딩 윈도우
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test2 {
  static int N, d, k, c;
  static int[] arr;
  static int[] chk;
  static int ans = 0, eat = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    d = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());

    arr = new int[N+k-1];
    chk = new int[d+1];

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(br.readLine());
    }

    int cnt = 0;
    for(int i=N; i<N+k-1; i++){
      arr[i] = arr[cnt++];
    }

    solve();

    System.out.println(ans);
  }

  static void solve(){

    // 처음 k개 먹어본다.
    for(int i=0; i<k; i++){
      if(chk[arr[i]]==0) eat++;
      chk[arr[i]]++;
    }

    ans = Math.max(ans, eat);
    if(chk[c]==0)
      ans++;

    int idx = 0;
    for(int i=k; i<N+k-1; i++){
      // 앞 초밥 뱉기
      if(chk[arr[idx]]==1){
        eat--;
      }
      chk[arr[idx++]]--;

      // 현재 초밥 먹기
      if(chk[arr[i]]==0){
        eat++;
      }
      chk[arr[i]]++;

      if(chk[c]==0)
        ans = Math.max(ans, eat+1);
      else
        ans = Math.max(ans, eat);
    }
  }
}