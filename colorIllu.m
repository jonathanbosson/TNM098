function [ colorIllu ] = colorIllu( imIn )
%COLORILLU Check distribution of illumination

%Convert to gray image
%imIn = rgb2gray(imIn);

%Check the illumination distribution in a certain area.
[x,y,z] = size(imIn);

area1 = imcrop(imIn, [0 0 x/2 y/2]);
area2 = imcrop(imIn, [x/2 0 x y/2]);
area3 = imcrop(imIn, [0 y/2 x/2 y]);
area4 = imcrop(imIn, [x/2 y/2 x y]);

%Check the image 
area1ColorDist = colorIlluWhole(area1);
area2ColorDist = colorIlluWhole(area2);
area3ColorDist = colorIlluWhole(area3);
area4ColorDist = colorIlluWhole(area4);

colorIllu = {area1ColorDist area2ColorDist ... 
    area3ColorDist area4ColorDist};

end

