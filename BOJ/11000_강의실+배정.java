import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p11000 {
    static int N;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        int[][] arr = new int[N+1][2];

        StringTokenizer st;
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken()); 
            
            arr[i][0] = x;
            arr[i][1] = y;
        }

        Arrays.sort(arr, new Comparator<int[]>(){
            //  오름차순 정렬
            public int compare(int[] a1, int[] a2){
                if(a1[0]==a2[0]) return a1[1] - a2[1];
                return a1[0] - a2[0];
            }
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        pq.add(arr[0][1]);

        for(int i=1; i<N; i++){
            if(arr[i][0] >= pq.peek()) pq.poll();
            pq.add(arr[i][1]);
        }

        System.out.println(pq.size());
    }

}
