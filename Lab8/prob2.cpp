#include<iostream>
template <typename T,class U,class P>

P sum2(T a,U b)
{
    return U(a+b);
}


int main()
{
    std::cout<<sum2<int,int,int>(2,2)<<' '<<sum2<float,int,float>(2.3,3)<<' '<<sum2<std::string,std::string,std::string>("ab","c");
    return 0;
}
