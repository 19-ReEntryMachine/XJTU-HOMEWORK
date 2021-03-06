clear;clc;
t=1:40;
tex=41:1:49;
m=[8.5229,8.7177,8.9221,9.0859,9.2420,9.3717,9.4974,9.6259,9.7542,9.8705,10.0072,10.1654,10.3008,10.4357,10.5851,10.7507,10.9300,11.1026,11.2704,11.4333,11.5823,11.7171,11.8517,11.985,12.1121,12.2389,12.3626,12.4761,12.5786,12.6743,12.7627,12.8453,12.9227,12.9988,13.0756,13.1448,13.2129,13.2802,13.3474,13.41];
mex=[13.4735,13.5405,13.6072,13.6782,13.7462,13.8271,13.9008,13.9538,14.0005];
plot(t,m,'k.','markersize',5);
hold on
axis([0 50 7 15])
nm=polyfit(t,m,3)
t0=0:0.1:50;
plot(t0,polyval(nm,t0),'b-','linewidth',2)
ma=0;
for i=1:40
    ma=ma+m(i)/40;
end
md=0;
mdm=0;
for i=1:40
    md=md+(m(i)-ma).^2;
    mdm=mdm+(m(i)-polyval(nm,t(i))).^2;
end
r=1-mdm/md
delex=0;
for i=1:9
    delex=delex+(mex(i)-polyval(nm,tex(i))).^2;
end
delex