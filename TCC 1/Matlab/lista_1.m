%lista 1 - Controle Moderno
clear
clc
format short
%pontos de operação
sp_h2 = input('Digite a altura do tanque 2 : ');
s_c = sqrt((2.6*sqrt(sp_h2)-0.03)/(2.617e-4));
sp_h1 = (2.6*sqrt(sp_h2)/6.78)^2+sp_h2;

syms h1 h2 u
%opções de simulação
t1 = 0:0.01:10;
t2 = 10:0.01:20;
tt = 0:0.01:20.01;
J = tf(1);
op2 = stepDataOptions('StepAmplitude',83.1294 - s_c);
op1 = stepDataOptions('StepAmplitude',61.0998 - s_c);
u1 = step(J,op1,t1);
u2 = step(J,op2,t2);
uf = [u1;u2];

%condições de contorno
q1 = 2.617e-4*(u^2) + 0.03;
q12 = 6.78*sqrt(abs(h1 - h2));
q0 = 2.6*sqrt(abs(h2));
 
%seleção dos modelos equações diferenciais
if(0<=sp_h1 && sp_h1<0.05 || sp_h1>0.95)
    f1 = (q1 - q12)/pi;
else
    f1 = (q1 - q12)/((h1^2 - h1 + 0.2975)*pi);
end
if(0<=sp_h2 && sp_h2<0.1)
    f2 = (q12 - q0)/pi;
else
    f2 = (q12 - q0)/((-h2^2 - 0.4*h2 + 2.21)*(pi/9));
end
% %análise não linear
% int1 = sp_h1;
% int2 = sp_h2;
% ynl = 0:0.01:20.01;
% figure
% for i=1:size(uf,1)
%      ynl(i) = int2;
%      diffh1 = double(subs(f1,[h1 h2 u],[int1,int2,uf(i)+s_c]));
%      diffh2 = double(subs(f2,[h1 h2],[int1 int2]));
%      int1 = int1 + diffh1*0.01;
%      int2 = int2 + diffh2*0.01;
% end

%jacobiano
A = double(subs(jacobian([f1;f2],[h1 h2]),[h1 h2 u],[sp_h1 sp_h2 s_c]));
B = double(subs(jacobian([f1;f2],u),[h1 h2 u],[sp_h1 sp_h2 s_c]));
%observação do estado 2 - h2
C = [0 1];
D = 0;
tanque = ss(A,B,C,D); 

%parte linear do sistema
Ylinear = lsim(tanque,uf,tt) + sp_h2;
plot(tt,Ylinear);
hold on
%plot(tt,ynl');

% erro_max = abs(max(ynl'-Ylinear));