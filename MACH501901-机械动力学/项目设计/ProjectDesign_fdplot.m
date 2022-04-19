clear;clc;
A=1;k=1000;m=10;miu=0.1;g=9.80665;c=0;dt=0.001;T=20;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,c,dt);
%[x_1,t_1]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T);
p1=plot(t,x(:,1),'b-');
axis on
grid on
hold on
title('干摩擦谐振子自由响应特性（k=1kN/m,m=10kg,x_{0}=1m,\mu=0.1）')
xlabel('时间t/s')
ylabel('位移x/m')
KK=4*miu*m*g/k/(2*pi*sqrt(m/k));
p2=plot([0 A/KK],[A 0],'b--');
p3=plot([0 A/KK],[-A 0],'r--');
legend([p1,p2,p3],'谐振子响应','上渐近线','下渐近线');