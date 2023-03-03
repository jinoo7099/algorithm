import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Point {
        int x;
        int y;

        Point(int x2, int y2) {
            this.x = x2;
            this.y = y2;
        }
    }

    static int n, m, k;
    static int arr[][] = new int[22][22];
    static int dx[] = { -1, 0, 1, 0 };
    static int dy[] = { 0, 1, 0, -1 };
    static int[][] dice = {
            { 0, 2, 0 }, { 4, 1, 3 }, { 0, 5, 0 }, { 0, 6, 0 }
    };

    static int nxtDir = 1;
    static int ans = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 1; j <= m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int x = 1;
        int y = 1;

        while (k-- > 0) {
            // 1
            int nx = x + dx[nxtDir];
            int ny = y + dy[nxtDir];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                // 0 -> 2
                // 1 -> 3
                // 2 -> 0
                // 3 -> 1
                nxtDir = (nxtDir + 2) % 4;

                nx = x + dx[nxtDir];
                ny = y + dy[nxtDir];
            }
            roll(nxtDir);

            // 2
            int B = arr[nx][ny];
            int C = bfs(B, nx, ny);

            ans += B * C;

            // 3
            int A = dice[3][1];
            if (A > B) {
                nxtDir = (nxtDir + 1) % 4;
            } else if (A < B) {
                nxtDir = (nxtDir - 1 + 4) % 4;
            }

            x = nx;
            y = ny;
        }

        System.out.println(ans);
    }

    private static int bfs(int B, int x, int y) {
        boolean[][] vis = new boolean[22][22];
        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(x, y));
        vis[x][y] = true;
        int cnt = 1;

        while (!q.isEmpty()) {
            Point cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;
                if (vis[nx][ny] == true || arr[nx][ny] != B)
                    continue;

                cnt++;
                vis[nx][ny] = true;
                q.offer(new Point(nx, ny));
            }
        }

        return cnt;
    }

    private static void roll(int nxtDir) {
        if (nxtDir == 0) {
            int c = dice[0][1];
            for (int i = 0; i < 3; i++) {
                dice[i][1] = dice[i + 1][1];
            }
            dice[3][1] = c;
        } else if (nxtDir == 1) {
            int c = dice[1][2];
            dice[1][2] = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[3][1];
            dice[3][1] = c;
        } else if (nxtDir == 2) {
            int c = dice[3][1];
            for (int i = 3; i > 0; i--) {
                dice[i][1] = dice[i - 1][1];
            }
            dice[0][1] = c;
        } else {
            int c = dice[1][0];
            dice[1][0] = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[3][1];
            dice[3][1] = c;
        }
    }
}
