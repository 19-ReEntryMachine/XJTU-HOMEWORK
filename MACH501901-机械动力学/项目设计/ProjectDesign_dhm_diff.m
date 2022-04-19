clear;clc;
A=1;k=1000;m=10;miu=0.2;g=9.80665;c=0;dt=0.001;T=10;
[x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,c,dt);
[x_1,t_1]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T);
axis on
grid on
hold on
p1=plot(t,x(:,1),'b-');
p2=plot(t_1,x_1(:,1),'g--');
%legend(p2,'���޲�ַ�')
legend([p1,p2],'���޲�ַ�','Duhammel���ַ�');
title('��Ħ��г������Ӧ���ԣ�k=1kN/m,m=10kg,x_{0}=1m��')
xlabel('ʱ��t/s')
ylabel('λ��x/m')