import java.io.*;
import java.util.*;

class Main {
    static class PQ implements Comparable<PQ> {
        int x;
        int y;

        public PQ(int x, int y) {
            super();
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(PQ o) {
            return this.x - o.x;
        }
    }

    static int n;
    static int[][] arr = new int[22][22];
    static int ans = 987654321;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 2; i <= n - 1; i++) {
            for (int j = 2; j <= n - 1; j++) {
                // int d1 = 2, d2 = 2;
                for (int d1 = 1; d1 <= n - 2; d1++) {
                    for (int d2 = 1; d2 <= n - 2; d2++) {
                        if (n < i + d1 + d2)
                            continue;
                        if (j - d1 < 1 || j + d2 > n)
                            continue;
                        solve(d1, d2, i, j);
                    }
                }
            }
        }

        System.out.println(ans);
    }

    private static void solve(int d1, int d2, int x, int y) {
        int[][] tmp = new int[22][22];
        // 1
        for (int i = 0; i <= d1; i++) {
            tmp[x + i][y - i] = 5;
        }
        // 2
        for (int i = 0; i <= d2; i++) {
            tmp[x + i][y + i] = 5;
        }
        // 3
        for (int i = 0; i <= d2; i++) {
            tmp[x + d1 + i][y - d1 + i] = 5;
        }
        // 4
        for (int i = 0; i <= d1; i++) {
            tmp[x + d2 + i][y + d2 - i] = 5;
        }

        bfs(x, y - 1, tmp);
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // System.out.print(tmp[i][j] + " ");
        // }
        // System.out.println("");
        // }
        // System.out.println("");

        int a5 = 0;
        int a1, a2, a3, a4;
        a1 = a2 = a3 = a4 = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum += arr[i][j];
                if (tmp[i][j] != 1) {
                    a5 += arr[i][j];
                    continue;
                }

                if (1 <= i && i < x + d1 && 1 <= j && j <= y) {
                    a1 += arr[i][j];
                } else if (1 <= i && i <= x + d2 && y < j && j <= n) {
                    a2 += arr[i][j];
                } else if (x + d1 <= i && i <= n && 1 <= j && j < y - d1 + d2) {
                    a3 += arr[i][j];
                } else if (x + d2 < i && i <= n && y - d1 + d2 <= j && j <= n) {
                    a4 += arr[i][j];
                }
            }
        }

        List<Integer> li = new ArrayList<>((Arrays.asList(a1, a2, a3, a4, a5)));
        // System.out.println(li + " " + a5);
        Collections.sort(li);

        ans = Math.min(li.get(4) - li.get(0), ans);
    }

    private static void bfs(int x, int y, int[][] tmp) {
        boolean[][] vis = new boolean[22][22];
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, 1, 0, -1 };
        Queue<PQ> q = new LinkedList<>();
        q.offer(new PQ(x, y));
        vis[x][y] = true;
        tmp[x][y] = 1;

        while (!q.isEmpty()) {
            PQ cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > n)
                    continue;
                if (tmp[nx][ny] == 5)
                    continue;
                if (vis[nx][ny] == true)
                    continue;

                q.offer(new PQ(nx, ny));
                vis[nx][ny] = true;
                tmp[nx][ny] = 1;
            }
        }
    }
}
