/**
 * 22-03-21
 * BOJ 16472 고냥이
 * 두 포인터
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    char[] c = br.readLine().toCharArray();

    int len = c.length;
    int[] arr = new int[len];
    int[] chk = new int[26];
    int cnt = 0;

    for(int i=0; i<len; i++){
      arr[i] = c[i] - 'a';
    }

    int l = 0, r = 0;

    chk[arr[0]]++;
    cnt++;

    int ans = 0;

    while(true){
      if(l==len) break;

      if(cnt <= N && r+1 < len){
        r++;

        if(chk[arr[r]]==0) cnt++;
        chk[arr[r]]++;

        if(cnt <= N)
          ans = Math.max(ans, r - l + 1);
      }
      else { // cnt > N
        chk[arr[l]]--;
        if(chk[arr[l]]==0) cnt--;

        l++;
      }
    }
    System.out.println(ans);
  }
}