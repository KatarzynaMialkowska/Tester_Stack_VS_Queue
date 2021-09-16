#include "stack.hxx"
#include <cassert>
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <string>
#include <sstream>
int main(int argc, char *argv[]) {
   
    //auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    int n_operations, x;
    char s;
    Stack<int,1000000>s1;
    
    std::cin >> n_operations;

      while(n_operations!=0){
        std::cin >> s;
        switch(s){
          
          case 'A':
              std::cin >> x;
              if(!s1.full()){
                s1.push(x);
              }else std::cout<<"Stack Overflow"<<"\n";
            break;
          
          case 'D':
              if(!s1.empty()) std::cout<<s1.pop()<<"\n";
              else std::cout<<"EMPTY"<<"\n";
            break;

          case 'S':
              std::cout<<s1.size()<<"\n";
            break;

          default:
            break;
        }

        n_operations--;
      }

    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << "\nElapsed time[s] =" <<elapsed.count() << std::endl;
  return 0;
}