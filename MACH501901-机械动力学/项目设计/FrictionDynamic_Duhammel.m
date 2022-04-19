function [x,t]=FrictionDynamic_Duhammel(A,m,k,miu,dt,T)
g=9.80665;
x=zeros(200,1);
t=zeros(200,1);
F=zeros(200,1);
F(1)=-miu*m*g;
x(1)=A;n=1;
while n<=T/dt
    x_0=0;
    for s=1:n
        x_0=x_0+dt*F(s)*sin((t(n)+dt-s*dt)*sqrt(k/m))/sqrt(m*k);
    end
    n=n+1;
    t(n)=t(n-1)+dt;
    x(n)=x_0+A*cos(t(n)*sqrt(k/m));
    F(n)=FrictionForce(x(n),(x(n)-x(n-1))/dt,k,miu*m*g);
end