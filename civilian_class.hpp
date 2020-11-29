//civilian_class.hpp
#ifndef civilian_class_hpp
#define civilian_class_hpp
#include <bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;

class community{
	protected:
	struct civilian;
	struct contact;
	struct civilian{
	     string id;
		 string name;
		 string colony;
		 string phone;
	     int covid_stat;
	     int age;
		 int contact_time;
	     list<contact*> contacts;
	 civilian(string id,int stat,string name,int age,int time,string colony,string phone):
	         id(id), covid_stat(stat), age(age),contact_time(time),phone(phone),colony(colony) {}
    };
    struct contact{
	     civilian* link;
	     string contactplace;
	     int days_after_contact;
	 contact(civilian* civ,string place,int time):
		link(civ), contactplace(place), days_after_contact(time) {}
    };
    std::tr1::unordered_map<string, civilian*>all;
    std::tr1::unordered_map<string, string>cluster_par;
    std::tr1::unordered_map<string, int>cluster_size;
    std::tr1::unordered_map<string, int>positive_size;
	public:
		   community();~community();
		   string find_par(string id);
		   void union1(string id1,string id2);
		   void addcivilian(string id,int stat,string name,int age,int time,string colony,string phone);
		   void addcontact(string id1,string id2,string place,int time);
		   void get_cluster(string id);
		   void largest_cluster();
		   int number_positive(string id);
		   
};
#endif