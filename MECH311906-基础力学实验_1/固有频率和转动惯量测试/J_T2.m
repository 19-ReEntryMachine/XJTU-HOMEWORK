clear;clc;
T2=[1.305 1.138 0.998 0.867 0.755 1.458].^2;
J=[7.52 5.32 3.52 2.12 1.12 10.12];
k=polyfit(T2,J,1);
T2p=-2:30;
Jp=polyval(k,T2p,1);
T2t=1.082;
Jt=polyval(k,T2t,1);
p1=plot(T2p,Jp,'k-','linewidth',2);
hold on
p2=plot(T2,J,'b.','markersize',15);
p3=plot(T2t,Jt,'r.','markersize',25);
axis([0 4 -3 20])
grid on
axis on
title('图6-2 质点系转动惯量-三线摆振动周期关系示意');
xlabel('三线摆振动周期平方T^2/s^2');
ylabel('质点系转动惯量J/10^{-5} kg*m^2');
legend([p1,p2,p3],{'J-T^2关系曲线','J-T^2实测数据点','发动机摇臂的转动惯量预测值'});
Jpj=0;T2pj=0;r2=0;dk=0;dJ2=0;ddJ2=0;dT22=0;T22=0;dd=0;
for i=1:6
    Jpj=Jpj+J(i)/6;
    T2pj=T2pj+T2(i)/6;
end
for i=1:6
    dJ2=dJ2+(J(i)-Jpj).^2;
    ddJ2=ddJ2+(J(i)-polyval(k,T2(i),1)).^2;
    dT22=dT22+(T2(i)-T2pj).^2;
    T22=T22+(T2(i)^2);
end
r2=1-ddJ2/dJ2;
dk=sqrt(ddJ2/(dT22*4));
dd=sqrt(T22*ddJ2/(dT22*4*6));
fprintf("一次项系数为%f,常数项系数为%f,可决系数为%f,一次项和常数项误差分别为%f和%f,发动机摇臂转动惯量为%f",k(1)*100000,k(2),r2,dk*100000,dd,Jt);
%一次项系数为576755.441035,常数项系数为-2.199925,可决系数为0.999683,一次项和常数项误差分别为5138.332294和0.069505,发动机摇臂转动惯量为4.040569>> 