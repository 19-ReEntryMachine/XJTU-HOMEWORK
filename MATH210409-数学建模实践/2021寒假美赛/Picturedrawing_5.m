clear;clc;
load('database4.mat');
p1=plot(Moisturetolerance,lnExtensionrate,'r.','markersize',20);
xlabel('Moisture tolerance');
ylabel('log(Extensionrate)');
hold on
grid on
axis on
x=-1:0.1:1;
y=2.0516622148*x-0.3459151934;
y1=2.0516622148*x-0.3459151934+0.6238939025;
y2=2.0516622148*x-0.3459151934-0.6238939025;
p2=plot(x,y1,'b--','linewidth',1);
p3=plot(x,y2,'b--','linewidth',1);
p4=plot(x,y,'b-','linewidth',2);