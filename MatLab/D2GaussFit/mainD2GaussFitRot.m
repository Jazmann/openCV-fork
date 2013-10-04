%% Fit a 2D gaussian function to data
%% PURPOSE:  Fit a 2D gaussian centroid to simulated data
% Uses lsqcurvefit to fit
%
% INPUT:
% 
%   MdataSize: Size of nxn data matrix
%   x0 = [Amp,x0,wx,y0,wy,fi]: Inital guess parameters
%   x = [Amp,x0,wx,y0,wy,fi]: simulated centroid parameters
%   noise: noise in % of centroid peak value (x(1)
%   InterpolationMethod = 'nearest' or 'linear' or 'spline' or 'cubic'
%       used to calculate cross-section along minor and major axis
%     
%
%
% NOTE:
%   The initial values in x0 must be close to x in order for the fit
%   to converge to the values of x (especially if noise is added)
%
% OUTPUT:  non
%
% CREATED: G. Nootz  May 2012
% 
%  Modifications:
%  non
%% ---------User Input---------------------
% MdataSize = 50; % Size of nxn data matrix
% % parameters are: [Amplitude, x0, sigmax, y0, sigmay, angel(in rad)]
% x0 = [1,0,50,0,50,0]; %Inital guess parameters
% x = [2,2.2,7,3.4,4.5,+0.02*2*pi]; %centroid parameters
% noise = 10; % noise in % of centroid peak value (x(1))
% InterpolationMethod = 'nearest'; % 'nearest','linear','spline','cubic'
% FitForOrientation = 0; % 0: fit for orientation. 1: do not fit for orientation
% 
% %% ---Generate centroid to be fitted--------------------------------------
% xin = x; 
% noise = noise/100 * x(1);
% [X,Y] = meshgrid(-MdataSize/2:MdataSize/2);
% xdata = zeros(size(X,1),size(Y,2),2);
% xdata(:,:,1) = X;
% xdata(:,:,2) = Y;
% [Xhr,Yhr] = meshgrid(linspace(-MdataSize/2,MdataSize/2,300)); % generate high res grid for plot
% xdatahr = zeros(300,300,2);
% xdatahr(:,:,1) = Xhr;
% xdatahr(:,:,2) = Yhr;
% %---Generate noisy centroid---------------------
% Z = D2GaussFunctionRot(x,xdata);
% Z = Z + noise*(rand(size(X,1),size(Y,2))-0.5);

%% ---------User Input---------------------
MdataSize = 256; % Size of nxn data matrix
zMin =16/255 ; zMax = 235/255; zMid = (zMax+zMin)/2 ;
xMin = 16/255; xMax = 240/255; xMid = (xMax+xMin)/2 ;
yMin = 16/255; yMax = 240/255; yMid = (yMax+yMin)/2 ;
%   x0 = [Amp,x0,wx,y0,wy,fi]: Inital guess parameters
%   x = [Amp,x0,wx,y0,wy,fi]: simulated centroid parameters
% parameters are: [Amplitude, x0, sigmax, y0, sigmay, angel(in rad)]
x0 = [1,c3A,0.5,c2A,0.5,0]; %Inital guess parameters
x = x0; %centroid parameters
xin = x;
noise = 10; % noise in % of centroid peak value (x(1))
InterpolationMethod = 'nearest'; % 'nearest','linear','spline','cubic'
FitForOrientation = 0; % 0: fit for orientation. 1: do not fit for orientation

%% ---Generate centroid to be fitted--------------------------------------
[X,Y] = meshgrid(xMin:(xMax-xMin)/(MdataSize-1):xMax,yMin:(yMax-yMin)/(MdataSize-1):yMax);
xdata = zeros(size(X,1),size(Y,2),2);
xdata(:,:,1) = X;
xdata(:,:,2) = Y;
% [Xhr,Yhr] = meshgrid(linspace(0,MdataSize-1,300)); % generate high res grid for plot
% xdatahr = zeros(256,256,2);
% xdatahr(:,:,1) = X ;%Xhr;
% xdatahr(:,:,2) = Y ;%Yhr;
%--- Normalised Histogram data ---------------------
Z = bin/max(max(bin));

%% --- Fit---------------------
if FitForOrientation == 0
    % define lower and upper bounds [Amp,xo,wx,yo,wy,fi]
    lb = [0,xMin,0,yMin,0,-pi/4];
    ub = [realmax('double'),xMax,(1)^2,yMax,(1)^2,pi/4];
    [x,resnorm,residual,exitflag] = lsqcurvefit(@D2GaussFunctionRot,x0,xdata,Z,lb,ub);
else
    x0 =x0(1:5);
    xin(6) = 0; 
    x =x(1:5);
    lb = [0,xMin,0,yMin,0];
    ub = [realmax('double'),xMax,(1)^2,yMax,(1)^2];
    [x,resnorm,residual,exitflag] = lsqcurvefit(@D2GaussFunction,x0,xdata,Z,lb,ub);
    x(6) = 0;
end

%% ---------Plot 3D Image-------------
figure(1)
C = del2(Z);
mesh(X,Y,Z,C) %plot data
hold on
surface(X,Y,D2GaussFunctionRot(x,xdata),'EdgeColor','none') %Xhr,Yhr,D2GaussFunctionRot(x,xdatahr),'EdgeColor','none') %plot fit
axis([xMin xMax yMin yMax -noise noise+x(1)])
alpha(0.2)  
hold off

%% -----Plot profiles----------------
hf2 = figure(2);
set(hf2, 'Position', [20 20 950 900])
alpha(0)
subplot(4,4, [5,6,7,9,10,11,13,14,15])
imagesc(X(1,:),Y(:,1)',Z)
set(gca,'YDir','reverse')
colormap('jet')

string1 = ['       Amplitude','            X            ', '    X-Sigma','            Y            ','    Y-Sigma','     Angle'];
string2 = ['Set     ',num2str(xin(1), '% 100.3f'),'             ',num2str(xin(2), '% 100.3f'),'         ',num2str(xin(3), '% 100.3f'),'         ',num2str(xin(4), '% 100.3f'),'        ',num2str(xin(5), '% 100.3f'),'     ',num2str(xin(6), '% 100.3f')];
string3 = ['Fit      ',num2str(x(1), '% 100.3f'),'             ',num2str(x(2), '% 100.3f'),'         ',num2str(x(3), '% 100.3f'),'         ',num2str(x(4), '% 100.3f'),'        ',num2str(x(5), '% 100.3f'),'     ',num2str(x(6), '% 100.3f')];

text(xMin,+yMax+.04,string1,'Color','red')
text(xMin,+yMax+.08,string2,'Color','red')
text(xMin,+yMax+.12,string3,'Color','red')

%% -----Calculate cross sections-------------
% generate points along horizontal axis
m = -tan(x(6));% Point slope formula
b = (-m*x(2) + x(4));
xvh = xMin:(xMax-xMin)/(MdataSize-1):xMax;
yvh = xvh*m + b;
hPoints = interp2(X,Y,Z,xvh,yvh,InterpolationMethod);
% generate points along vertical axis
mrot = -m;
brot = (mrot*x(4) - x(2));
yvv = yMin:(yMax-yMin)/(MdataSize-1):yMax;
xvv = yvv*mrot - brot;
vPoints = interp2(X,Y,Z,xvv,yvv,InterpolationMethod);

hold on % Indicate major and minor axis on plot

% % plot pints 
% plot(xvh,yvh,'r.') 
% plot(xvv,yvv,'g.')

% plot lins 
plot([xvh(1) xvh(size(xvh))],[yvh(1) yvh(size(yvh))],'r') 
plot([xvv(1) xvv(size(xvv))],[yvv(1) yvv(size(yvv))],'g') 

hold off
axis([xMin xMax yMin yMax])
%%

xdatafit = linspace(xMin,xMax,MdataSize);
hdatafit = x(1)*exp(-(xdatafit-x(2)).^2/(2*x(3)^2));
vdatafit = x(1)*exp(-(xdatafit-x(4)).^2/(2*x(5)^2));
subplot(4,4, [1:3])
xposh = (xvh-x(2))/cos(x(6))+x(2);% correct for the longer diagonal if fi~=0
plot(xposh,hPoints,'r.',xdatafit,hdatafit,'black')
axis([xMin xMax yMin yMax])
subplot(4,4,[8,12,16])
xposv = (yvv-x(4))/cos(x(6))+x(4);% correct for the longer diagonal if fi~=0
plot(vPoints,xposv,'g.',vdatafit,xdatafit,'black')
axis([yMin*1.1 yMax*1.1 xMin xMax])
set(gca,'YDir','reverse')
figure(gcf) % bring current figure to front

% Because we need to have 000 to 255,255,255 ie black to white as an axis
% then we only need one point from the color space. this point may as well
% be the center or the gaussian fit, i.e. the mean. 

% Choose the principle axis to be the one with the larger variance.

if x(3) > x(5)
ycbcrAxis1 = [zMid, (xvh(length(xvh)) - xvh(1))+xMin, (yvh(length(yvh)) - yvh(1))+yMin ]
ycbcrAxis1 = ycbcrAxis1 ./ sqrt(ycbcrAxis1(2)^2 + ycbcrAxis1(3)^2)
ycbcrAxis1(1) = zMid;
ycbcrAxis2 = [zMid, (xvv(length(xvv)) - xvv(1))+xMin, (yvv(length(yvv)) - yvv(1))+yMin ]
ycbcrAxis2 = ycbcrAxis2 ./ sqrt(ycbcrAxis2(2)^2 + ycbcrAxis2(3)^2)
ycbcrAxis2(1) = zMid;
ycbcrAxis2o = [zMid, -1.*ycbcrAxis1(3), ycbcrAxis1(2) ]
rgbAxis1 = ycbcr2rgb(ycbcrAxis1) 
rgbAxis2 = ycbcr2rgb(ycbcrAxis2) 
rgbAxis2o = ycbcr2rgb(ycbcrAxis2o) 
else
rgbAxis2 = ycbcr2rgb([zMid, (xvh(length(xvh)) - xvh(1))+xMin, (yvh(length(yvh)) - yvh(1))+yMin ]) 
rgbAxis1 = ycbcr2rgb([zMid, (xvv(length(xvv)) - xvv(1))+xMin, (yvv(length(yvv)) - yvv(1))+yMin ]) 
rgbAxis2o = ycbcr2rgb([zMid, -1.*((yvv(length(yvv)) - yvv(1))+yMin), (xvv(length(xvv)) - xvv(1))+xMin ]) 
end

% for decent conversion to RGB the color needs to be in a small sphere
% around the center.
sphereN = 33;
sphereL = floor((sphereN - 1)/2);
sphereH = floor((sphereN + 1)/2);

ycbcrPoints = [zMid,zMid,zMid,zMid ;xvv(ceil(length(xvv) * sphereL / sphereN)), xvv(floor(length(xvv) * sphereH / sphereN)), xvh(ceil(length(xvh) * sphereL / sphereN)), xvh(floor(length(xvh) * sphereH / sphereN)) ; yvv(ceil(length(yvv) * sphereL / sphereN)), yvv(floor(length(yvv) * sphereH / sphereN)), yvh(ceil(length(xvv) * sphereL / sphereN)), yvh(floor(length(yvh) * sphereH / sphereN))]
rgbPoints = ycbcr2rgb(ycbcrPoints')
a1 = (rgbPoints(2,:) - rgbPoints(1,:) ) * 255 ;
a2 = rgbPoints(4,:) - rgbPoints(3,:) * 255 ;

% Scale sigma along the axis and fit to 0:255 scaled axis.
hdatafit = x(1)*exp(-(xdatafit-x(2)).^2/(2*x(3)^2));
vdatafit = x(1)*exp(-(xdatafit-x(4)).^2/(2*x(5)^2));
hSigma = (x(3) - xMin)/(xMax-xMin) * 255/cos(x(6));
vSigma = (x(5) - yMin)/(yMax-yMin) * 255/sin(x(6));
c = ycbcr2rgb([zMid, x(4),x(2)]);
 