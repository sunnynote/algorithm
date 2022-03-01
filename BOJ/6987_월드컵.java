/**
 * 22-03-01
 * BOJ 6987 월드컵
 * DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
  static int[][] arr;
  static int[][] res;
  static boolean[] ans;
  static int[] list1 = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}; // A~F idx list
  static int[] list2 = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    arr = new int[6][3];
    res = new int[6][3];
    ans = new boolean[4];

    for(int team=0; team<4; team++){
      st = new StringTokenizer(br.readLine());

      for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
          arr[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      solve(0, team);
    }

    for(int i=0; i<4; i++) {
      if(ans[i]) System.out.print(1 + " ");
      else System.out.print(0 + " ");
    }
  }

  static void solve(int cnt, int idx){
    if(cnt==15){
      if(ans[idx]) return;

      for(int i=0; i<6; i++)
        for(int j=0; j<3; j++)
          if(arr[i][j] != res[i][j])
            return;

      ans[idx] = true;
      return;
    }

    int a_team = list1[cnt];
    int b_team = list2[cnt];

    // a win, b lose
    res[a_team][0]++;
    res[b_team][2]++;
    solve(cnt+1, idx);
    res[a_team][0]--;
    res[b_team][2]--;

    // a draw, b draw
    res[a_team][1]++;
    res[b_team][1]++;
    solve(cnt+1, idx);
    res[a_team][1]--;
    res[b_team][1]--;

    // a lose, b win
    res[a_team][2]++;
    res[b_team][0]++;
    solve(cnt+1, idx);
    res[a_team][2]--;
    res[b_team][0]--;
  }
}