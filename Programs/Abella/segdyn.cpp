struct node {
  vector<node> children;
  node &left() {
    if (children.empty()) children.resize(2);
    return children[0];
  }
  node &right() {
    if (children.empty()) children.resize(2);
    return children[1];
  }

  int sum;
  node(): sum(0) {}

  void update(int pos, int val, int l, int r) {
    if (l == r) sum = val;
    else {
      int m = (l+r)/2;
      if (pos <= m) left().update(pos, val, l, m);
      else right().update(pos, val, m+1, r);
      sum = left().sum + right().sum;
    }
  }

  int query(int a, int b, int l, int r) {
    if (a > r || b < l) return 0;
    else if (a <= l && r <= b) return sum;
    else {
      int m = (l+r)/2;
      if (children.empty()) return 0;
      return (left().query(a, b, l, m) +
	      right().query(a, b, m+1, r));
    }
  }
};

int main() {
  int nt;
  for (int t = 0; t < nt; ++t) {
    struct node root;
    
  }
  return 0;
}
