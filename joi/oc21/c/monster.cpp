#include "monster.h"

namespace {

bool example_variable;

}  // namespace

std::vector<int> Solve(int N) {
  std::vector<int> T(N);

  example_variable = Query(0, 1);

  for (int i = 0; i < N; i++) T[i] = (N - 1) - i;

  return T;
}
