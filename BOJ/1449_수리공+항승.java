/**
 * 22-03-16
 * BOJ 1449 수리공 항승
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int L = Integer.parseInt(st.nextToken());
    int[] loc = new int[N];

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<N; i++){
      loc[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(loc);

    int ans = 1;
    int cur = loc[0];

    for(int i=0; i<N; i++){
      if(loc[i] - cur + 1 > L){
        ans++;
        cur = loc[i];
      }
    }

    System.out.println(ans);
  }
}