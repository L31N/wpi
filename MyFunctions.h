/*
 * MyFunctions.h
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */

#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include <string>
#include "MyQuaternion.h"

MyQuaternion quaternion_rotation(double x,double y,double z,double const theta);
MyQuaternion rotateX(MyQuaternion const &X,MyQuaternion const &Q);
void Qprint(const MyQuaternion &,const std::string);


#endif /* MYFUNCTIONS_H_ */

