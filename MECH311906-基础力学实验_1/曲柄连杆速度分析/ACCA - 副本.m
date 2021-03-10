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
xlabel('ʱ��t/s')
ylabel('����λ��x/mm')
title('ͼ3-6-2 ����λ��-ʱ���ϵ')
figure(2)
p2=fplot(v,[0 10]);
xlabel('ʱ��t/s')
ylabel('�����ٶ�x/mm*s^{-1}')
title('ͼ3-7-2 �����ٶ�-ʱ���ϵ')
figure(3)
p3=fplot(a,[0 10]);
xlabel('ʱ��t/s')
ylabel('������ٶ�x/mm*s^{-2}')
title('ͼ3-8-2 ������ٶ�-ʱ���ϵ')
figure(4)
p4=fplot(cita,[0 10]);
xlabel('ʱ��t/s')
ylabel('�������\theta_{2}/rad')
title('ͼ3-9-2 �������-ʱ���ϵ')
figure(5)
p5=fplot(dcita,[0 10]);
xlabel('ʱ��t/s')
ylabel('���˽��ٶ�\omega_{2}/rad')
title('ͼ3-10-2 ���˽��ٶ�-ʱ���ϵ')
figure(6)
p6=fplot(d2cita,[0 10]);
xlabel('ʱ��t/s')
ylabel('���˽��ٶ�\alpha_{2}/rad')
title('ͼ3-11-2 ���˽Ǽ��ٶ�-ʱ���ϵ')