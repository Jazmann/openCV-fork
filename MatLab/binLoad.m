
xMin = 16/255; xMax = 240/255;
yMin = 16/255; yMax = 240/255;
[X,Y] = meshgrid(xMin:(xMax-xMin)/(MdataSize-1):xMax,yMin:(yMax-yMin)/(MdataSize-1):yMax);


bin(256,256) = 0;
c1 = 0;
c2 = 0;
c3 = 0;
c2T = 0;
c3T = 0;
cN = 0;


D = dir('Skin Samples/*.jpg');
imcell = cell(1,numel(D));
for k = 1:numel(D)
  imcell{k} = rgb2ycbcr(imread(strcat('Skin Samples/',D(k).name)));
  
[rows, cols, channels] = size(imcell{k});
for i = 1:rows
    for j = 1:cols
        c1 = imcell{k}(i,j,1)+1;
        c2 = imcell{k}(i,j,2)+1;
        c3 = imcell{k}(i,j,3)+1;
        bin(c2,c3) = bin(c2,c3) + 1;
    end
end

end


for i = 1:256
    for j = 1:256
        c2T = c2T + bin(j,i) * X(j,i);
        c3T = c3T + bin(j,i) * Y(j,i);
        cN = cN + bin(j,i);
    end
end

c2A = c2T/cN;
c3A = c3T/cN;


%[X, Y, Z] = meshgrid(0:1:254);

%scatter3(X(:),Y(:),Z(:),bin(:))