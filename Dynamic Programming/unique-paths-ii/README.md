###  63. Unique Paths II

## 题目网址
https://leetcode.com/problems/unique-paths-ii/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
无

## 我的做法
没什么好说的，用最简单的动态规划算法即可。计算的时候直接用$O(mn)$的动态规划算法就好。动态规划方程为

\begin{equation*}
f[i][j]=
\begin{cases}
0,& i=0 \lor j=0\\
1,& (i,j)=(1,1)\\
f[i][j-1]+f[i-1][j],& a[i-1][j-1]=0\\
0, &a[i-1][j-1]=1
\end{cases}
\end{equation*}

另外，像之前那道题一样，我们指出这道题的最大答案会超过`int`范围，亦即题目的保证是极其荒谬的，由于这个答案最大是$\binom{198}{99}=22750883079422934966181954039568885395604168260154104734000$（可以借助[WolframAlpha](http://www.wolframalpha.com)或者Mathematica来算出），这已经远大于`int`的范围，标准程序会算出一个负数来。

## 复杂度分析
算法的时间复杂度为$O(mn)$，空间复杂度也为$O(mn)$。
