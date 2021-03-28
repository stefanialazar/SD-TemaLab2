#include <iostream>
#include <fstream>

using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");

int n, k, v[5000001], deq[5000001];
long sum;

int main()
{
	f >> n >> k;
	int l, r;
	l = 0;
	r = -1;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		f >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		while (l <= r && v[i] <= v[deq[r]])
			r--;
	
		deq[++r] = i;

		if (deq[l] == i - k)
			l++;
		if (i + 1 >= k)
			sum = sum + v[deq[l]];
	}
}
