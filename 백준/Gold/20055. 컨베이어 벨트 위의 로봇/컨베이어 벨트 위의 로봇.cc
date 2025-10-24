#include <deque>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    deque<int> belt_dq(2 * N, 0);
    deque<int> robot_dq(2 * N, 0);
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> belt_dq[i];
    }
    int stage = 0;
    while (true)
    {
        // 단계 증가
        stage++;
        // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        int d = belt_dq.back(); belt_dq.pop_back();
        belt_dq.push_front(d);
        int robot = robot_dq.back(); robot_dq.pop_back();
        robot_dq.push_front(robot);

        // 내리는 위치 로봇이 도달 시 내림
        if (robot_dq[N - 1] == 1)
            robot_dq[N - 1] = 0;

        // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 
        // 만약 이동할 수 없다면 가만히 있는다
        // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다
        for (int i = N - 2; i >= 0; i--)
        {
            if (robot_dq[i] == 1)
            {
                int idx = i + 1;
                // 한칸 이동 및 내구도 1 감소
                if (belt_dq[idx] != 0 && robot_dq[idx] == 0)
                {
                    belt_dq[idx]--;
                    robot_dq[i] = 0;
                    robot_dq[idx] = 1;
                }
            }
        }

        // 내리는 위치 로봇이 도달 시 내림
        if (robot_dq[N - 1] == 1)
            robot_dq[N - 1] = 0;

        // 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다
        if (belt_dq[0] != 0)
        {
            robot_dq[0] = 1;
            belt_dq[0]--;
        }
        // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다
        int cnt = 0;
        for (int i = 0; i < 2 * N; i++)
        {
            if (belt_dq[i] == 0)
                cnt++;
            if (cnt >= K)
            {
                cout << stage;
                return 0;
            }
        }
    }
    return 0;
}
