#ifndef PID_H
#define PID_H
#include <iostream>
#include <vector>
using namespace std;

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  //double Kp;
  //double Ki;
  //double Kd;
  double s;
  double prevCte;
  int counter;
  int STEPS_PER_SESSION;
  double errorSum;
  double prevError;
  double iSum;
  int currentParam;
  int sessionCounter;
  
  std::vector<double> params;
  std::vector<double> tD;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double p, double i, double d);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double getSteerValue(double cte, double speed);

  double getThrottle(double cte, double speed);


  void switchParam();
};

#endif /* PID_H */
