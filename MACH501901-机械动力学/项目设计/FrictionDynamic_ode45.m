function [t,x]=FrictionDynamic_ode45(A,k,m,miu,T)
g=9.80665;f0=miu*m*g;
[t,x]=ode45(@(t,x)odefun(t,x,k/m,f0/m),[0 T],[A;0]);
end