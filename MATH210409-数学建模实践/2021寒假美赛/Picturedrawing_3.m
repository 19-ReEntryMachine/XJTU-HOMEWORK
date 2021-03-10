clear;clc;
load('database3.mat');
[x,y]=meshgrid(-2:0.5:2,-4:0.5:4);                                
z=0.360408*x+0.246776*y+1.833242;
surf(x,y,z);
shading interp
alpha(0.5);
hold on
axis on
grid on
xlabel('log(Extension rate)');
ylabel('Moisture Tolerance');
zlabel('log(Decomposition rate)');
plot3(lnalpha,beta,lndelta,'b.','markersize',20);