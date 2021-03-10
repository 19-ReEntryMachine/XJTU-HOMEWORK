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
title('图2-1 指定样本的吸光度-波长关系曲线')
xlabel('波长\lambda/nm')
ylabel('吸光度A(lg(I/I_0))')
legend([p1,p2],{'吸光度拟合曲线','在特定波长下的吸光度实测值'})