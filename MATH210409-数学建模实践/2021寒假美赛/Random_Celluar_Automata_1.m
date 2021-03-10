%random celluar automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','运行', 'fontsize',12, 'position',[150,400,50,20], 'callback', 'run=1;');
erasebutton=uicontrol('style','pushbutton','string','停止','fontsize',12,'position',[250,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','退出','fontsize',12,'position',[350,400,50,20],'callback','stop=1;close;');
number1 = uicontrol('style','text','string','1','fontsize',12, 'position',[20,400,50,20]);
number2 = uicontrol('style','text','string','1','fontsize',12, 'position',[80,400,50,20]);
n=100;
pic=ones(n,n,3)*255;
img=image(pic);
colour1=[255;0;0];
colour2=[0,0,255];
sum1=1;sum2=1;rate11=0.32;rate22=0.31;rate12=0.4;%11值是1的增长率，22是2的增长率，12是1对2的相对优势(大于0.5即是优势，这个在下文中就能看出来)
position=[randi(n),randi(n)];
for i=1:3
    pic(position(1),position(2),i)=colour1(i);
end
position=[randi(n),randi(n)];
for i=1:3
    pic(position(1),position(2),i)=colour2(i);
end
stop=0;run=0;freeze=0; 
while stop==0
    if run==1
        num1=floor(rate11*sum1)+1;
        num2=floor(rate22*sum2)+1;
        for i=1:num1
            position=[randi(n),randi(n)];
            if [pic(position(1),position(2),1),pic(position(1),position(2),2),pic(position(1),position(2),3)]==[255,255,255]
                for j=1:3
                    pic(position(1),position(2),j)=colour1(j);
                end
                sum1=sum1+1;
            else if [pic(position(1),position(2),1),pic(position(1),position(2),2),pic(position(1),position(2),3)]==colour1
                    continue;
                else
                    if rand()<=rate12
                        for j=1:3
                            pic(position(1),position(2),j)=colour1(j);
                        end
                        sum1=sum1+1;
                        sum2=sum2-1;
                    end
                end
            end
        end
        for i=1:num2
            position=[randi(n),randi(n)];
            if [pic(position(1),position(2),1),pic(position(1),position(2),2),pic(position(1),position(2),3)]==[255,255,255]
                for j=1:3
                    pic(position(1),position(2),j)=colour2(j);
                end
                sum2=sum2+1;
            else if [pic(position(1),position(2),1),pic(position(1),position(2),2),pic(position(1),position(2),3)]==colour2
                    continue;
                else
                    if rand()>=rate12
                        for j=1:3
                            pic(position(1),position(2),j)=colour2(j);
                        end
                        sum1=sum1-1;
                        sum2=sum2+1;
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
%position=[randi(n),randi(n)];
%该自动机目前仍有缺陷，一是计数变量存在问题，二是模拟结果失真