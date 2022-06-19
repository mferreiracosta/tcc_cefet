%% CÁLCULOS DOS PARÂMETROS MECÂNICOS DO PIDR - TCC 2 - 2022.1
% Autor: Matheus Ferreira Costa
% Orientador: Luís Filipe 

clc; clear all; close all

% Medidas de distâncias estão em centímetros (cm)
% Medidas de massa estão em quilogramas (kg)

% Largura das placas M1, M2 e M3 é uma constante como visto
W_placa = 8.0;

% Altura total das placas M1, M2 e M3 com seus respectivos componentes
h_1 = 0.8;
h_2 = 1.2;
h_3 = 2.0;

% Distâncias entre placas e o eixo que passa pelo motor
d_eixo_h1 = 1.5;
d_eixo_h2 = 12;
d_eixo_h3 = 18;

% Raio do motor e das rodas
r_motor = 1.25;
r_ext_roda = 3.15;
r_int_roda = 2.5;

% Massa total de cada conjunto que compõe a planta física
M_1 = 0.1152;
M_2 = 0.1552;
M_3 = 0.1914;
M_2motores = 0.2502;
M_2rodas = 0.062;

% Massa total da planta desconsiderando apenas as duas rodas
m = M_1 + M_2 + M_3 + M_2motores;

% Cálculos Momentos de Inércia das formas geométricas genericamente
Io_M1 = M_1*(h_1^2 + W_placa^2)/12;
Io_M2 = M_2*(h_2^2 + W_placa^2)/12;
Io_M3 = M_3*(h_3^2 + W_placa^2)/12;
Io_2motores = (M_2motores)*(r_motor^2)/2;
Io_rodas = M_2rodas*(r_ext_roda^2 + r_int_roda^2)/2;

% Cálculos Momentos de Inércia utilizando o Teorema dos Eixos Paralelos
I_M1 = Io_M1 + M_1*(d_eixo_h1.^2);
I_M2 = Io_M2 + M_2*((h_2+d_eixo_h2).*(h_2+d_eixo_h2));
I_M3 = Io_M3 + M_3*((h_3+d_eixo_h3).*(h_3+d_eixo_h3));
I_2motores = Io_2motores;

% Momento de inércia como um todo da planta, considerando o momento dos 
% motores e das placas com seus componentes, como é visto abaixo
I_eixo = I_2motores + I_M1 + I_M2 + I_M3;

% Cáclculo do centro de massa da planta
m_x_z_cm = M_1*(d_eixo_h1) + M_2*(h_2+d_eixo_h2) + M_3*(h_3+d_eixo_h3);
z_cm = (m_x_z_cm)/m;

% Cálculo do momento de inércia das rodas e da parte em balanço da planta
J_w = (1/2)*(M_2rodas)*(r_ext_roda^2 + r_int_roda^2);
J_p = I_eixo - m*z_cm^2;


%%
%d_eixo_h2 = 0:0.1:12;
%d_eixo_h3 = 0:0.1:17.5;
%m_x_l_cm = M_1*(d_eixo_h1) + mean(M_2*(h_2+d_eixo_h2)) + mean(M_3*(h_3+d_eixo_h3));
%I_M2 = mean(Io_M2 + M_2*((h_2+d_eixo_h2).*(h_2+d_eixo_h2)));
%I_M3 = mean(Io_M3 + M_3*((h_3+d_eixo_h3).*(h_3+d_eixo_h3)));

