#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
template<class t> class SegTreeLazy {
    vector<ll> *arr, st, lazy; int n;

    void build(int u, int i, int j) {
        if (i == j) {
            st[u] = (*arr)[i];
            return;
        }
        int m = (i+j)/2, l = u*2+1, r = u*2+2;
        build(l, i, m);
        build(r, m+1, j);
        st[u] = t::merge_op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x) {
        st[u] = t::range_op(st[u], i, j, x);
        if (i != j) {
            lazy[u*2+1] = t::prop_left_op(lazy[u*2+1], x);
            lazy[u*2+2] = t::prop_right_op(lazy[u*2+2], x);
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j) {
        if (j < a or b < i) return t::neutro;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        int m = (i+j)/2, l = u*2+1, r = u*2+2;
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m+1, j);
        return t::merge_op(x, y);
    }

    void update(int a, int b, ll value, int u, int i, int j) {
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return; else {
            int m = (i+j)/2, l = u*2+1, r = u*2+2;
            update(a, b, value, l, i, m);
            update(a, b, value, r, m+1, j);
            st[u] = t::merge_op(st[l], st[r]);
        }
    }

public:
    SegTreeLazy(vector<ll>& v) {
        arr = &v;
        n = v.size();
        st.resize(n*4+5);
        lazy.assign(n*4+5, 0);
        build(0, 0, n-1);
    }

    SegTreeLazy(int64_t n) {
        arr = new vector<ll>(4 * n);
        this->n = n;
        st.resize(n*4+5);
        lazy.assign(n*4+5, 0);
        build(0, 0, n-1);
    }

    ll query(int a, int b) {
        return query(a, b, 0, 0, n-1);
    }

    void update(int a, int b, ll value) {
        update(a, b, value, 0, 0, n-1);
    }
};

struct RSQ { // range sum query
    static ll const neutro = 0;
    static ll merge_op(ll x, ll y) { return x + y; }
    static ll range_op(ll st_u, int i, int j, ll x) { return st_u + (j - i + 1) * x; }
    static ll prop_left_op(ll left_child, ll x) { return left_child + x; }
    static ll prop_right_op(ll right_child, ll x) { return right_child + x; }
};


int coord_transform(int i, int j){
    return (n*(j-i-1)-((j-i-1)*(j-i))/2 + i);
}
// usage
int main() {
    int m, q, f1, f2, k, pos;
    cin >> n >> m >> q;
    vector<ll> A;
    A.assign((n*(n-1))/2, 1);
    SegTreeLazy<RSQ> stl(A);
    for (int i = 0; i < m; ++i) {
        cin >> k >> f1 >> f2;
        f1--; f2--;
        pos = coord_transform(f1,f2);
        stl.update(pos, pos+k-1, 1);
    }
    for (int j = 0; j < q; ++j) {
        cin >> f1 >> f2;
        f1--; f2--;
        if (f1 > f2) swap(f1,f2);
        pos = coord_transform(f1,f2);
        if (stl.query(pos,pos)%2 == 1){
            cout << "NO\n";
        }else{
            cout << "SI\n";
        }
    }
    return 0;
}