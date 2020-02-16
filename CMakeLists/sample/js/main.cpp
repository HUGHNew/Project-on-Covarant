#include<json/json.h>
#include<iostream>
#include<fstream>
int main(int argc,char **argv){
Json::Value value;
Json::Reader reader;
std::ifstream ifs(argv[1]);
reader.parse(ifs,value);
std::cout<<value["url"];
}
