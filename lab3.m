% Lab 3
% Create a feature vector and compare the images.

%Read all files and store them in a cell
loadFiles;

% First argument image in database
% Second argument image to compare
[result, imFeat] = main(images,4);

%Sort the result
[B,I] = sort(result);

%Index
I

%Result
disp('Results')