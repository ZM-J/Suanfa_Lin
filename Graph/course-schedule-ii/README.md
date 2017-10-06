###  210. Course Schedule II
## 题目网址
https://leetcode.com/problems/course-schedule-ii/description/
## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目适当转述
给定一个课表，其中欲学习某些课程可能需要先学习一个先行课程。若能将这些课程学完，则给出一个可能的学习顺序。若否，则返回空。
## 我的做法

这就是一个经典的拓扑排序问题，直接应用经典算法来解决此问题即可。直接先统计一遍每个点的入度，然后每次找一个入度为零的点，将其从图中删掉就可以了。在删掉的时候也将这个点计入答案序列即可。

注意一个坑就好：

> If it is impossible to finish all courses, return an empty array.

## 复杂度分析

由于我们一开始要将每个点的入度都要统计一遍，用队列实现一个。

且在删点的过程中，我们将每条边都要删除一次。

所以最后的时间复杂度就是$O(|V|+|E|)$。

由于需保存每个点的入度信息，以及每个点的出边的信息，故空间复杂度也是$O(|V|+|E|)$。
