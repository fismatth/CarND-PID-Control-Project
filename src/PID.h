#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double i_error_;

  /*
  * Coefficients
  */ 
  double Kp_;
  double Ki_;
  double Kd_;

  double prev_cte_;
  bool first_;

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
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  double UpdateError(double cte);
};

#endif /* PID_H */
