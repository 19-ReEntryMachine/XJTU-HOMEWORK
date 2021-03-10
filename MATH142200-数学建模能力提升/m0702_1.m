W = [1 4 8 2 7 7 1 3 2 2 2 5 1 1 3 3 6 5 3 4 3 7 6 4 4 2 2 4 8 7 6 4 4 6]; 
DG = sparse([8 8 8 8 8 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 4 5 5 5 5 6 6 6 6 7 7 7 7],[1 5 6 2 4 6 8 3 2 1 8 4 3 2 1 4 7 2 3 7 5 8 7 4 8 6 5 7 8 1 5 6 4 3],W) %有权的有向图
h = view(biograph(DG,[],'ShowWeights','on')) 
[dist,path,pred] = graphshortestpath(DG,8,7) 
set(h.Nodes(path),'Color',[1 0.4 0.4]) 
edges = getedgesbynodeid(h,get(h.Nodes(path),'ID'));
set(edges,'LineColor',[1 0 0]) 
set(edges,'LineWidth',1.5) 
