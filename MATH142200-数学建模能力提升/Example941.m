clc;
clear all;
close all;

% �������� ѵ�����ݼ�����֤���ݼ�������5000��ͼ��
[XTrain,~,YTrain] = digitTrain4DArrayData;
[XValidation,~,YValidation] = digitTest4DArrayData;

% ʹ�� imshow ��ʾ 20 �����ѵ��ͼ��
numTrainImages = numel(YTrain);
figure
idx = randperm(numTrainImages,20);
for i = 1:numel(idx)
    subplot(4,5,i)    
    imshow(XTrain(:,:,:,idx(i)))
    drawnow
end

% ������ݹ�һ��
figure
histogram(YTrain)
axis tight
ylabel('Counts')
xlabel('Rotation Angle')

% ���������
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

% ��������ѵ��ѡ��
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
% ʹ�� trainNetwork �������硣������ڼ��ݵ�GPU���������ʹ��GPU������trainNetwork ��ʹ��CPU
net = trainNetwork(XTrain,YTrain,layers,options);
% ��� net �� Layers �����а���������ܹ�����ϸ��Ϣ
net.Layers

YPredicted = predict(net,XValidation);

predictionError = YValidation - YPredicted;

thr = 10;
numCorrect = sum(abs(predictionError) < thr);
numValidationImages = numel(YValidation);

accuracy = numCorrect/numValidationImages

% ʹ�þ�������� (RMSE) ������Ԥ����ת�ǶȺ�ʵ����ת�Ƕ�֮��Ĳ���
squares = predictionError.^2;
rmse = sqrt(mean(squares))

% ʹ�� reshape ��������Բв���з��顣
residualMatrix = reshape(predictionError,500,10);
figure
boxplot (residualMatrix) 


% ʹ�� imshow ��ʾ 20 �����ѵ��ͼ��
numTrainImages = numel(YValidation);
figure
idx = randperm(numTrainImages,20);
for i = 1:numel(idx)
    subplot(4,5,i)    
    imshow(XValidation(:,:,:,idx(i)))
    drawnow
end
