/**
 * 22-03-21
 * BOJ 2036 수열의 점수
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    long[] arr = new long[N];
    BigInteger ans = new BigInteger("0");

    int m = 0, p = 0;
    int one = 0;

    for(int i=0; i<N; i++){
      arr[i] = Long.parseLong(br.readLine());
      if(arr[i] <= 0) m++;
      else if(arr[i] == 1) one++;
      else p++;
    }

    Arrays.sort(arr);

    for(int i=0; i<m; i++){
      if(i==m-1 && m%2==1) {
        ans = ans.add(BigInteger.valueOf(arr[i]));
      }
      else if(i+1 < m){
        ans = ans.add(BigInteger.valueOf(arr[i] * arr[i+1]));
        i++;
      }
      else{
        ans = ans.add(BigInteger.valueOf(arr[i]));
      }
    }

    if(one!=0){
      ans = ans.add(BigInteger.valueOf(one));
      m += one;
    }

    for(int i=m; i<N; i++){
      if(i==m && p%2==1){
        ans = ans.add(BigInteger.valueOf(arr[i]));
      }
      else if(i+1 < N) {
        ans = ans.add(BigInteger.valueOf(arr[i] * arr[i+1]));
        i++;
      }
      else{
        ans = ans.add(BigInteger.valueOf(arr[i]));
      }
    }

    System.out.println(ans);
  }
}