#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int h = 10, w = 10;

bool isBound(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

struct QueueNode
{
    int x,y;
    int dist;
};

struct Pos
{
    int x, y;
};

int main(){
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    char grid[h][w];                // Set up grid
    bool visited[h][w] = {false};

    Pos start, end;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fin >> grid[i][j];
            if (grid[i][j] == 'L') {
                start.x = j;
                start.y = i;
            } else if (grid[i][j] == 'B') {
                end.x = j;
                end.y = i;
            }
        }
    }

    queue<QueueNode> q;
    q.push({start.x, start.y, 0});
    visited[start.y][start.x] = true;
    int dx[] = {1, 0, -1, 0}; // Right, Down, Left, Up
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        QueueNode current = q.front();
        q.pop();

        if(current.x==end.x && current.y==end.y){
            fout << current.dist-1;
            return 0;
        }

        for(int i=0;i<4;i++){
            int nx=current.x+dx[i];
            int ny = current.y+dy[i];

            if(isBound(nx,ny) && !visited[ny][nx] && grid[ny][nx] != 'R'){
                visited[ny][nx] = true;
                q.push({ny,nx,current.dist+1});
            }
        }
    }
}
