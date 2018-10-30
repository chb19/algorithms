#include <random>
#include <algorithm>
#include <time.h>
#include <iostream>
using namespace std;

// Treap (Cartesian tree) with implicit key
//   zero-indexed
//   solves online RSQ
//   Time complexity for all operations is O(depth),
//   which is O(log(size)) for treap with random priorities

struct Node
{
    inline static std::mt19937 rnd{(unsigned int)time(0)};
    int size = 1;
    int prior;
    Node* left = nullptr;
    Node* right = nullptr;
    int value;
    int sum;
    Node(int v) : prior(rnd()), value(v), sum(v) {}
};

int _size(Node* n)
{
    return n? n->size : 0;
}

int _sum(Node* n)
{
    return n? n->sum : 0;
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

    int size()
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

    int& operator[](int index)
    {
        auto [l, x] = split(root, index);
        auto [m, r] = split(x, 1);
        int& v = m->value;
        root = merge(merge(l, m), r);
        return v;
    }

    // sum in range [left, right)
    int rangeSum(int left, int right)
    {
        auto [x, r] = split(root, right);
        // x = [0..right) r = [right..size)
        auto [l, m] = split(x, left);
        // l = [0..left) m = [left..right) r = [right..size)
        int ans = _sum(m);
        root = merge(merge(l, m), r);
        return ans;
    }
};

// for debug purposes
void print(Node* n)
{
    if (n)
    {
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