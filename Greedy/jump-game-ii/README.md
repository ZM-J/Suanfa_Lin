###  45. Jump Game II

## 题目网址
https://leetcode.com/problems/jump-game-ii/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
给一个长度为$n$的数组$a$，其中$a[i]$表示从第$i$位可以至多向前跳$a[i]$位，求至少用多少步才能跳到最后一位。
## 我的做法
用贪心法。

容易由动态规划的方法得到一个时间复杂度为$O(n^2)$的状态转移方程：

$f[i]=\min\limits_{0 \leq j < i \leq j+a[j]}{f[j]+1}$

这个动态规划的状态转移方程可以从前往后计算，而且具有单调递增，增量为$0$或$1$的特性。

所以我们可以让一个花费变量$cost$让其初值为$0$且每次递增$1$，然后去计算$f[i]=cost$的时候，$i$的取值区间即可。设当前$cost$的时候$i$的取值范围为$[l,r]$，$cost+1$的时候$i$的取值范围为$[nxtl,nxtr]$。一个的事实是$nxtl \geq r+1$与$nxtr \geq r+1$。所以我们也不难写出$nxtl$和$nxtr$的表达式来：

$nxtl=\min\{\min\limits_{l\leq i\leq r}{(i+a[i])},r+1\}$

$nxtr=\max\{\max\limits_{l\leq i\leq r}{(i+a[i])},r+1\}$

以及$cost$、$l$和$r$的初值都是0。这样计算一轮之后，将$l$和$r$的值分别赋为$nxtl$和$nxtr$的值即可。当$r \geq n-1$的时候，循环结束，此时的$cost$值即为答案。


## 复杂度统计

时间复杂度为$O(n)$，由于我们的$cost$递增的过程中，$i$相当于至多扫描遍了整个数组，且每次循环内都是常数级别的操作。

空间复杂度为$O(1)$，由于只用到几个简单的统计变量。
