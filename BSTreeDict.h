#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {
	    private:
		    BSTree<TableEntry<V>>* tree;
	    public:
		    BSTreeDict(){
			    tree = new BSTree<TableEntry<V>>();
		    }
		    ~BSTreeDict(){
			    delete tree;
		    }
	    	    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
			    out << *(bs.tree);
			    out << std::endl;
			    return out;
		    }
		    V operator[](std::string key){
			    return search(key);
		    }
		    void insert(std::string key, V value){
			    TableEntry<V> m(key,value);
			    tree->insert(m);
		    }
		    V search(std::string key){
			    TableEntry<V> a(key);
			    return tree->search(a).value;
		    }
		    V remove(std::string key){
			    TableEntry<V> a(key);
			    V num = search(key);
			    tree->remove(a);
			    return num;
		    }
		    int entries(){
			    return tree->size();
		    }


};
#endif
