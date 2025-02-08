#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

struct node
{
    node *child[26];
    long isEnd, cnt;
    node()
    {
        for (long i = 0; i < 26; i++)
            child[i] = NULL;
        isEnd = 0;
        cnt = 0;
    }
};
node *root = new node();
void Add(string &s)
{
    node *u = root;
    for (long i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (u->child[k] == 0)
        {
            u->cnt++;
            u->child[k] = new node();
        }
        u = u->child[k];
    }
    u->isEnd++;
}
bool Delete_Recursive(node *p, string &s, int i)
{
    if (i != int(s.size()))
    {
        int k = s[i] - 'a';
        bool isDelete = Delete_Recursive(p->child[k], s, i + 1);
        if (isDelete)
            p->child[k] = NULL;
    }
    else
        p->isEnd--;
    if (p != root)
    {
        p->cnt--;
        if (p->cnt == 0)
        {
            delete (p);
            return true;
        }
    }
    return false;
}
bool query(string &s)
{
    node *u = root;
    for (long i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (u->child[k] == 0)
            return false;
        u = u->child[k];
    }
    return u->isEnd;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, n;
    cin >> s;
    Add(s);
    Delete_Recursive(root, s, 0);
    cin >> n;
    cout << query(n);
}