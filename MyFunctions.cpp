/*
 * MyFunctions.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */

#include <cmath>
#include <iostream>
#include "MyFunctions.h"
#define PI 3.14159265

using namespace std;

MyQuaternion quaternion_rotation(double x,double y,double z,double const theta){

  MyQuaternion tmp;
  double sum;

  sum = x + y + z;
  x = x/sum;
  y = y/sum;
  z = z/sum;
  double theta2 = theta * PI/180;
  tmp[0] = x * sin(theta2/2);
  tmp[1] = y * sin(theta2/2);
  tmp[2] = z * sin(theta2/2);
  tmp[3] = cos(theta2/2);

  return tmp;


  
}


MyQuaternion rotateX(MyQuaternion const &X,MyQuaternion const &Q){


	return Q*X*(Q.conj());
}


/*
 *  vorgegeben:
 *
 */
void Qprint(const MyQuaternion &Q,const std::string txt=""){
	cout<<txt<<"("<<Q[0]<<","<<Q[1]<<","<<Q[2]<<","<<Q[3]<<")"<<endl;
}

