#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
	Kp = p;
	Ki = i;
	Kd = d;
	s = 0;
}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
}

double PID::getSteerValue(double cte) {
	s -= cte * Kp;
	return s;
}

