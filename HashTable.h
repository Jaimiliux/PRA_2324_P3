#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include <string>
#include <typeinfo>

#include "../../P1/PRA_2324_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!
	template <typename V>
	class HashTable: public Dict<V> {
	private:
		int n;
		int max;
		ListLinked<TableEntry<V>>* table;
        
		int h(std::string key) const{
			char c;
			int suma = 0;
			for(int i = 0; i < key.size(); i++){
				c = key.at(i);
				suma += int(c);
			}
		return suma % max;
		}
	public:
		HashTable(int size){
			max = size;
			n = 0;
			table = new ListLinked<TableEntry<V>>[size];
		}
		~HashTable(){
			delete[] table;
		}
		int capacity() {
			return max;
		}
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
			for(int i = 0; i < th.max ; i++){
				out << "Cubeta : " << i << " \n ------------" << std::endl;
				for(int j = 0; j < th.table[i].size(); j++){
					out << th.table[i].get(j) << std::endl;
				}
				out << std::endl;
			}
			out << std::endl;
			return out;
		}
		V operator[](std::string key){	
			return search(key);
		}

		void insert(std::string key, V value){
			int pos = h(key);
			if(table[pos].search(key) == -1){
				TableEntry<V> entry(key,value);
				table[pos].append(entry);
				n++;
			}
			else{
				throw std::runtime_error("Elemento duplicado, no se puede insertar");
			}
		}

		V search(std::string key){
			int pos = h(key);
			int elem = table[pos].search(key);
			if(elem != -1){
				return table[pos].get(elem).value;
			}
				throw std::runtime_error("Error, elemnto no encontradao");
		}
		V remove(std::string key){
			int pos = h(key); 
			int elem;
			if(elem = table[pos].search(key) == -1){
				throw std::runtime_error("Error, elemento no encontrado");
			}
				n--;
				return table[pos].remove(elem).value;
		}
		int entries(){
			return n;
		}
	};
#endif
