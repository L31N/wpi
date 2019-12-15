/*
 * main_aufgabe2.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */

#include <iostream>
#include <cmath>
#include "MyQuaternion.h"
#include "MyFunctions.h"

using namespace std;

int main(){
	//Aufgabe 2 =======
	MyQuaternion X,QR,XP;
	double x,y,z,theta;

	cout<<"Ortsvektor eingeben:";

	for(auto i=0;i<3;i++) cin>>X[i];
	X[3]=0.;

	cout<<"Rotation: Achsenrichtung (wird normiert)"<<endl;
	cin>>x>>y>>z;
	cout<<"Winkel [Grad]"<<endl;
	cin>>theta;

	Qprint(X,"Quaternion X=");
	QR=quaternion_rotation(x,y,z,theta);
	Qprint(QR,"QR=");

	XP=rotateX(X,QR);
	Qprint(XP,"XP=");

	return 0;
}



