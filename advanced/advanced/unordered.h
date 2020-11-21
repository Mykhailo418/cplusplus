#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void unordered_main() {
	cout << "- Unordered: " << endl;
	unordered_set<string> un_s;
	unordered_map<string, int> un_m;
	unordered_multimap<string, int> unm_map;

	un_m.rehash(5); // reserves at least the specified number of buckets
	un_s.reserve(50); // reserves space for at least the specified number of elements

	un_m["2"] = 2;
	un_m["4"] = 4;
	// un_m["5"] = 4;

	// bucket like a cell with hash number
	cout << un_m.bucket("2") << endl; // get bucket where value is placed
	cout << un_m.bucket("4") << endl;
	cout << un_m.bucket("0") << endl;
	cout << un_m.bucket("5") << endl;

	cout << "buckets sizes: " << endl;
	cout << "bucket 0 size: " << un_m.bucket_size(0) << endl; // returns the number of elements in specific bucket
	cout << "bucket 1 size: " << un_m.bucket_size(1) << endl;

	cout << "the number of buckets " << endl;
	cout << un_m.bucket_count() << endl; // returns the number buckets - elements at all
	cout << un_m.size() << endl; // if size() === bucket_count() there are no collisions, if size() > bucket_count() there is(are) colission(s)
	cout << un_m.max_bucket_count() << endl;

	cout << "average number of elements per bucket" << endl;
	cout << un_m.load_factor() << endl; // average number of elements per bucket
	cout << un_m.max_load_factor() << endl;

	un_m.hash_function();

	cout << un_m["2"] << " " << un_m["4"] << endl;

}