<br></br><br></br><br></br><br></br><br></br>
<center style="font-size:24px">哈尔滨工业大学计算机科学与技术学院 </center>
<center style="font-size:36px">作业报告 </center>
<br></br>
<center style="font-size:24px">课程名称：数据结构与算法</center>
<center style="font-size:24px">课程类型： 辅修</center>
<center style="font-size:24px">作业名称： 第三章与第四章作业</center>
<br></br>
<center style="font-size:24px">学号：1153470104</center>
<center style="font-size:24px">姓名：沈孙乐</center>
<div STYLE="page-break-after: always;"></div>


##### 1. 设计求解多阶段图最短路径问题的动态规划算法。要求：
1. 证明多阶段图最短路径问题具有优化子结构性质。
如果从 $a$ 点到 $b$ 点的最短路径一定经过 $k$ ,则 $a$ 到 $b$ 最短路径的优化解必然包含了子问题 $k$ 到 $b$ 的优化解也就是最短距离。因此，多段图最短路径问题具有优化子结构性质。
2. 证明多阶段图最短路径问题具有子问题重叠性质。
要证明其子问题重叠性质，即证明最短路径问题的子问题的答案会被多次利用，比如其中$dis(k,b)$为k到b的最短路径，因为与k相连的点可能不止一个，所以该值在计算中会被多次的利用到。所以具有子问题重叠性质。
3. 写出该问题的向前递推式，即由后向前计算最优解值
$$dis(a,b)=\min_{k}\{(a,k) + dis(k,b)\}$$
4. 写出算法的伪代码，并分析算法的时间复杂度。
- *利用递归方法逐层找出各个点到汇点的距离,即要找出从源点$p_1$到汇点$p_n$的最短路径*
- 初始设定：暂存中间值=$infinite$；$p_i$的下一个顶点为$W$，距离数组存储所有点到汇点的最短距离。
- 遍历所有与该点$p_i$相邻的顶点$p_k${
    &emsp; 如果：距离数组内没有$p_k$到$p_n$的最短距离{
        &emsp; &emsp;递归调用函数计算$p_k$到$p_n$的最短距离
    &emsp;}否则{
        &emsp; &emsp;取出$p_k$到$p_n$的最短距离
    }
    &emsp; 如果: 暂存中间值 大于 $p_ip_k$ + $p_k$到$p_n$的最短距离{
    &emsp;&emsp; 则将$p_k$赋值给$W$
    &emsp;}
}
- 最终$W$为$p_i$的下一个顶点 暂存中间值为最短路径长度
- 将值赋给距离数组
以$p_1$为计算点进行计算得到结果，最短路径即为从源点出发，遍历出每个顶点的下一个顶点，组成的序列就是最短路径。
##### 2. 设有一个m*n 个方格，每个格子有一个权值，表示经过此方格所需走过的路程。从左上角的格子开始每次只能向右或者向下走一个方格，最后到达右下角的位置，路径上所有的权值累加起来就是路径长度，返回所有的路径中最小的路径长度和路径。设计求解该问题的动态规划算法。要求：
1. 证明该问题具有优化子结构性质。
设在所有路径中最小的这条路径中的格子按顺序排列为$a_1,a_2,...,a_k$最后一个格子为$a_k$，而去掉最后一个格子的路径$a_1,a_2,...,a_{k-1}$一定为从左上角到$a_{k-1}$的最短路径。因为如果不是最短路径，则证明的前提将不成立，所以该问题的优化解包含了子问题的优化解，所以它具有优化子结构的性质。
2. 证明该问题具有子问题重叠性质。
在解决问题的递归过程中，左上角到某一格子的最短距离会在后续的计算中被重复使用，所以需要在计算中将它们存储到某个数据结构当中为以后利用准备，因此问题一定具有子问题重叠性。
3. 写出该问题的递推式及其边界条件。
$dis(a_m, b_n) = \min\{(a_{m-1},b_n + dis(a_{m-1}, b_n)), (a_{m},b_{n-1} + dis(a_{m}, b_{n-1}))\}$
4. 写出算法的伪代码，并分析算法的时间复杂度。
- *递归地计算前两种到达可能性中距离最短的一种*
- 递归地计算$(m,n)$点到源点的最短距离{
    &emsp;如果距离数组中有$dis(a_{m-1}, b_n)${
        &emsp;&emsp;取出$dis(a_{m-1}, b_n)$
    &emsp;}否则{
        &emsp;&emsp;递归地计算$(a_{m-1}, b_n)$到源点的距离
    &emsp;}
    &emsp;比较$(a_{m-1},b_n + dis(a_{m-1}, b_n)), (a_{m},b_{n-1} + dis(a_{m}, b_{n-1}))$选出两者中的较小者。将值赋给距离数组，同时记录对应的格子。
}
- 最终得到各个格子到源点的最短距离，与每一个格子的上一格
- 只要从后往前，一一推导就可以知道最短的具体路径
##### 3. （选作）设计如下问题的动态规划算法。
1. 0/1 背包问题

2. 最长公共子序列问题