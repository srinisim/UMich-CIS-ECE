#include <iostream>
using namespace std;

int sum(int n, int m)
{
	int s = 0;

	s = n + m;
	cout << "The sum of " << n << " and " << m << " is " << s << endl;

	return s;
}

void main()
{
	int n, m;
	
	//sum(1, 2);
	//sum(3, 8);
	cin >> n >> m;
	sum(n, m);

	system("pause");
}