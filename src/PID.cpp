#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/
#define TIMESTEP_S (0.02) // timestep
PID::PID() {}

PID::~PID() {}
static double prev_cte = 0;
void PID::Init(double Kp, double Ki, double Kd)
{
    // Initialize coefficients and errors.
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte)
{
    // Proportional part of error is proportional to the cross track error
    p_error = cte * Kp;
    // Integral part of error is proportional to the integral of the cross track error
    i_error += cte * Ki * TIMESTEP_S;
    // Derivative part of error is proportional to the derivative of the cross track error
    d_error = (cte - prev_cte)/TIMESTEP_S * Kd;
    prev_cte = cte;
}

double PID::TotalError()
{
    return p_error + i_error + d_error;
}
