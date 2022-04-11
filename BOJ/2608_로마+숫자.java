/**
 * 22-04-11
 * BOJ 2608 로마 숫자
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String str1 = br.readLine();
    String str2 = br.readLine();

    int ans = strToint(str1);
    ans += strToint(str2);

    System.out.println(ans);
    System.out.println(toRome(ans));
  }

  static int strToint(String s){
    int res = 0;

    for(int i=0; i<s.length(); i++){
      char cur = s.charAt(i);

      if(i+1 < s.length()) {
        if (cur == 'I' && s.charAt(i + 1) == 'V') {
          res += 4;
          i++;
          continue;
        }
        if (cur == 'I' && s.charAt(i + 1) == 'X') {
          res += 9;
          i++;
          continue;
        }
        if (cur == 'X' && s.charAt(i + 1) == 'L') {
          res += 40;
          i++;
          continue;
        }
        if (cur == 'X' && s.charAt(i + 1) == 'C') {
          res += 90;
          i++;
          continue;
        }
        if (cur == 'C' && s.charAt(i + 1) == 'D') {
          res += 400;
          i++;
          continue;
        }
        if (cur == 'C' && s.charAt(i + 1) == 'M') {
          res += 900;
          i++;
          continue;
        }
      }

      if(cur == 'I') res += 1;
      if(cur == 'V') res += 5;
      if(cur == 'X') res += 10;
      if(cur == 'L') res += 50;
      if(cur == 'C') res += 100;
      if(cur == 'D') res += 500;
      if(cur == 'M') res += 1000;
    }

    return res;
  }

  static String toRome(int n){
    String s = "";

    while(n > 0){
      if(n >= 1000){
        s += "M";
        n -= 1000;
      } else if(n >= 900){
        s += "CM";
        n -= 900;
      } else if(n >= 500){
        s += "D";
        n -= 500;
      } else if(n >= 400){
        s += "CD";
        n -= 400;
      } else if(n >= 100){
        s += "C";
        n -= 100;
      } else if(n >= 90){
        s += "XC";
        n -= 90;
      } else if(n >= 50){
        s += "L";
        n -= 50;
      } else if(n >= 40){
        s += "XL";
        n -= 40;
      } else if(n >= 10){
        s += "X";
        n -= 10;
      } else if(n >= 9){
        s += "IX";
        n -= 9;
      } else if(n >= 5){
        s += "V";
        n -= 5;
      } else if(n >= 4){
        s += "IV";
        n -= 4;
      } else {
        s += "I";
        n -= 1;
      }
    }

    return s;
  }
}
