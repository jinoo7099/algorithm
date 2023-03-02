import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static class Shark {
        int id, x, y, dir;
        int[][] priority = new int[5][5];

        Shark() {
        }

        public int findNextDir(Set<Integer> noSmellSet) {
            for (int i = 1; i <= 4; i++) {
                if (noSmellSet.contains(priority[dir][i])) {
                    return priority[dir][i];
                }
            }
            return 0;
        }
    }

    static int n, m, k;
    static int[][] arr = new int[21][21];
    static int[][] smellOwner = new int[21][21];
    static int[][] leftTime = new int[21][21];
    static Map<Integer, Shark> sharks = new HashMap<>();
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };
    static int time = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());

                if (arr[i][j] > 0) {
                    Shark s = new Shark();
                    s.id = arr[i][j];
                    s.x = i;
                    s.y = j;
                    sharks.put(s.id, s);

                    smellOwner[i][j] = s.id;
                    leftTime[i][j] = k;

                }
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            Shark s = sharks.get(i + 1);
            s.dir = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < m; i++) {
            Shark s = sharks.get(i + 1);

            for (int j = 0; j < 4; j++) {
                st = new StringTokenizer(br.readLine());

                for (int z = 0; z < 4; z++) {
                    s.priority[j + 1][z + 1] = Integer.parseInt(st.nextToken());
                }
            }
        }

        solve();
    }

    static void solve() {
        while (time++ < 1000) {
            moveShark();
            decreaseSmellTime();
            createSmell();

            if (sharks.size() == 1) {
                System.out.println(time);
                return;
            }
        }

        System.out.println(-1);
    }

    static void moveShark() {
        Queue<Integer> willRemove = new LinkedList<>();

        for (Integer id : sharks.keySet()) {
            Set<Integer> noSmellSet = new HashSet<>();
            Set<Integer> mySmellSet = new HashSet<>();

            Shark s = sharks.get(id);

            for (int i = 0; i < 4; i++) {
                int nx = s.x + dx[i];
                int ny = s.y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (smellOwner[nx][ny] == 0) {
                    noSmellSet.add(i + 1);
                } else if (smellOwner[nx][ny] == s.id) {
                    mySmellSet.add(i + 1);
                }
            }

            int nextDir = s.findNextDir(noSmellSet);

            if (nextDir == 0) {
                nextDir = s.findNextDir(mySmellSet);
            }

            arr[s.x][s.y] = 0;
            if (nextDir == 1) {
                s.x -= 1;
            } else if (nextDir == 2) {
                s.x += 1;
            } else if (nextDir == 3) {
                s.y -= 1;
            } else if (nextDir == 4) {
                s.y += 1;
            }

            if (arr[s.x][s.y] == 0 || s.id < arr[s.x][s.y]) {
                arr[s.x][s.y] = s.id;
                s.dir = nextDir;
            } else {
                willRemove.add(s.id);
            }
        }

        while (!willRemove.isEmpty()) {
            sharks.remove(willRemove.poll());
        }

    }

    static void decreaseSmellTime() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (leftTime[i][j] == 0)
                    continue;

                leftTime[i][j]--;

                if (leftTime[i][j] == 0) {
                    smellOwner[i][j] = 0;
                }
            }
        }
    }

    static void createSmell() {
        for (Integer id : sharks.keySet()) {
            Shark s = sharks.get(id);

            smellOwner[s.x][s.y] = s.id;
            leftTime[s.x][s.y] = k;
        }
    }

}

/*
 * https://bcp0109.tistory.com/213
 */