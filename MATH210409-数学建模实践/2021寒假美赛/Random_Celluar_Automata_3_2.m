%random celluar automata
clear;clc;
plotbutton=uicontrol('style','pushbutton','string','运行', 'fontsize',12, 'position',[250,400,50,20], 'callback', 'run=1;');             %UI Bottom Settings,
erasebutton=uicontrol('style','pushbutton','string','停止','fontsize',12,'position',[350,400,50,20],'callback','freeze=1;');
quitbutton=uicontrol('style','pushbutton','string','退出','fontsize',12,'position',[450,400,50,20],'callback','stop=1;close;');
number1 = uicontrol('style','text','string','0','fontsize',12, 'position',[0,400,50,20]);
number2 = uicontrol('style','text','string','0','fontsize',12, 'position',[50,400,50,20]);
number3 = uicontrol('style','text','string','0','fontsize',12, 'position',[100,400,50,20]);
number4 = uicontrol('style','text','string','0','fontsize',12, 'position',[150,400,50,20]);
number5 = uicontrol('style','text','string','0','fontsize',12, 'position',[200,400,50,20]);
n=150;                                                                                         %设置图片的几何尺度，并为图片分配一个三维数组（pic），用于储存图片上个点像素的RGB数值
pic=ones(n,n,3)*255;
img=image(pic);
indi=zeros(n,n,5);                                                                             %分配一个三维数组，用于储存种群信息。注意：横纵坐标用于描述像素点在图片中的位置，竖坐标用于描述种群的存在性，1为存在，0为不存在
colour1=[255;0;0];                                                                             %为各物种分配颜色，用于标记在每个像素上种群的存在性
colour2=[0;0;255];
colour3=[0;128;128];
colour4=[63;192;0];
colour5=[63;0;192];
colour=[colour1,colour2,colour3,colour4,colour5];
sum=ones(5);num=zeros(5);selfrate=[0.15,0.3,0.4,0.45,0.48];condirate=[0.9;0.5;0.4;0.35;0.32];  %定义/初始化其他参数，其中sum是种群在单一时刻下的总数，num是在单次循环中理想条件下种群个体数的增量，selfrate是自增长参数，condirate是适应性参数
control=1;                                                                                     %control是控制变量，用于计量循环进行的总次数
%indi(randi(n),randi(n),1)=1;
stop=0;run=0;freeze=0;                                                                         %初始化UI按钮
while stop==0                                                                                  %若我们按下开始键，则自动执行下列循环
    if run==1
        for i=1:5                                                                              %计算单次循环中理想条件下种群个体数的增量，这一增量是基于Malthus模型计算的
            num(i)=floor(selfrate(i)*sum(i))+1;
        end
        for i=1:5
            for j=1:num(i)
                indi(randi(n),randi(n),i)=1;                                                   %依据计算得到的增量，在平面上生成新个体（即在随机产生的新位置上标记物种的存在性）。注意，此语句同时完成了两个功能：一方面是繁殖——产生了新个体；另一方面是种内竞争，因为某些“随机产生的新位置”会与原本已经有此种群存在的位置重叠，这种重叠导致从数量上讲一部分个体被“覆盖”，即在种内竞争环节被淘汰
            end
        end                                                                                    %至此，我们完成了由Malthus模型向Logistic模型的修正。
        for i=1:n
            for j=1:n
                tmp=0;
                for t=1:5
                    tmp=tmp+indi(i,j,t);                                                       %检测图形中诸位点的种间竞争的存在性：如果有两个种群占据同一个位置，那么我们则可以认为种内竞争存在。
                end
                if tmp>1
                    randtmp=zeros(5);                                                          %若在指定位点存在种内竞争，则计算该点各种群的适应性参数。这一参数由种群本身的适应性参数、种群存在性、生成的随机数三者相乘而产生。
                    randrank=1:5;
                    for t=1:5
                        randtmp(t)=indi(i,j,t).*condirate(t).*rand();                          %选择排序，找出在该点具有最大的适应性参数的种群
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
                    for t=1:5                                                                  %最终在该点仅有一个种群（即在该点具有最大适应性参数的种群）存在，其他种群被淘汰
                        if randrank(1)==t
                            indi(i,j,t)=1;
                        else
                            indi(i,j,t)=0;
                        end
                    end
                end
            end
        end
        sum=zeros(5);                                                                          %重置计数变量，统计每个种群的规模
        for t=1:5
            for i=1:n
                for j=1:n
                    if indi(i,j,t)==1
                        sum(t)=sum(t)+1;
                    end
                end
            end
        end
        for i=1:n                                                                              %将刚刚计算得到的结果投射到图片数组中，生成用于描述种群演化的图片
            for j=1:n
                for t=1:5
                    if indi(i,j,t)==1                                                          %图片生成的原则为：将每个个体占据的像素涂上个体所属的种群对应的颜色
                        for k=1:3
                            pic(i,j,k)=colour(k,t);
                        end
                        break;
                    end
                end
            end
        end
        figure(1)
        img=image(pic);                                                                        %输出图片
        set(number1,'string',num2str(sum(1)));                                                 %更新显示数据，保证能够显示种群规模的实时数据
        set(number2,'string',num2str(sum(2)));
        set(number3,'string',num2str(sum(3)));
        set(number4,'string',num2str(sum(4)));
        set(number5,'string',num2str(sum(5)));
        control=control+1;                                                                     %计量循环次数，并将计算得到的种群规模存入特定矩阵中。
        controlvector(control)=control;
        for i=1:5
            sumtim(control,i)=sum(i);
        end
        %pause(1);
    end
    if freeze==1
        run=0;
        freeze=0;                                                                              %若我们按下暂停键，则作出各种群规模的含时变化的曲线，并投射到同一张画框内
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
%%整个程序结构的伪代码：
%%为诸变量分配空间并初始化这些变量。被分配的变量包括：空间的总大小，每个物种在图上对应的颜色，种群在单一时刻下的总数，单次循环中理想条件下种群个体数的增量，自增长参数，适应性参数，描述种群在平面上各点存在性的三维数组，输出图片对应的三维数组，控制变量
%%if 开始按钮被按下
%%计算每个种群在理想条件下的个体增量
%%依据个体增量，生成每个种群的新个体，在生成新个体的同时完成种内竞争的模拟
%%for 空间中的每个点
%%计算该点处种间竞争的存在性，即，是否在同一个点处存在两个种群
%%if 种间竞争存在
%%生成每个种群在该点的自适应参数
%%找出自适应参数最大者对应的种群
%%判定其他种群在竞争中失败，该点只存在刚刚筛选出的种群
%end
%end
%%统计图中所有种群的规模，并将各点各种群的存在性投射到图片上；输出图片及各种群的实时数据
%%储存每次循环得到的实时数据
%%if 暂停键被按下
%%重置暂停键和运行键
%%循环的运算被暂停，输出各种群规模的含时变化曲线