/**
 * 23-07-25
 * BOJ 15688 수 정렬하기 5
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    int[] arr = new int[N];

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(br.readLine());
    }

    Arrays.sort(arr);

    StringBuilder sb = new StringBuilder();
    for(int i=0; i<N; i++){
      sb.append(arr[i]).append("\n");
    }

    System.out.print(sb);
  }
}
