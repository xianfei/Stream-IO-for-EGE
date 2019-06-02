一个让ege支持类似std::cout的库

还在测试 如有问题请反馈~

截图：

![image](https://github.com/xianfei/Stream-IO-for-EGE/raw/master/example.png)

注意：

BUG：必须在结尾加上 std::endl 或 std::flush 才能正常输出

模拟cin必须在英文输入法下使用！不要使用中文输入法！



使用方式：

引入ege的头文件及该项目头文件#include "ege_stream.h"后，

创建EgeStream对象  EgeStream::BasicEgeStream egeout;

然后就可以像使用std::cout一样使用egeout啦~

（使用范例见ConsoleApplication1.cpp）




测试环境：VS2019 EGE19.01

by Xianfei SSE of BUPT 2019.5

更新日志：

v0.5  加入setXY(int x,int y)及setSpacing(int s)函数，用于设置输入输出流的位置。 注意：调用任何一个由BasicEgeStream创造的流的setXY或setSpacing函数，其他由BasicEgeStream创造的流也会改变

v0.4  加入了彩色输出(手动彩虹旗 doge)、可自行更改输入输出流的位置，更自由~

v0.3  加入了模拟cin

v0.2  重新更改构造函数，增加默认值。ege输出部分使用string容器对象。

TODO：待添加：自动换行 及 滚动翻页

~~TODO：待添加：对类似于cin的流提取支持~~
