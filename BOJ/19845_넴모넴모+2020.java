/**
 * 22-03-29
 * BOJ 19845 넴모넴모2020
 * 이분탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test4 {
  static int[] arr;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int Q = Integer.parseInt(st.nextToken());

    arr = new int[250001];

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    while(Q-- > 0){
      st = new StringTokenizer(br.readLine());
      int y = Integer.parseInt(st.nextToken());
      int x = Integer.parseInt(st.nextToken());

      int cntW = arr[x - 1] - y + 1;
      if(cntW < 0) cntW = 0;

      int cntH = solve(x, y);

      System.out.println(cntW + cntH);
    }
  }

  static int solve(int x, int y){

    int l = 0;
    int r = 250000;

    while(l < r) {
      int mid = (l + r) / 2;

      if (arr[mid] < y) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    int res = r - x;
    if(res < 0) res = 0;

    return res;
  }
}