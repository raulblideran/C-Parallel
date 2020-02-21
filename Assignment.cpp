#include <iostream>
#include <thread>
#include <string>

using namespace std;

	int** mat(int x)
	{
		int** a = new int* [10000];
		int i, j;
		for (i = 0; i < 10000; i++)
		{
			a[i] = new int[10000];
		}
		for (i = 0; i < 10000; i++)
		{
			for (j = 0; j < 10000; j++)
				if (j % 3 == 0)
					a[i][j] = x - 11505*(-369818);
				else if (i % 2 == 0)
					a[i][j] = x * 37245*147903;
				else if ((j % 5 == 0) && (i % 5 == 0))
					a[i][j] = x + 50000*4500;
				else if (i == j)
					a[i][j] = x + 2500 * 20;
				else
					a[i][j] = x;
		}
		for (i = 0; i < (20); i++)
		{
			for (j = 0; j < (20); j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		return a;
		for (i = 0; i < 10000; i++)
			delete[] a[i];
		delete[] a;
	}

	int** mat2(int x)
	{
		int** a = new int* [10000];
		int i, j;
		for (i = 0; i < 10000; i++)
		{
			a[i] = new int[10000];
		}
		for (i = 0; i < 10000; i++)
		{
			for (j = 0; j < 10000; j++)
				if (j % 3 == 0)
					a[i][j] = x - 11505 * (-36818);
				else if (i % 2 == 0)
					a[i][j] = x * 37245 * 148987903;
				else if ((j % 5 == 0) && (i % 5 == 0))
					a[i][j] = x + 50000 * 454800;
				else if (i == j)
					a[i][j] = x + 2500 * 2470;
				else
					a[i][j] = x;
		}
		for (i = 0; i < (20); i++)
		{
			for (j = 0; j < (20); j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		return a;
		for (i = 0; i < 10000; i++)
			delete[] a[i];
		delete[] a;
	}

	void mult(int x)
	{
		int** a = mat(x);
		int** b = mat2(x);
		int i, j, k;
		int** c = new int* [1500];
		for (i = 0; i < 1500; i++)
		{
			c[i] = new int[1500];
		}
		for (i = 0; i < 1500; i++)
		{

			for (j = 0; j < 1500; j++)
			{
				c[i][j] = 0;
				for (k = 0; k < 1500; k++)
				{
					if (k % 2 == 0)
						c[i][j] += a[i][k] * b[k][j]* 15000;
					else if (k % 3 == 0)
						c[i][j] += a[i][k] * b[k][j]- a[i][j]-250 + b[k][i]*250;

				}
			}

		}
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
				cout << c[i][j] << "  ";
				cout << endl;

		}
		for (i = 0; i < 1500; i++)
			delete[] c[i];
		
		delete[] c;
	}

	int iter(int x)
	{
		if (x <= 1)
			return 1;
		else
		{
			mult(x);
			return iter(x - 1);
		}

	}

int main()
{
	cout << "This little piece of software gets 2 user inputs builds based on an interator two matrices which then get\n"
		"returned and a CPU intensive multiplication is done\n";
	int n, m, o, p;
	char str[3];
	cout << "How do you want to execute the program, in serial or parallel?\n"
		"If you want serial type s or p for parallel: ";
	cin >> str;

	cout << "Now introduce the number of iterations for each thread\n";

	cout << "First variable= "; cin >> n;
	cout << "Second variable= "; cin >> m;
	cout << "Third variable= "; cin >> o;
	cout << "Forth variable= "; cin >> p;

	if (str[0] == 'p') {
		thread thread1(iter, n);
		thread thread2(iter, m);
		thread thread3(iter, o);
		thread thread4(iter, p);
		thread1.join();
		thread2.join();
		thread3.join();
		thread4.join();
	}
	else if(str[0] == 's')
	{
		iter(n);
		iter(m);
		iter(o);
		iter(p);
	}
	return 0;
	system("pause");
}