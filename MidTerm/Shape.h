#ifndef SHAPE_H

#define SHAPE_H

#include <iostream>


using namespace std;

class Shape {

public:

	int perimeter;
	int area;
	virtual void calcPerimeter() = 0;
	virtual void calcArea() = 0;


public:

	int a, b, c;

	Shape() {
		a = 0;
		b = 0;
		c = 0;
		perimeter = 0;
		area = 0;
	}
	Shape(int x, int y, int z) {
		perimeter = 0;
		area = 0;
		a = x;
		b = y;
		c = z;
	}


public:
	
	class ExceptionFifty {
	public:
		int value;
		ExceptionFifty(int i) {
			value = i;
		}
	};


	class CalcFailure {
	public:
		CalcFailure() {}
	};
	
};

class Circle : protected Shape {

public:
	int radius;

	Circle(int a, int b, int c) {
		radius = c;

		calcPerimeter();
		calcArea();

	}

	virtual void calcPerimeter() override {

		(*this).perimeter = (double)(*this).radius * 2 * 3.141592654;				// Don't need another preprocessor directive for PI()
	}
	virtual void calcArea() override {

		(*this).area = (double)(*this).radius * 3.141592654 * 3.141592654;		// Don't need another preprocessor directive for PI()
	}


	double getPerimeter() {
		return (*this).perimeter;
	}

	double getArea() {
		return (*this).area;
	}

	friend ostream& operator<<(ostream& out, Circle x) {

		out << "Perimeter: " << x.getPerimeter() << ", Area: " << x.getArea() << endl;
		return out;
	}

};

class Rectangle : protected Shape {

public:

	Rectangle(int x, int y, int z) {

		length = x;
		width = y;

		calcPerimeter();
		calcArea();

	}

	int length, width;
	virtual void calcPerimeter() override {
		(*this).perimeter = ((double)(*this).length * 2) + ((double)(*this).width * 2);

	}
	virtual void calcArea() override {

		(*this).area = (double)(*this).length * (double)(*this).width;
	}

	double getPerimeter() {
		return (*this).perimeter;
	}

	double getArea() {
		return (*this).area;
	}

	friend ostream& operator<<(ostream& out, Rectangle x) {

		out << "Perimeter: " << x.getPerimeter() << ", Area: " << x.getArea() << endl;
		return out;
	}

};

#endif