clear;clc;
x0=input('请输入起点横坐标');
y0=input('请输入起点纵坐标');
x1=input('请输入终点横坐标');
y1=input('请输入终点纵坐标');
delta=input('请输入插补间隔');
sgn_x=(x1-x0)/abs(x1-x0);
sgn_y=(y1-y0)/abs(y1-y0);
n=abs(x1-x0)/delta+abs(y1-y0)/delta;
xn=ones(1,n+1)*x0;
yn=ones(1,n+1)*y0;
x=x0;y=y0;nc=1;
while nc<=n&&x1-x0~=0
    nc=nc+1;
    if abs((x1-x0)*(y-y0))-abs((x-x0)*(y1-y0))>=0
        x=x+delta*sgn_x;
    else
        y=y+delta*sgn_y;
    end
    yn(nc)=y;
    xn(nc)=x;
end
if x1-x0==0
    yn=sgn_y*delta*(0:n)+y0;
end
p1=plot([x0,x1],[y0,y1],'k-');
hold on
axis on
grid on
p2=plot(xn,yn,'b-');
title('逐点比较法直线插补程序示例')
xlabel('x轴坐标x_{t}/mm')
ylabel('y轴坐标y_{t}/mm')
legend([p1,p2],'Theoretical Routine','Interpolation Routine')

%-----------------------------------%
%原作者：机械97 杨逢诜 2193712613
%禁止在合理使用范围外使用此代码
%软件著作权所有，抄袭必究