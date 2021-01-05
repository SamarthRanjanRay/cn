#include <bits/stdc++.h>
using namespace std;

// Internet checksum
int checksum(int flag)
{
	string s;
	cout << "Enter the string:";
	cin >> s;
	int n = s.length();
	if (n % 2)
		n = (n + 1) / 2;
	else
		n /= 2;
	int temp;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		temp = s[i * 2];
		temp = (temp * 256) + s[i * 2 + 1];
		sum += temp;
	}
	if (flag == 1)
	{
		cout << endl << "Enter the checksum:";
		cin >> temp;
		sum += temp;
	}
	if (sum % 65536 != 0)
	{
		sum = sum / 65536 + sum % 65536;
	}
	sum = 65536 - sum;
	return sum;
}
int main()
{
	int ch;
	int sum;
	do
	{
		cout << "Enter 1 encode 2 decode 3 exit";
		cin >> ch;
		switch (ch)
		{
		case 1: sum = checksum(0);
			cout << "Checksum: " << sum;
			break;
		case 2: sum = checksum(1);
			if (sum)
				cout << "Corrupt";
			else
				cout << "safe";
			break;
		case 3: break;
		default: cout << "Invalid, try again";
		}
	} while (ch != 3);
	return 0;
}