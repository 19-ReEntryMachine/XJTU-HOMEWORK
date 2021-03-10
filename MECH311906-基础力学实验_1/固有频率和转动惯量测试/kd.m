clear;clc;
x=[-2 8 14 19 24 29];
F=[0 0.1 0.15 0.2 0.25 0.3]*9.8;
k=polyfit(x,F,1);
xp=-2:30;
Fp=polyval(k,xp,1);
p1=plot(xp,Fp,'k-','linewidth',2);
hold on
p2=plot(x,F,'b.','markersize',15);
axis([-2 30 0 3])
grid on
axis on
title('图6-1 弹簧受力-变形量关系示意');
xlabel('弹簧变形量\delta/mm');
ylabel('弹簧所受的外力F/N');
legend([p1,p2],{'F-\delta关系曲线','F-\delta实测数据点'});
Fpj=0;xpj=0;r2=0;dk=0;dF2=0;ddF2=0;dx2=0;
for i=1:6
    Fpj=Fpj+F(i)/6;
    xpj=xpj+x(i)/6;
end
for i=1:6
    dF2=dF2+(F(i)-Fpj).^2;
    ddF2=ddF2+(F(i)-polyval(k,x(i),1)).^2;
    dx2=dx2+(x(i)-xpj).^2;
end
r2=1-ddF2/dF2;
dk=sqrt(ddF2/(dx2*4));
fprintf("弹簧弹性系数为%f,可决系数为%f,误差为%f",k(1)*1000,r2,dk*1000);
%弹簧弹性系数为94.171067,可决系数为0.999366,误差为1.185566>> 