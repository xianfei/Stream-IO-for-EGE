#include "ege_stream.h"
#include <graphics.h>

int main()
{
  initgraph(960,576);
  setcolor(CYAN);

  // 构造函数参数为 流缓冲区大小（设置为每行最大输出的字符数即可）、行距
  // 原型为：
  // BasicEgeStream(size_t buf_size = 100,int spacing = 25);

  EgeStream::BasicEgeStream egeout;
  egeout << std::string{ "Hello World" } << std::endl;
  egeout << "你好呀！我是衔飞\n";
  egeout << "output int:" << 123 << "    output double:" << 456.78 << std::endl;
  getch();
}