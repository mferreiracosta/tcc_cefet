figure(1)
plot(tsim,gyro_Y,'black')
hold on
plot([tsim(1) tsim(end)],[ans ans],'red','LineWidth',1)

%%
tiledlayout(2,1) % Requires R2019b or later

% Top plot
nexttile
plot(tsim,accel_X,'black')
hold on
plot([tsim(1) tsim(end)],[avgAccel_X avgAccel_X],'red','LineWidth',1)
title('Saída do Eixo-X. Média = 806.164')

% Bottom plot
nexttile
plot(tsim,accel_Z,'black')
hold on
plot([tsim(1) tsim(end)],[avgAccel_Z avgAccel_Z],'red','LineWidth',1)
title('Saída do Eixo-Z. Média = 15572')