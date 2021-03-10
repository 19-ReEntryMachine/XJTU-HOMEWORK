clear;clc;
load('database3.mat');
a=0;
for i=1:34
    a(i)=1;
end
A=[lnalpha beta transpose(a)];
AT=A.';
B=inv(AT*A)*AT*lndelta;
fprintf('p=%f,q=%f,r=%f',B(1),B(2),B(3));