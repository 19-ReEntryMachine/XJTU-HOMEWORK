clc;
clear all;
close all;

% 加载数据 训练数据集和验证数据集各包含5000个图像
[XTrain,~,YTrain] = digitTrain4DArrayData;
[XValidation,~,YValidation] = digitTest4DArrayData;

% 使用 imshow 显示 20 个随机训练图像
numTrainImages = numel(YTrain);
figure
idx = randperm(numTrainImages,20);
for i = 1:numel(idx)
    subplot(4,5,i)    
    imshow(XTrain(:,:,:,idx(i)))
    drawnow
end

% 检查数据归一化
figure
histogram(YTrain)
axis tight
ylabel('Counts')
xlabel('Rotation Angle')

% 创建网络层
layers = [
    imageInputLayer([28 28 1])

    convolution2dLayer(3,8,'Padding','same')
    batchNormalizationLayer
    reluLayer
    
    averagePooling2dLayer(2,'Stride',2)

    convolution2dLayer(3,16,'Padding','same')
    batchNormalizationLayer
    reluLayer
    
    averagePooling2dLayer(2,'Stride',2)
  
    convolution2dLayer(3,32,'Padding','same')
    batchNormalizationLayer
    reluLayer
    
    convolution2dLayer(3,32,'Padding','same')
    batchNormalizationLayer
    reluLayer
    
    dropoutLayer(0.2)
    fullyConnectedLayer(1)
    regressionLayer];

% 创建网络训练选项
miniBatchSize  = 128;
validationFrequency = floor(numel(YTrain)/miniBatchSize);
options = trainingOptions('sgdm', ...
    'MiniBatchSize',miniBatchSize, ...
    'MaxEpochs',30, ...
    'InitialLearnRate',1e-3, ...
    'LearnRateSchedule','piecewise', ...
    'LearnRateDropFactor',0.1, ...
    'LearnRateDropPeriod',20, ...
    'Shuffle','every-epoch', ...
    'ValidationData',{XValidation,YValidation}, ...
    'ValidationFrequency',validationFrequency, ...
    'Plots','training-progress', ...
    'Verbose',false);
% 使用 trainNetwork 创建网络。如果存在兼容的GPU，此命令会使用GPU。否则，trainNetwork 将使用CPU
net = trainNetwork(XTrain,YTrain,layers,options);
% 检查 net 的 Layers 属性中包含的网络架构的详细信息
net.Layers

YPredicted = predict(net,XValidation);

predictionError = YValidation - YPredicted;

thr = 10;
numCorrect = sum(abs(predictionError) < thr);
numValidationImages = numel(YValidation);

accuracy = numCorrect/numValidationImages

% 使用均方根误差 (RMSE) 来衡量预测旋转角度和实际旋转角度之间的差异
squares = predictionError.^2;
rmse = sqrt(mean(squares))

% 使用 reshape 按数字类对残差进行分组。
residualMatrix = reshape(predictionError,500,10);
figure
boxplot (residualMatrix) 


% 使用 imshow 显示 20 个随机训练图像
numTrainImages = numel(YValidation);
figure
idx = randperm(numTrainImages,20);
for i = 1:numel(idx)
    subplot(4,5,i)    
    imshow(XValidation(:,:,:,idx(i)))
    drawnow
end
