#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	int studentNum, enrollTime, recommendCount;
} Student;
vector<Student> candidate;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

bool compareForDelete(Student a, Student b) {
	if (a.recommendCount == b.recommendCount) return a.enrollTime > b.enrollTime;
	else return a.recommendCount > b.recommendCount;
}

bool compareLess(Student a, Student b) {
	return a.studentNum < b.studentNum;
}

bool isExist(int n) {
	// 이미 존재한다면 추천 수만 올려주자
	for (int i = 0; i < candidate.size(); ++i) {
		if (candidate[i].studentNum == n) {
			candidate[i].recommendCount++;
			return true;
		}
	} return false;
}

void deleteMinimum() {
	// 추천수 가장 작은 -> 같다면 가장 오래된 사람 찾아서 pop
	// 내림차순 정렬해서 pop_back해준다
	sort(candidate.begin(), candidate.end(), compareForDelete);
	candidate.back().recommendCount = 0;
	candidate.pop_back();
}

int main() { // 후보 추천하기
	init();
	int n; cin >> n;
	int votes; cin >> votes;
	for (int num, time = 0; time < votes; ++time) {
		cin >> num;
		if (isExist(num)) continue;
		Student s = { num, time, 1 };

		// 꽉 찼으면 하나 삭제해주자
		if(candidate.size() >= n) deleteMinimum();
		candidate.push_back(s);
	}
	sort(candidate.begin(), candidate.end(), compareLess);
	for (const auto& c : candidate) {
		cout << c.studentNum << " ";
	}

	return 0;
}
