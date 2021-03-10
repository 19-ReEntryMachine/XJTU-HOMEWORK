clear;clc;
epsilon=[195.2,184.9,157.3,133.9,93.6,76.8];
lnc=[-9.210,-8.517,-6.908,-6.215,-4.605,-3.912];
a=polyfit(lnc,epsilon,1);
lncp=-10:-1;
ep=polyval(a,lncp);
p1=plot(lnc,epsilon,'k.','markersize',10);
hold on
grid on
axis on
axis([-10 -1 50 200])
p2=plot(lncp,ep,'b-','linewidth',2);
title('图7-1 氯离子选择性电极电动势-氯离子浓度对数关系曲线示意');
xlabel('氯离子浓度对数lgc');
ylabel('氯离子选择性电极电动势\epsilon/mV');
legend([p1,p2],{'实测电动势','电动势-浓度对数拟合曲线'});
c=0;dc=0;epsil=0;dep=0;delta=0;
for i=1:6
    c=c+lnc(i)/6;
    epsil=epsil+epsilon(i)/6;
end
for i=1:6
    dc=dc+(lnc(i)-c).^2;
    dep=dep+(epsilon(i)-epsil).^2;
    delta=delta+(epsilon(i)-polyval(a,lnc(i))).^2;
end
wucha=sqrt((delta./dc)./4);
jueding=1-delta/dep;
fprintf("选择性电极电动势-氯离子浓度对数拟合的结果中的一次项为%f,常数项为%f.\n 此次拟合的一次项系数误差为%f,可决系数为%f.\ny残差平方和为%f,x均值为%f,y均值为%f.",a(1),a(2),wucha,jueding,delta,c,epsil);
%选择性电极电动势-氯离子浓度对数拟合的结果中的一次项为-22.818969,常数项为-9.435726.
%此次拟合的一次项系数误差为1.213131,可决系数为0.988821.>> 
%y残差平方和为129.075173,x均值为-6.561167,y均值为140.283333.