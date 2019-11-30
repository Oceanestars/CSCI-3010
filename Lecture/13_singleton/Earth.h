#ifndef _EARTH_H_
#define _EARTH_H_
//NAME: Oceane Andreis

class Earth {
public:
	//#2
	static Earth& GetInstance() {
		// gets instantiated the first time
		static Earth instance; // guaranteed to be destroyed

		return instance;
	}
		int random_num;
    int get_population() { return population_; };

    void IncreasePopulation() { population_ += 1; };

	// #3 Delete the methods we don't want
	Earth(Earth const&) = delete; // copy constructor
	void operator=(Earth const&) = delete; // assignment operator

 private:
	 //#1
 	Earth();  // private constructor

    int population_;

};  // class Earth

#endif  // _EARTH_H_
