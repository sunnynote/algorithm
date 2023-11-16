/**
 * 23-11-16
 * BOJ 6996 애너그램
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

  private static boolean solveAnagrams(String first, String second) {
    /* ------------------- INSERT CODE HERE --------------------
     *
     * Your code should return true if the two strings are anagrams of each other.
     *
     * */

    int[] arr = new int[26];

    for(int i=0; i<first.length(); i++){
      char c = first.charAt(i);
      arr[c - 'a']++;
    }

    for(int i=0; i<second.length(); i++){
      char c = second.charAt(i);
      arr[c - 'a']--;
    }

    for(int i=0; i<26; i++){
      if(arr[i] != 0) return false;
    }

    return true;

    /* -------------------- END OF INSERTION --------------------*/
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int numTests = sc.nextInt();

    for (int i = 0; i < numTests; i++) {
      String first = sc.next().toLowerCase();
      String second = sc.next().toLowerCase();

      System.out.println(first + " & " + second + " are " + (solveAnagrams(first, second) ? "anagrams." : "NOT anagrams."));
    }
  }
}
