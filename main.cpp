#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <iomanip>

double average(std::vector<double> x,int n){
	double sum_i = 0.0;
	for(int i=0;i<=x.size();i++){
		sum_i += x[i];
	};
		
	double s = sum_i/n;
	return s;
}

double resizeing(double y){
	double z = (3.0/4.0) *y - (7.0/4.0);
	return z;
}

int main()
{
    std::ifstream file_i("data.txt");// fstr.open("data.txt);
	    if (file_i.fail()) { 
        std::cerr << "Impossibile aprire il file!" << std::endl;
        return 1; 
    }
    std::ofstream file_o("output.txt", std::ios::trunc);
	file_o << "# N Mean"<<"\n";
	std::string line;
    unsigned int val;
	std::vector<double> v;
	int n=1;
    while (std::getline(file_i, line))
    {
          double num = std::stold(line);
          double resize_num = resizeing(num);
          v.push_back(resize_num);
		  double avg = average(v,n);
		  std::cout << n << " " << std::scientific << std::setprecision(16) << avg << std::endl;
		  file_o << n << " " << std::scientific << std::setprecision(16) << avg << "\n";
		  file_o.flush();
		  n+=1;	  
	};
	file_i.close();
	file_o.close();	  
    return 0;
}
