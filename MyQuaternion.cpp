/*
 * MyQuaternion.cpp
 *
 *  Created on: 13.12.2019
 *      Author: admin
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include <cassert>

#include "MyQuaternion.h"

MyQuaternion::MyQuaternion() {
	this->dataPtr = new double[4];
}

MyQuaternion::MyQuaternion(const MyQuaternion &Q) {
	this->dataPtr = new double[4];
	for (std::size_t i=0;i<4;i++)
		this->dataPtr[i] = Q.dataPtr[i];
}

MyQuaternion::MyQuaternion(double a, double b, double c, double d) {
	this->dataPtr = new double[4];
	this->dataPtr[0] = a;
	this->dataPtr[1] = b;
	this->dataPtr[2] = c;
	this->dataPtr[3] = d;
}

MyQuaternion::~MyQuaternion() {
	delete [] this->dataPtr;
}

MyQuaternion & MyQuaternion::operator =(const MyQuaternion & c){

	for (std::size_t i=0;i<4;i++)
		this->dataPtr[i] = c.dataPtr[i];

	return *this;
}

MyQuaternion & MyQuaternion::operator =(const double value){

	for (std::size_t i=0;i<4;i++)
		this->dataPtr[i] = value;

	return *this;
}

const MyQuaternion MyQuaternion::operator+ (const MyQuaternion &A) const{

	MyQuaternion tmp;

	for (std::size_t i=0;i<4;i++)
		tmp.dataPtr[i] = this->dataPtr[i] + A.dataPtr[i];

	return tmp;
}

const MyQuaternion MyQuaternion::operator- (const MyQuaternion &A) const{

	MyQuaternion tmp;

	for (std::size_t i=0;i<4;i++)
		tmp[i] = this->dataPtr[i] - A.dataPtr[i];

	return tmp;
}

double & MyQuaternion::operator[] (std::size_t const n){
	assert(n<4);

	return this->dataPtr[n];
}

const double & MyQuaternion::operator[] (std::size_t const n) const{
	assert(n<4);
	return this->dataPtr[n];
}

const MyQuaternion MyQuaternion::operator* (const MyQuaternion & c) const{

	MyQuaternion tmp;
	double e1a = this->dataPtr[0];
	double e2a = this->dataPtr[1];
	double e3a = this->dataPtr[2];
	double e4a = this->dataPtr[3];
	double e1b = c.dataPtr[0];
	double e2b = c.dataPtr[1];
	double e3b = c.dataPtr[2];
	double e4b = c.dataPtr[3];
	tmp[0] = e1a*e4b + e4a*e1b - e2a*e3b + e3a*e2b;
	tmp[1] = e2a*e4b + e4a*e2b - e3a*e1b + e1a*e3b;
	tmp[2] = e3a*e4b + e4a*e3b - e1a*e2b + e2a*e1b;
	tmp[3] = e4a*e4b - e1a*e1b - e2a*e2b - e3a*e3b;

	return tmp;

}

const MyQuaternion MyQuaternion::operator* (const double & value) const{

	MyQuaternion tmp;

	for (std::size_t i=0;i<3;++i)
        tmp[i] = this->dataPtr[i] * value;

    return tmp;
}

MyQuaternion MyQuaternion::conj() const{

	MyQuaternion tmp;

	tmp[0] = -1 * this->dataPtr[0];
	tmp[1] = -1 * this->dataPtr[1];
	tmp[2] = -1 * this->dataPtr[2];
	tmp[3] =  this->dataPtr[3];

	return tmp;

}
