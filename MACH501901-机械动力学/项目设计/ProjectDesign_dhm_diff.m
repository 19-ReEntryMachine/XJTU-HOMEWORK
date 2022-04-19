clear;clc;
A=1;k=1000;m=10;miu=0.2;g=9.80665;c=0;dt=0.001;T=10;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,c,dt);
[x_1,t_1]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T);
axis on
grid on
hold on
p1=plot(t,x(:,1),'b-');
p2=plot(t_1,x_1(:,1),'g--');
%legend(p2,'有限差分法')
legend([p1,p2],'有限差分法','Duhammel积分法');
title('干摩擦谐振子响应特性（k=1kN/m,m=10kg,x_{0}=1m）')
xlabel('时间t/s')
ylabel('位移x/m')