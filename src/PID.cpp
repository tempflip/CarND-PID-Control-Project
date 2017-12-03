#include "PID.h"
#include <iostream>
#include <math.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double p, double i, double d) {
	params.push_back(p);
	params.push_back(i);
	params.push_back(d);
	// Kp = p;
	// Ki = i;
	// Kd = d;
	s = 0;
	prevCte = 0;
	counter = 0;
	STEPS_PER_SESSION = 100;
	errorSum = 0;
	iSum = 0;
	tD = {0.01, 0.0001, 0.3};
	prevError = 99999999999;
	currentParam = 2;
	sessionCounter = 0;
}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
}

double PID::getSteerValue(double cte, double speed) {
	counter ++;
	double p = params[0];
	double i = params[1];
	double d = params[2];
	//double speedTerm = 1 + speed / 200;

	double pTerm = -1 * cte * (p);
	double dTerm = (prevCte - cte) * d;
	double iTerm;
	if (iSum == 0) iTerm = 0;
	else iTerm = -1/iSum * i;

	// cout << iTerm << endl;

	prevCte = cte;
    errorSum += sqrt(cte*cte);
	iSum += cte;

	s = pTerm + dTerm + iTerm;

	if (counter == STEPS_PER_SESSION) {
		sessionCounter++;
		if (sessionCounter % 4 == 0) switchParam();

		/*
		if (errorSum > prevError) {
			params[currentParam] += tD[currentParam];
			//cout << "## UP!\t" << currentParam << "\t||\t\t" << tD[0] << "\t" << tD[2] << endl;
		} else {
			params[currentParam] -= tD[currentParam] * 2;
			tD[currentParam] = tD[currentParam] / 2;
			//cout << "## DOWN!\t" << currentParam << "\t||\t\t" << tD[0] << "\t" << tD[2] << endl;
		}
		*/
		cout << "prev.error\t" << errorSum 
			<< "\tcurr.P\t" << params[0] 
			<< "\tcurr.D\t" << params[2] 
			;
		cout << "\t\t\ttP\t" << tD[0] << "\ttD\t" << tD[2] << endl;

		prevError = errorSum;
		counter = 0;
		errorSum = 0;
		
		//cout << "------------------------" << endl;
	}

    //std::cout << "c\t" << counter << "\terrorSum\t" << errorSum << "\tp\t" << params[0] << std::endl;

	// cout << "cte\t" << cte << "\tP\t" << pTerm << "\tD\t" << dTerm << endl;
	return s;
}

double PID::getThrottle(double cte, double speed) {
	//cout << cte << "\t\t" << speed << endl;

	if (sqrt(cte * cte) > 0.5) return 0.5;
	if (sqrt(cte * cte) > 1) return 0.3;
	if (sqrt(cte * cte) > 2) return 0;
	return 0.8;
}


void PID::switchParam() {
	return;
	if (currentParam == 0) currentParam = 2;
	else currentParam = 0;
	cout << "### currentParam: " << currentParam << endl;
}

