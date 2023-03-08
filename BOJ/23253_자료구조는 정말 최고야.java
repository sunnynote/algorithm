/**
 * 23-03-08
 * BOJ 23253 자료구조는 정말 최고야
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    String ans = "Yes";

    for(int m = 0; m < M; m++){
      int t = Integer.parseInt(br.readLine());
      st = new StringTokenizer(br.readLine());

      int[] arr = new int[t];

      for(int i = 0; i < t; i++){
        arr[i] = Integer.parseInt(st.nextToken());
      }

      for(int i = 0; i < t-1; i++){
        if(arr[i] < arr[i+1]){
          ans = "No";
          break;
        }
      }

      if(ans.equals("No")) break;
    }

    System.out.println(ans);
  }
}
