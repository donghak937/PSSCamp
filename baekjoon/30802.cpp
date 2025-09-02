#include <iostream>

using namespace std;

int main() {
    int n;
    int s, m, l, xl, xxl, xxxl;
    int t, p;

    int t_total = 0;
    int p_group;
    int p_indi;

    cin >> n >> s >> m >> l >> xl >> xxl >> xxxl >> t >> p;

    t_total += s / t;
    if (s % t != 0 && s != 0) t_total++;

    t_total += m / t;
    if (m % t != 0 && m != 0) t_total++;

    t_total += l / t;
    if (l % t != 0 && l != 0) t_total++;

    t_total += xl / t;
    if (xl % t != 0 && xl != 0) t_total++;

    t_total += xxl / t;
    if (xxl % t != 0 && xxl != 0) t_total++;

    t_total += xxxl / t;
    if (xxxl % t != 0 && xxxl != 0) t_total++;

    p_group = n / p;
    p_indi = n % p;

    cout << t_total << endl;
    cout << p_group << " " << p_indi << endl;
}