function MyInteImg_result=MyInteImg(img)

%完善积分图像的计算过程

img = double(img);


[m,n]=size(img);

s = zeros(m, n);
ii = zeros(m, n);

% 计算第一行第一列的累加和和积分图像值
s(1, 1) = img(1, 1);
ii(1, 1) = s(1, 1);

% 计算第一行其他列的累加和和积分图像值
for j = 2:n
    s(1, j) = s(1, j-1) + img(1, j);
    ii(1, j) = s(1, j);
end
% 计算第一列其他行的累加和和积分图像值
for i=2:m
    s(i, 1) = img(i, 1);
    ii(i, 1) = s(i, 1)+ii(i-1,1);
end
% 计算其他行的累加和和积分图像值
for i = 2:m
    
    for j = 2:n
    s(i, j) = s(i, j-1) + img(i, j);
    ii(i, j) = ii(i-1, j) + s(i, j);
    end
end


MyInteImg_result = mat2gray(ii);
%返回原图像计算得到的积分图像MyInteImg_result
end