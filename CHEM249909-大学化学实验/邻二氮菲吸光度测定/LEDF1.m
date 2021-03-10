clear;clc;
I=[0.275,0.321,0.376,0.395,0.408,0.415,0.420,0.415,0.396,0.321,0.136,0.054];
lambda=[430,450,470,490,500,505,510,515,520,530,550,570];
lp=428:0.1:572;
%Ip=spline(lambda,I,lp);
Ip=interp1(lambda,I,lp,'pchip');
p1=plot(lp,Ip,'k-','linewidth',2);
hold on
grid on
axis on
axis([420 580 0 0.5])
p2=plot(lambda,I,'b.','markersize',15);
title('ͼ2-1 ָ�������������-������ϵ����')
xlabel('����\lambda/nm')
ylabel('�����A(lg(I/I_0))')
legend([p1,p2],{'������������','���ض������µ������ʵ��ֵ'})