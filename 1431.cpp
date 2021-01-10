
// 버스에서 집 오는 길에 폰으로 푼 첫 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> serials;

int getNumber(const char& c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    return 0; // 숫자가 아니면 0을 반환해서 영향 없도록
}

bool compare(const string& a, const string& b) {
    int alen = a.length();
    int blen = b.length();
    if (alen == blen) {
        int asum = 0;
        int bsum = 0;
        for (int i = 0; i < alen; i++) {
            asum += getNumber(a[i]);
            bsum += getNumber(b[i]);
        }
        if (asum == bsum) {
            return a < b;
        }
        return asum < bsum;
    }
    return alen < blen;
}

int main() {
    cin >> N;
    while (N--) {
        string input;
        cin >> input;
        serials.emplace_back(input);
    }
    
    sort(serials.begin(), serials.end(), compare);
    
    for (const string& serial : serials)
        cout << serial << '\n';
    
    return 0;
}
