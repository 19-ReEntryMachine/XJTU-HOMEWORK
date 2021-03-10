clear;clc;
load('database3.mat');
delta=exp(lndelta);
aalpha=exp(lnalpha);
[x,y]=meshgrid(0:0.005:10,-1:0.005:3);                                
z=(x.^(0.360408)).*exp(0.246776*y).*exp(1.833242);
p1=surf(x,y,z);
hold on
shading interp
alpha(0.5);
%hold on
plot3(aalpha,beta,delta,'r.','markersize',20);
axis on
grid on
xlabel('Extension rate');
ylabel('Moisture Tolerance');
zlabel('Decomposition rate');