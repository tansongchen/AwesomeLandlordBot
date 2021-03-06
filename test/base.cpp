#include <iostream>
#include <set>

#include "../src/base.h"
#include "catch2/catch.hpp"

using namespace std;

TEST_CASE("Card / Level conversion", "[conversion]") {
  Card card1 = blackJoker;
  Card card2 = redJoker;
  Level level1 = blackJokerLevel;
  Level level2 = redJokerLevel;
  Card card3 = 18;  // one of the "7" s
  Level level3 = 4;
  REQUIRE(card_to_level(card1) == level1);
  REQUIRE(card_to_level(card2) == level2);
  REQUIRE(card_to_level(card3) == level3);
}

TEST_CASE("Counter class", "[counter]") {
  Group group = {0, 1, 2, 4, 5, blackJoker, redJoker};
  Counter counter({{0, 3}, {1, 2}, {blackJokerLevel, 1}, {redJokerLevel, 1}});
  REQUIRE(Counter(group) == counter);
  REQUIRE(counter.get_group(group) == group);
}

TEST_CASE("Hand class", "[hand]") {
  Counter counters[4] = {Counter({0, 1, 2}), Counter({0, 4, 8, 12, 16}), Counter({20, 21, 22, 29}), Counter({{0, 1}, {1, 1}, {3, 1}, {7, 1}, {10, 4}, {11, 4}})};
  Hand hands[4] = {Hand(0, 1, 3), Hand(4, 5, 1), Hand(5, 1, 3, 1, {7}), Hand(11, 2, 4, 1, {0, 1, 3, 7})};
  for (int i = 0; i != 4; ++i) {
    REQUIRE(Hand(counters[i]) == hands[i]);
    REQUIRE(counters[i] == hands[i].get_counter());
  }
}

TEST_CASE("Level combination", "[combination]") {
  vector<Level> attachables = {3, 4, 8, 10};
  REQUIRE(combinations(attachables, 0) == vector<set<Level>>{});
  REQUIRE(combinations(attachables, 1) == vector<set<Level>>{set<Level>{3}, set<Level>{4}, set<Level>{8}, set<Level>{10}});
  REQUIRE(combinations(attachables, 2) == vector<set<Level>>{set<Level>{3, 4}, set<Level>{3, 8}, set<Level>{4, 8}, set<Level>{3, 10}, set<Level>{4, 10}, set<Level>{8, 10}});
}
