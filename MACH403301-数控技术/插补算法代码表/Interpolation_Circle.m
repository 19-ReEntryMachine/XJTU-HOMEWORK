clear;clc;
x0=input('��������������');
y0=input('���������������');
x1=input('�������յ������');
y1=input('�������յ�������');
xo=input('������Բ�ĺ�����');
yo=input('������Բ��������');
r=sqrt((x0-xo)^2+(y0-yo)^2);
if r-sqrt((x1-xo)^2+(y1-yo)^2)~=0
    fprintf('��Ч���룺���㲻�ܶԶ�Բ�Ĺ�Բ');
    return;
end
delta=input('������岹���');
x=x0;y=y0;nc=1;
while sqrt((x-x1)^2+(y-y1)^2)>delta/3
    yn(nc)=y;
    xn(nc)=x;
    if sqrt((x-xo)^2+(y-yo)^2)-r>=0
        if signal(x-xo)*signal(y-yo)>=0
            y=y-delta*signal(y-yo);
        else
            x=x-delta*signal(x-xo);
        end
    else
        if signal(x-xo)*signal(y-yo)>=0
            x=x+delta*signal(y-yo);
        else
            y=y-delta*signal(x-xo);
        end
    end
    nc=nc+1;
end
syms u v t
u=xo+r*cos(t);
v=yo+r*sin(t);
if angelCalculate(xo,yo,x1,y1)<angelCalculate(xo,yo,x0,y0)
    p1=fplot(u,v,[angelCalculate(xo,yo,x1,y1),angelCalculate(xo,yo,x0,y0)],'r-');
else
    p1=fplot(u,v,[angelCalculate(xo,yo,x1,y1),2*pi+angelCalculate(xo,yo,x0,y0)],'r-');
end
hold on
axis on
grid on
p2=plot(xn,yn,'b-');
title('���ȽϷ�Բ���岹����ʾ��')
xlabel('x������x_{t}/mm')
ylabel('y������y_{t}/mm')
legend([p1,p2],'Theoretical Routine','Interpolation Routine')


%-----------------------------------%
%ԭ���ߣ���е97 ���ڷ 2193712613
%��ֹ�ں���ʹ�÷�Χ��ʹ�ô˴���
%�������Ȩ���У���Ϯ�ؾ�