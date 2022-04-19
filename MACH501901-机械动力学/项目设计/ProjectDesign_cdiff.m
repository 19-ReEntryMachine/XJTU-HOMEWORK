clear;clc;
A=1;k=1000;m=10;miu=0.1;g=9.80665;c=2*sqrt(k*m);dt=0.001;T=20;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,0.1*c,dt);
[x_1,v_1,a_1,t_1]=FrictionDynamic_diffeqs(A,k,m,miu,0.2*c,dt);
[x_2,v_2,a_2,t_2]=FrictionDynamic_diffeqs(A,k,m,miu,0.3*c,dt);
p1=plot(t,x(:,1),'b-');
axis on
grid on
hold on
p2=plot(t_1,x_1(:,1),'r-');
p3=plot(t_2,x_2(:,1),'k-');
title('含阻尼干摩擦谐振子自由响应特性（k=1kN/m,m=10kg,x_{0}=1m,\mu=0.1）')
xlabel('时间t/s')
ylabel('位移x/m')
KK=4*miu*m*g/k/(2*pi*sqrt(m/k));
%p2=plot([0 A/KK],[A 0],'b--');
%p3=plot([0 A/KK],[-A 0],'r--');
legend([p1,p2,p3],'\zeta=0.1','\zeta=0.2','\zeta=0.3');