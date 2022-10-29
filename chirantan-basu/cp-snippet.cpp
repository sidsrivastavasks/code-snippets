    /*
        “All you need was that one little match, to start that whole fire.”
    */ 
     
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
     
    #include <bits/stdc++.h>
     
     
    #define ll long long
    using namespace std;
     
     
     
    const int  INF  =  0x7f7f7f7f;
     
    // segment_tree<long long> st(a, n, LLONG_MAX, [&](auto x, auto y) { return min(x, y); });
    template<typename T>
    struct segment_tree {
        using F = std::function<T(const T&, const T&)>;
     
        int n;
        std::vector<T> t;
        std::vector<int> lazy;
        T e;
        F f;
     
        segment_tree() : n(), e(), f() {}
     
        template<typename U>
        segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
            build(arr, 1, 0, n - 1);
        }
     
        template<typename U>
        void build(const U &arr, int i, int l, int r) {
            if (l == r) {
                t[i] = T(arr[l]);
                return;
            }
            int mid = (l + r) >> 1;
            build(arr, i << 1, l, mid);
            build(arr, i << 1 | 1, mid + 1, r);
            t[i] = f(t[i << 1], t[i << 1 | 1]);
        }
     
        void push(int x, int l, int r) {
            if (lazy[x]) {
                t[x << 1] += lazy[x];
                t[x << 1 | 1] += lazy[x];
                lazy[x << 1] += lazy[x], lazy[x << 1 | 1] += lazy[x];
                lazy[x] = 0;
            }
        }
     
        template<typename U>
        void update(int ql, int qr, U val) {
            update_helper(ql, qr, val, 1, 0, n - 1);
        }
     
        template<typename U>
        void update_helper(int ql, int qr, U val, int i, int l, int r) {
            if (r < ql || qr < l)
                return;
            if (ql <= l && r <= qr) {
                t[i] += val;
                lazy[i] += val;
                return;
            }
            push(i, l, r);
            int mid = (l + r) >> 1;
            update_helper(ql, qr, val, i << 1, l, mid);
            update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);
     
            t[i] = f(t[i << 1], t[i << 1 | 1]);
        }
     
        T query(int ql, int qr) {
            return query_helper(ql, qr, 1, 0, n - 1);
        }
     
        T query_helper(int ql, int qr, int i, int l, int r) {
            if (r < ql || qr < l)
                return e;
            if (ql <= l && r <= qr)
                return t[i];
            push(i, l, r);
            int mid = (l + r) >> 1;
            T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
            return f(x, y);
        }
    };
     
    int main()
    {
        #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
        #endif
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            struct info {
                int x , y , i;
                info(int l,int r,int c) {
                    x = l;
                    y = r;
                    i = c;
                }
            };
            
        


            cout << "\n" ;
     
        }
        return 0;
    }  