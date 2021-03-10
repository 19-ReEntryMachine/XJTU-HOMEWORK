clear;clc;
f=@(k,x)k.*x;
A=[0,0.172,0.349,0.535,0.697,0.846];
c=[0,0.8,1.6,2.4,3.2,4.0];
[k1,resnorm1]=lsqcurvefit(f,[0],c,A);
cp=0:0.1:5;
Ap=k1*cp;
p1=plot(c,A,'m.','markersize',15);
hold on
grid on
p2=plot(cp,Ap,'k-','linewidth',2);
axis([0 6 0 1])
axis on
title('ͼ2-2 �ڶ����Ʒֹⷨ��׼��������')
xlabel('�����A(lg(I/I_0))')
ylabel('��Ũ��c_Fe /\mug��ml^-1')
legend([p1,p2],{'�����ʵ��ֵ','��������(���Իع�)'})
fprintf("����б��Ϊ%03f,����/epsilonΪ%f\n",k1,k1*100);
