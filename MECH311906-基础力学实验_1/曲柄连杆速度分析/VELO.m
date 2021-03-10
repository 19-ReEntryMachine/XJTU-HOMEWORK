syms t;
r1=0.15;r2=0.55;omega=150;
x=r1*cos(omega*t)+sqrt(r2^2-(r1^2)*(sin(omega*t)^2));
cita=atan(r1*sin(omega*t)/(x-r1*cos(omega*t)));
v=diff(x,t);
a=diff(v,t);
dcita=diff(cita,t);
p1=fplot(x,[0 10]);
xlabel('时间t/s')
ylabel('滑块位置x/mm')
title('图3-1-2 滑块位置-时间关系')
figure(2)
p2=fplot(v,[0 10]);
xlabel('时间t/s')
ylabel('滑块速度x/mm*s^{-1}')
title('图3-2-2 滑块速度-时间关系')
figure(3)
p3=fplot(a,[0 10]);
xlabel('时间t/s')
ylabel('滑块加速度x/mm*s^{-2}')
title('图3-3-2 滑块加速度-时间关系')
figure(4)
p4=fplot(cita,[0 10]);
xlabel('时间t/s')
ylabel('连杆倾角\theta_{2}/rad')
title('图3-4-2 连杆倾角-时间关系')
figure(5)
p5=fplot(dcita,[0 10]);
xlabel('时间t/s')
ylabel('连杆角速度\omega_{2}/rad')
title('图3-5-2 连杆角速度-时间关系')