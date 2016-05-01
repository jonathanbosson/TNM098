function [ resultVec, imagesFeature ] = main(images, compImage)
%MAIN function the runs through lab3.m

disp('Loop through all the images')
for k = 1:numel(images)
    
    %Current image
    disp(k)
    image = images{k};
    
    %Color balance with gray world
    image = grayWorld(image); 
    
    % 1: Check total color distribution
    colCont = colorCont(image); 
    imageFeature(1) = colCont(1); %Amount of Red
    imageFeature(2) = colCont(2); %Amount of Green
    imageFeature(3) = colCont(3); %Amount of Blue
    
    % 3: Check illumination for whole image
    colIlluWhole = colorIlluWhole(image);
    imageFeature(4) = colIlluWhole; %Illumination whole image
    
    % 4: Check illumination in four regions
    colIllu = colorIllu(image);
    imageFeature(5) = colIllu{1}; %Illumination area 1
    imageFeature(6) = colIllu{2}; %Illumination area 2
    imageFeature(7) = colIllu{3}; %Illumination area 3 
    imageFeature(8) = colIllu{4}; %Illumination area 4
    
    % 5: Check aspect ration of image
    % Not used in res as of now
    imgRatio = imageRatio(image);
    imageFeature(9) = imgRatio; %Aspect ratio
    
    % 6: Check face
    imageFeature(10) = findFace(image);
    
    % 7: Check color distribution in four regions
    % using saturation
    colDist = colorDist(image);
    imageFeature(11) = colDist{1}; %Area 1
    imageFeature(12) = colDist{2}; %Area 2
    imageFeature(13) = colDist{3}; %Area 3
    imageFeature(14) = colDist{4}; %Area 4
    
    % 8: Check edges
    %edgeImg = edgeDetec(image);
    %imageFeature{4} = edgeImg;
    
    %Weight
    
    
    %Save the features for this image
    imagesFeature{k} = imageFeature;
    
end

%Image to be compared
im = imagesFeature{compImage};

disp('Euclidian distance')
for h=1:12
    resultVec(h) = norm(im - imagesFeature{h});
end

end

