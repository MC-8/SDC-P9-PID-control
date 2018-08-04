#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/
#define TIMESTEP_S (0.001) // myTODO time?
PID::PID() {}

PID::~PID() {}
static double prev_cte = 0;
void PID::Init(double Kp, double Ki, double Kd)
{
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte)
{
    p_error = cte * Kp;
    i_error += cte * Ki * TIMESTEP_S;
    d_error = (cte - prev_cte)/TIMESTEP_S * Kd;
    prev_cte = cte;
}

double PID::TotalError()
{
    return p_error + i_error + d_error;
}
