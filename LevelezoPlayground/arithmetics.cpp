#include "stdafx.h"
#include "arithmetics.h"

int bias = 25;

DoubleValue::DoubleValue(std::string name, int a, int b) : ValueType(name) {
	this->a = new int{ a };
	this->b = new int{ b };
}

DoubleValue::~DoubleValue() {
	std::cout << "Double value destructor called" << std::endl;
	delete this->a;
	delete this->b;
}

DoubleValue::DoubleValue(const DoubleValue& masik) : ValueType("copied") {
	this->a = new int{ *(masik.a) };
	this->b = new int{ *(masik.b) };
}

DoubleValue::DoubleValue(DoubleValue&& masik) : ValueType("moved") {
	this->a = masik.a;
	this->b = masik.b;
	masik.a = nullptr;
	masik.b = nullptr;
}

DoubleValue& DoubleValue::operator=(DoubleValue& masik) {
	// if copy assignment fails, left-hand side variable will be left in an inconsistent state!
	DoubleValue tmp(masik); // so first we create a totally new temporary object. If this fails, no problem
	std::swap(*this, tmp); // then we swap the two
	return *this; // however, swap doesn't work without move assignment! (bc std::swap uses move semantics!)
}

DoubleValue& DoubleValue::operator=(DoubleValue&& masik) {
	delete a; // a es be felul lesz irva, ezert eloszor toroljuk a mem.teruletet, amire hivatkozik!
	delete b;
	a = new int{ *(masik.a) };
	b = new int{ *(masik.b) };
	masik.a = nullptr; // masikra mar nem lesz szuksegunk! kinullazzuk, mivel a vegen a destruktor le fog ra futni!!
	masik.b = nullptr;
	return *this;
}

int DoubleValue::sum() const { // const mert nem valtoztatja az osztaly allapotat
	return *a + *b;
}

int DoubleValue::prod() const {
	return *a * *b;
}

void DoubleValue::resetA(int val) {
	delete a;
	a = new int{ val };
}

void DoubleValue::print() const {
	std::cout << getName() << ": values, sum and prod are: "; // getName() is muszaj, hogy const legyen!!
	std::cout << "(" << *a << ",  " << *b << "), ";
	std::cout << sum() << " and " << prod() << std::endl;
}

TripleValue::TripleValue(std::string name, int a, int b, int c) : ValueType(name) {
	this->a = new int{ a };
	this->b = new int{ b };
	this->c = new int{ c };
}

TripleValue::~TripleValue() {
	std::cout << "Triple value destructor called" << std::endl;
	delete this->a;
	delete this->b;
}

void TripleValue::print() const {
	std::cout << getName() << ": values, sum and prod are: "; // getName() is muszaj, hogy const legyen!!
	std::cout << "(" << *a << ",  " << *b << ", " << *c << "), ";
	std::cout << sum() << " and " << prod() << std::endl;
}

int sum(int a, int b) {
	return a + b;
}

int prod(int a, int b) {
	return a * b;
}
