###  62. Unique Paths

## 题目网址
https://leetcode.com/problems/maximum-subarray/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
无

## 我的做法
没什么好说的，答案即为$\binom{m+n-2}{m-1}$。由于题目保证了$n$和$m$至多为100，计算的时候就用$O(mn)$的动态规划算法就好。

另外这道题的最大答案是在`int`范围内，亦可设计一个$O(m+n)$的算法，即直接从$m$循环到$m+n-2$计算答案即可。但是我们指出，题目的保证是极其荒谬的，由于这个答案最大是$\binom{198}{99}=22750883079422934966181954039568885395604168260154104734000$（可以借助[WolframAlpha](http://www.wolframalpha.com)或者Mathematica来算出），这已经远大于`int`的范围，标准程序会算出一个负数来。

## 复杂度分析
算法1的时间复杂度为$O(mn)$，空间复杂度也为$O(mn)$。

算法2的时间复杂度为$O(m+n)$，空间复杂度为$O(1)$。
