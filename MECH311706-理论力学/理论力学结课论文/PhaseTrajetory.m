%m2=10kg,ת�������ܺ�J=4kgm2������ϵ��k=1000N/m��x0=10cm,ƫ�ľ�e=5cm
clear;clc;
E=10:10:300;
dcita=0;fdcita=0;
for i=1:30
    cita=0:0.01:6*pi;
    for j=1:6*pi/0.01+1
        if E(i)-1000*(0.05*cos(cita(j))+0.1)/2>0
            dcita(j)=sqrt((E(i)-1000*(0.05*cos(cita(j))+0.1)/2)/(4/2+10*(0.05^2)*(sin(cita(j))^2)/2));
        else
            dcita(j)=0;
        end
        fdcita(j)=-dcita(j);
    end
    plot(cita,dcita,'k-','linewidth',2);
    hold on
    axis on 
    grid on
    plot(cita,fdcita,'k-','linewidth',2);
end
title('ͼ1-1 ʧЧ�����µ������')
xlabel('ϵͳ��λ��\theta')
ylabel('ϵͳ���ٶ�\omega=d\theta/dt')
axis([0 6*pi -10 10])