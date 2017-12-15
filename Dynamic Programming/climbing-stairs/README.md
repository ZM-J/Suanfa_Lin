###  70. Climbing Stairs
## 题目网址
https://leetcode.com/problems/climbing-stairs/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
无
## 我的做法

经典到不能再经典的问题，没什么好说的，依题意递推式即为$f[i]=f[i-1]+f[i-2] \forall n \geq 3$，初值$f[1]=1,f[2]=2$。这就是一个Fibonacci数列，由于其为指数增长，故$n$稍微大一点结果就会溢出，也不需要利用矩阵快速幂等方法来计算结果，直接用最简单的循环计算即可。

## 复杂度分析

时间复杂度为$O(n)$，空间复杂度为$O(1)$。
