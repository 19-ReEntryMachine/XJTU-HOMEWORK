clear;clc;
epsilon=[195.2,184.9,157.3,133.9,93.6,76.8];
lnc=[-9.210,-8.517,-6.908,-6.215,-4.605,-3.912];
a=polyfit(lnc,epsilon,1);
lncp=-10:-1;
ep=polyval(a,lncp);
p1=plot(lnc,epsilon,'k.','markersize',10);
hold on
grid on
axis on
axis([-10 -1 50 200])
p2=plot(lncp,ep,'b-','linewidth',2);
title('ͼ7-1 ������ѡ���Ե缫�綯��-������Ũ�ȶ�����ϵ����ʾ��');
xlabel('������Ũ�ȶ���lgc');
ylabel('������ѡ���Ե缫�綯��\epsilon/mV');
legend([p1,p2],{'ʵ��綯��','�綯��-Ũ�ȶ����������'});
c=0;dc=0;epsil=0;dep=0;delta=0;
for i=1:6
    c=c+lnc(i)/6;
    epsil=epsil+epsilon(i)/6;
end
for i=1:6
    dc=dc+(lnc(i)-c).^2;
    dep=dep+(epsilon(i)-epsil).^2;
    delta=delta+(epsilon(i)-polyval(a,lnc(i))).^2;
end
wucha=sqrt((delta./dc)./4);
jueding=1-delta/dep;
fprintf("ѡ���Ե缫�綯��-������Ũ�ȶ�����ϵĽ���е�һ����Ϊ%f,������Ϊ%f.\n �˴���ϵ�һ����ϵ�����Ϊ%f,�ɾ�ϵ��Ϊ%f.\ny�в�ƽ����Ϊ%f,x��ֵΪ%f,y��ֵΪ%f.",a(1),a(2),wucha,jueding,delta,c,epsil);
%ѡ���Ե缫�綯��-������Ũ�ȶ�����ϵĽ���е�һ����Ϊ-22.818969,������Ϊ-9.435726.
%�˴���ϵ�һ����ϵ�����Ϊ1.213131,�ɾ�ϵ��Ϊ0.988821.>> 
%y�в�ƽ����Ϊ129.075173,x��ֵΪ-6.561167,y��ֵΪ140.283333.