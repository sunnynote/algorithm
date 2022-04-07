/**
 * 22-04-07
 * BOJ 9081 단어 맞추기
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test1 {
  static String s;
  static char[] arr;
  static int len;
  static String ans;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    while(N-- > 0){
      s = br.readLine();

      arr = s.toCharArray();
      len = s.length();
      ans = "";

      nx_pm();

      for(int i=0; i<len; i++){
        ans += arr[i];
      }

      System.out.println(ans);
    }
  }

  static void nx_pm(){
    int i = len - 1;

    while(i > 0 && arr[i - 1] >= arr[i]){ // i 위치 찾기
      i--;
    }

    if(i == 0) return;

    i--;

    int j = len - 1;

    while (arr[i] >= arr[j]){ // j 위치 찾기
      j--;
    }

    char tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;

    Arrays.sort(arr, i + 1, len);
  }
}