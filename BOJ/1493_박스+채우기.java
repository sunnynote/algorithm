/**
 * 22-03-28
 * BOJ 1493 박스 채우기
 * 분할 정복
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test3 {
  static int[] cube;
  static int ans = 0;
  static boolean f;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int L = Integer.parseInt(st.nextToken());
    int W = Integer.parseInt(st.nextToken());
    int H = Integer.parseInt(st.nextToken());

    int N = Integer.parseInt(br.readLine());
    cube = new int[20];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      cube[a] = b;
    }

    func(L, W, H);

    if(f) System.out.println(ans);
    else System.out.println(-1);
  }

  static void func (int l, int w, int h){
    if(l==0 || w==0 || h==0) return;

    f = false;
    int len = 0;

    for(int i=19; i>=0; i--){
      if(cube[i]==0) continue;

      len = 1 << i; // 2^i

      if(l >= len && w >= len && h >= len){
        ans++;
        cube[i]--;
        f = true;
        break;
      }
    }

    if(!f) return;

    func(l - len, w, len);
    func(len, w - len, len);
    func(l, w, h - len);
  }
}