// This program calculates the graphics quality the user will be able to run on a newly develooped video game based on the specifications of their computer's hardware.

#include <iostream>

using namespace std;

int main()
{
int GPUspeed = 0, CPUspeed = 0, cores = 0, resolutionChoice = 0;
float multiplier = 0.0, performanceScore = 0.0;
string graphicsQuality = "", headerText = "Computer Hardware Graphics Quality Recommendation Tool";
int resolutionMatrix[4][2] ={
{1280, 720},
{1920, 1080},
{2560, 1440},
{3840, 2160}
};
cout << "Please enter the clock speed (in Megahertz) of your graphics card: ";
cin >> GPUspeed;
      
cout << "Please enter the clock speed (in Megahertz) of your processor: ";
cin >> CPUspeed;
      
cout << "Please enter the number of cores of your processor: ";
cin >> cores;
      
//display resolutionMatrix
cout << "What is the resolution of your monitor?" << endl;
for(int i=0; i<4; i++)
cout << i+1 << ". " << resolutionMatrix[i][0] << " x " << resolutionMatrix[i][1] << endl;
cout<<"Please select from the options above: ";
cin >> resolutionChoice;
      
switch(resolutionChoice){
case 1 : multiplier = 1;
break;
case 2 : multiplier = 0.75;
break;
case 3 : multiplier = 0.55;
break;
case 4 : multiplier = 0.35;
break;
default : cout << "Wrong choice input!";
exit(0);
}
      
//calculate performanceScore
//Performance Score = ((5 * GPU Clock Speed) + (Number of Cores * CPU Clock Speed)) * Multiplier
performanceScore = ((5*GPUspeed) + (cores*CPUspeed))*multiplier;
      
//determine graphicsQuality
if(performanceScore >= 17000)
graphicsQuality="Ultra";
else if(performanceScore >= 15000)
graphicsQuality="High";
else if(performanceScore >= 13000)
graphicsQuality="Medium";
else if(performanceScore >= 11000)
graphicsQuality="Low";
else
graphicsQuality="Unable to play.";
      
//output results
cout << headerText << endl;
cout << "GPU Clock Speed: " << GPUspeed << " MHz" << endl;
cout << "CPU Clock Speed: " << CPUspeed << " MHz" << endl;
cout << "Number of cores: " << cores << endl;
cout << "Monitor Resolution: " << resolutionMatrix[resolutionChoice-1][0] << " x " << resolutionMatrix[resolutionChoice-1][1] << endl;
cout << "Performance Score: " << performanceScore << endl;
cout << "Recommended Graphics Quality: " << graphicsQuality << endl;
return 0;
}

