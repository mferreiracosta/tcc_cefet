%% CONTROLADOR LQG PÊNDULO INVERTIDO - TCC 2 - 2022.1
% Autor: Matheus Ferreira Costa
% Orientador: Luís Filipe 

clc; clear all; close all

%% Definição dos Parâmetros
syms g M_p m z_cm r R kt

% Massa dos componentes
M_1 = 0.1152;
M_2 = 0.1552;
M_3 = 0.1914;
M_2motores = 0.2502;
M_2rodas = 0.062;

g = 9.80665;
r = 0.0315;
R = 0.91;
ke = 0.2729;
km = 0.3902;
z_cm = 0.08362;
J_p = 0.00530429;
J_w = 0.00005013;

Ke_motor = -(km*ke)/R;
K_motor = km/R;

M_p = M_1 + M_2 + M_3 + M_2motores;
m = M_p + M_2rodas;

J_eq = J_p + J_w;

den = J_eq + m*r^2 + M_p*z_cm*(1 + 2*r);

%% Calculando as matrizes do sistema A, B, C e D

A = [      0          1;
     (m*g*z_cm)/den   Ke_motor/den];
B = [0; K_motor/den];
C = [1 0];
D = [0];

sys = ss(A,B,C,D);

%figure('Color',[1 1 1]);
%pzmap(sys)

%% Calculando o rank de controlabilidade e observabilidade do sistema

Sc = ctrb(sys);
So = obsv(sys);

rank_ctrb = rank(Sc);
rank_obsv = rank(So);

%% Escolhendo as matrizes Q e R para calcular o controlador LQR

Q = [1   0;            
     0   1];
 
R = 1;

%% Controlador LQR no Tempo Contínuo

[Kr,S,lambda] = lqr(A,B,Q,R);

%% Construção do Sistema em Espaço de Estados no Tempo Discreto

Ts = 0.01;
sysd = c2d(sys,Ts);

% Matrizes discretas: Ad e Bd, Cd = C e Dd = D
Ad = sysd.a;
Bd = sysd.b;

figure('Color',[1 1 1]);
pzmap(sysd)

%% Construção do controlador LQR no Tempo Discreto

[Krd,S_d,lambda_d] = dlqr(Ad,Bd,Q,R);

%% Construção do LQE - Filtro de Kalman no Tempo Discreto

Qo = 1;                  % matriz de covariância do distúrbio             
Ro = 1;                  % (escalar) covariância do ruído de medição  

% Construção do LQE - Filtro de Kalman
[kalmf,Lf,P] = kalman(sysd,Qo,Ro);

Ld = dlqr(Ad',C',Qo,Ro);
Ld = Ld';

sysKFd = ss(Ad-Lf*C,[Bd Lf],eye(2),zeros(2,2));