#include <bits/stdc++.h>

using namespace std;
typedef int ll;
struct node{
  ll L, R, sum, ans;
  node(int tmp){
    L = R = sum = ans = tmp;
  }
  node(){
    node(0);
  }
};
int A[50010];
node tree[200100];

void build_tree(int pos, int l, int r){
  if(l == r)
    tree[pos].L = tree[pos].R = tree[pos].sum = tree[pos].ans = A[l];
  else{
    build_tree(2*pos, l, (l + r)/2);
    build_tree(2*pos + 1, (l + r)/2 + 1, r);
    tree[pos].sum = tree[2*pos].sum + tree[2*pos + 1].sum;
    tree[pos].L = max(tree[2*pos].L, tree[2*pos].sum + tree[2*pos + 1].L);
    tree[pos].R = max(tree[2*pos + 1].R, tree[2*pos].R + tree[2*pos + 1].sum);
    tree[pos].ans = max(max(tree[2*pos].ans, tree[2*pos + 1].ans), tree[2*pos].R + tree[2*pos + 1].L);
  }
  return;
}

node merge(node a, node b){
  node ret;
  ret.sum = a.sum + b.sum;
  ret.L = max(a.L, a.sum + b.L);
  ret.R = max(b.R, a.R + b.sum);
  ret.ans = max(max(a.ans, b.ans), a.R + b.L);
  return ret;
}

node query(int pos, int left, int right, int a, int b){
  if(a <= left && right <= b) return tree[pos];

  int mid = (left + right) >> 1;
  node l_node = node(-10000000), r_node = node(-10000000);
  if(a <= mid)
    l_node = query(2*pos, left, mid, a, b);
  if(b > mid)
    r_node = query(2*pos + 1, mid + 1, right, a, b);
  //cout << mid << endl;
  node ret;
  ret = merge(l_node, r_node);
  //cout << l_node.ans << " " << l_node.L << " " << l_node.R << " " << l_node.sum << endl;
  //cout << r_node.ans << " " << r_node.L << " " << r_node.R << " " << r_node.sum << endl;
  //cout << ret.ans << " " << ret.L << " " << ret.R << " " << ret.sum << endl;
  return ret;
}

int main(){
  int n, m, a, b;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  build_tree(1, 1, n);
  //for(int i = 1; i <= 4*n; ++i) cout << tree[i].sum << endl;
  scanf("%d", &m);
  for(int i = 0; i < m; ++i){
    scanf("%d %d", &a, &b);
    printf("%d\n", query(1, 1, n, a, b).ans);
  }

  return 0;
}
