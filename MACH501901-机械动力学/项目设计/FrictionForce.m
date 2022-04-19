function f=FrictionForce(x,dx,k,f0)
if dx~=0
    f=-f0*dx/abs(dx);
else
    if k*x>f0
        f=-f0;
    else
        if k*x<-f0
            f=f0;
        else
            f=kx;
        end
    end
end