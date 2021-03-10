clear;clc;
syms t;
r1=0.15;r2=0.55;alpha=10;
x=r1*cos((alpha*t^2)/2)+sqrt(r2^2-(r1^2)*(sin((alpha*t^2)/2)^2));
cita=atan(r1*sin((alpha*t^2)/2)/(x-r1*cos((alpha*t^2)/2)));
v=diff(x,t);
a=diff(v,t);
dcita=diff(cita,t);
d2cita=diff(dcita,t);
p1=fplot(x,[0 10]);
xlabel('时间t/s')
ylabel('滑块位置x/mm')
title('图3-6-2 滑块位置-时间关系')
figure(2)
p2=fplot(v,[0 10]);
xlabel('时间t/s')
ylabel('滑块速度x/mm*s^{-1}')
title('图3-7-2 滑块速度-时间关系')
figure(3)
p3=fplot(a,[0 10]);
xlabel('时间t/s')
ylabel('滑块加速度x/mm*s^{-2}')
title('图3-8-2 滑块加速度-时间关系')
figure(4)
p4=fplot(cita,[0 10]);
xlabel('时间t/s')
ylabel('连杆倾角\theta_{2}/rad')
title('图3-9-2 连杆倾角-时间关系')
figure(5)
p5=fplot(dcita,[0 10]);
xlabel('时间t/s')
ylabel('连杆角速度\omega_{2}/rad')
title('图3-10-2 连杆角速度-时间关系')
figure(6)
p6=fplot(d2cita,[0 10]);
xlabel('时间t/s')
ylabel('连杆角速度\alpha_{2}/rad')
title('图3-11-2 连杆角加速度-时间关系')