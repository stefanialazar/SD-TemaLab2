#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream f("queue.in");
ofstream g("queue.out");


int n, x, i, j;
stack <int> s1, s2;
string str;


int main()
{
    f >> n;
    for (i = 1; i <= n; i++)
    {
        f >> str;
        g << i << ": ";
        if (str.substr(0, 4) == "push")
        {
            g << "read(";
            x = 0;
            for (j = 10; str[j] != ')'; j++)
                x = x * 10 + str[j] - '0';
            g << x << ") push(1," << x << ")" << '\n';
            s1.push(x);
        }
        else
        {
            if (!s2.empty())
            {
                g << "pop(2) write(" << s2.top() << ")" << '\n';
                s2.pop();
            }
            else
            {
                while (s1.size() >= 2)
                {
                    g << "pop(1) push(2," << s1.top() << ") ";
                    s2.push(s1.top());
                    s1.pop();
                }
                g << "pop(1) " << "write(" << s1.top() << ")" << '\n';
                s1.pop();
            }
        }
    }
}
