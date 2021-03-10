clear;clc;
t=[23.9,22.9,20.1,19.1,15.4,11.5,9.5,8.2];
h=[0,1.5,2.5,4.6,8.2,12.5,16.5,26.5];
axis([0 30 0 25])
grid
plot(h,t,'k.','markersize',10);
hold on
n2=polyfit(h,t,2);
n3=polyfit(h,t,3);
u=@(a,x)a(1).*exp(a(2).*x.^2+a(3)*x);
nn=lsqcurvefit(u,[0 0 0],h,t)
h0=0:0.1:30;
plot(h0,polyval(n3,h0),'r-','linewidth',2);
plot(h0,polyval(n2,h0),'b-','linewidth',2);
plot(h0,u(nn,h0),'k-','linewidth',2);
tp=0;
td=0;
td2=0;
td3=0;
tdn=0;
for i=1:8
    tp=tp+t(i)/8;
end
for j=1:8
    td=td+(t(j)-tp)^2;
    td2=td2+(t(j)-polyval(n2,h(j)))^2;
    td3=td3+(t(j)-polyval(n3,h(j)))^2;
    tdn=tdn+(t(j)-u(nn,h(j)))^2;
end
r1=1-td2/td;
r2=1-td3/td;
r3=1-tdn/td