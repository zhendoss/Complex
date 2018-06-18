#include "stdafx.h"
#include "iostream"

using namespace std;

#include "Complex.h"

	Complex::Complex() : _real(0), _imag(0) {}								// конструктор по умолчанию
	Complex::Complex(const double a, const double b) : _real(a), _imag(b){}	// конструктор с параметрами
	Complex::Complex(const Complex &a) : _real(a._real), _imag(a._imag){}	// копирующий конструктор

	void Complex::prnComplex(){
		cout << endl << "real part " << _real;
		cout << endl << "imaginary part " << _imag << endl;
	}

	Complex Complex::addComplex(const Complex *a, const Complex *b){
		_real =a->_real +b->_real, 
		_imag =a->_imag +b->_imag;
		return *this;
	}

	Complex Complex::subComplex(const Complex *a, const Complex *b){
		_real =a->_real -b->_real, 
		_imag =a->_imag -b->_imag;
		return *this;
	}

	Complex Complex::mltComplex(const int k){
		return mltComplex((double) k);
	}

	Complex Complex::mltComplex(const double k){
		_real =_real *k;
		_imag =_imag *k;
		return *this;
	}

	Complex Complex::mltComplex(const Complex *b){
		double myReal =_real *b->_real -_imag *b->_imag; 
		double myImag =_real *b->_imag +_imag *b->_real;

		_real =myReal;
		_imag =myImag;

		return *this;
	}

	double Complex::powComplex(const Complex *a){				// находим квадрат модул€
		return a->_real *a->_real +
			   a->_imag *a->_imag;
	}

	Complex Complex::divComplex(const int k){
		return divComplex((double) k);
	}

	Complex Complex::divComplex(const double k){
		_real =_real /k;
		_imag =_imag /k;
		return *this;
	}

	Complex Complex::operator * (const Complex &a){
		return Complex(_real *a._real - _imag *a._imag,
						_real *a._imag + _imag *a._real);
	}

	Complex Complex::operator *= (const Complex &a){
		*this =mltComplex(&a);
		return *this;
	}

	Complex Complex::operator / (const Complex &a){
		Complex c =Complex(a._real, -a._imag) *(*this);			// умножаем на комплексно-сопр€жЄнное число
		return c.divComplex(powComplex(&a));
	}

	Complex Complex::operator /= (const Complex &a){
		Complex c(a._real, -a._imag);
		*this = mltComplex(&c);								// умножаем на комплекно-сопр€жЄнное число
		*this =divComplex(powComplex(&a));
		return *this;
	}

	Complex Complex::operator += (const Complex &a){
		_real +=a._real;
		_imag +=a._imag;
		return *this;
	}

	Complex Complex::operator -= (const Complex &a){
		_real -=a._real;
		_imag -=a._imag;
		return *this;
	}

	Complex Complex::operator = (const Complex &a){
		_real =a._real;
		_imag =a._imag;
		return *this;
	}

	bool Complex::operator == (const Complex &a){
		return (_real ==a._real) && (_imag ==a._imag);
	}

	ostream & operator << (ostream &os, const Complex &a){  
		os << a._real << (a._imag <0 ? " - j" : " + j") << fabs(a._imag) << endl;
		return os;  
	}

	istream & operator >> (istream &is, Complex &a){
		std::cout << "введите действительную и мнимую части комплексного числа" << endl;
		std::cout << "действительна€ часть ";
		is >> a._real;
		std::cout << "мнима€ часть ";
		is >> a._imag;
		return is;  
	}
	Complex::~Complex(){}
