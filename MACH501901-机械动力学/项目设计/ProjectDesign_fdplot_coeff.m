clear;clc;
A=1;k=1000;m=10;miu=0.1;g=9.80665;c=2*sqrt(k*m);dt=0.001;T=20;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,0.05*c,dt);
%[x_1,t_1]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T);
p1=plot(t,x(:,1),'b-');
axis on
grid on
hold on
title('干摩擦谐振子响应特性（k=1kN/m,m=10kg,x_{0}=1m,\mu=0.1,\zeta=0.05）')
xlabel('时间t/s')
ylabel('位移x/m')
asy=zeros(10,1);n=1;asy(1)=A;
while asy(n)>0.02
    n=n+1;
    asy(n)=A*exp(-0.05*sqrt(k/m)*t(n))*(1-t(n)*2*miu*m*g/(A*pi*sqrt(k*m)));
end
p2=plot(t(1:n),asy,'r--');
p3=plot(t(1:n),-asy,'r--');
    