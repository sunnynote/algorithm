/**
 * 23-04-11
 * BOJ 2785 체인
 */

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int N = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    int[] arr = new int[N];

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(arr);

    int idx = 0;
    int fi = N - 1;
    int ans = 0;

    while(idx < fi){
      arr[idx]--;
      fi--;
      ans++;

      if(arr[idx] == 0) idx++;
    }

    System.out.println(ans);
  }
}
