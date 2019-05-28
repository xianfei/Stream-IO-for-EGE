#pragma once
#include <iostream>
#include <string>
#include <sstream>

//  Version 0.2 By Xianfei (王衔飞) SSE of BUPT  2019.5
// 
//  参考资料： 

//  https://zh.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
//  C++ 之定制输入输出流 http://kaiyuan.me/2017/06/22/custom-streambuf/

namespace EgeStream {

// a simple stream buf for ege output stream
class EgeStreamBuf : public std::streambuf {
public:
    EgeStreamBuf(size_t buf_size, int spacing);
    ~EgeStreamBuf();

    int underflow();
    int overflow(int c);
    int sync();

private:
    const size_t buf_size_;
    const int spacing_;
    char* pbuf_;
    char* gbuf_;
};


class BasicEgeStream : public std::iostream {
public:
    BasicEgeStream(size_t buf_size = 100,int spacing = 25);
    ~BasicEgeStream();

private:
    const size_t buf_size_;
    const int spacing_;
};

}  
