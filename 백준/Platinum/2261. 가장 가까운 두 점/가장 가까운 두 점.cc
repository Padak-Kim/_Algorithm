#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct Point {
	int x, y;

	bool operator<(const Point& p) const {
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
};

long long dist(const Point& p1, const Point& p2)
{
	long long dx = p1.x - p2.x;
	long long dy = p1.y - p2.y;
	return dx * dx + dy * dy;
}
long long solve(vector<Point>& points, int left, int right) 
{
	int n = right - left;
	if (n <= 1) return (1LL << 62);

	if (n == 2) {
		if (points[left].y > points[left + 1].y) swap(points[left], points[left + 1]); // y정렬 유지
		return dist(points[left], points[left + 1]);
	}

	int mid = left + right >> 1;
	long long midx = points[mid].x;

	long long dl = solve(points, left, mid);
	long long dr = solve(points, mid, right);
	long long d = min(dl, dr);

	int i = left, j = mid, k = 0;

	vector<Point> temp(n);
	while (i < mid && j < right) {
		if (points[i].y <= points[j].y) {
			temp[k++] = points[i++];
		}
		else
		{
			temp[k++] = points[j++];
		}
	}
	while (i < mid) temp[k++] = points[i++];
	while (j < right) temp[k++] = points[j++];
	for (int t = 0; t < n; t++) points[left + t] = temp[t];

	vector<Point> strip;
	strip.reserve(n);
	for (int t = left; t < right; t++)
	{
		long long dx = points[t].x - midx;
		if (dx * dx < d) strip.push_back(points[t]);
	}

	int N = (int)strip.size();
	for (int a = 0; a < N; a++)
	{
		for (int b = a + 1; b < N; b++)
		{
			long long dy = strip[b].y - strip[a].y;
			if (dy * dy >= d) break;
			long long cur = dist(strip[a], strip[b]);
			if (cur < d) d = cur;
		}
	}

	return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<Point> points(N);
	for (int i = 0; i < N; i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	sort(points.begin(), points.end());

	long long ans = solve(points, 0, N);

	cout << ans << "\n";

	return 0;
}