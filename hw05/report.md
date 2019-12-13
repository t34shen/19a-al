<br></br><br></br><br></br><br></br><br></br>
<center style="font-size:24px">哈尔滨工业大学计算机科学与技术学院 </center>
<center style="font-size:36px">作业报告 </center>
<br></br>
<center style="font-size:24px">课程名称：数据结构与算法</center>
<center style="font-size:24px">课程类型： 辅修</center>
<center style="font-size:24px">作业名称： 第五章与第六章作业</center>
<br></br>
<center style="font-size:24px">学号：1153470104</center>
<center style="font-size:24px">姓名：沈孙乐</center>
<div STYLE="page-break-after: always;"></div>


##### 1.给定一个0-1 背包问题，背包容量为15，(待选物品信息如下表) 所示请利用分支界限法求解最优的选择方案和对应的最大价值。要求写明结点扩展和剪枝的过程，并标明每个结点（格局）的价值的上界和下界。
物品编号 | 价值$V$ | 重量$W$
:-:|:-:|:-:
1 |18| 9|
2 |24 |8|
3 |20 |2|
4 |30| 10|
其中物品的价值下界为30，价值上界为59
首先将单位价值排序，重新编过的物品顺序为：
物品编号 | 价值$V$ | 重量$W$
:-:|:-:|:-:
3 |20 |2|
4 |30| 10|
2 |24 |8|
1 |18| 9|
下面就按照这个顺序对背包进行分支界限法求解。
<center> w=0 v=0  UB=150 </center>
<center>/&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\</center>
<center> w=2 v=20 UB=59 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; X 剪枝 w=0 v=0 UB=45</center>
<center>/&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>w=12 v=50 UB=59 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; w=2 v=20 UB=59 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;/&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>w=12 v=50 UB=56 &emsp;&emsp;&emsp;w=10 v=44 UB=54 &emsp;&emsp;X 剪枝 w=2 v=20 UB=46 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; </center>
<center>&emsp;w=12 v=50 UB=50 &emsp;&emsp;X 剪枝 w=10 v=44 UB=44 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>

##### 2. 请利用回溯法求解上面的0-1 背包问题。要求写明结点扩展、回溯和剪枝的过程，并标明每个结点（格局）的价值的上界和下界。
首先将单位价值排序，重新编过的物品顺序为：
物品编号 | 价值$V$ | 重量$W$
:-:|:-:|:-:
3 |20 |2|
4 |30| 10|
2 |24 |8|
1 |18| 9|
回溯法和分支界限法的区别在于是否在下一步选择子树时使用一个启发式的测度函数来区别。由于非常凑巧，因为物品编号的问题这两题的回溯过程是一样的，下面就按照这个顺序对背包进行回溯法求解。
<center> w=0 v=0  UB=150 </center>
<center>/&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\</center>
<center> w=2 v=20 UB=59 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; X 剪枝 w=0 v=0 UB=45</center>
<center>/&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>w=12 v=50 UB=59 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; w=2 v=20 UB=59 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;/&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>w=12 v=50 UB=56 &emsp;&emsp;&emsp;w=10 v=44 UB=54 &emsp;&emsp;X 剪枝 w=2 v=20 UB=46 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>
<center>\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; </center>
<center>&emsp;w=12 v=50 UB=50 &emsp;&emsp;X 剪枝 w=10 v=44 UB=44 &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;</center>

##### 3. 用优先级队列实现一个经典A*搜索算法，来找到一个8-puzzle 问题的解（或者在有限时间内发现它的无解性），写出算法的伪代码。
