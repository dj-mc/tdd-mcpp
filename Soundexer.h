#ifndef Soundexer_h
#define Soundexer_h
#include <iostream>
#include <string>

class Soundexer {
public:
  std::string encode(const std::string &word) const {
    auto encoded = word.substr(0, 1);
    std::cout << encoded;
    if (word.length() > 1) {
      encoded += "1";
    }
    return pad_zeroes(encoded);
  }

private:
  const unsigned char min_word_length = 4;
  std::string pad_zeroes(const std::string &word) const {
    auto zeroes_needed = min_word_length - word.length();
    return word + std::string(zeroes_needed, '0');
  }
};

#endif
