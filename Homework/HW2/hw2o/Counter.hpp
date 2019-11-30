
/**
Oceane Andreis,  Abby Nay

Abby and I have both edited every single function.
We have done all of it together.
Homework 2
Date: October 1 2019
This program is my Counter.hpp
It includes map because of my map declaration
and it includes vector because I'm also declaring vectors.
I have my class Counter wrapped in a Template.
This class counter works like a map.

*/

//http://www.cplusplus.com/reference/map/map/erase/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <class T>
class Counter {
    // vector<T> not_empty;
    public:
    Counter();
    Counter(vector<T> v);

    void Increment(T input);
    void Decrement(T input);
    //with n
    void Increment(T input, int n);
    void Decrement(T input, int n);

    void Insert(T input);

    map<T,int>  MostCommon(int n);
    map<T,int>  LeastCommon(int n);

    int Range(T min, T max);
    void Remove(T input);
    int TotalCount();

    map<T,double> NormalizeWeights();
    map<T,int> GetMap();

    vector<T> Keys();
    vector<int> Values();

    template<class T2>
        friend ostream& operator<<(ostream& os, Counter<T2> c);
    template<class T3>
        friend ostream& operator<<(ostream& os, map<T3,double> m2);

    private:
    map<T,int> * map_;
    int sum=0;
};

/**
    Return nothing.(Constructor)

    @param vector of input.
    @return nothing.

*/
template <class T>
Counter<T>::Counter(vector<T> input) {
  map<T,int> *temp = new map<T,int>;
  map_ = temp;

  for(unsigned int i = 0; i<input.size(); i++)
  {
    Insert(input[i]);
  }


}

/**
    Return nothing.(Constructor)

    @param nothing.
    @return nothing.

*/
template <class T>
Counter<T>::Counter() {
  map<T,int> *temp = new map<T,int>;
  map_ = temp;

}

/**
    Return nothing.
    We are incrementing the value of our key by one
    @param input.
    @return nothing.

*/
template <class T>
void Counter<T>::Increment(T input) {
    /*typename map<T, int>::iterator it = map_->find(input);
    if(it != map_->end()){
        it->second++;
    }*/
    map_->at(input) += 1;
}

/**
    Return nothing.
    We are incrementing the value of our key by n
    @param input & int n.
    @return nothing.

*/
template <class T>
void Counter<T>::Increment(T input, int n) {
    typename map<T, int>::iterator it = map_->find(input);
    if(it != map_->end()){
        it->second+=n;
    }
}

/**
    Return nothing.
    We are checking to see if the key is already in the map if it isn't
    then we increase the count to one. If it is we increase the count by one.
    We are inserting the user input into the map
    @param input.
    @return nothing.

*/
template <class T>
void Counter<T>::Insert(T input) {
    bool in_map = false;
    for(auto it = map_->begin(); it != map_->end(); it++ ){
        if(it->first == input){
            Increment(input);
            in_map = true;
        }
    }
    if(!in_map){
       map_->insert(pair<T, int>(input, 1));
    }
}

/**
    Return nothing.
    We are Decrementing the value of our key by one
    @param input.
    @return nothing.

*/
template <class T>
void Counter<T>::Decrement(T input) {
    typename map<T, int>::iterator it = map_->find(input);
    if(it != map_->end()){
        it->second--;
    }
}

/**
    Return nothing.
    We are Decrementing the value of our key by n
    @param input.
    @return nothing.

*/
template <class T>
void Counter<T>::Decrement(T input, int n) {
    typename map<T, int>::iterator it = map_->find(input);
    if(it != map_->end()){
        it->second-=n;
    }
}

/**
    Return our map.
    We are printing out our map by using ostream
    @param ostream and Counter.
    @return os.

*/
template <class T2>
ostream& operator<<(ostream& os, Counter<T2> c){
    for( auto it = c.map_->begin(); it != c.map_->end(); it++ ) {
        os<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }
    return os;
}

/**
    Return our map.
    We are printing out our map by using ostream
    @param ostream and map.
    @return os.

*/
template <class T3>
ostream& operator<<(ostream& os, map<T3,double> m2){
    for ( auto it = m2.begin(); it !=m2.end(); it++){
        os<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }
    return os;
}


/**
    Return a map.
    We are finding the n most common key in our map
    @param int n.
    @return map.

*/
template <class T>
map<T,int> Counter<T>::MostCommon(int n) {
    vector <T> hold_key;
    vector <int> hold_value;
    int z = 0;
    T commonKey;
    map<T,int> map2;
    for( auto it = map_->begin(); it != map_->end(); it++ ) {
        hold_key.push_back(it->first);
        hold_value.push_back(it->second);
    }
    for (int j = 0 ; j < n; j++){
        int tmp = 0;
        int size = hold_value.size();
        for(int i = 0; i < size; i++){
            if (tmp<hold_value[i]){
                tmp = hold_value[i];
                z = i;
            }
        }
        commonKey = hold_key[z];
        map2.insert(pair<T, int>(commonKey,hold_value[z]));
    }
    return map2;
}

/**
    Return a map.
    We are finding the n least common key in our map
    @param int n.
    @return map.

*/
template <class T>
map<T,int> Counter<T>::LeastCommon(int n) {
    vector <T> hold_key;
    vector <int> hold_value;
    int z = 0;
    T leastKey;
    map<T,int> map2;
    for( auto it = map_->begin(); it != map_->end(); it++ ) {
        hold_key.push_back(it->first);
        hold_value.push_back(it->second);
    }
    int size = hold_value.size();
    for (int j = 0 ; j < n; j++){
        int tmp = hold_value[0];
        for(int i = 0; i < size; i++){
            if (tmp>hold_value[i]){
                tmp = hold_value[i];
                z = i;
            }
        }
        leastKey = hold_key[z];
        map2.insert(pair<T, int>(leastKey,hold_value[z]));
    }
    return map2;
}

/**
    Return an int.
    We are summing up the values in a certain rage
    @param T min & T max.
    @return an int.

*/
template <class T>
int Counter<T>::Range(T min, T max) {

    int sum = 0;
    for( auto it = map_->begin(); it != map_->end(); it++ ) {
        if(it->first >= min && it->first <=max){
            sum+=it->second;
        }
      }
    return sum;
  }

  /**
      Return an int.
      We are summing up all values in our map
      @param nothing.
      @return an int.

  */
template <class T>
int Counter<T>::TotalCount() {
    vector <int> hold_value;
    int sum2 =0;
    for( auto it = map_->begin(); it != map_->end(); ++it ) {
        hold_value.push_back(it->second);
    }
    int size = hold_value.size();
    for(int i=0 ; i<size; i++){
        sum2 += hold_value[i];
    }
    return sum2;
}


/**
    Return nothing.
    We are removing a key from the map
    @param an input(the key we want to delete).
    @return nothing.

*/
template <class T>
void Counter<T>::Remove(T input) {
    typename map<T, int>::iterator it = map_->find(input);
    if(map_->count(input) > 0){
        map_->erase(it);
    }
    else if (map_->count(input) == 0){
        cout<<"Object does not exist"<<endl;
    }
}

/**
    Return a map.
    We are calculating the normalize weight of each key object
    @param anothing.
    @return a map.

*/
template <class T>
map<T,double> Counter<T>::NormalizeWeights(){
    int total = this->TotalCount();
    map<T,double> map2;
    double percent;
    double val;
    for(auto it = map_->begin(); it != map_->end(); it++){
        val = (double)it->second;
        percent = (val/(double) total);
        map2.insert(pair<T, double>(it->first,percent));
    }
    return map2;
}

/**
    Return a map.
    We are getting the map
    @param anothing.
    @return a map.

*/
template <class T>
map<T,int> Counter<T>::GetMap(){
  return (*map_);
}

/**
    Return a vector.
    We are getting the keys
    @param nothing.
    @return a vector.

*/
template <class T>
std::vector<T> Counter<T>::Keys()
{
    std::vector<T> v;
    for(auto it = map_->begin(); it != map_->end(); it++){
       v.push_back(it->first);
    }
    return v;
}


/**
    Return a vector.
    We are getting the values
    @param nothing.
    @return a vector.

*/
template <class T>
std::vector<int> Counter<T>::Values()
{
    std::vector<int> v;
    for(auto it = map_->begin(); it != map_->end(); it++){
       v.push_back(it->second);
    }
    return v;
}
