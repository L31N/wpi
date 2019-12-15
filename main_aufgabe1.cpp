/*
 * main_aufgabe1.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */

#include<iostream>
#include"MyQuaternion.h"

using namespace std;


void eine_test_funktion(const MyQuaternion & Q){
	cout<<"Information in Funktion: Komponenten von Q "<<endl;
	for(auto i=0;i<4;i++) cout<<Q[i]<<" ";
	cout<<endl<<"-------------------------------------------"<<endl;
}

void Qprint(const MyQuaternion &Q,std::string txt=""){
	cout<<txt<<"("<<Q[0]<<","<<Q[1]<<","<<Q[2]<<","<<Q[3]<<")"<<endl;
}

int main(int argc, char **argv) {
	// test Aufgabe1
	MyQuaternion QA(1.,2.,3.,4.);
	MyQuaternion QB;

	cout<<"Ausgabe Aufgabe 1: zu kopierender Abschnitt beginnt"<<endl<<endl;

	Qprint(QA,"QA=");

	cout<<endl;

	QB=QA+QA.conj();
	Qprint(QB,"QB=QA+QA.conj()     =");
	cout<<endl;

	QB=(QA-QA.conj())*2.;
	Qprint(QB,"QB=(QA-QA.conj())*2.=");
	cout<<endl;

	MyQuaternion QC(QA+QB);
	Qprint(QC,"QC=");


	QC=QA*QB;
	Qprint(QC,"QC=QA*QB= ");
	cout<<endl;

	for(auto i=0; i<4; i++) QC[i]=double(rand())/double(RAND_MAX);
	Qprint(QC,"QC rand = ");
	cout<<endl;

	eine_test_funktion(QC);
	QC=1.;

	eine_test_funktion(QC);
	cout<<"Ende des Ergebnisteils =============="<<endl;

	return 0;
}



