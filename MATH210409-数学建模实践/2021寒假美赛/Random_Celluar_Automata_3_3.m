%random celluar automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','Run', 'fontsize',12, 'position',[250,400,50,20], 'callback', 'run=1;');
erasebutton=uicontrol('style','pushbutton','string','Pause','fontsize',12,'position',[350,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','Quit','fontsize',12,'position',[450,400,50,20],'callback','stop=1;close;');
for i=1:3
    number(i) = uicontrol('style','text','string','0','fontsize',12, 'position',[45*i-45,400,50,20]);
end
n=150;
pic=ones(n,n,3)*255;
img=image(pic);
indi=zeros(n,n,3);
colour1=[255;0;0];
colour2=[0;0;255];
colour3=[0;128;128];
colour=[colour1,colour2,colour3];
sum=ones(3);num=zeros(3);selfrate=[0.28,0.35,0.42];condirate=[0.41;0.35;0.29];
control=1;
%indi(randi(n),randi(n),1)=1;
stop=0;run=0;freeze=0;
while stop==0
    if run==1
        for i=1:3
            num(i)=floor(selfrate(i)*sum(i))+1;
        end
        for i=1:3
            for j=1:num(i)
                indi(randi(n),randi(n),i)=1;
            end
        end
        for i=1:n
            for j=1:n
                tmp=0;
                for t=1:3
                    tmp=tmp+indi(i,j,t);
                end
                if tmp>1
                    randtmp=zeros(3);
                    randrank=1:3;
                    for t=1:3
                        randtmp(t)=indi(i,j,t).*condirate(t).*rand();
                    end
                    for m=2:3
                        if randtmp(1)<randtmp(m)
                            a=[randtmp(1),randrank(1)];
                            randtmp(1)=randtmp(m);
                            randrank(1)=randrank(m);
                            randtmp(m)=a(1);
                            randrank(m)=a(2);
                        end
                    end
                    for t=1:3
                        if randrank(1)==t
                            indi(i,j,t)=1;
                        else
                            indi(i,j,t)=0;
                        end
                    end
                end
            end
        end
        sum=zeros(3);
        for t=1:3
            for i=1:n
                for j=1:n
                    if indi(i,j,t)==1
                        sum(t)=sum(t)+1;
                    end
                end
            end
        end
        for i=1:n
            for j=1:n
                for t=1:3
                    if indi(i,j,t)==1
                        for k=1:3
                            pic(i,j,k)=colour(k,t);
                        end
                        break;
                    end
                end
            end
        end
        figure(1)
        img=image(pic);
        for i=1:3
            set(number(i),'string',num2str(sum(i)));
        end
        control=control+1;
        controlvector(control)=control;
        for i=1:3
            sumtim(control,i)=sum(i);
        end
        %pause(1);
    end
    if freeze==1
        run=0;
        freeze=0;
        for i=1:3
            figure(2)
            p(i)=plot(controlvector,sumtim(:,i),'linewidth',2);
            hold on
            axis on
            grid on
        end
        legend(p,{'Species 1','Species 2','Species 3'});
        xlabel('time(Num. of Calculation)');
        ylabel('Size of species');
    end
    drawnow
end