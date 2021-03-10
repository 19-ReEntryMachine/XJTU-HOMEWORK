clear;clc;
h1 = subplot(3,2,1);
h2 = subplot(3,2,2);
h3 = subplot(3,2,3);
h4 = subplot(3,2,4);
h5 = subplot(3,2,5);
h6 = subplot(3,2,6);
im1 = imread('figure_RCA_5_3_1.jpg');
im2 = imread('figure_RCA_5_3_2.jpg');
im3 = imread('figure_RCA_5_4_1.jpg');
im4 = imread('figure_RCA_5_4_2.jpg');
im5 = imread('figure_RCA_5_5_1.jpg');
im6 = imread('figure_RCA_5_5_2.jpg');
imshow(im1,'parent',h1)
imshow(im2,'parent',h2)
imshow(im3,'parent',h3)
imshow(im4,'parent',h4)
imshow(im5,'parent',h5)
imshow(im6,'parent',h6)