#include "ege_stream.h"
#include <graphics.h>

int main()
{
  initgraph(900, 580);  // 初始化ege画板
  rectangle(80, 80, 820, 500);   // 画一个小框框

  // 创建ege输出流：
  //     构造函数参数为 X坐标  Y坐标  行距  流缓冲区大小（设置为每行最大输出的字符数即可
  //     原型为：
  //     BasicEgeStream(int x=5,int y=5, int spacing = 25,size_t buf_size = 100);
  EgeStream::BasicEgeStream egeout(100, 100);
  EgeStream::BasicEgeStream egein(100, 100); // v0.4版本加入自定义输入输出流的输出位置，更自由~

  // 注意：(maybe is BUG) 必须在结尾加上 std::endl 或 std::flush 才能正常输出
  egeout << std::string{ "Hello World" } << std::endl;

  // v0.5版本加入setXY(int x,int y)及setSpacing(int s)函数
  // 用于设置输入输出流的位置 注意：调用任何一个流的setXY或setSpacing函数，其他输入输出流也会改变
  egeout.setXY(150, 150);

  // v0.4版本加入了彩色输出  手动彩虹旗 doge
  egeout << egeout.pink << "I'm pink." << std::endl;
  egeout << egeout.orange << "I'm orange." << std::endl;
  egeout << egeout.yellow << "I'm yellow." << std::endl;
  egeout << egeout.green << "I'm green." << std::endl;
  egeout << egeout.blue << "I'm bule." << std::endl;
  egeout << egeout.purple << "I'm purple." << std::endl;

  egeout << "你好呀！我是衔飞\n";
  egeout << "output int:" << 123 << "    output double:" << 456.78 << std::endl;

  // v0.3版本加入了输入流
  std::string s1;
  int a;
  egein >> s1 >> a;
  egeout << "您输入的是：" << s1 << "   int:" << a << std::endl;
  getch();
}