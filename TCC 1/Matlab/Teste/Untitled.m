clc; clear all; close all
% variação da distância entre placas
h=0:0.1:20;
% medidas
M_2motor = 0.242;
M1 = 0.155;
M2 = 0.245;
dM_fios =(25)*0.003;
M = 0.062;
M_4barras = 0.252;
M_placa = 0.160;
m = M_2motor+ M1 + M2 + 2*M_placa + M_4barras+ dM_fios;
h1 = 2.1;
d_h1 = 1.0;
d_h2 = 1.5;
d_hb = (3.8-1.5);
hp = 23;
e = 0.3;
R_motor = 1.15;
r = 6.3/2;
r_interno = 5.3/2;
d_eixos = 23;
%calculos
Io_2motor = (M_2motor)*(R_motor^2)/2;
Io_placa = M_placa*(e^2)/12;
Io_M1 = M1*(d_h1^2)/12;
Io_M2 = M2*(d_h2^2)/12;
Io_4barras = M_4barras*(hp).*(hp)/12;
Io_rodas = M*((r+r_interno)/2)^2;
I_2motor = Io_2motor;
I_placa1 = Io_placa + M_placa*(h1^2);
I_M1 = Io_M1 + M1*((h1+d_h1)^2);
I_4barras = Io_4barras + M_4barras*((hp/2)-d_hb).*((hp/2)-d_hb);
I_placa2 = Io_placa + M_placa*((h1+h).*(h1+h));
I_M2 = Io_M2 + M2*((h1+h+d_h2).*(h1+h+d_h2));
I_eixo = I_2motor+I_placa1+I_M1+I_4barras+I_placa2+I_M2;
m_x_l_cm = M_placa*h1 + M1*(h1+d_h1) + M_4barras*(hp/2 -d_hb) + M_placa*(h1+h) + M2*(h+h1+d_h2) + dM_fios*(h1+h/2);
l_cm = (m_x_l_cm)/m;