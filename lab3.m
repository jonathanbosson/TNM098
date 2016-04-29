% Lab 3
% Create a feature vector and compare the images.

%Read all files and store them in a cell
loadFiles;

%Loop through all the images
for k = 1:numel(images)
    
    %Current image
    image = images{k};
    
    %Check total color distribution
    colCont = colorCont(image);
    imageFeature{1} = colCont;
    
    %Check color distribution in four regions
    colDist = colorDist(image);
    imageFeature{2} = colDist;
    
    %Check illumination for whole image
    colIlluWhole = colorIlluWhole(image);
    imageFeature{3} = colIlluWhole;
    
    %Check illumination in four regions
    colIllu = colorIllu(image);
    imageFeature{4} = colIllu;
    
    %Check aspect ration of image
    imgRatio = imageRatio(image);
    imageFeature{5} = imgRatio;
    
    %Check edges
    %edgeImg = edgeDetec(image);
    %imageFeature{4} = edgeImg;
    
    %Check face
    %Color balance with gray world
    %imd = grayWorld(image); 
    
    imagesFeature{k} = imageFeature;
end
