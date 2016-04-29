function [ imOut ] = colorIlluWhole( imIn )
%COLORILLUWHOLE Check the illumination distribution in the image
% Must be a gray image.

%Convert to gray image
imIn = rgb2gray(imIn);

yIllu = imhist(imIn);

illuSum = 0;

%Calculate the sum of the RGB intensity 
%for the whole image
for k=1:256
   illuSum = illuSum + (yIllu(k) * k);
end

imOut = illuSum;
end

