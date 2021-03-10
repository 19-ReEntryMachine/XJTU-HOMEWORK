syms t;
r1=0.15;r2=0.55;omega=150;
x=r1*cos(omega*t)+sqrt(r2^2-(r1^2)*(sin(omega*t)^2));
cita=atan(r1*sin(omega*t)/(x-r1*cos(omega*t)));
v=diff(x,t);
a=diff(v,t);
dcita=diff(cita,t);
p1=fplot(x,[0 10]);
xlabel('ʱ��t/s')
ylabel('����λ��x/mm')
title('ͼ3-1-2 ����λ��-ʱ���ϵ')
figure(2)
p2=fplot(v,[0 10]);
xlabel('ʱ��t/s')
ylabel('�����ٶ�x/mm*s^{-1}')
title('ͼ3-2-2 �����ٶ�-ʱ���ϵ')
figure(3)
p3=fplot(a,[0 10]);
xlabel('ʱ��t/s')
ylabel('������ٶ�x/mm*s^{-2}')
title('ͼ3-3-2 ������ٶ�-ʱ���ϵ')
figure(4)
p4=fplot(cita,[0 10]);
xlabel('ʱ��t/s')
ylabel('�������\theta_{2}/rad')
title('ͼ3-4-2 �������-ʱ���ϵ')
figure(5)
p5=fplot(dcita,[0 10]);
xlabel('ʱ��t/s')
ylabel('���˽��ٶ�\omega_{2}/rad')
title('ͼ3-5-2 ���˽��ٶ�-ʱ���ϵ')