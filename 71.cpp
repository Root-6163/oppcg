//input code (1):
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){

typedef map<string,int>maptype;
maptype populationmap
populationmap.insert(pair<string,int>("maharashtra :",709387));
populationmap.insert(pair<string,int>("Rajastan : ",298374));
populationmap.insert(pair<string,int>("kashmir :",234546));
populationmap.insert(pair<string,int>("punjab :",938472));

maptype::iterator iter;
cout<<"size of populatoin map"<<populationmap.size()<<endl;
string state_name;
cin>>state_name;
iter = populationmap.find(state_name);

if iter != populationmap.end(){
cout<<state_name<<" populatoin is"<<iter -> second;
else
cout<<"key is not populationmap"<<"\n";
population.clear();
}

