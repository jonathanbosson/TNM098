function colCont = colorCont( imIn )
%COLORDIST Check the color distribution in the image
%Normalize?

%Split into RGB Channels
red = imIn(:,:,1);
green = imIn(:,:,2);
blue = imIn(:,:,3);

%Get histValues for each channel
[yRed, x] = imhist(red);
[yGreen, x] = imhist(green);
[yBlue, x] = imhist(blue);

redSum = 0;
greenSum = 0;
blueSum = 0;

%Calculate the sum of the RGB intensity 
%for the whole image
for k=1:256
   redSum = redSum + (yRed(k) * k);
   greenSum = greenSum + (yGreen(k) * k);
   blueSum = blueSum + (yBlue(k) * k);
end

colCont = [redSum, greenSum, blueSum];

end

