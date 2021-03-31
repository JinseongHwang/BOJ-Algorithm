//
// Created by jinseonghwang on 21. 3. 29..
//
// 카드 합체 놀이

#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

struct cmp {
    bool operator()(const ll &a, const ll &b) {
        return a > b;
    }
};

int main() {

    ll N, M;
    scanf("%lld %lld", &N, &M);

    priority_queue<ll, vector<ll>, cmp> pq;

    for (int i = 0; i < N; i++) {
        ll input;
        scanf("%lld", &input);
        pq.push(input);
    }

    ll A, B;
    for (int i = 0; i < M; i++) {
        A = pq.top();
        pq.pop();
        B = pq.top();
        pq.pop();
        pq.push(A + B);
        pq.push(A + B);
    }

    ll result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    printf("%lld\n", result);

    return 0;
}