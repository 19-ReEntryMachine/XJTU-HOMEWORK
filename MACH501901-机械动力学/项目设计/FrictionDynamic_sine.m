function p1=FrictionDynamic_sine(A,k,m,miu)
g=9.80665;
xt=A;T=pi*sqrt(m/k);n=1;
syms t
while xt>=miu*m*g/k
    if mod(n,2)==0
        r=-1;
    else
        r=1;
    end
    A=xt-miu*m*g/k;
    x_0=r*A*cos(sqrt(k/m)*(t-(n-1)*T))+r*miu*m*g/k;
    p1(n)=fplot(t,x_0,[(n-1)*T,n*T],'b-');
    hold on
    xt=xt-2*miu*m*g/k;
    n=n+1;
end