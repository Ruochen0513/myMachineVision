function MyInteImg_result=MyInteImg(img)

%���ƻ���ͼ��ļ������

img = double(img);


[m,n]=size(img);

s = zeros(m, n);
ii = zeros(m, n);

% �����һ�е�һ�е��ۼӺͺͻ���ͼ��ֵ
s(1, 1) = img(1, 1);
ii(1, 1) = s(1, 1);

% �����һ�������е��ۼӺͺͻ���ͼ��ֵ
for j = 2:n
    s(1, j) = s(1, j-1) + img(1, j);
    ii(1, j) = s(1, j);
end
% �����һ�������е��ۼӺͺͻ���ͼ��ֵ
for i=2:m
    s(i, 1) = img(i, 1);
    ii(i, 1) = s(i, 1)+ii(i-1,1);
end
% ���������е��ۼӺͺͻ���ͼ��ֵ
for i = 2:m
    
    for j = 2:n
    s(i, j) = s(i, j-1) + img(i, j);
    ii(i, j) = ii(i-1, j) + s(i, j);
    end
end


MyInteImg_result = mat2gray(ii);
%����ԭͼ�����õ��Ļ���ͼ��MyInteImg_result
end