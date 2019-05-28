一个让ege支持类似std::cout的库

还在测试 目前仅支持输出至绘图区

使用方式：

引入ege的头文件及该项目头文件#include "ege_stream.h"后，
创建EgeStream对象  EgeStream::BasicEgeStream egeout;
然后就可以像使用std::cout一样使用egeout啦~

  // 构造函数参数为 流缓冲区大小（设置为每行最大输出的字符数即可）、行距
  // 原型为：
  // BasicEgeStream(size_t buf_size = 100,int spacing = 25);

测试环境：VS2019 EGE19.01

by Xianfei SSE of BUPT 2019.5

更新日志：

v0.2  重新更改构造函数，增加默认值。ege输出部分使用string容器对象。

TODO：待添加：自动换行 及 滚动翻页

TODO：待添加：对类似于cin的流提取支持
