/**
 * 23-05-31
 * BOJ 15886 내 선물을 받아줘 2
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    String s = br.readLine();
    char[] arr = new char[N];

    for(int i=0; i<N; i++){
      arr[i] = s.charAt(i);
    }

    int ans = 0;

    for(int i=0; i<N-1; i++){
      if(arr[i]=='E' && arr[i+1]=='W') ans++;
    }

    System.out.println(ans);
  }
}
