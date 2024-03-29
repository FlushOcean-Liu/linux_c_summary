# 互斥锁（mutex）

互斥锁主要用于实现内核中的互斥访问功能。内核互斥锁是在原子API之上实现的，但这对于内核用户是不可见的。  

对它的访问必须遵循一些规则：  
* 同一时间只能有一个任务持有互斥锁，而且只有这个任务可以对互斥锁进行解锁;
* 互斥锁不能进行递归锁定或解锁;
* 一个互斥锁对象必须通过其API初始化，而不能使用memset或复制初始化;
* 一个任务在持有互斥锁的时候是不能结束的;
* 互斥锁所使用的内存区域是不能被释放的;
* 使用中的互斥锁是不能被重新初始化的;
* 互斥锁不能用于中断上下文。

但是互斥锁比当前的内核信号量选项更快，并且更加紧凑，因此如果它们满足您的需求，那么它们将是您明智的选择。
