#include <algorithm>

#include "../strategy.h"

Hand solo_selector(Counter *counter) {
  Level level = find_if(counter->begin(), counter->end(),
                        [](Count count) { return count; }) -
                counter->begin();
  return Hand(level);
}
