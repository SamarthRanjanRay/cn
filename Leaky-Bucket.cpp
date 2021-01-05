// Leaky Bucket
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int orate, bucket, count = 0, drop;
	cout << "Enter the o/p rate:";
	cin >> orate;
	cout << "Enter the bucket size:";
	cin >> bucket;
	int i = 0;
	int inp[100];
	int ch;
	do
	{
		cout << "enter the incoming bits at second " << i + 1 << endl;
		cin >> inp[i];
		cout << "0 to stop, 1 to continue" << endl;
		cin >> ch;
		i++;
	} while (ch);
	int nsec = i;
	cout << "seconds \t recieved \t sent \t dropped \t remained" << endl;
	for (int i = 0; count || i < nsec; i++)
	{
		cout << i + 1 << "\t\t";
		cout << inp[i] << "\t\t";
		cout << min(inp[i] + count, orate) <<  "\t\t";
		int x = inp[i] + count - orate;
		if (x > 0)
		{
			if (x > bucket)
				count = bucket, drop = x - bucket;
			else
				count = x, drop = 0;
		}
		else
			drop = 0, count = 0;
		cout << drop << "\t\t" << count << endl;

	}

	return 0;
}