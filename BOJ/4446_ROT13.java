/**
 * 23-06-27
 * BOJ 4446 ROT13
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String s1 = "aiyeouaiyeouAIYEOUAIYEOU";
    String s2 = "bkxznhdcwgpvjqtsrlmfbkxznhdcwgpvjqtsrlmfBKXZNHDCWGPVJQTSRLMFBKXZNHDCWGPVJQTSRLMF";

    String s = "";

    while((s = br.readLine()) != null) {
      String res = "";

      for (int i = 0; i < s.length(); i++) {
        char cur = s.charAt(i);
        if (cur == 'a' || cur == 'i' || cur == 'y'
                || cur == 'e' || cur == 'o' || cur == 'u'
                || cur == 'A' || cur == 'I' || cur == 'Y'
                || cur == 'E' || cur == 'O' || cur == 'U') {
          for (int j = 0; j < s1.length(); j++) {
            if (cur == s1.charAt(j)) {
              res += s1.charAt(j + 3);
              break;
            }
          }
        } else if('A' < cur && cur <= 'z') {
          for (int j = 0; j < s2.length(); j++) {
            if (cur == s2.charAt(j)) {
              res += s2.charAt(j + 10);
              break;
            }
          }
        }
        else res += s.charAt(i);
      }
      System.out.println(res);
    }
  }
}
