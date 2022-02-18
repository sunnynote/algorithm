/**
 * 22-02-18
 * BOJ 3079 입국심사
 * 이분 탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
  static int N, M;
  static int[] arr;
  static long mx;
  static long ans;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    arr = new int[N];
    ans = 0;

    for(int i=0; i<N; i++) {
      arr[i] = Integer.parseInt(br.readLine());

      if(mx < arr[i])
        mx = arr[i];
    }

    solve();
    System.out.println(ans);
  }

  static void solve() {
    long l = 0;
    long r = mx * M; // 걸릴 수 있는 최대 시간

    while(l <= r){
      long mid = (l + r) / 2;

      long res = func(mid);

      if(M <= res){
        r = mid - 1;
        ans = mid;
      }
      else if(M > res){
        l = mid + 1;
      }
    }
  }

  static long func(long m){
    long sum = 0;

    for(int i=0; i<N; i++){
        sum += (m/arr[i]);
    }

    return sum;
  }
}
