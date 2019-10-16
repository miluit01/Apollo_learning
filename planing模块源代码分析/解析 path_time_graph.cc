
百度Apollo中使用Frenet坐标系下的s-t图来帮助分析障碍物的状态（静态、动态）对于自车轨迹规划的影响。典型的如Lattice Planner中，在s-t图中绘制出障碍物占据的s-t区间范围，便可以在范围外采样无碰撞的轨迹点（end condition)，然后拟合和评估轨迹，选取最优的输出。

在s-t图中，静态障碍物是矩形块表示，因为直观的，随着时间推移，其s轴位置始终不变；动态障碍物是四边形表示（如果是匀速运动，则是平行四边形），因为随着时间推移，障碍物的s轴位置不断朝着s轴正方向移动，且斜率就是移动的速度。

当感知模块输出检测到的障碍物、预测模块输出预测的n秒内的障碍物可能轨迹后，应该如何创建s-t图呢？path_time_graph类就是解决这个问题的。文件路径：apollo\modules\planning\lattice\behavior\http://path_time_graph.cc。原理比较简单，就直接贴关键的代码和注释了。


