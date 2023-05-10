/**
 * 23-05-10
 * BOJ 11328 Strfry
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      int[] arr1 = new int[26];
      int[] arr2 = new int[26];

      String s1 = st.nextToken();
      String s2 = st.nextToken();

      for(int j=0; j<s1.length(); j++){
        arr1[s1.charAt(j) - 'a']++;
      }

      for(int j=0; j<s2.length(); j++){
        arr2[s2.charAt(j) - 'a']++;
      }

      boolean f = true;

      for(int j=0; j<26; j++){
        if(arr1[j] != arr2[j]){
          f = false;
          break;
        }
      }

      if(f) System.out.println("Possible");
      else System.out.println("Impossible");
    }

  }
}
