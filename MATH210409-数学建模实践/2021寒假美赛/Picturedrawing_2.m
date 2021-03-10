clear;clc;
load('database2.mat');
p1=plot(Moisttolerance,logDecompositionrate,'b.','markersize',20);
xlabel('Moist. tolerance');
ylabel('log(Decomposition rate)');
axis([-1 1 0 4])
hold on
grid on
axis on