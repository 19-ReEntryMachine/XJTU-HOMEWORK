clear;clc;
A=1;k=1000;m=10;miu=0.1;g=9.80665;c=0;dt=0.001;T=20;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,c,dt);
[x_1,v_1,a_1,t_1]=FrictionDynamic_diffeqs(A,k,m,2*miu,c,dt);
[x_2,v_2,a_2,t_2]=FrictionDynamic_diffeqs(A,k,m,3*miu,c,dt);
%[x_1,t_1]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T);
p1=plot(t,x(:,1),'b-');
axis on
grid on
hold on
p2=plot(t_1,x_1(:,1),'k-');
p3=plot(t_2,x_2(:,1),'r-');
legend([p1,p2,p3],'\mu=0.1','\mu=0,2','\mu=0.3');
title('不同动摩擦因数下干摩擦谐振子响应特性（k=1kN/m,m=10kg,x_{0}=1m）')
xlabel('时间t/s')
ylabel('位移x/m')
%KK=4*miu*m*g/k/(2*pi*sqrt(m/k));
%plot([0 A/KK],[A 0],'b--');
%plot([0 A/KK],[-A 0],'b--');