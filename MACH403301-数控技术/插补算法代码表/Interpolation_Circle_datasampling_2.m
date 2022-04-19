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
F=input('�������������');
t=input('��������������');
deltal=F*t/(60*1000);
if angelCalculate(xo,yo,x1,y1)>angelCalculate(xo,yo,x0,y0)
    n=abs(angelCalculate(xo,yo,x1,y1)-angelCalculate(xo,yo,x0,y0))/(2*asin(deltal/r/2));
else
    n=abs(angelCalculate(xo,yo,x0,y0)-2*pi-angelCalculate(xo,yo,x1,y1))/(2*asin(deltal/r/2));
end
x=x0;y=y0;nc=1;
dx=0;dy=0;dx0=0;dy0=0;
while nc<=n+1
    yn(nc)=y;
    xn(nc)=x;
    nc=nc+1;
    theta=angelCalculate(xo,yo,x,y);
    if tan(theta)>=-1&&tan(theta)<=1
        dy=deltal*(x-dx0/2)/r;
        y=y+dy;
        if abs(y-yo)>r
            y=yo+signal_ds(y-yo)*r;
        end
        x=sqrt(r^2-(y-yo)^2)*signal(x-xo)+xo;
    else
        dx=deltal*(y+dy0/2)/r;
        x=x-dx;
        if abs(x-xo)>r
            x=xo+signal_ds(x-xo)*r;
        end
        y=sqrt(r^2-(x-xo)^2)*signal(y-yo)+yo;
    end
    dx0=(x-xn(nc-1));
    dy0=(y-yn(nc-1));
end
yn(nc)=y1;
xn(nc)=x1;
syms u v t
u=xo+r*cos(t);
v=yo+r*sin(t);
if angelCalculate(xo,yo,x1,y1)>angelCalculate(xo,yo,x0,y0)
    p1=fplot(u,v,[angelCalculate(xo,yo,x0,y0),angelCalculate(xo,yo,x1,y1)],'r-');
else
    p1=fplot(u,v,[angelCalculate(xo,yo,x0,y0),2*pi+angelCalculate(xo,yo,x1,y1)],'r-');
end
hold on
axis on
grid on
p2=plot(xn,yn,'b--');
title('���ݲ�����Բ���岹����ʾ��')
xlabel('x������x_{t}/mm')
ylabel('y������y_{t}/mm')
legend([p1,p2],'Theoretical Routine','Interpolation Routine')


%-----------------------------------%
%ԭ���ߣ���е97 ���ڷ 2193712613
%��ֹ�ں���ʹ�÷�Χ��ʹ�ô˴���
%�������Ȩ���У���Ϯ�ؾ�