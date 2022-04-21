/**
 * 22-04-21
 * BOJ 2885 초콜릿 식사
 * 수학
 */

import java.io.*;
import java.util.*;

public class test6 {
  static int K;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    K = Integer.parseInt(br.readLine());

    int mx = 1;
    while(mx < K){
      mx *= 2;
    }

    System.out.println(mx + " " + tenTotwo(K));
  }

  static int tenTotwo(int x){
    String s = "";

    while(x > 0){
      if(x % 2 == 0) s += "0";
      else s += "1";

      x /= 2;
    }

    boolean f = false;
    int res = 0;

    for(int i=0; i<s.length(); i++){
      if(s.charAt(i) != '0') f = true;
      if(!f) continue;

      res++;
    }

    if(res == 1) res = 0;

    return res;
  }
}