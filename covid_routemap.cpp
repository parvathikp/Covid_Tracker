#include "civilian_class.hpp"
#include "civilians_functions.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include<tr1/unordered_map>
using namespace std;
int main(){
	int n,m;cout<<"Enter number of civilians"<<endl;cin>>n;cout<<"Enter total number of contacts"<<endl;cin>>m;
	string file;cout<<"Enter file with details(first n entries as name of civilians and next m as contacts"<<endl;cin>>file;
	file=file+".txt";int f=file.size();char d[f];for(int i=0;i<f;i++){
		d[i]=file[i];
	}community com;
	FILE* fp2;fp2=fopen(d,"r");int line_count=0;char line[1000];
	while(fgets(line,1000,fp2)){
		if(line_count<=n-1){
		char id[50];
		char name[50];
		 char colony[50];
		 char phone[10];
	     int stat;
	     int age;
		 int time;
		fscanf(fp2,"%s %s %s %s %d %d %d",id,name,colony,phone,&stat,&age,&time);com.addcivilian((string)id,stat,(string)name,age,time,(string)colony,(string)phone);
		}
		else{char id1[50],id2[50],place[50];int time;fscanf(fp2,"%s %s %s %d",id1,id2,place,&time);com.addcontact((string)id1,(string)id2,(string)place,time);
		}line_count++;
	}
	 return 0;
}