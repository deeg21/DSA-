#include<iostream>
#include<vector>
#include<string>
#include<iterator>

int main(int argc,char* argv[])
{
    std::vector<std::string> arguments;

    for(int i=0;i<argc;++i)
    {
       arguments.push_back(std::string(argv[i]));
    }
    for(std::vector<std::string>::iterator j=arguments.begin();j!=arguments.end();++j)
    std::cout<<*j<<std::endl;
}