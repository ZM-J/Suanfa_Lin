###  8.12

## markdown在线编辑&查看
https://www.zybuluo.com/mdeditor
## 题目
The **$k$-spanning tree** problem is the following.

> *Input:* An undirected graph $G=(V,E)$
> *Output:* A spanning tree of $G$ in which each node has degree $\leq k$, if such a tree exists.

Show that for any $k \geq 2$:

(a) **$k$-spanning tree** is a search problem.

(b) **$k$-spanning tree** is **NP**-complete. (*Hint:* Start with $k=2$ and consider the relation between this problem and **Rudrata path**.)

## 我的做法

翻译过来，**$k$生成树**是指给定一个无向图，找到一个生成树，其中每个节点的度数不超过$k$的问题。

(a) 验证任意给定的正解$S$是否是**$k$生成树**的过程，只需要用图搜索算法对$S$进行搜索。通过搜索$S$中所有顶点，我们可以验证$S$不包含环，且每个点的度数不超过$k$，那么$S$就是原图$G$的**$k$生成树**。同时，图的搜索算法可以在多项式时间内解决。因此，**$k$生成树**问题是一个搜索问题，同时也证明它是一个**NP**问题。

(b) 欲证明**$k$生成树**是**NP**完全问题，只需要找到一个**NP**完全问题并将其规约到**$k$生成树**问题。这里我们选择用**Rudrata路径**问题来规约。当$k=2$时，所要寻找的生成树其实就是一条经过所有顶点的路径，只不过相比**Rudrata路径**而言，这个生成树是没有回路的。那么**Rudrata路径**问题就可以归约为寻找一个**$2$生成树**，在找到这个**$2$生成树**之后，加上一条边便使生成树成为一个环，这就是要寻找的**Rudrata路径**。因此，**$k$生成树**问题为**NP**完全问题。
