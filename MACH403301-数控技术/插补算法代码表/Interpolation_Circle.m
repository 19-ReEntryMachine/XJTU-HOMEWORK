clear;clc;
x0=input('请输入起点横坐标');
y0=input('请输入起点纵坐标');
x1=input('请输入终点横坐标');
y1=input('请输入终点纵坐标');
xo=input('请输入圆心横坐标');
yo=input('请输入圆心纵坐标');
r=sqrt((x0-xo)^2+(y0-yo)^2);
if r-sqrt((x1-xo)^2+(y1-yo)^2)~=0
    fprintf('无效输入：两点不能对定圆心共圆');
    return;
end
delta=input('请输入插补间隔');
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
title('逐点比较法圆弧插补程序示例')
xlabel('x轴坐标x_{t}/mm')
ylabel('y轴坐标y_{t}/mm')
legend([p1,p2],'Theoretical Routine','Interpolation Routine')


%-----------------------------------%
%原作者：机械97 杨逢诜 2193712613
%禁止在合理使用范围外使用此代码
%软件著作权所有，抄袭必究