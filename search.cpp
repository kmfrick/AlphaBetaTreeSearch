#include <iostream>

#define SZ 32

// Array representation of a binary tree
// Position 0 is empty, while for all i, the left child is at
// position 2i while the right child is at 2i+1 (see #defines)
int tree[SZ] = {0,  -1,  -1,   -1,  -1, -1, -1, -1, -1,  -1, -1,
                -1, -1,  -1,   -1,  -1, 2,  76, 38, -86, 79, 78,
                60, -78, -100, -33, 37, 33, 52, 43, 87,  -20};

#define left(i) 2 * i
#define right(i) 2 * i + 1
#define INF 1000
#define COUNT 5
#define CHILDREN 2

int alphabeta(int node, int depth, int a, int b, bool maximizing_player) {
  if (depth == 0 || node >= SZ / CHILDREN) {
    return tree[node];
  }
  if (maximizing_player) {
    int value = -INF;
    for (int i = 0; i < CHILDREN; i++) {
      int child = left(node) + i;
      value = std::max(value, alphabeta(child, depth - 1, a, b, false));
      if (value >= b) {
        break; // b cutoff
      }
      a = std::max(a, value);
    }
    std::cout << "Node " << node << ": a = " << a << ", val = " << value
              << ", b = " << b << std::endl;
    return value;
  } else {
    int value = +INF;
    for (int i = 0; i < CHILDREN; i++) {
      int child = left(node) + i;
      value = std::min(value, alphabeta(child, depth - 1, a, b, true));
      if (value <= a) {
        break; // a cutoff
      }
      b = std::min(b, value);
    }
    std::cout << "Node " << node << ": a = " << a << ", val = " << value
              << ", b = " << b << std::endl;
    return value;
  }
  return -1;
}

int main() {
  std::cout << alphabeta(1, 1000, -INF, INF, true) << std::endl;
  return 0;
}
