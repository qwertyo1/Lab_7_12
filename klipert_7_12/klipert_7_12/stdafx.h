#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

class B1
{
	int a;
public:
	B1() { };
	B1(int x) { a = x; }
	void show_B1() { cout << "B1 = " << a << endl; }
	void show() { cout << "B1 = " << a << endl; }
};

class B2
{
	int b;
public:
	B2() { };
	B2(int x) { b = x; }
	void show_B2() { cout << "B2 = " << b << endl; }
	void show() { cout << "B2 = " << b << endl; }
};

class B3
{
	int c;
public:
	B3() { };
	B3(int x) { c = x; }
	void show_B3() { cout << "B3 = " << c << endl; }
	void show() { cout << "B3= " << c << endl; }
};

class D1 : public B1, public B2, private B3
{
	int d;
public:
	D1(int a, int x, int y, int z) : B1(x), B2(y), B3(z) { d = a; }
	void show_D1() { cout << "D1 = " << d << endl; show_B1(); show_B2(); show_B3(); }
	void show() { cout << "D1 = " << d << endl; }
};

class D2 : public D1
{
	int e;
public:
	D2(int a, int b, int x, int y, int z) : D1(b, x, y, z) { e = a; }
	void show_D2() { cout << "D2 = " << e << endl; show_D1(); }
	void show() { cout << "D2 = " << e << endl; }
};
