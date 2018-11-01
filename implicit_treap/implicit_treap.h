#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;

// Treap (Cartesian tree) with implicit key
//   zero-indexed
//   all ranges are half-open: [left, right)
//   allows lazy propagation
//   solves online RSQ with range assignments
//   Time complexity for all operations is O(depth),
//   which is O(log(size)) for treap with random priorities

struct Node
{
    inline static std::mt19937 rnd{(unsigned int)chrono::high_resolution_clock::now().time_since_epoch().count()};
    int size = 1;
    int prior;
    Node* left = nullptr;
    Node* right = nullptr;
    long long value;
    long long sum;
    long long assign = -1;
    Node(long long v) : prior(rnd()), value(v), sum(v) {}
};

int _size(Node* n)
{
    return n? n->size : 0;
}

void push(Node* n)
{
    if (n and n->assign != -1)
    {
        if (n->left)
            n->left->assign = n->assign;
        if (n->right)
            n->right->assign = n->assign;
        n->value = n->assign;
        n->sum = n->assign * n->size;
        n->assign = -1;
    }
}

long long _sum(Node* n)
{
    if (not n)
        return 0;
    return n->assign == -1? n->sum : n->size * n->assign;
}

void update(Node* n)
{
    n->size = _size(n->left) + _size(n->right) + 1;
    n->sum = _sum(n->left) + _sum(n->right) + n->value;
}

struct Treap
{
    Node* root = nullptr;

    // splits treap in two subtrees: [0..key) and [key..size)
    pair<Node*, Node*> split(Node* n, int key)
    {
        if (not n)
            return pair(nullptr, nullptr);
        push(n);
        int sz = _size(n->left) + 1;
        if (key < sz)
        {
            auto [ll, lr] = split(n->left, key);
            n->left = lr;
            update(n);
            return pair(ll, n);
        }
        else
        {
            auto [rl, rr] = split(n->right, key - sz);
            n->right = rl;
            update(n);
            return pair(n, rr);
        }
    }

    Node* merge(Node* l, Node* r)
    {
        push(l);
        push(r);
        if (not l or not r)
            return l? l : r;
        if (l->prior > r->prior)
        {
            l->right = merge(l->right, r);
            update(l);
            return l;
        }
        else
        {
            r->left = merge(l, r->left);
            update(r);
            return r;
        }
    }

    int size() const
    {
        return _size(root);
    }

    void push_back(int value)
    {
        root = merge(root, new Node(value));
    }

    void insert(int index, int value)
    {
        auto [l, r] = split(root, index);
        root = merge(merge(l, new Node(value)), r);
    }

    void remove(int index)
    {
        auto [l, x] = split(root, index);
        auto [m, r] = split(x, 1);
        (void)m; // warning suppression
        root = merge(l, r);
    }

    const long long& operator[](int index)
    {
        auto [l, x] = split(root, index);
        auto [m, r] = split(x, 1);
        root = merge(merge(l, m), r);
        return m->value;
    }

    void set(int index, int value)
    {
        auto [l, x] = split(root, index);
        auto [m, r] = split(x, 1);
        m->value = value;
        update(m);
        root = merge(merge(l, m), r);
    }

    long long rangeSum(int left, int right)
    {
        auto [x, r] = split(root, right);
        auto [l, m] = split(x, left);
        long long ans = _sum(m);
        root = merge(merge(l, m), r);
        return ans;
    }

    void rangeAssign(int left, int right, int value)
    {
        auto [x, r] = split(root, right);
        auto [l, m] = split(x, left);
        m->assign = value;
        root = merge(merge(l, m), r);
    }
};

// for debug purposes
void print(Node* n)
{
    if (n)
    {
        push(n);
        print(n->left);
        cout << n->value << " ";
        print(n->right);
    }
}

void print(Treap& treap)
{
    print(treap.root);
    cout << endl;
}