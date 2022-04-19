clear;clc;
A=1;k=1000;m=10;miu=0.2;g=9.80665;c=0;dt=0.001;T=10;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,c,dt);
p1=FrictionDynamic_sine(A,k,m,miu);
%[x_1,t_1]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T);
axis on
grid on
hold on
p2=plot(t,x(:,1),'g--');
%legend(p2,'���޲�ַ�')
legend([p1(1),p2],'���Ǻ������ʷ�','���޲�ַ�');
title('��Ħ��г������Ӧ���ԣ�k=1kN/m,m=10kg,x_{0}=1m��')
xlabel('ʱ��t/s')
ylabel('λ��x/m')