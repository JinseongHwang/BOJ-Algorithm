#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
	string name;
	int kor, eng, math;

	bool operator<(const Student& s) const {
		if (this->kor == s.kor) {
			if (this->eng == s.eng) {
				if (this->math == s.math) {
					return this->name < s.name;
				}
				else return this->math > s.math;
			}
			else return this->eng < s.eng;
		}
		else return this->kor > s.kor;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<Student> v;
	while (n--) {
		string a; int b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a,b,c,d });
	}
	sort(v.begin(), v.end());
	for (const Student& s : v) cout << s.name << "\n";

	return 0;
}
