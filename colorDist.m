function [ imOut ] = colorDist( imIn )
%COLORDIST Check the color distribution around
% several points
%Normalize?

imIn = hsv2rgb(imIn);

%Check the colorfulness in a certain area.
% Saturation
[x,y,z] = size(imIn);

area1 = imcrop(imIn, [0 0 x/2 y/2]);
area2 = imcrop(imIn, [x/2 0 x y/2]);
area3 = imcrop(imIn, [0 y/2 x/2 y]);
area4 = imcrop(imIn, [x/2 y/2 x y]);

%Check the image 
area1ColorSat = area1(:,:,2);
area2ColorSat = area2(:,:,2);
area3ColorSat = area3(:,:,2);
area4ColorSat = area4(:,:,2);

%Sum all elements
area1ColorSat = sum(area1ColorSat(:));
area2ColorSat = sum(area2ColorSat(:));
area3ColorSat = sum(area3ColorSat(:));
area4ColorSat = sum(area4ColorSat(:));


imOut = {area1ColorSat area2ColorSat ... 
    area3ColorSat area4ColorSat};

end

