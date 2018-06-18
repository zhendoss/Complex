// myComplex.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Complex.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	setlocale(LC_ALL, "rus");

	Complex *a =new Complex(1.0, 2.0);
	Complex *b =new Complex(2.0, -3.0);

	Complex *c =new Complex();
	
	cout << "����������� ����� a = " << *a;
	cout << "����������� ����� b = " << *b;

	Complex d(*a);
	d =d.mltComplex(-2);
	cout << "����������� ����� d = " << d;

	*c =*a * (*b);
	cout << "����������� ����� c = " << *c;

	*a *= *b;
	cout << "����������� ����� a = " << *a;

	if(*c == *a) cout << endl << "����������� ����� 'a' � '�' ����� !!" << endl;

	d =*a / (*c);
	cout << endl << "��������� �������    a / � = " << d << endl;

	*c /= a->divComplex(2);
	cout << endl << "��������� �������    c /= (a/2) -> " << *c << endl;

	Complex *f =new Complex;
	cin >> *f;
	cout << "����������� ����� f = " << *f;

	cout << endl;
 //   Console::WriteLine(L"����������, ���!");
    system("pause");
    return 0;
}
