#include <gmock/gmock.h>
// #include <gtest/gtest.h>
#include <string>

// using ::testing::Eq;
// using namespace testing;

class Soundexer {
public:
  std::string encode(const std::string &word) const { return pad_zeroes(word); }

private:
  std::string pad_zeroes(const std::string &word) const { return word + "000"; }
};

class SoundexerFixture : public testing::Test {
public:
  Soundexer sdxr;
};

TEST_F(SoundexerFixture, FirstCharacter) {
  auto encoded = sdxr.encode("A");
  ASSERT_THAT(encoded, testing::Eq("A"));
}

TEST_F(SoundexerFixture, PadThreeDigits) {
  auto encoded = sdxr.encode("I");
  ASSERT_THAT(encoded, testing::Eq("I000"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
