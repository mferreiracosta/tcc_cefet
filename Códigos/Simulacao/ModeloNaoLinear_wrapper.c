
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
 * Output function
 *
 */
void ModeloNaoLinear_Outputs_wrapper(const real_T *u0,
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
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Derivatives function
 *
 */
void ModeloNaoLinear_Derivatives_wrapper(const real_T *u0,
			real_T *y0,
			real_T *dx,
			real_T *xC)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
double M_1 = 0.1152;
double M_2 = 0.1552;
double M_3 = 0.1914;
double M_2motores = 0.2502;
double M_2rodas = 0.062;

double g = 9.80665;
double r = 0.0315;
double R = 0.91;
double ke = 0.2729;
double kt = 0.3902;
double z_cm = 0.08362;
double J_p = 0.00530429;
double J_w = 0.00005013;

double M_p, m, K_m, K_e;

double a, b;

double Sy, Cy;

M_p = M_1 + M_2 + M_3 + M_2motores;
m = M_p + M_2rodas;

K_e = -(kt*ke)/R;
K_m = kt/R;

a = (J_p + J_w) + m*r*r + M_p*z_cm;
b = 2*M_p*r*z_cm;

Sy = sin(xC[0]);
Cy = cos(xC[0]);

dx[0] = xC[1];
dx[1] = ((K_m*u0[0] + K_e*xC[1]) + (M_p*z_cm*r*Sy)*(xC[1]*xC[1]) + m*g*z_cm*Sy)/(a + b*Cy);
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}

