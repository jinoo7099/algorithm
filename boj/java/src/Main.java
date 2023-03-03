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

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

    }
}
