#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

int n, maxl, l;
string p;
stack <int> s;

int main()
{
	f >> n;
	f >> p;
	for (int i = 0; i < n; i++)
	{
		if ((p[i] == ')' && p[s.top()] == '(') || (p[i] == ']' && p[s.top()] == '[') || (p[i] == '}' && p[s.top()] == '{'))
		{
			s.pop();
		}
		else
			s.push(i);
	}
	if (s.empty())
		g << n;
	else
	{
		l = s.top();
		s.pop();
		while (!s.empty()) 
		{
			if (l - s.top() - 1 > maxl)
				maxl = l - s.top() - 1;
			l = s.top();
			s.pop();
		}
		g << maxl;
	}
}