#include "ege_stream.h"
#include <graphics.h>

int main()
{
  initgraph(960,576);
  setcolor(CYAN);

  // 注意：BUG：必须在结尾加上 std::endl 或 \n 才能正常输出

  // 构造函数参数为 流缓冲区大小（设置为每行最大输出的字符数即可）、行距
  // 原型为：
  // BasicEgeStream(size_t buf_size = 100,int spacing = 25);

  EgeStream::BasicEgeStream egeout;
  EgeStream::BasicEgeStream egein;
  egeout << std::string{ "Hello World" } << std::endl;
  egeout << "你好呀！我是衔飞\n";
  egeout << "output int:" << 123 << "    output double:" << 456.78 << std::endl;
  std::string s1;
  egein >> s1;
  egeout << "您输入的是：" << s1 << std::endl;
  getch();
}