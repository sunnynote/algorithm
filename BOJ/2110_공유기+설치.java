/**
 * 22-03-08
 * BOJ 2110 공유기 설치
 * 이분 탐색
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test {
  static int N, C;
  static int[] house;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());
    house = new int[N];

    for(int i=0; i<N; i++)
       house[i] = Integer.parseInt(br.readLine());

    Arrays.sort(house);

    int l = 1;
    int r = house[N-1] - house[0];
    int ans = -1;

    while(l <= r){
      int mid = (l+r)/2;

      if(func(mid)){
        ans = mid;
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }

    System.out.println(ans);
  }

  static boolean func(int dist){
    int cnt = 1;
    int last_loc = house[0];

    for(int i=1; i<N; i++){
      if(house[i] - last_loc >= dist){
        cnt++;
        last_loc = house[i];
      }
    }

    if(cnt >= C) return true; // l = mid + 1;
    return false; // r = mid - 1;
  }
}