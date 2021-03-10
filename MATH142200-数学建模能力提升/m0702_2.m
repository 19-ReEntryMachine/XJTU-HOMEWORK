clear;clc   
W = [0 10 25 25 43 27 43 40 22 0 15 15 33 27 43 40 22 0 8 18 20 36 33 27 0 18 12 28 25 27 0 24 20 33 45 0 16 13 21 0 17 29 0 18 0];
DG = sparse([1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 4 4 4 4 4 4 5 5 5 5 5 6 6 6 6 7 7 7 8 8 9],[1 2 3 4 5 6 7 8 9 2 3 4 5 6 7 8 9 3 4 5 6 7 8 9 4 5 6 7 8 9 5 6 7 8 9 6 7 8 9 7 8 9 8 9 9],W)
UG=DG+DG'
view(biograph(UG,[],'ShowArrows','off','ShowWeights','on'))
[ST,pred] = graphminspantree(UG)
view(biograph(ST,[],'ShowArrows','off','ShowWeights','on'))
axis([0 40 0 40])
plot([0,5],[15,20],'k-','linewidth',2);
hold on
plot([5,16],[20,24],'k-','linewidth',2);
plot([16,20],[24,20],'k-','linewidth',2);
plot([16,33],[24,25],'k-','linewidth',2);
plot([20,23],[20,11],'k-','linewidth',2);
plot([23,35],[11,7],'k-','linewidth',2);
plot([23,25],[11,0],'k-','linewidth',2);
plot([25,10],[0,3],'k-','linewidth',2);
grid