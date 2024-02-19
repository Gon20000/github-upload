#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input{};
    int res{};

    while (getline(cin, input))
    {
        if (input.empty())
            break;
        int n1{}, n2{};
        for (char chr : input)
        {
            if (chr >= '0' && chr <= '9')
            {
                int num{(int)chr - '0'};
                if (n1 == 0)
                    n1 = num;
                n2 = num;
            }
        }

        res += n1 * 10 + n2;
    }

    cout << res << '\n';

    return 0;
}