#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;
	i_error_ = 0.0;
	first_ = true;
}

double PID::UpdateError(double cte) {
	if (first_)
	{
		prev_cte_ = cte;
		first_ = false;
	}

	i_error_ += cte;
	double d_cte = cte - prev_cte_;
	prev_cte_ = cte;
	cout << "d_cte = " << d_cte << endl;
	cout << "P = " << -Kp_ * cte << endl;
	cout << "D = " << -Kd_ * d_cte << endl;
	cout << "I = " << -Ki_ * i_error_ << endl;
	return -Kp_ * cte - Kd_ * d_cte - Ki_ * i_error_;
}

//double PID::TotalError() {
//}

