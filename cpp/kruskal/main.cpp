#include <cstdlib>
#include <array>
#include <utility>
#include <cmath>
#include <vector>
#include <tuple>

struct Node_Struct {
  int index;
  struct Node_Struct * name;
};

typedef struct Node_Struct Node;

int getName(Node * n) {
  while(n->name) n = n->name;
  return n->index;
}

int main() {
  const int nnodes =  7;

  std::array<Node*, nnodes> nodes;
  std::vector<std::tuple<int, int, int> > edges;

  for(int i = 0; i < nnodes; i++) {
    Node * x = new Node();
    x->index = i;
    x->name = nullptr;
    nodes[i] = x;

    for(int j = 0; j < nnodes; j++) {
      if (i == j - 1) {
        edges.push_back(std::make_tuple(i, j, 1));
      }
    }
  }

  for(std::tuple<int, int, int> e : edges) {
    Node * u = nodes[std::get<0>(e)];
    Node * v = nodes[std::get<1>(e)];
    if (getName(u) != getName(v)) {
      v->name = u;
      printf("(%d, %d)\n", u->index, v->index);
    }
  }

  return 0;
}
