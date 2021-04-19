#include <bits/stdc++.h>

using namespace std;

const string date[7] = {
        "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};

int getFullDay(int m) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    else {
        return 28;
    }
}

int main() {
    int m, d;
    cin >> m >> d;

    int fullDay = 0;
    for (int i = 1; i < m; i++) {
        fullDay += getFullDay(i);
    }
    fullDay += d;

    cout << date[fullDay % 7] << '\n';

    return 0;
}
