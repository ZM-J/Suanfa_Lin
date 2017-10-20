class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, backi = m, backj = -1;
        while (i < m)
        {
        	if (j >= n)
        	{
        		i = backi, j = backj;
        		backi++;
        	}
        	else if (s[i] == p[j] || p[j] == '?')
        	{
        		i++, j++;
        	}
        	else if (p[j] == '*')
        	{
        		j++;
        		backi = i, backj = j;
        	}
        	else
        	{
        		i = backi, j = backj;
        		backi++;
        	}
        }
		while (j < n)
		{
			if (p[j] != '*') return false;
			j++;
		}
		return true;
    }
};
