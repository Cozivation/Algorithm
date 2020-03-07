#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int n, m, x, y, k;
int cmd, dir, res; // 명령, 현재방향, 윗면에 쓰인 수
int new_x, new_y, tmp;
int dice[7], board[21][21], dice_tmp[7];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0}; // (0) 동 (1) 서 (2) 북 (3) 남
deque<int> d; // 명령

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k; // n행 m열, 주사위 초기좌표(x,y), 명령의 갯수 k
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    for(int i=1; i<=k; i++){
        cin >> cmd;
        d.push_back(cmd);
    }

    for(int i=1; i<=k; i++){
        dir = d.front()-1;
        d.pop_front();
        new_x = x + dx[dir];
        new_y = y + dy[dir];

        /*
        cout << i << "th try\n";
        cout << "new_x, new_y = " << new_x << " " << new_y << "\n";
        */

        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
            continue;

        for(int j=1; j<=6; j++)
            dice_tmp[j] = dice[j];

        if(dir == 0){ //동
            dice[1] = dice_tmp[3];
            dice[3] = dice_tmp[6];
            dice[4] = dice_tmp[1];
            dice[6] = dice_tmp[4];
            //루프 발생하면서 값이 덮어씌워진다 -> copy 로 해결
        }
        else if(dir == 1){ //서
            dice[1] = dice_tmp[4];
            dice[3] = dice_tmp[1];
            dice[4] = dice_tmp[6];
            dice[6] = dice_tmp[3];
        }
        else if(dir == 2){ //북
            dice[1] = dice_tmp[2];
            dice[2] = dice_tmp[6];
            dice[5] = dice_tmp[1];
            dice[6] = dice_tmp[5];
        }
        else{ //남
            dice[1] = dice_tmp[5];
            dice[2] = dice_tmp[1];
            dice[5] = dice_tmp[6];
            dice[6] = dice_tmp[2];
        }

        if(board[new_x][new_y] == 0){ //board 가 0 : 주사위 -> board
            board[new_x][new_y] = dice[6];
        }
        else{ //board 가 0이 아닌 경우 : board -> 주사위
            // cout << "board not 0\n";
            // cout << board[new_x][new_y] << "\n";
            dice[6] = board[new_x][new_y];
            board[new_x][new_y] = 0;
        }
        /*
        cout << "dice[1]~[6]\n";
        for(int i=1; i<=6; i++){
            cout << dice[i] << " ";
        }
        cout << "\n";
        */
        x = new_x;
        y = new_y;

        cout << dice[1] << "\n";
    }
}
