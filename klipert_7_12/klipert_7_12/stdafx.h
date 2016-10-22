#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

class B {
	int a;
public:
	B() {}
	B(int x) { a = x; }
	void show_B() { cout << "B = " << a << endl; }
	void show() { cout << "B = " << a << endl; }
};

class D1 : public B {
	int b;
public:
	D1(int a, int x) : B(x) { b = a; }
	void show_D1() {
		cout << "D1 = " << b << endl; 
		show_B();
	}
	void show() { cout << "D1 = " << b << endl; }
};

class D2 : private B {
	int c;
public:
	D2(int a, int x) : B(x) { c = a; }
	void show_D2() {
		cout << "D2 = " << c << endl;
		show_B();
	}
	void show() { cout << "D2 = " << c << endl; }
};

class D3 : private B {
	int d;
public:
	D3(int a, int x) : B(x) { d = a; }
	void show_D3() {
		cout << "D3 = " << d << endl;
		show_B();
	}
	void show() { cout << "D3 = " << d << endl; }
};

class D4 : private D1, public D2 {
	int e;
public:
	D4(int a, int x, int y) : D1(x,y), D2(x,y) { e = a; }
	void show_D4() {
		cout << "D4 = " << e << endl;
		show_D2();
		show_D1();
	}
	void show() { cout << "D4 = " << e << endl; }
};

class D5 : private D3, public D2 {
	int f;
public:
	D5(int a, int x, int y) : D2(x, y), D3(x, y) { f = a; }
	void show_D5() {
		cout << "D5 = " << f << endl;
		show_D2();
		show_D3();
	}
	void show() { cout << "D5 = " << f << endl; }
};