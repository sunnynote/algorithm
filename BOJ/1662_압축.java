/**
 * 22-03-25
 * BOJ 1662 압축
 * 스택
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String s = br.readLine();

    char[] c = s.toCharArray();
    Stack<Info> stk = new Stack<>();

    int ans = 0;

    for(int i=0; i<c.length; i++) {
      if(c[i] == ')') {
        int cnt = 0;

        while(!stk.isEmpty()){
          if(stk.peek().c != '('){
            cnt += stk.peek().n;
            stk.pop();
          }
          else if(stk.peek().c == '('){
            stk.pop();

            int mul = stk.peek().c - '0';
            stk.pop();

            cnt *= mul;
            stk.add(new Info('1', cnt));
            break;
          }
        }
      }
      else {
        stk.add(new Info(c[i], 1));
      }
    }

    while(!stk.isEmpty()){
      ans += stk.peek().n;
      stk.pop();
    }

    System.out.println(ans);
  }
}

class Info{
  char c;
  int n;
  Info(char c, int n){
    this.c = c;
    this.n = n;
  }
}