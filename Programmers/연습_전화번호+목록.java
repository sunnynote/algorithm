/**
 * 23-01-02
 * Programmers 연습 - 전화번호 목록
 */

import java.util.*;

class Solution {
  public boolean solution(String[] phone_book) {
    boolean answer = true;

    Set<String> st = new HashSet<>();

    for(int i=0; i<phone_book.length; i++){
      st.add(phone_book[i]);
    }

    for(int i=0; i<phone_book.length; i++){
      String cur = phone_book[i];

      for(int j=0; j<cur.length(); j++){

        if(st.contains(cur.substring(0, j))){
          return false;
        }
      }
    }

    return answer;
  }
}