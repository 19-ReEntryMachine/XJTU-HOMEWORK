clear;clc;
p1=plot([8,7,7,7,7,7,6,6,6,5,5,4,3,3,2,1,0],[0,0,1,2,3,4,4,5,6,6,7,7,7,8,8,8,8],'k');
axis on
grid on
hold on
syms x;
y=sqrt(64-x*x);
p2=fplot(x,y,[0,8]);
axis([-1 9 -1 9])
title('œ∞Ã‚3-6‘≤ª°≤Â≤ππÏº£ æ“‚');
xlabel('axis X')
ylabel('axis Y')
legend([p1,p2],'Interpolation Routine','Theoretical Routine')