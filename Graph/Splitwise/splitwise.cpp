#include <iostream>
#include <set>
using namespace std;
int main()
{
    int no_of_transactions, friends;
    cin >> no_of_transactions >> friends;
    int x, y, amount;

    //make a 1d array to store the net amount that each person will have to take
    int net[100000] = { 0 };
    while (no_of_transactions--) {
        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;
    }
    //init a list and sort it
    multiset<int> m;
    for (int i = 0; i < friends; i++) {
        if (net[i] != 0) {
            m.insert(net[i]);
        }
    }
    // Pop out two person from left and right and try to settle them
    //each iteration is taken a one transaction
    int cnt = 0;
    while (!m.empty()) {
        auto low = m.begin();
        auto high = prev(m.end());

        int debit = *low;
        int credit = *high;

        //erase
        m.erase(low);
        m.erase(high);

        //settlement
        int settlement_amount = min(-debit, credit);
        cnt++;
        //transfer settlement_amount from donor to receptor
        //one of them will become 0
        debit
            += settlement_amount;
        credit -= settlement_amount;

        if (debit != 0) {
            m.insert(debit);
            if (credit != 0)
                m.insert(credit);
        }
    }
    cout << cnt;
}