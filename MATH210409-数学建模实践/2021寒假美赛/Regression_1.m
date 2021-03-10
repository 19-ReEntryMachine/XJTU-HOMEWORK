clear;clc;
load('database3.mat');
a=0;
for i=1:34
    a(i)=1;
end
A=[lnalpha beta a];
AT=transpose(A);
B=inv(AT*A)*AT*lndelta;