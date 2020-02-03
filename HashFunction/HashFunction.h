#pragma once
#include <iostream>
#include <string>

template <typename K, typename V>
class tHashmap {
private:
	//Struct for the hash data
	struct hashData {
		int hash;
		K key;
		V value;
	};
	hashData * data;
	size_t dataCapacity;
	//Converts the given key and returns an integer value
	int hashed(K value) {
		int hashed = 0;
		for (int i = 0; i < value.size(); i++) {
			hashed += value[i];
		}
		return hashed;
	}
public:
	//Main startup function
	tHashmap() {
		data = new hashData[1];
		dataCapacity = 1;
		reset();
	}
	//Other start function to give it a set size
	tHashmap(size_t size) {
		dataCapacity = size;
		data = new hashData[dataCapacity];
		reset();
	}
	//Other start function that take a hashmap, then sets it to it
	tHashmap(const tHashmap & value) {
		data = value->data;
		dataCapacity = value->dataCapacity;
	}
	//Sets a hashmap equal to another hashmap
	tHashmap operator= (const tHashmap & value) {
		data = value->data;
		dataCapacity = value->dataCapacity;
	}
	//Deletes the data
	~tHashmap() {
		delete[] data;
	}

	//Resets the current hashmap
	void reset() {
		for (int i = 0; i < dataCapacity; i++) {
			data[i].hash = 0;
			data[i].value = 0;
		}
	}
	//Returns true of false based on whether or not the hashmap has anything in it
	bool empty() {
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].hash != 0) {
				return false;
			}
		}
		return true;
	}

	//Returns the size of how many hashes are in the hashmap based on the key
	size_t size() {
		size_t size = 0;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key != "") {
				size++;
			}
		}
		return size;
	}
	//Returns the size of how many times the given key was found in the hashmap
	size_t count(const K & key) {
		size_t size = 0;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == key) {
				size++;
			}
		}
		return size;
	}
	//Sets or returns the value at given key
	V & operator[] (const K & key) {
		int temp;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == key && data[i].hash == hashed(key)) {
				return data[i].value;
			}
			else {
				temp = i;
			}
		}
		return data[temp].value;
	}
	//Sets a value given the key, and makes a hash of the key
	void set(const K & key, const V & value) {
		int free;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == "") {
				free = i;
				break;
			}
			if (i == dataCapacity - 1) {
				std::cout << "No avalible space\n";//Maybe do something for adding it anyway
				return;
			}
		}
		data[free].value = value;
		data[free].key = key;
		data[free].hash = hashed(key);
	}
	//Returns the value of the hash at the given key
	V & at(const K & key) {
		int temp;
		for (int i = 0; i < dataCapacity; i++) {
			if (data[i].key == key) {
				return data[i].value;
			}
			else {
				temp = i;
			}
		}
		std::cout << "No data at given key";
		return data[temp].value;
	}
	//Sets or returns the constant value at given key
	const V & operator[] (const K & key) const {
		return data[hashed(key) % dataCapacity];
	}
	//Sets the size of the hashmap, then give new values if needed
	void setSize(size_t newCapacity) {
		hashData * temp = new hashData[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			if (i < dataCapacity) {
				temp[i] = data[i];
			}
			else {
				temp[i].hash = 0;
				temp[i].value = 0;
			}
		}
		dataCapacity = newCapacity;
		data = temp;
	}
};