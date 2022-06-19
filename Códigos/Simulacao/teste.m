%% Resultado da Planta utilizando apenas o LQR
t_lqr       = ResultadoLQR.time(1:500);
pos_lqr     = ResultadoLQR.signals(1).values(1:500);
vel_lqr     = ResultadoLQR.signals(2).values(1:500);
sig_ctr_lqr = SinalControleLQR.signals.values(1:500);

% Figuras das respostas dos Estados theta e dtheta/dt
figure(1);
subplot(2,1,1);
plot(t_lqr,pos_lqr,'blue','linewidth',1)
ylabel('Ângulo (º)');
title('Resposta do Estado \theta');

subplot(2,1,2);
plot(t_lqr,vel_lqr,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Velocidade (º/s)');
title('Resposta do Estado d\theta/dt');

% Figura da resposta do sinal de controle
figure (2);
plot(t_lqr,sig_ctr_lqr,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Tensão (V)');
title('Sinal de Controle U');

%% Resultado da Planta utilizando o LQG sem Ruído ou Distúrbio
t_lqg       = ResultadoLQG.time(1:500);
pos_lqg     = ResultadoLQG.signals(1).values(1:500);
vel_lqg     = ResultadoLQG.signals(2).values(1:500);
sig_ctr_lqg = SinalControleLQG.signals.values(1:500);

figure(3);
subplot(2,1,1);
plot(t_lqg,pos_lqg,'blue','linewidth',1)
ylabel('Ângulo (º)');
title('Resposta do Estado \theta');

subplot(2,1,2);
plot(t_lqg,vel_lqg,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Velocidade (º/s)');
title('Resposta do Estado d\theta/dt');

% Figura da resposta do sinal de controle
figure (4);
plot(t_lqg,sig_ctr_lqg,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Tensão (V)');
title('Sinal de Controle U');

%%
t_lqg_real       = ResultadoLQGreal.time(1:5000);

pos_lqr_real     = ResultadoLQRreal.signals(1).values(1:5000);
vel_lqr_real     = ResultadoLQRreal.signals(2).values(1:5000);
sig_ctr_lqr_real = SinalControleLQRreal.signals.values(1:5000);

pos_lqg_real     = ResultadoLQGreal.signals(1).values(1:5000);
vel_lqg_real     = ResultadoLQGreal.signals(2).values(1:5000);
sig_ctr_lqg_real = SinalControleLQGreal.signals.values(1:5000);
sig_ruido_branco = SinalRuidoMedicao.signals.values(1:5000);

figure(5);
subplot(2,1,1);
plot(t_lqg_real,pos_lqg_real,'blue','linewidth',1)
ylabel('Ângulo (º)');
title('Resposta do Estado \theta');

subplot(2,1,2);
plot(t_lqg_real,vel_lqg_real,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Velocidade (º/s)');
title('Resposta do Estado d\theta/dt');

% Figura da resposta do sinal de controle
figure (6);
plot(t_lqg_real,sig_ctr_lqg_real,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Tensão (V)');
title('Sinal de Controle U');

% Figura da resposta do sinal de controle
figure (7);
plot(t_lqg_real,sig_ruido_branco,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Graus (º)');
title('Sinal do Ruído de Medição Inserido');

figure(8);
subplot(2,1,1);
plot(t_lqg_real,pos_lqr_real,'blue','linewidth',1)
ylabel('Ângulo (º)');
title('Resposta do Estado \theta');

subplot(2,1,2);
plot(t_lqg_real,vel_lqr_real,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Velocidade (º/s)');
title('Resposta do Estado d\theta/dt');

figure (9);
plot(t_lqg_real,sig_ctr_lqr_real,'blue','linewidth',1);
xlabel('Tempo (s)');
ylabel('Tensão (V)');
title('Sinal de Controle U');