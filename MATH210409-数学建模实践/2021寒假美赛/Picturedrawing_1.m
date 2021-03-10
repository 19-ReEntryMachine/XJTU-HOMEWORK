clear;clc;
load('database1.mat');
p1=plot(C,Decompositionrate,'b.','markersize',20);
hold on
grid on
axis on
p2=plot(C1,Decompositionrate,'r.','markersize',20);
p3=plot(C2,Decompositionrate,'g.','markersize',20);
xlabel('Hyphal extension rate');
ylabel('Decomposition rate');
legend([p1,p2,p3],{'10\circC','16\circC','22\circC'})