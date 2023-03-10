/**
 * 23-03-10
 * BOJ 3273 두 수의 합
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    StringTokenizer st = new StringTokenizer(br.readLine());
    int[] arr = new int[N];

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(arr);

    int X = Integer.parseInt(br.readLine());

    int l = 0;
    int r = N - 1;
    int ans = 0;

    while(true){
      if(l >= r) break;

      int res = (arr[l] + arr[r]);

      if(res == X){
        l++;
        r--;
        ans++;
      }
      else if(res < X){
        l++;
      }
      else if(res > X){
        r--;
      }
    }

    System.out.println(ans);
  }
}
