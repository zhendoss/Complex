#pragma once

#include "iostream"
using namespace std;


struct Complex{

private:
	double _real;
	double _imag;

public:
	Complex();
	Complex(const double, const double);
	Complex(const Complex &);
	~Complex();

	void prnComplex();

	double powComplex(const Complex *);

	Complex addComplex(const Complex *, const Complex *);
	Complex subComplex(const Complex *, const Complex *);
	Complex mltComplex(const int);			// переопределённый метод
	Complex mltComplex(const double);
	Complex mltComplex(const Complex *);	// переопределённый метод
	Complex divComplex(const int);			// переопределённый метод
	Complex divComplex(const double);		

	Complex operator * (const Complex &);
	Complex operator / (const Complex &);

	Complex operator *= (const Complex &);
	Complex operator /= (const Complex &);
	Complex operator += (const Complex &);
	Complex operator -= (const Complex &);

	Complex operator = (const Complex &);
	bool operator == (const Complex &);
	
	friend ostream & operator << (ostream &, const Complex &);
	friend istream & operator >> (istream &, Complex &);
};
	
	