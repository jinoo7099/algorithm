import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Point {
    int x;
    int y;
    int z;

    Point(int z, int x, int y) {
        this.z = z;
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int dx[] = { -1, 0, 1, 0, 0, 0 };
    static int dy[] = { 0, 1, 0, -1, 0, 0 };
    static int dz[] = { 0, 0, 0, 0, 1, -1 };
    static int l, r, c;
    static char arr[][][];
    static int[][][] vis;
    static Queue<Point> q;
    static int cnt;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            if (l == 0 && r == 0 && c == 0) {
                break;
            }

            arr = new char[l][r][c];
            vis = new int[l][r][c];
            q = new LinkedList<>();
            cnt = 0;

            for (int i = 0; i < l; i++) {
                for (int j = 0; j < r; j++) {
                    String str = br.readLine();
                    for (int k = 0; k < c; k++) {

                        arr[i][j][k] = str.charAt(k);
                        if (arr[i][j][k] == 'S') {
                            Point p = new Point(i, j, k);
                            vis[i][j][k] = 1;
                            q.add(p);
                        }
                    }
                }
                br.readLine();
            }

            bfs();

            if (cnt == 0) {
                System.out.println("Trapped!");
            }

        }

    }

    static void bfs() {
        while (!q.isEmpty()) {
            Point cur = q.poll();

            for (int i = 0; i < 6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) {
                    continue;
                }

                if (arr[nz][nx][ny] == '.' && vis[nz][nx][ny] == 0) {
                    vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
                    q.add(new Point(nz, nx, ny));
                } else if (arr[nz][nx][ny] == 'E') {
                    cnt++;
                    System.out.println("Escaped in " + vis[cur.z][cur.x][cur.y] + " minute(s).");

                    q.clear();
                    return;
                }
            }
        }
    }
}
