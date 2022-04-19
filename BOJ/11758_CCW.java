/**
 * 22-04-19
 * BOJ 11758 CCW
 * 기하학
 */

import java.io.*;
import java.util.*;

public class test6 {
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);

    int x1 = sc.nextInt();
    int y1 = sc.nextInt();
    int x2 = sc.nextInt();
    int y2 = sc.nextInt();
    int x3 = sc.nextInt();
    int y3 = sc.nextInt();

    int a = x1 * y2 + x2 * y3 + x3 * y1;
    int b = x2 * y1 + x3 * y2 + x1 * y3;

    if(a - b > 0) System.out.println(1);
    else if(a - b == 0) System.out.println(0);
    else System.out.println(-1);
  }

}