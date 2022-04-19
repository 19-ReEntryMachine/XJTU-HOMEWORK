function [x,v,a,t]=FrictionDynamic_diffeqs(A,k,m,miu,c,dt)
x_0=zeros(100,1);
v_0=zeros(100,1);
a_0=zeros(100,1);
T=zeros(100,1);
g=9.80665;x_0(1)=1;v_0(1)=0;a_0(1)=(-k*x_0(1)+miu*m*g)/m;
x_1=A;v_1=0;a_1=0;
T(1)=0;n=1;
while ~((abs(v_0(n))<0.000001)&&(abs(k*x_0(n))<=abs(miu*m*g)))
    a_1=(-k*x_0(n)-c*v_0(n)+FrictionForce(x_0(n),v_0(n),k,miu*m*g))/m;
    v_1=v_0(n)+a_1*dt;
    x_1=x_0(n)+v_1*dt;
    n=n+1;
    a_0(n)=a_1;
    v_0(n)=v_1;
    x_0(n)=x_1;
    T(n)=T(n-1)+dt;
end
x=x_0;
v=v_0;
a=a_0;
t=T;
end