/**
 * 23-07-21
 * BOJ 14244 트리 만들기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class d {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    for(int i=0; i<N-1; i++){
      if(i < N-M)
        System.out.println(i + " " + (i+1));
      else
        System.out.println((N-M) + " " + (i+1));
    }
  }
}
