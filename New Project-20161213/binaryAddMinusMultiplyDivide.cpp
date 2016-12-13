#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <assert.h>

//加法
int Add(int a, int b)
{
	int t;
	while (b)
		t = a ^ b, b = (a & b) << 1, a = t;
	return a;
}

//取相反数
int Neg(int a)
{
	return Add(~a, 1); //取反加一
}

//减法
int Min(int a, int b)
{
	return Add(a, Neg(b)); // a + (-b)
}

//乘法
int Mul(int a, int b)
{
	bool isNeg = (a > 0) ^ (b > 0);
	unsigned int x = a > 0 ? a : Neg(a), y = b > 0 ? b : Neg(b);
	int ans = 0;
	while (y)
	{
		if (y & 0x01) ans = Add(ans, x);
		y >>= 1, x <<= 1;
	}
	return isNeg ? Neg(ans) : ans;
}

//乘方
int Pow(int a, int b)
{
	int ans = 1, q = a;
	while (b)
	{
		if (b & 0x01) ans = Mul(ans, q);
		b >>= 1, q = Mul(q, q);
	}
	return ans;
}

//除法
int Div(int a, int b) //b不为0
{
	bool isNeg = (a > 0) ^ (b > 0);
	unsigned int x = a > 0 ? a : Neg(a), y = b > 0 ? b : Neg(b);
	int ans = 0;
	for (int i = 31; i >= 0; i--)
		if ((x >> i) >= y) //x >= (y << i)等价写法，避免溢出
			x = Min(x, y << i), ans = Add(ans, 1 << i);
	return isNeg ? Neg(ans) : ans;
}


//取模
int Mod(int a, int b)
{
	return Min(a, Mul(Div(a , b), b)); //a - a / b * b
}


int main()
{
	srand(time(0));
	for (int i = 0; i < 1e7; i++)
	{
		int t1 = rand() + 1, t2 = t1 / 2;
		int a = rand() % t1 - t2, b = rand() % t1 - t2;
		//printf("%d %d\n", a, b);

		int c, d;
		c = Add(a, b), d = a + b; assert(c == d);
		c = Min(a, b), d = a - b; assert(c == d);
		c = Mul(a, b), d = a * b; assert(c == d);
		if (b != 0)
		{
			c = Div(a, b), d = a / b; assert(c == d);
			c = Mod(a, b), d = a % b; assert(c == d);
		}
	}
	printf("Done!\n");
}

