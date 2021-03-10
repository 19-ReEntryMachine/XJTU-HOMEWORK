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
title('图2-2 邻二氮菲分光法标准工作曲线')
xlabel('吸光度A(lg(I/I_0))')
ylabel('铁浓度c_Fe /\mug·ml^-1')
legend([p1,p2],{'吸光度实测值','工作曲线(线性回归)'})
fprintf("曲线斜率为%03f,参数/epsilon为%f\n",k1,k1*100);
