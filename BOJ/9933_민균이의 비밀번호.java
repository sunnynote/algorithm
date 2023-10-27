/**
 * 23-10-28
 * BOJ 9933 민균이의 비밀번호
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    String[] arr = new String[N];

    HashSet<String> hs = new HashSet<>();

    for(int i=0; i<N; i++){
      arr[i] = br.readLine();

      hs.add(arr[i]);
    }

    String ans = "";

    for(int i=0; i<N; i++){
      String cur = "";

      for(int j=arr[i].length()-1; j >=0; j--){
        cur += arr[i].charAt(j);
      }

      if(hs.contains(cur)){
        ans = cur;
        break;
      }
    }

    int len = ans.length();

    System.out.print(len + " " + ans.charAt(len/2));
  }
}
