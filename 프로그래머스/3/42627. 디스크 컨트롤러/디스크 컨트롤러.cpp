#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    int request_time;
    int execution_time;

    Task(int rt, int et) : request_time(rt), execution_time(et) {}
};

// 실행 시간이 짧은 작업이 우선
struct cmp {
    bool operator()(const Task& a, const Task& b) {
        return a.execution_time > b.execution_time;
    }
};

int solution(vector<vector<int>> jobs) {
    // 요청 시간 순으로 정렬
    sort(jobs.begin(), jobs.end());

    priority_queue<Task, vector<Task>, cmp> pq;

    int time = 0;       // 현재 시간
    int idx = 0;        // jobs 인덱스
    int totalTime = 0;  // 총 대기 시간
    int completed = 0;  // 완료된 작업 수
    int n = jobs.size();

    while (completed < n) {
        // 현재 시간까지 들어온 작업들 큐에 넣기
        while (idx < n && jobs[idx][0] <= time) {
            pq.push(Task(jobs[idx][0], jobs[idx][1]));
            idx++;
        }

        if (!pq.empty()) {
            // 가장 짧은 작업 처리
            Task task = pq.top(); pq.pop();
            time += task.execution_time;
            totalTime += (time - task.request_time);
            completed++;
        } else {
            // 큐가 비어있다면 다음 작업 요청 시간으로 점프
            if (idx < n)
                time = jobs[idx][0];
        }
    }

    return totalTime / n;
}
