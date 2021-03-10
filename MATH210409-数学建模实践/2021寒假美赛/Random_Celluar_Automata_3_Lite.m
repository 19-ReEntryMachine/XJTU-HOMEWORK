%Random_Celluar_Automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','Run', 'fontsize',12, 'position',[250,400,50,20], 'callback', 'run=1;');
erasebutton=uicontrol('style','pushbutton','string','Pause','fontsize',12,'position',[350,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','Quit','fontsize',12,'position',[450,400,50,20],'callback','stop=1;close;');
for i=1:5
    number(i) = uicontrol('style','text','string','0','fontsize',12, 'position',[45*i-45,400,50,20]);
end
n=150;pic=ones(n,n,3)*255;img=image(pic);indi=zeros(n,n,5);
colour1=[255;0;0];colour2=[0;0;255];colour3=[0;128;128];colour4=[63;192;0];colour5=[63;0;192];
colour=[colour1,colour2,colour3,colour4,colour5];control=1;sum=ones(5);num=zeros(5);
selfrate=[0.15,0.25,0.33,0.45,0.58];condirate=[0.967;0.7;0.58;0.478;0.428];stop=0;run=0;freeze=0;
while stop==0
    if run==1
        for i=1:5
            num(i)=floor(selfrate(i)*sum(i))+1;
        end
        for i=1:5
            for j=1:num(i)
                indi(randi(n),randi(n),i)=1;
            end
        end
        for i=1:n
            for j=1:n
                tmp=0;
                for t=1:5
                    tmp=tmp+indi(i,j,t);
                end
                if tmp>1
                    randtmp=zeros(5);randrank=1:5;
                    for t=1:5
                        randtmp(t)=indi(i,j,t).*condirate(t).*rand();
                    end
                    for m=2:5
                        if randtmp(1)<randtmp(m)
                            a=[randtmp(1),randrank(1)];
                            randtmp(1)=randtmp(m);randrank(1)=randrank(m);
                            randtmp(m)=a(1); randrank(m)=a(2);
                        end
                    end
                    for t=1:5
                        if randrank(1)==t
                            indi(i,j,t)=1;
                        else
                            indi(i,j,t)=0;
                        end
                    end
                end
            end
        end
        sum=zeros(5);
        for t=1:5
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
                for t=1:5
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
        control=control+1;controlvector(control)=control;
        for i=1:5
            sumtim(control,i)=sum(i);
            set(number(i),'string',num2str(sum(i)));
        end
    end
    if freeze==1
        run=0;freeze=0;
        for i=1:5
            figure(2)
            p(i)=plot(controlvector,sumtim(:,i),'linewidth',2);
            hold on
            axis on
            grid on
        end
        legend(p,{'Species 1','Species 2','Species 3','Species 4','Species 5'});
        xlabel('time(Num. of Calculation)');ylabel('Size of species');
    end
end