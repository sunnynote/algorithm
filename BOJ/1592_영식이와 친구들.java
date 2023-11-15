/**
 * 23-11-15
 * BOJ 1592 영식이와 친구들
 * BAEKJOON solved 1000...
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int L = Integer.parseInt(st.nextToken());

    int[] arr = new int[N+1];
    int cnt = 0;
    int idx = 0;

    arr[idx]++;
    cnt++;

    while(true){
      if(arr[idx] == M){
        System.out.print(cnt - 1);
        break;
      }

      if(arr[idx] % 2 == 1){
        idx = (idx + L) % N;
      }
      else{
        idx = (idx - L + N) % N;
      }

      arr[idx]++;
      cnt++;
    }
  }
}
