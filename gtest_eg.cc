#include "Soundexer.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <string>

// using ::testing::Eq;
// using namespace testing;

class SoundexerFixture : public testing::Test {
public:
  Soundexer sdxr;
};

TEST_F(SoundexerFixture, first_character) {
  auto encoded = sdxr.encode("A");
  ASSERT_THAT(encoded, testing::Eq("A000"));
}

TEST_F(SoundexerFixture, pad_to_three_digits) {
  auto encoded = sdxr.encode("abc");
  ASSERT_THAT(encoded.length(), testing::Eq(4));
}

TEST_F(SoundexerFixture, consonant_to_numeral) {
  EXPECT_THAT(sdxr.encode("Ab"), testing::Eq("A100"));
  EXPECT_THAT(sdxr.encode("Ac"), testing::Eq("A200"));
  EXPECT_THAT(sdxr.encode("Ad"), testing::Eq("A300"));
  // No need to test everything, considering the functionality will be identical
  EXPECT_THAT(sdxr.encode("Ax"), testing::Eq("A200"));
}

TEST_F(SoundexerFixture, ignore_non_alphabet) {
  ASSERT_THAT(sdxr.encode("A#"), testing::Eq("A000"));
}

// TEST_F(SoundexerFixture, many_consonants_to_numerals) {
//   ASSERT_THAT(sdxr.encode("Acdl"), testing::Eq("A234"));
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
