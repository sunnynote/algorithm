/**
 * 22-04-28
 * BOJ 11509 풍선 맞추기
 * 그리디
 */

import java.io.*;
import java.util.*;

public class test7 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int N = Integer.parseInt(br.readLine());
    int[] arr = new int[N+1];
    int[] cnt = new int[N+1];

    st = new StringTokenizer(br.readLine());

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    int ans = 0;

    for(int i=0; i<N; i++){
      int cur = arr[i];

      if(cnt[cur] == 0){
        ans++;
      }
      else{
        cnt[cur]--;
      }

      cnt[cur-1]++;
    }

    System.out.println(ans);
  }
}