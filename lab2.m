% Data dimensions: time,id,duration,gpIndex,x,y
data = csvread('eyetrack.csv');


% plot of gaze points on screen over the entire duration.
%plot (data(:,5), data(:,6), '.')

% Spatial clustering
X = [data(:,5) data(:,6)]

[idx,ctrs] = kmeans(X,5,'Distance','city',...
              'Replicates',5);

%// Plot starts here
figure,hold on

%// Set x and y limits of the plot
xlim([0 max(data(:,5))+50])
ylim([0 max(data(:,6))+50])

%// Plot point by point
for k = 1:size(data,1)
    color = 'r.';
    if(idx(k) == 2)
        color = 'b.';
    end
    if(idx(k) == 3)
        color = 'g.';
    end
    if(idx(k) == 4)
        color = 'y.';
    end
    if(idx(k) == 5)
        color = 'k.';
    end
    plot(data(k,5),data(k,6), color) %// Choose your own marker here
    
    %// MATLAB pauses for 0.001 sec before moving on to execue the next 
    %%// instruction and thus creating animation effect
    pause(0.001);     
end

% Cluster by duration
X2 = [data(:,3)]

[idx2,ctrs2] = kmeans(X2,3,'Distance','city',...
              'Replicates',5);

%// Plot starts here
figure
hold on

%// Set x and y limits of the plot
xlim([0 max(data(:,5))+50])
ylim([0 max(data(:,6))+50])

%// Plot point by point
for k = 1:size(data,1)
    color = 'r.';
    if(idx2(k) == 2)
        color = 'b.';
    end
    if(idx2(k) == 3)
        color = 'g.';
    end
    plot(data(k,5),data(k,6), color) %// Choose your own marker here
    
    %// MATLAB pauses for 0.001 sec before moving on to execue the next 
    %%// instruction and thus creating animation effect
    pause(0.001);     
end
