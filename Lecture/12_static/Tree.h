#ifndef _TREE_H_
#define _TREE_H_

class Tree {
    public:

        virtual void Seed() { number_seeds_ += 1; };

        int get_number_seeds() { return number_seeds_; }
        static int count_tree(){return num_tree;};
        Tree(){num_tree++;};


    private:
        static int number_seeds_;
        static int num_tree;


};

class Pine : public Tree {
  public:
    void Seed() {Tree::Seed(); Tree::Seed(); };

};


#endif // _TREE_H_
