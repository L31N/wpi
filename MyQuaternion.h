/*
 * MyQuaternion.h
 *
 *  Created on: 13.12.2019
 *      Author: admin
 */

#ifndef MYQUATERNION_H_
#define MYQUATERNION_H_

#include <cstddef>

class MyQuaternion {
public:
	MyQuaternion();
	MyQuaternion(const MyQuaternion &Q);
	MyQuaternion(double a, double b, double c, double d);

	const MyQuaternion operator+ (const MyQuaternion & A) const;
	const MyQuaternion operator- (const MyQuaternion & A) const;
	const double & operator[] (std::size_t const n) const;
	double & operator[] (std::size_t const n);
	MyQuaternion & operator=(const MyQuaternion &c);
	MyQuaternion & operator=(const double value);
	MyQuaternion conj() const;
	const MyQuaternion operator* (const MyQuaternion & c) const;
	const MyQuaternion operator* (const double & value) const;
	virtual ~MyQuaternion();

private:

	double * dataPtr;
};

#endif /* MYQUATERNION_H_ */
