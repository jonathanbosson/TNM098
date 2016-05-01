function [ imOut ] = imageRatio( imIn )
%IMAGERATIO check image aspect ratio

m = size(imIn,1);
n = size(imIn,2);

AR = n/m;

imOut = AR;
end

