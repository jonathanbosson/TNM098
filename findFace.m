function valueOut = findFace( im )
%Detect the face in the image
%   Viola-Jones algorthm is used

FDetect = vision.CascadeObjectDetector;

%Returns Bounding Box values based on number of objects
BB = step(FDetect,im);

%Returns 1 if true else 0
valueOut = isempty(BB);

end