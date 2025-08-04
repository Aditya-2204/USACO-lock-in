/*
ID: aditya_10
LANG: C++
TASK: castle
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 50;
int M, N;
int grid[MAXN][MAXN];
int roomID[MAXN][MAXN]; // ID of the room each cell belongs to
int roomSize[MAXN * MAXN]; // Size of each room
bool visited[MAXN][MAXN];

// Directions: west, north, east, south
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int wallMask[4] = {1, 2, 4, 8};

int totalRooms = 0;
int maxRoomSize = 0;

int bfs(int sy, int sx, int id) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;
    roomID[sy][sx] = id;

    int size = 1;
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visited[ny][nx]) continue;
            if (grid[y][x] & wallMask[d]) continue; // wall exists

            visited[ny][nx] = true;
            roomID[ny][nx] = id;
            q.push({ny, nx});
            size++;
        }
    }
    return size;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    cin >> M >> N;
    for (int i = 0; i < N; i++) // Note: N rows, M columns
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    // Step 1: Flood-fill to find rooms
    int roomCount = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!visited[y][x]) {
                int size = bfs(y, x, roomCount);
                roomSize[roomCount] = size;
                maxRoomSize = max(maxRoomSize, size);
                roomCount++;
            }
        }
    }

    // Step 2: Try removing each north/east wall
    int bestSize = 0;
    int bestX = 0, bestY = 0;
    char bestDir = ' ';

    for (int x = 0; x < M; x++) {
        for (int y = N - 1; y >= 0; y--) {
            int currID = roomID[y][x];
            // Try north wall
            if ((grid[y][x] & 2) && y > 0) {
                int nextID = roomID[y - 1][x];
                if (currID != nextID) {
                    int combined = roomSize[currID] + roomSize[nextID];
                    if (combined > bestSize ||
                        (combined == bestSize && (x < bestX ||
                         (x == bestX && y > bestY))) ||
                        (combined == bestSize && x == bestX && y == bestY && bestDir == 'E')) {
                        bestSize = combined;
                        bestY = y;
                        bestX = x;
                        bestDir = 'N';
                    }
                }
            }
            // Try east wall
            if ((grid[y][x] & 4) && x < M - 1) {
                int nextID = roomID[y][x + 1];
                if (currID != nextID) {
                    int combined = roomSize[currID] + roomSize[nextID];
                    if (combined > bestSize ||
                        (combined == bestSize && (x < bestX ||
                         (x == bestX && y > bestY))) ||
                        (combined == bestSize && x == bestX && y == bestY && bestDir == 'N')) {
                        bestSize = combined;
                        bestY = y;
                        bestX = x;
                        bestDir = 'E';
                    }
                }
            }
        }
    }

    // Output
    cout << roomCount << "\n";
    cout << maxRoomSize << "\n";
    cout << bestSize << "\n";
    cout << bestY + 1 << " " << bestX + 1 << " " << bestDir << "\n";

    return 0;
}
