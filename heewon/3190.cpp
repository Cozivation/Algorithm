#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int board[101][101];
int n, k, cnt, dir, t;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
deque<pair<int, int> > rec; // 방향전환 몇초, 방향(D(1) 오른쪽/L(2) 왼쪽)
deque<pair<int, int> > d;

int main(){
    cin >> n >> k; // n*n board, k개의 사과
    for(int i=1; i<=k; i++){
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과 위치
    }
    cin >> cnt; // 방향전환 횟수
    for(int i=1; i<=cnt; i++){
        int a;
        char b;
        cin >> a >> b;
        if(b == 'D')
            rec.push_back({a, 1});
        else // b == "L"
            rec.push_back({a, 2});
    }

    d.push_back({1, 1});
    dir = 1;

    while(true){
        bool flag = false; // 자기 몸 부딪쳤는지 여부
        t++;
        // cout << t << "초\n";

        /*
        cout << "rec list\n";
        for(int i=0; i<rec.size(); i++)
            cout << rec[i].first << " " << rec[i].second << "\n";
        */

        int new_x = d.back().first + dx[dir-1];
        int new_y = d.back().second + dy[dir-1];

        // cout << "new_x, new_y = "<< new_x << "," << new_y << "\n";
        if(new_x < 1 || new_x > n || new_y < 1 || new_y > n){ // 벽
            // cout << "벽\n";
            break;
        }
        for(int i=0; i<d.size(); i++){
            if(d[i].first == new_x && d[i].second == new_y){ // 자기 몸
                flag = true;
                break;
            }
        }
        if(flag){
            // cout << "flag 걸림\n";
            break;
        }
        if(board[new_x][new_y] == 1){ // 사과 있음
            board[new_x][new_y] = 0; // 사과 먹음
            d.push_back({new_x, new_y});
        }
        else{
            d.push_back({new_x, new_y});
            d.pop_front(); // 꼬리 위치한 칸 비우기
        }

        if(rec.size()){
            if(t == rec.front().first){
                if(rec.front().second == 1){ // 오른쪽
                    if(dir == 4)
                        dir = 1;
                    else
                        dir++;
                }
                else{ // 왼쪽
                    if(dir == 1)
                        dir = 4;
                    else
                        dir--;
                }
                rec.pop_front();
                // cout << "dir = " << dir << "\n";
            }
        } // 방향 전환
    }
    cout << t << "\n";
}