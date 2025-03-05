#include <iostream>
#include <deque>

using namespace std;
deque <int> dq;

int main() {
    const int NMAX = 100;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(2);
    int elem = 2, current = 3;
    while(current < NMAX) {
        elem = 3 - elem;
        for(int i = 0; i < dq[2] && current < NMAX; i++) {
            dq.push_back(elem);
            current++;
        }
        cout << dq.front() << " ";
        dq.pop_front();
    }
    for (auto i : dq) {
        cout << i << " ";
    }
    return 0;
}