// myComplex.cpp: главный файл проекта.

#include "stdafx.h"
#include "Complex.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	setlocale(LC_ALL, "rus");

	Complex *a =new Complex(1.0, 2.0);
	Complex *b =new Complex(2.0, -3.0);

	Complex *c =new Complex();
	
	cout << "комплексное число a = " << *a;
	cout << "комплексное число b = " << *b;

	Complex d(*a);
	d =d.mltComplex(-2);
	cout << "комплексное число d = " << d;

	*c =*a * (*b);
	cout << "комплексное число c = " << *c;

	*a *= *b;
	cout << "комплексное число a = " << *a;

	if(*c == *a) cout << endl << "комплексные числа 'a' и 'с' равны !!" << endl;

	d =*a / (*c);
	cout << endl << "результат деления    a / с = " << d << endl;

	*c /= a->divComplex(2);
	cout << endl << "результат деления    c /= (a/2) -> " << *c << endl;

	Complex *f =new Complex;
	cin >> *f;
	cout << "комплексное число f = " << *f;

	cout << endl;
 //   Console::WriteLine(L"Здравствуй, мир!");
    system("pause");
    return 0;
}
