#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
	    public:
		    T elem;
		    BSNode<T>* left;
		    BSNode<T>* right;
		    BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){
			    this->right = right;
			    this->left = left;
			    this->elem = elem;
		    }
		    friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
			    return out << "Elemento: " << bsn.elem << std::endl;
		    }
		     
};
#endif
