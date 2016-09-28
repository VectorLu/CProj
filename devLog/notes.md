### 开发环境
1. 文本编辑器：atom

### 遇到的困惑和解决方案
#### Q1：
首先准备完成main函数的C文件，但是，
1. 究竟需要包含哪些头文件呢？
2. 以前接触到的C语言程序都是比较小的，单个文件就能完成任务的，虽然这次的程序不算大，但是我准备采用多个文件来构成这个项目，究竟是将头文件分散在这些项目中，还是就统一放在包含 ```main()``` 函数的menuMain.c文件中呢？
3. 不同的方法会有不同么？哪一种比较好呢？

#### S1:
1. //TODO 对C语言不够熟悉，暂时还不知道需要包含哪些头文件，先包含常用的 ```stdio.h``` 和 ```stdlib.h```
2. //TODO
3. //TODO


#### Q2:
// TODO showGame() 及界面设计
```showGame()``` 函数的参数类型的选择，要尽量让其能够满足在任何选项下都能打印出游戏界面，而且有一定的可扩展性。如何实现这个至关重要的函数  

#### S2:
用一个整型数组的地址作为参数，这个地址是一个整形数组的首地址，用这个整型数组来存储关于游戏的纪录，如果需要每隔一段时间换地图，那么```gameRecord```还可以存下当前的地图等状态

#### Q3:
文件如何保存到一个容易找到的相对路径下？以便保存玩家暂停退出的进度和不同玩家的记录。

#### S3:
1. 试验
```
#include <stdio.h>
int main()
{
    FILE *tCurrentPath1;
    FILE *tCurrentPath2;
    FILE *tPrevPath;
    FILE *tChildPath;

    //测试当前路径1
    tCurrentPath1 = fopen("testCurrentPath1.log", "a");
    fprintf(tCurrentPath1, "Current path test 1 succeeded!\n");

    //测试当前路径2
    tCurrentPath2 = fopen("./testCurrentPath2.log", "a");
    fprintf(tCurrentPath2, "C 2 succeeded!\n");

    //测试去上一层路径
    tPrevPath = fopen("../testPrevPath.log", "w+");
    fprintf(tPrevPath, "Previous path test succeeded!\n");

    //测试去下一层路径
    tChildPath = fopen("./child/testChildPath.log", "w+");
    fprintf(tChildPath, "Child path test succeeded!\n");

    return 0;
}
```

2. 发现有个问题：不能用```fopen()```创建文件夹，虽然它可以创建新文件，但是不能创建文件夹。实际上C标准库中没有创建文件夹的函数。编译成功但是，执行程序后会报错```segmentation fault : 11```，将测试去下一层的代码注释调就不会报错了。上网查找了一下，这个错误主要原因是非法操作内存，比如
    1. 以上从一个不存在的文件夹创建／打开文件；
    2. 数组过大造成堆栈甚至内存（静态变量）溢出；
    3. 对
