clear;clc;
xo=0;yo=0;x0=4;y0=-3;x1=3;y1=-4;
r=sqrt((x0-xo)^2+(y0-yo)^2);
if r-sqrt((x1-xo)^2+(y1-yo)^2)~=0
    fprintf('无效输入：两点不能对定圆心共圆');
end
F=1600;t=2;
deltal=F*t/(60*1000);
n=abs(angelCalculate(xo,yo,x0,y0)-2*pi-angelCalculate(xo,yo,x1,y1))/(2*asin(deltal/r/2));
x=x0;y=y0;nc=1;
dx=0;dy=0;dx0=0;dy0=0;
while nc<=n
    yn(nc)=y;
    xn(nc)=x;
    nc=nc+1;
    theta=angelCalculate(xo,yo,x,y);
    if theta>=pi/2
        theta=theta-pi/2;
    else
        if theta<0&&theta>=-pi/2
            theta=theta+pi/2;
        else
            if theta<-pi/2&&theta>=-pi
                theta=theta+pi;
            end
        end
    end
    if theta<=pi/4
        dx=deltal*(y+dy0/2)/r;
        x=x-dx;
        if abs(x-xo)>r
            x=xo+signal_ds(x-xo)*r;
        end
        y=sqrt(r^2-(x-xo)^2)*signal(y-yo)+yo;
    else
        dy=deltal*(x-dx0/2)/r;
        y=y+dy;
        if abs(y-yo)>r
            y=yo+signal_ds(y-yo)*r;
        end
        x=sqrt(r^2-(y-yo)^2)*signal(x-xo)+xo;
    end
    dx0=(x-xn(nc-1));
    dy0=(y-yn(nc-1));
end
syms u v t
u=xo+r*cos(t);
v=yo+r*sin(t);
p1=fplot(u,v,[angelCalculate(xo,yo,x0,y0),2*pi+angelCalculate(xo,yo,x1,y1)],'k-');
hold on
axis on
grid on
p2=plot(xn,yn,'b-');
title('数据采样法圆弧插补程序示例')
xlabel('x轴坐标x_{t}/mm')
ylabel('y轴坐标y_{t}/mm')
legend([p1,p2],'Theoretical Routine','Interpolation Routine')