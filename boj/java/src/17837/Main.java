import java.io.*;
import java.util.*;

class Main {
    static class PQ implements Comparable<PQ> {
        int fi;
        int se;

        public PQ(int fi, int se) {
            super();
            this.fi = fi;
            this.se = se;
        }

        @Override
        public int compareTo(PQ o) {
            return this.fi - o.fi;
        }
    }

    static int n, k;
    static int[][] color = new int[14][14];
    static int[][] horses;
    static List<Integer>[][] map;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        map = new ArrayList<>;
        // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n; j++) {
        // pos[i][j] = new Vector<>();
        // }
        // }

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                color[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i <= k; i++) {
            int r, c, d;

            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());

        }

    }
}
