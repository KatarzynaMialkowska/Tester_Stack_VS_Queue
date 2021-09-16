#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>

int main(int argc, char *argv[])
{
    std::uniform_int_distribution<int> dist1 ( 0,1000000 ); 
    std::uniform_int_distribution<int> dist2 ( 0,2 ); 
    std::mt19937 gen ( time ( NULL ) ); // Mersenne Twister 32bit pseudo-random generator 
    int n_operations;
    if(argc==2){   
       std::istringstream iss( argv[1] );
       if (iss >> n_operations){}
    }else n_operations=dist1 ( gen ); 
    int n_comm;
    
    std::cout<<n_operations<<"\n";
    for( int i = 0; i < n_operations; i++ )
    {
        n_comm = dist2 ( gen );
        if(n_comm==0) std::cout<<"A "<<dist1(gen) << "\n";
        if(n_comm==1) std::cout<<"D " << "\n"; 
        if(n_comm==2) std::cout<<"S " << "\n"; 
    
    }
 
    return 0;
} 