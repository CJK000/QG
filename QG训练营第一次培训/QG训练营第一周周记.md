# QG训练营数据挖掘组第一周周记：2019年3月26日

## 生活随记

### 3/22周五

训练营第一次培训，师兄给我们梳理了单链表和双链表的相关知识，简单介绍了链表的基本操作，代码实现就是训练营的课后作业了。这次延期完成作业让我对打码有了新的认识。

周五晚上拿到作业，看上去蛮简单的，就还没开始动手，而是安排了周末另外的两三个小时来做，但是，翻车了。

### 3/23周六

周六早上坐车回家，这是我安排来做作业的时间，但是这一整块的时间我一行代码也没有写出来，因为以前自己写做文件编程所有的文件都是放在同一个文件夹的，而这个作业的文件是放在多个文件夹的，所有这坨时间又是百度又是问人才搞清楚是怎么回事。

#### 相对路径

\1. 相对路径 ，用正斜杠’/‘

​    1.1向上一级目录指向

​    ./    表示当前路径，相当于E:\test\file

​    ../  表示当前路径的上一级路径，相当于E:\test

​    ../../  表示当前路径上上一级路径，相当于E:

​    更多指向上级路径的表示以此类推。

​    1.2 向下一级目录指向

​    ./data  表示当前路径下一级路径，相当于E:\test\file\data

​    ./data/xxx   表示当前路径的下下一级路径，相当于 E:\test\file\data\xxx

​    更多向下指向的路径的表示以此类推。

参考资料：

<https://www.jianshu.com/p/191d1e21f7ed>

#### 工程文件

第一次用别人已经建立好的文件往里面填代码，刚拿到的时候竟然懵了，怎样把在不同文件夹里的源代码文件同时编译然后链接到一起。想了好久之后，才醒过来。

##### turbo C

上学期强哥带我们的时候，要求用tuebo C作为编译器，其中多文件编程时需要建议一个后缀为.prj的工程文件，然后把需要用的源代码.c文件名写进去，再进行编译和链接。

##### Linux

我还没用过Linux，但是在看视频教程里面见过，在Linux多文件编译时不用建立工程文件，但是在输入编译指令后面需要同时输入需要编译的所有文件名。

##### Dec-C++

直接建立项目 ，然后把需要用到的文件都添加到项目里面去就行了，再直接编译就行了。

 

### 3/24周日

在周六搞清楚那些问题之后就开始打码了，然后又遇到了新的问题（啊~哀嚎一声）。

#### 链表

##### 头结点

上学期强哥教的链表每个结点都是存放值的，但按着那样写着写着才发现不对劲，原来是作业写的链表是又不存放值的头结点的。

##### 函数参数

有些函数是传入二级指针的，好吧，我到现在都还没弄懂是为什么。

##### 非法输入

这是一个巨大的问题，经过苦思冥想和改来改去，终于想出来了，估计现在的代码没啥问题了

```c
int GetNumber(int *n){
	char a[4];
	while(1){
		scanf("%3s",a);
		if(strcmp(a,"-1")==0){
			printf("pragram has exited.\n");
			exit (0);
		}
		if(strlen(a)==1&&'0'<=a[0]&&a[0]<='5'){	//根据需要做出适当修改
			*n=a[0]-'0';
			putchar(10);
			return *n;
		}
		else{
			while(getchar()!='\n');				//吃掉缓冲区剩下的所有字符
			printf("enter error,please enter again:\n");
			return GetNumber(n);
		}
	}
}
```

## 总结

拿到作业应该第一时间完成，不要高估自己以为很快就能写完，只有在写的时候才会时不时地冒出一大堆奇奇怪怪的问题。

## 下周规划

在课余开始学习python。