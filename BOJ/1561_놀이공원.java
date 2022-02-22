/**
 * 22-02-22
 * BOJ 1561 놀이공원
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test{
  static long N, M;
  static int[] arr;
  static int mx;
  static long good, ans;
  static int idx;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Long.parseLong(st.nextToken());
    M = Long.parseLong(st.nextToken());
    arr = new int[(int)M+1];
    mx = -1;
    good = 0;
    ans = Long.MAX_VALUE;
    idx = -1;

    st = new StringTokenizer(br.readLine());

    for(int i=0; i<M; i++){
      arr[i] = Integer.parseInt(st.nextToken());
      if(mx < arr[i]) mx = arr[i];
    }

    if(N <= M){
      System.out.println(N);
    }
    else {
      func();
      lastOne();
      System.out.println(idx);
    }
  }

  static void func(){
    long l = 0;
    long r = mx*N;

    while(l<=r){
      long mid = (l+r) / 2;
      long val = calc(mid);

      if(val >= N){
        r = mid - 1;
        good = mid;
      }
      else{
        l = mid + 1;
      }
    }
  }

  static long calc(long m){
    long sum = M;
    for(int i=0; i<M; i++)
      sum += m/arr[i];
    return sum;
  }

  static void lastOne(){
    long num = M;

    for(int i=0; i<M; i++){
      num += (good-1)/arr[i];
    }

    for(int i=0; i<M; i++){
      if(good % arr[i] == 0){
        num++;
      }
      if(num==N) {
        idx = i + 1;
        break;
      }
    }
  }
}