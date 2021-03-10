clear;clc
H=[0.3;0.7];
A=[0.95,0.03;0.05,0.97];
axis([0 100 0 1]);
grid
plot(i,H(1),'k.','markersize',10)
hold on
plot(i,H(2),'r.','markersize',10)
for i=1:100
    H=A*H;
    plot(i,H(1),'k.','markersize',10)
    plot(i,H(2),'r.','markersize',10)
    if(i<=3)
        fprintf('第%d年农村人口为%04f\n',i,H(1))
        fprintf('第%d年城镇人口为%04f\n',i,H(2))
    end
end