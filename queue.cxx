#include "queue.hxx"
#include <cassert>
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>


int main() {
  //  auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
  //   std::vector<int> vec(
  //   std::istream_iterator<int>(std::cin),
  //   std::istream_iterator<int>()
  // );
    int n_operations, x;
    char s;
    Quene<int,1000000>s1;

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