#include "stdafx.h"
#include"afxwin.h"
#include "Windows.h"
#include "lib1.h"

int factorial(int n)
{
	if (n == 0||n==1) return 1;
	else return factorial(n - 1)*n;
}

float Fac:: convert(float deg)
{
	return (3.14 / 180) * deg;
}
