%% PROGRAMA P�NDULO INVERTIDO - TCC 1 - 2019.1
% Autor: Matheus Ferreira Costa
% Orientador: Lu�s Filipe 

clc; clear all; close all

%% Defini��o dos Par�metros
syms g Jb Mb L Jw Mw r Rm b Ke Km

g  = 9.81;
Jb = ;  Mb = 0.797;  L = 0.0752;
Jw = 0.00011479;  Mw = 0.033;  r = 0.033;
Rm = 0.92;  b = 0.002;  Ke = 0.2729;  Km = 0.54;

% Momentos de In�rcia deslocado
Jb_barra = Jb + Mb*L^2;
Jw_barra = Jw + Mw*r^2;

%% Par�metros linearizados das matrizes A, B, C, D
den = Ra*(2*Jb_barra*Jw_barra + Jb*Mb*r^2);

sigma = (2*(Rm*b - Ke*Km)*(Jb + Mb*L^2 + Mb*L*r))/den;
tau = (-Mb^2*g*L^2*r^2)*Rm/den;
lambda = (2*(Rm*b - Ke*Km)*(2*Jw + 2*Mw*r^2 + Mb*L*r + Mb*r^2))/(r*den);
psi = (Mb*g*L*(2*Jw + 2*Mw*r^2 + Mb*r^2))/den;

alfa = (2*Km*r*(Jb + Mb*L^2 + Mb*L*r))/den;
beta = (-2*Km*(2*Jw + 2*Mw*r^2 + Mb*r^2 + Mb*L*r))/den;

%% Defini��o das Matrizes A, B, C, D 

A = [  sigma      tau    -r*sigma; 
           0        0           1; 
     -lambda      psi    r*lambda];
  
B = [alfa; 0; beta];

C = [0 1 0];

D = zeros(size(C,1),size(B,2));

%% Constru��o do Sistema em Espa�o de Estados no Tempo Cont�nuo
sys = ss(A,B,C,D);
Sc = ctrb(sys);
So = obsv(sys);

%% Escolha das matrizes Q e R:
Q = [1   0   0;     % Considerando Q = C'C
     0   1   0; 
     0   0   1;];
R = 1;

%% Constru��o do Sistema em Espa�o de Estados no Tempo Discreto
Ts = 0.015;
sysd = c2d(sys,Ts);

% Matrizes discretas: Ad e Bd, Cd = C e Dd = D
Ad = sysd.a;
Bd = sysd.b;

%% Controlador LQR e do Estimador LQE

% LQR Discreto
[Krd,Pd,Erd] = dlqr(Ad,Bd,Q,R);

% Sistema aumentado inserindo dist�rbio e ru�do
Qo = .1*eye(3);  % matriz de covari�ncia do dist�rbio             
Ro = 1;          % (escalar) covari�ncia do ru�do de medi��o  

% Constru��o do LQE - Filtro de Kalman
[Ld,Sd,Z,Ed] = dlqe(Ad,Qo,C,Qo,Ro);  % Comando do estimador linear quadr�tico discreto

sysKFd = ss(Ad-Ld*C,[Bd Ld],eye(3),0*[Bd Ld]);

%% Controlador LQR (Linear Quadratic Regulator)
[Kr,P,Er] = lqr(A,B,Q,R);   %Kr = ganho do LQR
                            % P = solu��o da equa��o de Riccati
                            %Er = closed-loop eigenvalues Er = EIG(A-B*K)

%% Sistema aumentado inserindo dist�rbio e ru�do
Wd = .1*eye(3);  % matriz de covari�ncia do dist�rbio             xdot = Ax + Bu + Wd*d + 0*n         BF = [B Wd 0][u; d; n]
Vn = 1;          % (escalar) covari�ncia do ru�do de medi��o         y = Cx + (Du + 0*d + Vn*n)    D_aum = [0 0 Vn][u; d; n]

BF = [B Wd 0*B];

sysC = ss(A,BF,C,[0 0 0 0 Vn]); % Sistema no Espa�o de Estados com dist�rbio e ru�do

sysFullOutput = ss(A,BF,eye(3),zeros(3,size(BF,2))); % Sitema no SS com todos estados medidos, dist�rbio e sem ru�do

%% Constru��o do LQE - Filtro de Kalman
[L,S,E] = lqe(A,Wd,C,Wd,Vn);  % Comando do estimador linear quadr�tico
%L = (lqr(A',C',Wd,Vn))';      % Outra possibilidade para encontrar o ganho do Filtro de Kalman (LQE)

sysKF = ss(A-L*C,[B L],eye(3),0*[B L]);




