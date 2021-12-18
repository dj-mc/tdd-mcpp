#include <string>
class Soundexer {
public:
  std::string encode(const std::string &word) const { return ""; }
};

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(SoundexerEncoder, FirstCharacter) {
  Soundexer sdxr;
  auto encoded = sdxr.encode("A");
}

TEST(HelloTest, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}

// cmake -S . -B build
// cmake --build build
