#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        bool **f = new bool* [sl+1];
        for (int i = 0; i <= sl; i++)
        {
            f[i] = new bool [pl+1];
            memset(f[i],false,sizeof(bool)*(pl+1));
        }
        f[0][0] = true;
        for (int i = 0; i <= sl; i++)
        {
            for (int j = 1; j <= pl; j++)
            {
                if (p[j-1] != '*')
                {
                    if (i >= 1) f[i][j] = f[i-1][j-1] && isAccept(s[i-1], p[j-1]);
                }
                else
                {
                    if (j >= 2)
                    {
                        bool ack = true;
                        int k = 0;
                        do
                        {
                            f[i][j] = f[i-k][j-2] && ack;
                            k++;
                            if (k > i) break;
                            ack &= isAccept(s[i-k], p[j-2]);
                        }
                        while (!f[i][j] && ack);
                    }
                }
            }
        }
        bool ret = f[sl][pl];
        for (int i = 0; i <= sl; i++)
        {
            delete [] f[i];
        }
        delete [] f;
        return ret;
    }
private:
    bool isAccept(char x, char y) {
        return x == y || y == '.';
    }
};
