#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

typedef struct Info{
	int age;
	string name;
	bool operator<(const Info& nxt) const { return age < nxt.age; } // 정렬 방법 1
} Info;

int main() {
	int n; cin >> n;
	vector<Info> members;
	while(n--) {
		int age; cin >> age;
		string name; cin >> name;
		members.push_back({ age, name });
	}
	stable_sort(members.begin(), members.end()); // 정렬 방법 1
	// 람다식을 활용한 정렬 - 방법 2
	//stable_sort(members.begin(), members.end(), [](const Info& a, const Info& b) { return a.age < b.age; });
	for (const Info& elem : members) cout << elem.age << ' ' << elem.name << endl;
	return 0;
}
