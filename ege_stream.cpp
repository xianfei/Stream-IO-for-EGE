

#include "ege_stream.h"
#include <graphics.h>

namespace EgeStream {
static int textY = 5;
EgeStreamBuf::EgeStreamBuf(size_t buf_size, int spacing = 25) :
    buf_size_(buf_size),spacing_(spacing){
    pbuf_ = new char[buf_size_]; 
    gbuf_ = new char[buf_size_];

    setp(pbuf_, pbuf_ + buf_size_); // set the pointers for output buf
    setg(gbuf_, gbuf_, gbuf_);      // set the pointers for input buf
}

EgeStreamBuf::~EgeStreamBuf() {
    if(pbuf_ != nullptr) {
        delete pbuf_;
        pbuf_ = nullptr;
    }

    if(gbuf_ != nullptr) {
        delete gbuf_;
        gbuf_ = nullptr;
    }
}

// flush the data to the ege
int EgeStreamBuf::sync() {
  std::string str;
  for (int i = 0; i < pptr() - pbase(); i++) str.push_back (*(pbase() + i));
  std::istringstream f(str);
  std::string line;
  while (std::getline(f, line)) {
    outtextxy(5, textY, line.c_str());
    textY += spacing_;
  }
    setp(pbase(), pbase() + buf_size_);
    pbump(0);  // reset the pptr
    return 0;
}

int EgeStreamBuf::overflow(int c) {
    if (-1 == sync()) {
        return traits_type::eof();
    }
    else {
        if (!traits_type::eq_int_type(c, traits_type::eof())) {
            sputc(traits_type::to_char_type(c));
        }

        // return eq_int_type(c, eof()) ? eof():c;
        return traits_type::not_eof(c);
    }
}

int EgeStreamBuf::underflow() {
    // 有待加入流提取相关部分
  int ret = buf_size_;
  std::string str;
  int textX = 5;
  do {
    char a = getch();
    if (a == 8) {
      color_t c = getfillcolor();
      setfillcolor(getbkcolor());
      bar(textX - 10, textY + spacing_, textX, textY);
      textX -= 10;
      str.erase(str.end() - 1);
      setfillcolor(c);
      continue;
    }
    str.push_back(a);
    if (a == 13)break;
    outtextxy(textX, textY, std::string{a}.c_str());
    textX += 10;
    
  } while (1);
  textY += spacing_;
      strcpy_s(eback(), buf_size_,str.c_str());
    if (str.size()) {
        setg(eback(), eback(), eback() + ret);
        return traits_type::to_int_type(*gptr());
    } else {
        return traits_type::eof();
    }
    return 1;
}

BasicEgeStream::BasicEgeStream(size_t buf_size, int spacing):
    std::iostream(new EgeStreamBuf(buf_size)), buf_size_(buf_size),spacing_(spacing) {
}

BasicEgeStream::~BasicEgeStream() {
    delete rdbuf();
}

}  // EgeStream

