/**
 * 22-03-12
 * BOJ 24523 내 뒤에 나와 다른 수
 * Stack
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class test2 {
  static int N;
  static int[] arr;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    Stack<Integer> stk = new Stack<>();
    StringBuilder sb = new StringBuilder();

    N = Integer.parseInt(br.readLine());
    arr = new int[N+1];

    st = new StringTokenizer(br.readLine());
    for(int i=1; i<=N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    for(int i=1; i<=N; i++){
      int x = arr[i];

      if(stk.isEmpty()){
        stk.add(x);
      }
      else{
        if(stk.peek() == x){
          stk.add(x);
        }
        else{
          while(!stk.isEmpty()){
            stk.pop();
            sb.append(i + " ");
          }
          stk.add(x);
        }
      }
    }

    while(!stk.isEmpty()){
      stk.pop();
      sb.append(-1 + " ");
    }

    System.out.println(sb);
  }
}