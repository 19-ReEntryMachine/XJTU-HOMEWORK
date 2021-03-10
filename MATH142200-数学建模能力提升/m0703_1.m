clear;clc
x=[0.1:0.01:0.16,0.18];
y=[42.3,41.5,45.2,45.5,44.9,47.6,48.9,50.2];
axis([0.1 0.3 40 60])
grid
plot(x,y,'k.','markersize',10);
hold on
n1=polyfit(x,y,2);
x0=0:0.1:0.3;
plot(x0,polyval(n1,x0),'b-','linewidth',2);
yp=0;
for i=1:8
    yp=yp+y(i)/8;
end
y1=0;
yd=0;
for j=1:8
    y1=y1+(y(i)-yp).^2;
    yd=yd+(y(i)-polyval(n1,x(i)))^2;
end
r=1-yd/y1