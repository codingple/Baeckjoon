#include <iostream>
#include <queue>

using namespace std;

typedef struct bead{
    int x;
    int y;
}bead;
typedef struct state{
    bead blue;
    bead red;
}state;

int areFacing(bead red, bead blue){
    return (red.x == blue.x && red.y == blue.y) ? 1 : 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    char map[N][M];
    bead red;
    bead blue;
    bead hole;
    queue<state> stat;
    int last = 1;
    int cnt = 1;
    int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char tmp;
            cin >> tmp;
            if (tmp=='B'){
                blue.x = j;
                blue.y = i;
                tmp = '.';
            }
            else if (tmp=='R'){
                red.x = j;
                red.y = i;
                tmp = '.';
            }
            else if (tmp=='O'){
                hole.x = j;
                hole.y = i;
            }

            map[i][j] = tmp;
        }
    }
    state crnt_state;
    crnt_state.blue = blue;
    crnt_state.red = red;
    stat.push(crnt_state);

    int letMeGetOut = 0;
    while (cnt < 11){
        if (stat.empty())
            cnt = -1;
        int i = last;
        for(i; i>0; i--){
            state crnt_state = stat.front();
            stat.pop();
            last --;

            for(int j=0; j<4; j++){
                state s = crnt_state;
                int red_moved = 0;
                int blue_moved = 0;
                // red moves
                while(map[s.red.y + d[j][0]][s.red.x + d[j][1]] == '.'){
                    s.red.y += d[j][0];
                    s.red.x += d[j][1];
                    red_moved++;
                }
                // blue moves
                while(map[s.blue.y + d[j][0]][s.blue.x + d[j][1]] == '.'){
                    s.blue.y += d[j][0];
                    s.blue.x += d[j][1];
                    blue_moved++;
                }

                // blue goal : nothing
                if (map[s.blue.y + d[j][0]][s.blue.x + d[j][1]] == 'O')
                    continue;

                // red goal
                else if (map[s.red.y + d[j][0]][s.red.x + d[j][1]] == 'O'){
                    letMeGetOut = 1;
                    break;
                }

                // both faced
                else if (areFacing(s.red, s.blue)){
                    if (red_moved > blue_moved){
                        s.red.y -= d[j][0];
                        s.red.x -= d[j][1];
                    }
                    else if (red_moved < blue_moved){
                        s.blue.y -= d[j][0];
                        s.blue.x -= d[j][1];
                    }
                    else
                        cout << "ERROR";
                }

                stat.push(s);
                last++;

            } // each direction
            if (letMeGetOut)
                break;
        } // each cnt
        if (letMeGetOut)
                break;
        cnt++;
    }
    if (cnt == 11)
        cnt = -1;

    cout << cnt;

    return 0;
}
