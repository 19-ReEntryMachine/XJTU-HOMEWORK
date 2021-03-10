%random celluar automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','Run', 'fontsize',12, 'position',[250,400,50,20], 'callback', 'run=1;');
erasebutton=uicontrol('style','pushbutton','string','Pause','fontsize',12,'position',[350,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','Quit','fontsize',12,'position',[450,400,50,20],'callback','stop=1;close;');
number1 = uicontrol('style','text','string','0','fontsize',12, 'position',[0,400,50,20]);
number2 = uicontrol('style','text','string','0','fontsize',12, 'position',[50,400,50,20]);
number3 = uicontrol('style','text','string','0','fontsize',12, 'position',[100,400,50,20]);
number4 = uicontrol('style','text','string','0','fontsize',12, 'position',[150,400,50,20]);
n=150;
pic=ones(n,n,3)*255;
img=image(pic);
indi=zeros(n,n,4);
colour1=[255;0;0];
colour2=[0;0;255];
colour3=[0;128;128];
colour4=[63;192;0];
colour=[colour1,colour2,colour3,colour4];
sum=ones(4);num=zeros(4);selfrate=[0.2,0.3,0.4,0.5];condirate=[0.6;0.5;0.4;0.3];%selfrate是自增长参数，condirate是适应性参数
condi=0;control=1;
for i=1:4
    condi=condi+condirate(i);
end
%indi(randi(n),randi(n),1)=1;
stop=0;run=0;freeze=0; 
while stop==0
    if run==1
        for i=1:4
            num(i)=floor(selfrate(i)*sum(i))+1;
        end
        for i=1:4
            for j=1:num(i)
                indi(randi(n),randi(n),i)=1;
            end
        end
        for i=1:n
            for j=1:n
                tmp=0;
                for t=1:4
                    tmp=tmp+indi(i,j,t);
                end
                if tmp>1
                    randtmp=zeros(4);
                    randrank=1:4;
                    for t=1:4
                        randtmp(t)=indi(i,j,t).*condirate(t).*rand();
                    end
                    for m=2:4
                        if randtmp(1)<randtmp(m)
                            a=[randtmp(1),randrank(1)];
                            randtmp(1)=randtmp(m);
                            randrank(1)=randrank(m);
                            randtmp(m)=a(1);
                            randrank(m)=a(2);
                        end
                    end
                    for t=1:4
                        if randrank(1)==t
                            indi(i,j,t)=1;
                        else
                            indi(i,j,t)=0;
                        end
                    end
                end
            end
        end
        sum=zeros(4);
        for t=1:4
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
                for t=1:4
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
        set(number1,'string',num2str(sum(1)));
        set(number2,'string',num2str(sum(2)));
        set(number3,'string',num2str(sum(3)));
        set(number4,'string',num2str(sum(4)));
        control=control+1;
        controlvector(control)=control;
        for i=1:4
            sumtim(control,i)=sum(i);
        end
        %pause(1);
    end
    if freeze==1
        run=0;
        freeze=0;
        for i=1:4
            figure(2)
            p(i)=plot(controlvector,sumtim(:,i),'linewidth',2);
            hold on
            axis on
            grid on
        end
        legend(p,{'Species 1','Species 2','Species 3','Species 4'});
        xlabel('time(Num. of Calculation)')
        ylabel('Size of species')
    end
    drawnow
end