###  64. Minimum Path Sum

## 题目网址
https://leetcode.com/problems/minimum-path-sum/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
无

## 我的做法
没什么好说的，用最简单的动态规划算法即可。计算的时候直接用$O(mn)$的动态规划算法就好。动态规划方程为

\begin{equation*}
f[i][j]=grid[i][j]+
\begin{cases}
0,& i=0 \land j=0\\
f[i][j-1],& i=0 \land j>0\\
f[i-1][j],& i>0 \land j=0\\
min\{f[i][j-1],f[i-1][j]\}, & i>0 \land j>0
\end{cases}
\end{equation*}

## 复杂度分析
算法的时间复杂度为$O(mn)$，空间复杂度也为$O(mn)$。
