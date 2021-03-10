%random celluar automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','运行', 'fontsize',12, 'position',[150,400,50,20], 'callback', 'run=1;');
erasebutton=uicontrol('style','pushbutton','string','停止','fontsize',12,'position',[250,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','退出','fontsize',12,'position',[350,400,50,20],'callback','stop=1;close;');
number1 = uicontrol('style','text','string','0','fontsize',12, 'position',[20,400,50,20]);
number2 = uicontrol('style','text','string','0','fontsize',12, 'position',[80,400,50,20]);
n=100;
pic=ones(n,n,3)*255;
img=image(pic);
indi=zeros(n,n,2);
colour1=[255;0;0];
colour2=[0;0;255];
sum1=0;sum2=0;rate11=0.5;rate22=0.3;rate12=0.8;%11值是1的增长率，22是2的增长率，12是1对2的相对优势(大于0.5即是优势，这个在下文中就能看出来)
%indi(randi(n),randi(n),1)=1;
stop=0;run=0;freeze=0; 
while stop==0
    if run==1
        num1=floor(rate11*sum1)+1;
        num2=floor(rate22*sum1)+1;
        for i=1:num1
            indi(randi(n),randi(n),1)=1;
        end
        for i=1:num2
            indi(randi(n),randi(n),2)=1;
        end
        for i=1:n
            for j=1:n
                if indi(i,j,2)+indi(i,j,1)>1
                    if rand()>rate12
                        indi(i,j,2)=0;
                    else
                        indi(i,j,1)=0;
                    end
                end
            end
        end
        sum1=0;sum2=0;
        for i=1:n
            for j=1:n
                if indi(i,j,1)==1
                    sum1=sum1+1;
                end
                if indi(i,j,2)==1
                    sum2=sum2+1;
                end
            end
        end
        for i=1:n
            for j=1:n
                if indi(i,j,1)==1
                    for k=1:3
                        pic(i,j,k)=colour1(k);
                    end
                end
                 if indi(i,j,2)==1
                    for k=1:3
                        pic(i,j,k)=colour2(k);
                    end
                 end
            end
        end
        img=image(pic);
        set(number1,'string',num2str(sum1));
        set(number2,'string',num2str(sum2));
        pause(1);
    end
    if freeze==1
        run=0;
        freeze=0;
    end
    drawnow
end