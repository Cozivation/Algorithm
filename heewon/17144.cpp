#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int R, C, T;
int new_x, new_y, dust, sec, res;
itn air_x, air_y;
int A_copy[51][51];
int A[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cw[4] = {0, 3, 1, 2};
int ccw[4] = {0, 2, 1, 3};
vector<pair<int, int> > air;
queue<pair<int, int> > dust;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> T;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> A[i][j];
            if(A[i][j] == -1)
                air.push_back({i, j});
        }
    }

    for(int t=1; t<=T; t++){
        for(int i=0; i<r; i++) {
            for (int j = 0; j < c; j++) {
                if (A[i][j] <= 0)
                    continue;
                dust.push({i, j});
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                A_copy[i][j] = A[i][j];
            }
        }

        while(!q.empty()) {
            tmp_x = q.front().first;
            tmp_y = q.front().second;
            q.pop();

            for(int dir=0; dir<4; dir++){
                new_x = i + dx[dir];
                new_y = j + dy[dir];

                if(new_x < 0 || new_x >= r || new_y < 0 || new_y >= c)
                    continue;

                if(A[new_x][new_y] <= 0)
                    continue;

                dust = A_copy[i][j] / 5;
                A[new_x][new_y] += dust;
                A[i][j] -= dust;
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                A_copy[i][j] = A[i][j];
            }
        }

        air_x = v[0].first;
        air_y = v[0].second;

        air_x ++;
        A[air_x][air_y] = 0;
        for(int dir=0; dir<4; dir++){
            while(true){
                new_x = air_x + dx[ccw[dir]];
                new_y = air_y + dy[ccw[dir]];

                if(new_x < 0 || new_x >= r || new_y < 0 || new_y >= c)
                    break;
                if(new_x == v[0].first && new_y == v[0].second)
                    break;

                A[new_x][new_y] = A_copy[air_x][air_y];
                air_x = new_x;
                air_y = new_y;
            }
        }

        air_x = v[1].first;
        air_y = v[1].second;

        air_x ++;
        A[air_x][air_y] = 0;
        for(int dir=0; dir<4; dir++){
            while(true){
                new_x = air_x + dx[cw[dir]];
                new_y = air_y + dy[cw[dir]];

                if(new_x < 0 || new_x >= r || new_y < 0 || new_y >= c)
                    break;
                if(new_x == v[1].first && new_y == v[1].second)
                    break;

                A[new_x][new_y] = A_copy[air_x][air_y];
                air_x = new_x;
                air_y = new_y;
            }
        }
        // 공기청정기
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(A[i][j] > 0)
                res += A[i][j];
        }
    }
    cout << res << '\n';
    return 0;
}