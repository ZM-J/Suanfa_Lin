###  72. Edit Distance
## 题目网址
https://leetcode.com/problems/edit-distance/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
求字符串$word1$到字符串$word2$的编辑距离。

## 我的做法

求两个字符串的编辑距离是一个经典问题。用动态规划来解决。

设动态规划的数组为$f$，那么其元素$f[i][j]$的含义为前缀子串$word1[1 \ldots i]$到前缀子串$word2[1 \ldots j]$的编辑距离。

由于三个操作（插入、删除、替换）都只是针对一个字符来进行的，所以我们对于$f[i][j]$，仅需考虑与其有关的前一步状态$f[i-1][j-1]$、$f[i-1][j]$与$f[i][j-1]$即可。

* 对于插入：亦即对目标串$word2$的前缀子串后加入一个字符，对应之前状态$word1[1 \ldots i]$及$word2[1 \ldots j-1]$；
* 对于删除：亦即对源串$word1$的前缀子串后加入一个字符，对应之前状态$word1[1 \ldots i-1]$及$word2[1 \ldots j]$；
* 对于替换：亦即对源串$word1$和目标串的前缀子串后分别加入一个字符，对应之前状态$word1[1 \ldots i-1]$及$word2[1 \ldots j-1]$。

特别地，如果$word1[i-1]$与$word2[j-1]$相等，那么直接进行不增加代价的替换转移。

所以我们得到如下状态转移方程：对所有的$1 \leq i \leq |word1|$以及$1 \leq j \leq |word2|$，有

\begin{equation*}
f[i][j]=
\begin{cases}
\min\{f[i-1][j-1],f[i-1][j],f[i][j-1]\}+1, &word1[i-1] \neq word2[j-1]\\
f[i-1][j-1]{}, &word1[i-1]=word2[j-1]
\end{cases}
\end{equation*}

边界条件：

\begin{equation*}
f[i][j] = \max\{i,j\}, i = 0 \lor j = 0
\end{equation*}

计算完动态规划数组$f$，那么$f[|word1|][|word2|]$即为所求答案。

## 复杂度分析

该算法时间复杂度为$O(|word1||word2|)$，空间复杂度为$O(|word1||word2|)$。
