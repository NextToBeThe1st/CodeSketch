#if 01
#include <iostream>
using namespace std;

int n, l, st, ed, mn = 2e9,mx = 0;
char road[10004];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> l;
	fill(road, road + 10004, '.');
	for (int i = 0;i < n;i++) {
		cin >> st >> ed;
		for (int j = st;j < ed;j++) {
			road[j] = 'M';
		}
		mn = min(mn, st);
		mx = max(mx, ed);
	}

	for (int i = 0;i <=mx;i++) {
		cout << road[i];
	}

	return 0;
}
#endif