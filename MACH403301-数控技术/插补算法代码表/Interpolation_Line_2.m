clear;clc;
x0=input('��������������');
y0=input('���������������');
x1=input('�������յ������');
y1=input('�������յ�������');
delta=input('������岹���');
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
title('���ȽϷ�ֱ�߲岹����ʾ��')
xlabel('x������x_{t}/mm')
ylabel('y������y_{t}/mm')
legend([p1,p2],'Theoretical Routine','Interpolation Routine')

%-----------------------------------%
%ԭ���ߣ���е97 ���ڷ 2193712613
%��ֹ�ں���ʹ�÷�Χ��ʹ�ô˴���
%�������Ȩ���У���Ϯ�ؾ�