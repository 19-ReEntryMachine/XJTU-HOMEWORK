clear;clc;
p1=plot([0,1,1,1,2,2],[0,0,-1,-2,-2,-3],'k');
axis on
grid on
hold on
p2=plot([0,2],[0,-3],'b');
axis([-0.5 2.5 -3.5 0.5])
title('习题3-5直线插补轨迹示意');
xlabel('axis X')
ylabel('axis Y')
legend([p1,p2],'Interpolation Routine','Theoretical Routine')