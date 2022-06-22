

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void penduloinvertido_naolinear_Outputs_wrapper(const real_T *u0,
			real_T *y0,
			const real_T *xC)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
y0[0] = xC[0];
y0[1] = xC[1];
y0[2] = xC[2];
y0[3] = xC[3];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Derivatives function
 *
 */
void penduloinvertido_naolinear_Derivatives_wrapper(const real_T *u0,
			real_T *y0,
			real_T *dx,
			real_T *xC)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
double g = -9.81;
double Mb = 1.017;
double Mw = 0.0844;
double L = 0.096331;
double Jb = 0.00547151;
double Jw = 0.00445738;
double r = 0.325;
double Rm = 7;
double b = 0.002;
double Ke = 0.1404;
double Km = 0.3922;
double Sy;
double Cy;
double den;

double omega;
double psi;
double Delta;

double upsilon;
double Zeta;
double Phi;

Sy = sin(xC[2]);
Cy = cos(xC[2]);

den = Rm*(2*((Jw + Mw*r*r)*(Jb + Mb*L*L))+(Jb*Mb*r*r)+((Mb*L*r)*(Mb*L*r)*(1-Cy*Cy)));

omega = 2*r(Rm*b - Km*Ke)*(Jb + Mb*L*L + Mb*L*r*Cy);
psi = (-Mb*Mb*g*L*L*r*r)*Sy*Cy;
Delta = (2*Km*r(Jb + Mb*L*L + Mb*L*r*Cy));

upsilon = 2*(Rm*b - Km*Ke)*(2*Jw + Mb*L*r*Cy + r*r(2*Mw + Mb));
Zeta = Mb*g*L*Sy*(2*Jw + r*r*(2*Mw + Mb));
Phi = -2*Km*(2*Jw + Mb*L*r*Cy + r*r(2*Mw + Mb));

dx[0] = xC[1];
dx[1] = (omega/(r*den))*xC[1] - (omega/den)*xC[3] + psi/den + (Delta/den)*u0[0];
dx[2] = xC[3];
dx[3] = (upsilon/den)*xC[3] - (upsilon/(r*den))*xC[1] + Zeta/den + (Phi/den)*u0[0]



/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}
