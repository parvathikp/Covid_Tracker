#ifndef civilians_functions_hpp
#define civilians_functions_hpp
#include "civilian_class.hpp"
#include <bits/stdc++.h>
#include <fstream>
#include<tr1/unordered_map>
using namespace std;
community::community(){}
community::~community(){}
string community::find_par(string id){
    if(cluster_par[id]==""){
	     return id;
}
	return cluster_par[id]=find_par(cluster_par[id]);
}
void community::addcivilian(string id,int stat, string name,int age,int time,string colony,string phone){
	all[id]=new civilian(id,stat,name,age,time,colony,phone);
	cluster_par[id]="";cluster_size[id]=1;
	if(stat){
	     positive_size[id]=1;
	}
	else{
	     positive_size[id]=0;
	}
	return;
}
void community::union1(string id1,string id2){
	string a=find_par(id1),b=find_par(id2);
	if(a==b){
	     return;
	}
	if(cluster_size[a]>=cluster_size[b]){
	     cluster_par[b]=a;
		 cluster_size[a]+=cluster_size[b];
		 positive_size[a]+=positive_size[b];
	return;}
	cluster_par[a]=b;
	cluster_size[b]+=cluster_size[a];
	positive_size[b]+=positive_size[a];
	return;
}
void community::addcontact(string id1,string id2,string place,int time){
	if(all[id1]==NULL || all[id2]==NULL){
	     return;
	}
	union1(id1,id2);
	(all[id1]->contacts).push_back(new contact(all[id2],place,time));
	(all[id2]->contacts).push_back(new contact(all[id1],place,time));
	return;
}
int community::number_positive(string id){
     string a=find_par(id);
	 return positive_size[a];
}

void community::get_cluster(string id){
     string j=id+".txt";
	 int g=j.size();
	 char c[g];
	 for(int i=0;i<g;i++){
	     c[i]=j[i];
     }
	 cout<<"The largest cluster is stored in file"<<endl;
	 FILE* fp;
	 fp=fopen(c,"w+");
	 std::tr1::unordered_map<string,int> visited;
	 queue<civilian*> q;
	 q.push(all[id]);
	 while(!q.empty()){
		civilian* cur=q.front();q.pop();
		visited[cur->id]=1;
		string s= cur->id+" "+cur->name+" "+cur->phone+"\n";
		int u=s.size();char t[u];
		for(int i=0;i<u;i++){
		     t[i]=s[i];
		}
		fputs(t,fp);
		list<contact*>::iterator it;
		for( it=(cur->contacts).begin();it!=(cur->contacts).end();it++){
			 if(!visited[((*it)->link)->id]){
			     q.push((*it)->link);
			}
		}
	}
return;}
void community::largest_cluster(){int max1=-1;
     string maxpar;
	 std::tr1::unordered_map<string, civilian*>::iterator it;
	 for(it=all.begin();it!=all.end();it++){
		     string a=it->first;
			 if(cluster_par[a]!=""){continue;
		     }if(positive_size[a]>=2 && cluster_size[a]>max1){
			      max1=cluster_size[a];maxpar=a;
		     }
	}
	cout<<"The largest cluster is stored in file max.txt and has size "<<max1<<endl;
	FILE* fp1;
	fp1=fopen("max.txt","w+");
	std::tr1::unordered_map<string,int> visited;
	queue<civilian*> q;
	q.push(all[maxpar]);
	while(!q.empty()){
		civilian* cur=q.front();q.pop();
		visited[cur->id]=1;
		string s= cur->id+" "+cur->name+" "+cur->phone+"\n";
		int g=s.size();char c[g];
		for(int i=0;i<s.size();i++){
		     c[i]=s[i];
		}
		fputs(c,fp1);
		list<contact*>::iterator it;
		for(it=(cur->contacts).begin();it!=(cur->contacts).end();it++){
			 if(!visited[((*it)->link)->id]){
				q.push((*it)->link);
			}
		}
	}
return;}
#endif