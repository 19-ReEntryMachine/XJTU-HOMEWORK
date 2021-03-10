clc;
clear all;
close all;

t=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15];
y=[ 352 211 197 160 142 106 104  60  56  38  36  32  21  19 15];
figure
plot(t,y,'-*')

p2=polyfit(t,y,2)


p3=polyfit(t,y,3)


y2=1.9897*t.^2-51.1394*t+347.8967 ;
y3=-0.1777*t.^3+6.2557*t.^2-79.3303*t+391.4095 ;
figure
plot(t,y,'-*',t,y2,'-o',t,y3,'-+'),

legend('原始数据','二次函数','三次函数') 

R2=1-sum((y-y2).^2)/sum((y-mean(y)).^2)
R3=1-sum((y-y3).^2)/sum((y-mean(y)).^2)

polyval(p2,16)
