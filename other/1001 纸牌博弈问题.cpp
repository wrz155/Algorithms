/*
有一排正数，玩家A和玩家B都可以看到。
每位玩家在拿走数字的时候，都只能从最左和最右的数中选择一个。
玩家A先拿，玩家B再拿，两人交替拿走所有的数字，
两人都力争自己拿到的数的总和比对方多。请返回最后获胜者的分数。

例如：
5,2,3,4
玩家A先拿，当前他只能拿走5或者4。
如果玩家A拿走5，那么剩下2，3，4。轮到玩家B，此时玩家B可以选择2或4中的一个，…
如果玩家A拿走4，那么剩下5，2，3。轮到玩家B，此时玩家B可以选择5或3中的一个，…

*/