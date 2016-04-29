%READ IN THE IMAGES
%----------------------------------------------
% http://matlab.wikia.com/wiki/FAQ#How_can_I_process_a_sequence_of_files.3F
% Specify the folder where the files live.
myFolder = '.\images';
% Check to make sure that folder actually exists.  Warn user if it doesn't.
if ~isdir(myFolder)
  errorMessage = sprintf('Error: The following folder does not exist:\n%s', myFolder);
  uiwait(warndlg(errorMessage));
  return;
end
% Get a list of all files in the folder with the desired file name pattern.
filePattern = fullfile(myFolder, '*.jpg'); % Change to whatever pattern you need.
theFiles = dir(filePattern);
imageArray = size(12);
for k = 1 : length(theFiles)
  baseFileName = theFiles(k).name;
  fullFileName = fullfile(myFolder, baseFileName);
  fprintf(1, 'Now reading %s\n', fullFileName);
  % Now do whatever you want with this file name,
  % such as reading it in as an image array with imread()
  imageArray = imread(fullFileName);
  images{k} = imageArray; 
  %imshow(imageArray);  % Display image.
end

%Clear all variables except the cell array with images
clearvars -except images