#include "PID.h"
#include <iostream>
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init() {
	Kp = 0.5;
	Ki = 0.1;
	Kd = 0.1;
	s = 0;
	prevCte = 0;
}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
}

double PID::getSteerValue(double cte, double speed) {
	double pTerm = -1 * cte * (Kp);
	double dTerm = (prevCte - cte) * Kd;
	
	prevCte = cte;
	
	s = pTerm + dTerm;

	std::cout << "P\t" << pTerm << "\tD\t" << dTerm << "\ts\t" << s << std::endl;
	return s;
}

