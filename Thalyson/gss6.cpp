#include <bits/stdc++.h>
#define INF (1 << 21)


using namespace std;
static struct IO {
    char tmp[1 << 10];

    // fast input routines
    char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }

    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

    inline IO& operator >> (char & c) { c = nextChar(); return *this; }

    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }

    inline IO& operator >> (string & s) {
        if (skipBlanks()) { s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }

    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this; }

#define defineInFor(intType) \
    inline IO& operator >>(intType & n) { \
        if (skipBlanks()) { \
            int sign = +1; \
            if (peekChar() == '-') { \
                sign = -1; \
                n = nextChar() - '0'; \
            } else \
                n = peekChar() - '0'; \
            while (!isBlank(nextChar())) { \
                n += n + (n << 3) + peekChar() - 48; \
            } \
            n *= sign; \
        } \
        return *this; \
    }

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

    // fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
    inline char * toString(intType n) { \
        char * p = (tmp + 30); \
        if (n) { \
            bool isNeg = 0; \
            if (n < 0) isNeg = 1, n = -n; \
            while (n) \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg) *--p = '-'; \
        } else *--p = '0'; \
        return p; \
    } \
    inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/

struct node{
  int v, p, cnt, ans, suff, pre, sum;
  node *l, *r;
  node(){}
  node(int _v = 0, int _p = 0){
    v = _v;
    p = _p;

    l = r = NULL;

    ans = suff = pre = sum = v;
  }
};

int count(node *t){
  if(t == NULL) return 0;
  return t -> cnt;
}

int fpre(node *t){
  if(t == NULL)  return 0;
  return t -> pre;
}

int fsuff(node *t){
  if(t == NULL) return 0;
  return t -> suff;
}

int fans(node *t){
  if(t == NULL) return -INF;
  return t -> ans;
}

int fsum(node *t){
  if(t == NULL) return 0;
  return t -> sum;
}

void upd(node *&t){
  if(t == NULL) return;
  int v = t -> v;

  t -> ans = max(0, fpre(t -> r)) + v + max(0, fsuff(t -> l));
  t -> ans = max(t -> ans, max(fans(t -> l), fans(t -> r)));

  t -> sum = fsum(t -> l) + v + fsum(t -> r);

  t -> cnt = count(t -> l) + 1 + count(t -> r);

  t -> pre = max(fpre(t -> l), fsum(t -> l) + v);
  t -> pre = max(t -> pre, fsum(t -> l) + v + fpre(t -> r));

  t -> suff = max(fsuff(t -> r), fsum(t -> r) + v);
  t -> suff = max(t -> suff, fsuff(t -> l) + v + fsum(t -> r));

}

void split(node *t, node *&l, node *&r, int val){
  if(t == NULL){
    l = r = NULL;
    return;
  }
  if(count(t -> l) + 1 <= val){
    split(t -> r, t -> r, r, val - count(t -> l) - 1);
    l = t;
  }
  else{
    split(t -> l, l, t -> l, val);
    r = t;
  }
  upd(t);
}

void merge(node *&t, node *l, node *r){
  if(l == NULL || r == NULL){
    if(l == NULL) t = r;
    else t = l;
  }
  else if(l -> p >= r -> p){
    merge(l -> r, l -> r, r);
    t = l;
  }
  else{
    merge(r -> l, l, r -> l);
    t = r;
  }
  upd(t);
}

void insert(node *&t, int v, int p){
  node *l = NULL, *r = NULL, *nd = NULL;
  nd = new node(v, rand());
  if(t == NULL){
    t = nd;
    return;
  }
  split(t, l, r, p - 1);
  merge(t, l, nd);
  merge(t, t, r);
}

void banish(node *&t, int p){
  if(t == NULL) return;
  node *l = NULL, *r = NULL, *ll = NULL, *lr = NULL;
  split(t, l, r, p);
  split(l, ll, lr, p - 1);
  merge(t, ll, r);
}

int query(node *&t, int x, int y){
  int ret = 0;
  node *l = NULL, *r = NULL, *rl = NULL, *rr = NULL;
  split(t, l, r, x - 1);
  split(r, rl, rr, y - x + 1);
  ret = fans(rl);
  merge(r, rl, rr);
  merge(t, l, r);
  return ret;
}

void print(node *t){
  if(t == NULL) return;
  print(t -> l);
  cout << (t -> v) << " ";
  print(t -> r);
}

void print(node *t, int whatever){
  print(t);
  cout << "\n";
}

node *t;

int main(){
  //cin.tie(0);
  srand(time(NULL));
  //ios_base::sync_with_stdio(0);
  char op[5];
  int n, x, q, y;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> x;
    insert(t, x, i);
  }
  cin >> q;
  while(q--){
    cin >> op >> x;
    if(op[0]== 'I'){
      cin >> y;
      insert(t, y, x);
    }
    else if(op[0] == 'D')
      banish(t, x);
    else if(op[0] == 'R'){
      cin >> y;
      banish(t, x);
      insert(t, y, x);
    }
    else{
      cin >> y;
      cout << query(t, x, y) << "\n";
    }
  }



  return 0;
}
