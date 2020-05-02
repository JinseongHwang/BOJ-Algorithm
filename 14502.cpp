// 14502 연구소 - BFS
/*
- bfs로 벽을 어디에 세울것인지 정하는 것
: 최대 8 * 8 = 64칸 중에 벽 지을 3칸을 정해서 지어보고 경우의 수 중 안전지대의 갯수가 가장 많이 나오는 값을 반환
  C(64, 3) == 41,664 -> 가능할것같기도 ?

  1. 벽의 위치를 작은 index부터 차차 커지도록. (단, index값이 1이거나 2이면 넘어간다.)
  1-1. 벽을 위치를 어떻게 바꿀것이냐 ... : 6중 for문 : 연구실의 크기가 작으니 가능하다고 생각함.
  2. 벽의 위치가 바뀔때마다 바이러스를 기준으로 bfs로 탐색한다.
  3. 안전지대의 값이 가장 큰 값을 result에 넣어준다. 갱신필수

  - 다른 접근방법들
- 바이러스를 기준으로 bfs를 진행하는 것 : 벽을 어디세워야 할지 모르겠음
- 안전지대를 0부터 h*w 까지 늘려가며 가능한지 판단하는 것 : 매우비효율적
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAX 8
typedef pair<int, int> pii;

int h, w; // height, width
int lab[MAX][MAX]; // 연구실의 전체 구조를 저장(-1: 가상의 벽, 0: 빈공간, 1: 기존의 벽, 2: 바이러스)
int num_virus = 0; // 각 바이러스에 identity 부여, 최초 입력된 바이러스의 개수
int num_walls = 0; // 최초 입력된 벽의 개수
vector<pii> pos_virus; // 입력된 바이러스의 위치를 저장
bool visit[MAX][MAX]; // BFS 시행 시 방문 노드 확인용
pii start; bool chk; // 벽을 만들 수 있는 최초의 벽의 위치를 저장
int result = 0; // 구해야하는 문제의 목표 : 안전지대의 최댓값

int bfs();
int calc_safety_zone(int virus);
int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 0 && !chk) { // 최초의 빈공간의 위치를 저장
				start = make_pair(i, j); chk = true;
			}
			if (lab[i][j] == 1) num_walls++; // 입력된 벽의 갯수
			if (lab[i][j] == 2) {// 입력된 값이 바이러스일 경우
				pos_virus.push_back(pii(i, j));
				num_virus++;
			}
		}
	} /* 입력완료 & 바이러스 위치를 pair<int, int> 타입의 vector에 저장 */

	int first_row = start.first, first_col = start.second,
		second_row, second_col, third_row, third_col; // 초기값 설정
	bool isFirst = false;
	// 하위 벽을 넘어가거나 겹칠 수 없으며 상위 벽이 움직여야 하는 경우는 하위 벽이 끝까지 갔기때문.
	// -> 하위 벽 초기화 필요. 바로 위의 벽의 다음위치로.
	for (; first_row < h; ++first_row) { // 첫번째 벽의 이동
		for (first_col = 0; first_col < w; ++first_col) {
			if (!isFirst) {
				first_col = start.second;
				isFirst = true;
			}
			if (lab[first_row][first_col] >= 1) continue;

			for (second_row = first_row; second_row < h; ++second_row) { // 두번째 벽의 이동
				for (second_col = 0; second_col < w; ++second_col) {
					if (first_row == second_row && first_col >= second_col) continue;
					if (lab[second_row][second_col] >= 1) continue;

					for (third_row = second_row; third_row < h; ++third_row) { // 세번째 벽의 이동
						for (third_col = 0; third_col < w; ++third_col) {
							if (second_row == third_row && second_col >= third_col) continue;
							if (lab[third_row][third_col] >= 1) continue;
							lab[first_row][first_col] = -1; // 만들어준 벽은 -1의 값을 가진다.
							lab[second_row][second_col] = -1;
							lab[third_row][third_col] = -1;
							result = max(result, bfs()); // 탐색 후 최댓값을 result에 넣는다.
							lab[first_row][first_col] = 0; // 탐색 후 다시 0으로 되돌려놓는다.
							lab[second_row][second_col] = 0;
							lab[third_row][third_col] = 0;
						}
					}
				}
			}
		}
	}
	printf("%d\n", result);
	return 0;
}
int bfs() {
	/*  1. 최초 위치했던 바이러스들 1개씩 bfs를 진행한다.
		 1) 처음 위치를 push한다. visit = true 한다
		 2) 처음(front) 노드를 pop하면서 pop하는 노드의 상 하 좌 우를 push한다.
		 3) 큐가 빈 공간이 될 때까지 1), 2) 과정을 반복한다.
		2. 기존의 바이러스가 아닌 곳에 visit = true 찍을 때 마다 spread_virus++ 해주자.
		3. 모든 바이러스의 bfs를 마치면 visit은 초기화한다.
		4. 모든 바이러스의 bfs를 마치면 spread_virus + num_virus 값을 반환해주자.
	*/
	int spread_virus = 0;
	memset(visit, 0, sizeof(bool) * MAX * MAX);
	for (int i = 0; i < num_virus; ++i) {
		queue<pii> q; // 큐 생성
		q.push(pii(pos_virus[i].first, pos_virus[i].second));
		visit[pos_virus[i].first][pos_virus[i].second] = true;
		while (!q.empty()) {
			pii tmp = q.front();
			q.pop();
			if (tmp.first - 1 >= 0 && !visit[tmp.first - 1][tmp.second] && lab[tmp.first - 1][tmp.second] == 0) { // 상
				// 연구실 범위를 벗어나지 않으며 && 방문하지 않은 노드여야 하며 && 빈 공간이어야 한다.
				q.push(pii(tmp.first - 1, tmp.second));
				visit[tmp.first - 1][tmp.second] = true; spread_virus++;
			}
			if (tmp.first + 1 < h && !visit[tmp.first + 1][tmp.second] && lab[tmp.first + 1][tmp.second] == 0) { // 하
				q.push(pii(tmp.first + 1, tmp.second));
				visit[tmp.first + 1][tmp.second] = true; spread_virus++;
			}
			if (tmp.second - 1 >= 0 && !visit[tmp.first][tmp.second - 1] && lab[tmp.first][tmp.second - 1] == 0) { // 좌
				q.push(pii(tmp.first, tmp.second - 1));
				visit[tmp.first][tmp.second - 1] = true; spread_virus++;
			}
			if (tmp.second + 1 < w && !visit[tmp.first][tmp.second + 1] && lab[tmp.first][tmp.second + 1] == 0) { // 우
				q.push(pii(tmp.first, tmp.second + 1));
				visit[tmp.first][tmp.second + 1] = true; spread_virus++;
			}
		}
	}
	return calc_safety_zone(spread_virus + num_virus);
}
int calc_safety_zone(int virus) {
	int ret_value = (h * w) - num_walls - virus - 3;
	return ret_value;
}
