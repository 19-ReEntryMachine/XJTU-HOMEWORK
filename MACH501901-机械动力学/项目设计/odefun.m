function dx=odefun(t,x,k,f0)
dx=[x(2);
    (-k*x(1)+FrictionForce(x(1),x(2),k,f0))];
end