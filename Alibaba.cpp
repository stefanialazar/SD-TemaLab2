#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

int n, k;
string numar;
deque<char> dq;

ifstream f("alibaba.in");
ofstream g("alibaba.out");

int main() 
{
	// n = nr de cifre
	// k = nr de cifre taiate
	// numar = numarul dupa cufar
	f >> n >> k >> numar;
    int aux = 0;
    int size;
    dq.push_back(numar[0]);
    for (int i = 1; i < n; i++) 
    {
        while ((dq.size() > 0) && (numar[i] > dq.back()) && (aux < k)) 
        {
            dq.pop_back();
            aux++;
        }
        size = dq.size();
        if (size < n - k)
            dq.push_back(numar[i]);
    }

    while (dq.size() > 0) 
    {
        g << dq.front();
        dq.pop_front();
    }
}