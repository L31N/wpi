/*
 * main_aufgabe3.cpp
 *
 *  Created on: 09.12.2019
 *      Author: DWeygand IAM-CMS
 */
// ggf hilfreiche Bibliotheken....
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>
#include <vector>
#include <array>
#include <cassert>

#include "MyQuaternion.h"
#include "MyFunctions.h"
using namespace std;

// Abkuerzungen fuer Datentypen:
typedef std::array<double,4> Vec4d;

// for seed of random number generator in C++11
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> zufall(-1.,1.); //C++11 documentation
//http://www.cplusplus.com/reference/random/uniform_real_distribution/

//Hilfsfunktion fuer random_vec4d:
void zufall_in_einheitskreis(double &a, double &b, double &s){
	do{
		a = zufall(mt);
		b = zufall(mt);
		s = (a*a+b*b);
	}while(s>=1.);
}

// Algorithm 4 of Marsaglia paper, The Annals of Math. Stat. 1972,645-6
// random point on a surface
// hier: Methode 4: point on unit 4d-sphere
//
void random_vec4d(Vec4d &Q){
	double v1,v2,v3,v4,s1,s2;
	zufall_in_einheitskreis(v1,v2,s1);
	zufall_in_einheitskreis(v3,v4,s2);
	//
	const double tmp = sqrt(max(0.,(1.-s1))/s2);
	Q[0]= v1;
	Q[1]= v2;
	Q[2]= v3*tmp;
	Q[3]= v4*tmp;
}


// Aufgabe 3.2.A:
double get_theta(const MyQuaternion &Q){
	return 2*acos(Q[3]);

	/// TODO: should also the axis be calculated ?
}


//Aufgabe 3.2.B:
double get_theta_cubic(const MyQuaternion &Q){
	double e[4] = {Q[0], Q[1], Q[2], Q[3]};
	std::sort(std::begin(e), std::end(e));

    MyQuaternion q1(e[0], e[1], e[2], e[3]);
    MyQuaternion q2((e[0]-e[1])/sqrt(2), (e[0]+e[1])/sqrt(2), (e[2]-e[3])/sqrt(2), (e[2]+e[3])/sqrt(2));
    MyQuaternion q3((e[0]-e[1]-e[3]+e[2])/2, (e[1]-e[3]-e[2]+e[0])/2, (e[2]-e[3]-e[0]+e[1])/2, (e[3]+e[0]+e[1]+e[2])/2);

    // find the smallest rotation angle
    double theta[3] = {get_theta(q1), get_theta(q2), get_theta(q3)};
    std::sort(std::begin(theta), std::end(theta));

    // return the smallest angle
    return theta[0];
}


//

int main(){
	//generate data:
	Vec4d tmp;
	int nmax;

	do{
		cout<<"Anzahl der Zufallsorientierungen eingeben:";
		cin>>nmax;
	}while(nmax<1);

	std::vector<MyQuaternion> QL(nmax);

	//random Initialisierung:
	for (unsigned int i = 0; i < nmax; i++) {
        random_vec4d(tmp);
        MyQuaternion quaternion(tmp[0], tmp[1], tmp[2], tmp[3]);
        QL[i] = (quaternion);
        //Qprint(quaternion, "new random quaternion");
	}

	//AUFGABE 3:

	//TEIL A)
	cout<<"Aufgabe A:"<<endl;

	std::ofstream ofs_ergebnis_random("ergebnis_random.dat");
	if (!ofs_ergebnis_random.is_open()) {
        std::cerr << "could not open output file..." << std::endl;
        return -1;
	}

	unsigned int histogram[180] = {0};
	unsigned int entries = 0;

    for (int i = 0; i < nmax; i++) {
        for (int j = i+1; j < nmax; j++) {
            if (i != j) {
                double misorientation = get_theta(QL[j]*QL[i].conj())/(2*M_PI)*360;
                ofs_ergebnis_random << misorientation << std::endl;
                //std::cout << "misorientation: " << misorientation << std::endl;

                histogram[(int)(misorientation/2)]++; // increment number of box
                entries++;
            }
        }
    }
    std::cout << "Note: wrote file 'ergebnis_random.dat'" << std::endl;
    ofs_ergebnis_random.close();

    // print histogram to file
    std::ofstream ofs_hist_random("hist_random.dat");
    if (!ofs_hist_random.is_open()) {
        std::cerr << "could not open output file..." << std::endl;
        return -1;
    }

    for (int i = 0; i < 180; i++) {
            if (histogram[i] != 0)
            ofs_hist_random << i*2+1 << " " << (double)(histogram[i])/entries << std::endl;
    }
    std::cout << "Note: wrote file 'hist_random.dat'" << std::endl;
    ofs_hist_random.close();







	//TEIL B)
	cout<<"Aufgabe B:"<<endl;

	std::ofstream ofs_ergebnis_cube("ergebnis_cube.dat");
	if (!ofs_ergebnis_cube.is_open()) {
        std::cerr << "could not open output file..." << std::endl;
        return -1;
	}

	histogram[180] = {0};

    for (int i = 0; i < nmax; i++) {
        for (int j = i+1; j < nmax; j++) {
            if (i != j) {
                double misorientation = get_theta_cubic(QL[j]*QL[i].conj())/(2*M_PI)*360;
                ofs_ergebnis_cube << misorientation << std::endl;

                histogram[(int)(misorientation/2)]++; // increment number of box
            }
        }
    }
    std::cout << "Note: wrote file 'ergebnis_cube.dat'" << std::endl;
    ofs_ergebnis_cube.close();

    // print histogram to file
    std::ofstream ofs_hist_cube("hist_cube.dat");
    if (!ofs_hist_cube.is_open()) {
        std::cerr << "could not open output file..." << std::endl;
        return -1;
    }

    for (int i = 0; i < 180; i++) {
            if (histogram[i] != 0)
            ofs_hist_cube << i*2+1 << " " << (double)(histogram[i])/entries << std::endl;
    }
    std::cout << "Note: wrote file 'hist_cube.dat'" << std::endl;
    ofs_hist_cube.close();

	cout<<"DONE"<<endl;

	return 0;
}

