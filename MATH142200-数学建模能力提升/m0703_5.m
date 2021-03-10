clear;clc
x=[3,4,5,7,8,10,11,14,15,16,18,19];
y=[109.2,109.58,109.5,110.0,109.93,110.49,110.59,110.60,110.9,110.76,111,111.2];
axis([0 25 100 120])
grid
plot(x,y,'k-','markersize',10);
n1=polyfit(x,y,1);
x0=0:0.1:25;
plot(x0,polyval(n1,x0),'b-','linewidth',2);
hold on
yp=0;
for i=1:12
    yp=yp+y(i)/12;
end
y1=0;
yd=0;
for j=1:12
    y1=y1+(y(i)-yp).^2;
    yd=yd+(y(i)-polyval(n1,x(i)))^2;
end
r=1-yd/y1