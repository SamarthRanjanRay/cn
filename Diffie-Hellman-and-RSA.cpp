#include <bits/stdc++.h>
using namespace std;
#define INF 999


// Diffie Hellman

// int diffie(int a, int m , int p)
// {
// 	return (int)pow(a, m) % p;
// }
// int main()
// {
// 	int P = 23;
// 	int G = 9;

// 	int a = 4;
// 	int b = 3;

// 	int A = diffie(G, a, P);
// 	int B = diffie(G, b, P);

// 	int ka = diffie(B, a, P);
// 	int kb = diffie(A, b, P);
// 	cout << ka << " " << kb;
// 	return 0;
// }


//RSA
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
int main()
{
	double p = 3;
	double q = 7;
	double n = p * q;
	double totient = (p - 1) * (q - 1);
	double e =  2;
	while (e < totient)
	{
		if (gcd(e, totient) == 1)
			break;
		else
			e++;
	}

	double k = 2;
	double d = (1 + k * totient) / e;
	double msg = 12;

	double c = pow(msg, e);
	double m = pow(c, d);

	c = fmod(c, n);
	m = fmod(m, n);

	cout << "Encry: " << c << endl;
	cout << "Msg: " << m << endl;


}
