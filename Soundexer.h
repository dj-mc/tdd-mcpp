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
    return pad_zeroes(head(word) + encoded_to_digits(word));
    // return pad_zeroes(head(word)) + encoded_to_digits(tail(word));
  }

private:
  std::string head(const std::string &word) const { return word.substr(0, 1); }
  // std::string tail(const std::string &word) const { return word.substr(1); }

  std::string encoded_to_digit(char letter) const {
    const std::unordered_map<char, std::string> mapped_encodings{
        // https://en.wikipedia.org/wiki/Soundex
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"},
        {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"},
    };
    auto found_it = mapped_encodings.find(letter);
    // Check if find() points to end(), returning an empty string
    // If not, return the encoded (second) value what was found
    return found_it == mapped_encodings.end() ? "" : found_it->second;
  }

  std::string encoded_to_digits(const std::string &word) const {
    std::string encoded;
    for (auto letter : word)
      encoded += encoded_to_digit(letter);
    return encoded;
  }

  std::string pad_zeroes(const std::string &word) const {
    auto zeroes_needed = min_word_length - word.length();
    return word + std::string(zeroes_needed, '0');
  }
};

#endif
