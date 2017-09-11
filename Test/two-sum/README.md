###  1. Two Sum
## 题目网址
https://leetcode.com/problems/two-sum/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
无
## 我的做法

维护一个`unordered_map`，键值对的含义为$<元素值, 元素标号>$。

遍历该数组，便利到第$i$个元素的时候先查找$target-nums[i]$是否在其内。

* 若是，则输出结果（为[$i$, 查到的值对应的元素标号]）。
* 若否，则将键值对$<nums[i], i>$插入该`unordered_map`中。

## 复杂度分析

由于该算法用到了`unordered_map`，查找和插入均为$O(1)$的时间复杂度，故该算法的时间复杂度和空间复杂度为$O(n)$。
