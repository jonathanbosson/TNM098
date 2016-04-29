function [ imOut ] = colorDist( imIn )
%COLORDIST Check the color distribution around
% several points
%Normalize?

%Check the color distribution in a certain area.
[x,y,z] = size(imIn);

area1 = imcrop(imIn, [0 0 x/2 y/2]);
area2 = imcrop(imIn, [x/2 0 x y/2]);
area3 = imcrop(imIn, [0 y/2 x/2 y]);
area4 = imcrop(imIn, [x/2 y/2 x y]);

%Check the image 
area1ColorDist = colorCont(area1);
area2ColorDist = colorCont(area2);
area3ColorDist = colorCont(area3);
area4ColorDist = colorCont(area4);

imOut = {area1ColorDist area2ColorDist ... 
    area3ColorDist area4ColorDist};

end

