%%
clc
clear all
close all

%% Defini��o dos Par�metros
syms g Jb Mb L Jw Mw r Rm b Ke Km

g  = 9.81;
Jb = 0.00547151;  Mb = 1.017;  L = 0.096331;
Jw = 0.00445738;  Mw = 0.0844;  r = 0.325;
Rm = 7;  b = 0.002;  Ke = 0.1404;  Km = 0.3922; 

% Momentos de In�rcia deslocado
Jb_barra = Jb + Mb*L^2;
Jw_barra = Jw + Mw*r^2;

%% Par�metros linearizados das matrizes A, B, C, D
den = Rm*(2*Jb_barra*Jw_barra + Jb*Mb*r^2);

sigma = (2*(Rm*b - Ke*Km)*(Jb + Mb*L^2 + Mb*L*r))/den;
tau = (-Mb^2*g*L^2*r^2)*Rm/den;
lambda = (2*(Rm*b - Ke*Km)*(2*Jw + 2*Mw*r^2 + Mb*L*r + Mb*r^2))/(r*den);
psi = (Mb*g*L*(2*Jw + 2*Mw*r^2 + Mb*r^2))/den;

alfa = (2*Km*r*(Jb + Mb*L^2 + Mb*L*r))/den;
beta = (-2*Km*(2*Jw + 2*Mw*r^2 + Mb*r^2 + Mb*L*r))/den;

%% Defini��o das Matrizes A, B, C, D 

% Matrizes dos Estados
A = [0         1        0           0; 
     0     sigma      tau    -r*sigma; 
     0         0        0           1; 
     0   -lambda      psi    r*lambda];
     
%A = [   0          0              1             0; 
    %    0          0              0             1;
   %   psi          0       r*lambda       -lambda; 
    %  tau          0       -r*sigma         sigma];
 
B = [0; alfa; 0; beta];

%B = [0; 0; beta; alfa];

% Matrizes da Sa�da
%C = [0 0 1 0;
     %0 0 0 1];
 
C = [0 0 1 0];

D = 0;

%% Constru��o do Sistema no Espa�o de Estados
sys = ss(A,B,C,D);
Sc = ctrb(sys);
So = obsv(sys);

%% Ganho do LQR (Linear Quadratic Regulator)

Q = [1   0   0    0;
     0   1   0    0;
     0   0  10    0;
     0   0   0  100];
R = 10;
Kr = lqr(A,B,Q,R);


