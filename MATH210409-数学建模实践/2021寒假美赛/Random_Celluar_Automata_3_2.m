%random celluar automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','����', 'fontsize',12, 'position',[250,400,50,20], 'callback', 'run=1;');             %UI Bottom Settings,
erasebutton=uicontrol('style','pushbutton','string','ֹͣ','fontsize',12,'position',[350,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','�˳�','fontsize',12,'position',[450,400,50,20],'callback','stop=1;close;');
number1 = uicontrol('style','text','string','0','fontsize',12, 'position',[0,400,50,20]);
number2 = uicontrol('style','text','string','0','fontsize',12, 'position',[50,400,50,20]);
number3 = uicontrol('style','text','string','0','fontsize',12, 'position',[100,400,50,20]);
number4 = uicontrol('style','text','string','0','fontsize',12, 'position',[150,400,50,20]);
number5 = uicontrol('style','text','string','0','fontsize',12, 'position',[200,400,50,20]);
n=150;                                                                                         %����ͼƬ�ļ��γ߶ȣ���ΪͼƬ����һ����ά���飨pic�������ڴ���ͼƬ�ϸ������ص�RGB��ֵ
pic=ones(n,n,3)*255;
img=image(pic);
indi=zeros(n,n,5);                                                                             %����һ����ά���飬���ڴ�����Ⱥ��Ϣ��ע�⣺�������������������ص���ͼƬ�е�λ�ã�����������������Ⱥ�Ĵ����ԣ�1Ϊ���ڣ�0Ϊ������
colour1=[255;0;0];                                                                             %Ϊ�����ַ�����ɫ�����ڱ����ÿ����������Ⱥ�Ĵ�����
colour2=[0;0;255];
colour3=[0;128;128];
colour4=[63;192;0];
colour5=[63;0;192];
colour=[colour1,colour2,colour3,colour4,colour5];
sum=ones(5);num=zeros(5);selfrate=[0.15,0.3,0.4,0.45,0.48];condirate=[0.9;0.5;0.4;0.35;0.32];  %����/��ʼ����������������sum����Ⱥ�ڵ�һʱ���µ�������num���ڵ���ѭ����������������Ⱥ��������������selfrate��������������condirate����Ӧ�Բ���
control=1;                                                                                     %control�ǿ��Ʊ��������ڼ���ѭ�����е��ܴ���
%indi(randi(n),randi(n),1)=1;
stop=0;run=0;freeze=0;                                                                         %��ʼ��UI��ť
while stop==0                                                                                  %�����ǰ��¿�ʼ�������Զ�ִ������ѭ��
    if run==1
        for i=1:5                                                                              %���㵥��ѭ����������������Ⱥ����������������һ�����ǻ���Malthusģ�ͼ����
            num(i)=floor(selfrate(i)*sum(i))+1;
        end
        for i=1:5
            for j=1:num(i)
                indi(randi(n),randi(n),i)=1;                                                   %���ݼ���õ�����������ƽ���������¸��壨���������������λ���ϱ�����ֵĴ����ԣ���ע�⣬�����ͬʱ������������ܣ�һ�����Ƿ�ֳ�����������¸��壻��һ���������ھ�������ΪĳЩ�������������λ�á�����ԭ���Ѿ��д���Ⱥ���ڵ�λ���ص��������ص����´������Ͻ�һ���ָ��屻�����ǡ����������ھ������ڱ���̭
            end
        end                                                                                    %���ˣ������������Malthusģ����Logisticģ�͵�������
        for i=1:n
            for j=1:n
                tmp=0;
                for t=1:5
                    tmp=tmp+indi(i,j,t);                                                       %���ͼ������λ����ּ侺���Ĵ����ԣ������������Ⱥռ��ͬһ��λ�ã���ô�����������Ϊ���ھ������ڡ�
                end
                if tmp>1
                    randtmp=zeros(5);                                                          %����ָ��λ��������ھ����������õ����Ⱥ����Ӧ�Բ�������һ��������Ⱥ�������Ӧ�Բ�������Ⱥ�����ԡ����ɵ������������˶�������
                    randrank=1:5;
                    for t=1:5
                        randtmp(t)=indi(i,j,t).*condirate(t).*rand();                          %ѡ�������ҳ��ڸõ����������Ӧ�Բ�������Ⱥ
                    end
                    for m=2:5
                        if randtmp(1)<randtmp(m)
                            a=[randtmp(1),randrank(1)];
                            randtmp(1)=randtmp(m);
                            randrank(1)=randrank(m);
                            randtmp(m)=a(1);
                            randrank(m)=a(2);
                        end
                    end
                    for t=1:5                                                                  %�����ڸõ����һ����Ⱥ�����ڸõ���������Ӧ�Բ�������Ⱥ�����ڣ�������Ⱥ����̭
                        if randrank(1)==t
                            indi(i,j,t)=1;
                        else
                            indi(i,j,t)=0;
                        end
                    end
                end
            end
        end
        sum=zeros(5);                                                                          %���ü���������ͳ��ÿ����Ⱥ�Ĺ�ģ
        for t=1:5
            for i=1:n
                for j=1:n
                    if indi(i,j,t)==1
                        sum(t)=sum(t)+1;
                    end
                end
            end
        end
        for i=1:n                                                                              %���ոռ���õ��Ľ��Ͷ�䵽ͼƬ�����У���������������Ⱥ�ݻ���ͼƬ
            for j=1:n
                for t=1:5
                    if indi(i,j,t)==1                                                          %ͼƬ���ɵ�ԭ��Ϊ����ÿ������ռ�ݵ�����Ϳ�ϸ�����������Ⱥ��Ӧ����ɫ
                        for k=1:3
                            pic(i,j,k)=colour(k,t);
                        end
                        break;
                    end
                end
            end
        end
        figure(1)
        img=image(pic);                                                                        %���ͼƬ
        set(number1,'string',num2str(sum(1)));                                                 %������ʾ���ݣ���֤�ܹ���ʾ��Ⱥ��ģ��ʵʱ����
        set(number2,'string',num2str(sum(2)));
        set(number3,'string',num2str(sum(3)));
        set(number4,'string',num2str(sum(4)));
        set(number5,'string',num2str(sum(5)));
        control=control+1;                                                                     %����ѭ����������������õ�����Ⱥ��ģ�����ض������С�
        controlvector(control)=control;
        for i=1:5
            sumtim(control,i)=sum(i);
        end
        %pause(1);
    end
    if freeze==1
        run=0;
        freeze=0;                                                                              %�����ǰ�����ͣ��������������Ⱥ��ģ�ĺ�ʱ�仯�����ߣ���Ͷ�䵽ͬһ�Ż�����
        for i=1:5
            figure(2)
            p(i)=plot(controlvector,sumtim(:,i),'linewidth',1);
            hold on
            axis on
            grid on
        end
        legend(p,{'Species 1','Species 2','Species 3','Species 4','Species 5'});
        xlabel('time(Num. of Calculation)');
        ylabel('Size of species');
    end
    drawnow
end
%%��������ṹ��α���룺
%%Ϊ���������ռ䲢��ʼ����Щ������������ı����������ռ���ܴ�С��ÿ��������ͼ�϶�Ӧ����ɫ����Ⱥ�ڵ�һʱ���µ�����������ѭ����������������Ⱥ����������������������������Ӧ�Բ�����������Ⱥ��ƽ���ϸ�������Ե���ά���飬���ͼƬ��Ӧ����ά���飬���Ʊ���
%%if ��ʼ��ť������
%%����ÿ����Ⱥ�����������µĸ�������
%%���ݸ�������������ÿ����Ⱥ���¸��壬�������¸����ͬʱ������ھ�����ģ��
%%for �ռ��е�ÿ����
%%����õ㴦�ּ侺���Ĵ����ԣ������Ƿ���ͬһ���㴦����������Ⱥ
%%if �ּ侺������
%%����ÿ����Ⱥ�ڸõ������Ӧ����
%%�ҳ�����Ӧ��������߶�Ӧ����Ⱥ
%%�ж�������Ⱥ�ھ�����ʧ�ܣ��õ�ֻ���ڸո�ɸѡ������Ⱥ
%end
%end
%%ͳ��ͼ��������Ⱥ�Ĺ�ģ�������������Ⱥ�Ĵ�����Ͷ�䵽ͼƬ�ϣ����ͼƬ������Ⱥ��ʵʱ����
%%����ÿ��ѭ���õ���ʵʱ����
%%if ��ͣ��������
%%������ͣ�������м�
%%ѭ�������㱻��ͣ���������Ⱥ��ģ�ĺ�ʱ�仯����