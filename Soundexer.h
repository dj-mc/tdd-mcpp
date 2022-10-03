#ifndef Soundexer_h
#define Soundexer_h
#include <cstddef>
#include <iostream>
#include <map>
#include <unordered_map>

class Soundexer {
public:
  static const std::size_t min_word_length{4};
  std::string encode(const std::string &word) const {
    return pad_zeroes(zero_index_of(word) + encoded_digits(word));
  }

private:
  std::string zero_index_of(const std::string &word) const {
    return word.substr(0, 1);
  }

  std::string encoded_digit(char letter) const {
    const std::unordered_map<char, std::string> encodings{
        {'b', "1"},
        {'c', "2"},
        {'d', "3"},
    };
    return encodings.find(letter)->second;
  }

  std::string encoded_digits(const std::string &word) const {
    if (word.length() > 1) {
      return encoded_digit(word[1]);
    } else {
      return std::string();
    }
  }

  std::string pad_zeroes(const std::string &word) const {
    auto zeroes_needed = min_word_length - word.length();
    return word + std::string(zeroes_needed, '0');
  }
};

#endif
