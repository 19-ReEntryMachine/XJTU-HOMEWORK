clear;clc;
load('database5.mat');
average=zeros(100,1);
sigma=zeros(100,1);
NU=0:0.001:1000;
for i=1:100
    for j=1:1000
        average(i)=average(i)+Untitled(i,j)/1000;
    end
end
for i=1:100
    for j=1:1000
        sigma(i)=sigma(i)+(Untitled(i,j)-average(i)).^2/1000;
    end
    sigma(i)=sqrt(sigma(i));
end
for i=1:1000
    pic(i)=plot(Number,Untitled(:,i),'b.','markersize',0.2);
    pic(i).Color(4) = 0.3;
    hold on
    axis on
end
AVE=spline(Number,average,NU);
SGM=spline(Number,sigma,NU);
plot(NU,AVE,'b-','linewidth',2);
p3=plot(NU,AVE+3*SGM,'r--','linewidth',1.5);
p4=plot(NU,AVE-3*SGM,'r--','linewidth',1.5);
axis([0 1000 0 6500])
p3.Color(4) = 0.5;
p4.Color(4) = 0.5;
figure(2)
x1=2500:5000;x2=2450:100:4450;
n1=1000*exp(-(x1-average(50)).^2/(2*sigma(50).^2))./sqrt(2*pi*sigma(50).^2);
n2=[1 1 0 3 5 14 26 22 40 60 84 101 140 128 119 111 63 42 32 6 2];
[hAxes,hBar,hLine]=plotyy(x2,n2,x1,n1,'bar','plot');
set(hLine,'LineWidth',2);
xlabel('Overall decomposition rate')
ylabel(hAxes(1),'(Bar Chart)')
ylabel(hAxes(2),'(Normal Distribution Line)')
hold on
axis on
grid on
%histogram(Untitled(50,:));