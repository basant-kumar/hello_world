#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename lhsT,typename rhsT>
auto tf(lhsT & lhs,rhsT & rhs) -> decltype(lhs+rhs) {
    return (lhs+rhs);
}

int main( int argc, char ** argv ) {
    const char *str="this is c-string";
    string strobj("this is a string");
    auto z=tf(str,strobj);
    cout<<"value is "<<z<<endl;
    return 0;
}
