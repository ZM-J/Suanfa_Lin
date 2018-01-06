#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isScramble(string s1, string s2) {
        f.clear();
        return recScramble(s1, s2);
    }
private:
    bool recScramble(string s1, string s2) {
        pair<string, string> pair1 = make_pair(s1,s2), pair2 = make_pair(s2,s1);
        if (f.find(pair1) != f.end())
        {
            return f[pair1];
        }
        
        if (s1 == s2) 
        {
            f[pair1] = f[pair2] = true;
            return true;
        }
        int l = s1.length();
        map<char, int> freq1, freq2;
        for (int i = 0; i < l; i++)
        {
            freq1[s1[i]]++;
            freq2[s2[i]]++;
        }
        if (freq1 != freq2)
        {
            f[pair1] = f[pair2] = false;
            return false;
        }
        
        for (int i = 1; i < l; i++)
        {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
            {
                f[pair1] = f[pair2] = true;
                return true;
            }
            if (isScramble(s1.substr(0,i), s2.substr(l-i)) && isScramble(s1.substr(i), s2.substr(0,l-i)))
            {
                f[pair1] = f[pair2] = true;
                return true;
            }            
        }
        f[pair1] = f[pair2] = false;
        return false;
    }
    map<pair<string, string>, bool> f;
};
