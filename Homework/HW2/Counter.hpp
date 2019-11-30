//http://www.cplusplus.com/reference/map/map/erase/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <class T>
class Counter {

  vector<T> not_empty;
public:
  Counter();
  Counter(vector<T> v);
  void Increment(T input);
  void Decrement(T input);
  //with n
  void Increment(T input, int n);
  void Decrement(T input, int n);
  void Insert(T input);
  void mostCommon(int n);
  void leastCommon(int n);
  int Range(int min, int max);
  void Remove(T input);
  int totalCount();



  template<class T2>
  friend ostream& operator<<(ostream& os, Counter<T2> c);

private:

    // Counter<T,v> not_empty;
    map<T,int> * map_;
    int sum=0;

};

template <class T>
Counter<T>::Counter() {
  map<T,int> *temp = new map<T,int>;
  map_ = temp;


}
template <class T>
Counter<T>::Counter(vector<T> input) {

  //Trying to initialize from a vector, told to do it in constructor

  not_empty = input;

}


template <class T>
void Counter<T>::Increment(T input) {
typename map<T, int>::iterator it = map_->find(input);
  if(it != map_->end())
  {
    it->second++;
  }
}
template <class T>
void Counter<T>::Increment(T input, int n) {
typename map<T, int>::iterator it = map_->find(input);
  if(it != map_->end())
  {
    it->second+=n;
  }
}

template <class T>
void Counter<T>::Decrement(T input) {
typename map<T, int>::iterator it = map_->find(input);
  if(it != map_->end())
  {
    it->second--;
  }
}

template <class T>
void Counter<T>::Decrement(T input, int n) {
typename map<T, int>::iterator it = map_->find(input);
  if(it != map_->end())
  {
    it->second-=n;
  }
}
//find & count & insert
//this class is a wrapper for map
template <class T>
void Counter<T>::Insert(T input) {
typename map<T, int>::iterator it = map_->find(input);
  if(map_->count(input) > 0)
  {
    Increment(input);
  }
  else if (map_->count(input) == 0)
  {
    map_->insert(pair<T, int>(input, 1));
  }
  it = map_->find(input);
  //cout for testing purposes
  // cout<<it->first<<endl;
  // cout<<it->second<<endl;

}
template <class T2>
ostream& operator<<(ostream& os, Counter<T2> c){

  //go through the map
  // pair<T2,string> p;
  for( auto it = c.map_->begin(); it != c.map_->end(); ++it ) {
  os<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
}



return os;
}


template <class T>
void Counter<T>::mostCommon(int n) {

  vector <T> hold_key;
  vector <int> hold_value;

  int z = 0;
  T commonKey;

  for( auto it = map_->begin(); it != map_->end(); ++it ) {
    hold_key.push_back(it->first);
    hold_value.push_back(it->second);
  }
  for (int j = 0 ; j < n; j++){
      int tmp = 0;
    for(int i = 0; i < hold_value.size(); i++)
    {

      if (tmp<hold_value[i])
      {
        tmp = hold_value[i];
        z = i;

      }
    }
  commonKey = hold_key[z];
  cout<<commonKey<<endl;
  hold_key.erase(hold_key.begin() + z);
  hold_value.erase(hold_value.begin() + z);

  }

}

template <class T>
void Counter<T>::leastCommon(int n) {

  vector <T> hold_key;
  vector <int> hold_value;

  int z = 0;
  T leastKey;

  for( auto it = map_->begin(); it != map_->end(); ++it ) {
    hold_key.push_back(it->first);
    hold_value.push_back(it->second);
  }
  for (int j = 0 ; j < n; j++){
      int tmp = hold_value[0]; //INT_MAX
    for(int i = 0; i < hold_value.size(); i++)
    {

      if (tmp>hold_value[i])
      {
        tmp = hold_value[i];
        z = i;

      }
    }
  leastKey = hold_key[z];
  cout<<leastKey<<endl;
  hold_key.erase(hold_key.begin() + z);
  hold_value.erase(hold_value.begin() + z);

  }

}

template <class T>
int Counter<T>::Range(int min, int max) {
  vector <int> hold_value;
  vector <T> hold_key;
  sum = 0;
  for( auto it = map_->begin(); it != map_->end(); ++it ) {
    hold_key.push_back(it->first);
    hold_value.push_back(it->second);
  }

  for(int i=0 ; i<hold_value.size(); i++)
  {
    if ((unsigned)(hold_key[i] - min) <= (max-min))
    sum += hold_value[i];
  }

  return sum;
}

template <class T>
int Counter<T>::totalCount() {
  vector <int> hold_value;

  for( auto it = map_->begin(); it != map_->end(); ++it ) {

    hold_value.push_back(it->second);
  }

  for(int i=0 ; i<hold_value.size(); i++)
  {
    sum += hold_value[i];
  }

  return sum;
}

template <class T>
void Counter<T>::Remove(T input) {

  typename map<T, int>::iterator it = map_->find(input);
    if(map_->count(input) > 0)
    {
      map_->erase(it);
    }
    else if (map_->count(input) == 0)
    {
      cout<<"Object does not exist"<<endl;
    }

}
