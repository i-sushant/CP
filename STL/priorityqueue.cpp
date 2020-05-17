#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> p; //min heap
    for (int i = 0; i <= 5; i++) {
        int n;
        cin >> n;
        pq.push(n);
    }

    while (!pq.empty()) {
        cout << pq.top() << ", ";
        pq.pop();
    }
}