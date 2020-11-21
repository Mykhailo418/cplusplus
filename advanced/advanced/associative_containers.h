#pragma once
#include <iostream>
#include <set>
#include <iterator>

using namespace std;

void assoc_containers_main() {
	cout << endl << "- Associative containers: " << endl;

	// set
	set<string> my_set = { "a", "a", "d", "big_string" }; // one "a" would be removed, only unique 

	cout << "my_set size: " << my_set.size() << endl;

	my_set.insert("ab");
	my_set.insert("dabd");

	auto it = my_set.find("d"); // return iterator
	my_set.emplace_hint(it, "de"); // place value withour copy and with hint
	auto st = my_set.equal_range("d"); // find value and bext after this value

	cout << "equal range: " << *st.first << endl;
	cout << "equal range: " << *st.second << endl;

	cout << "my_set - cout symbol 'a': " << my_set.count("a") << endl;

	for (auto el : my_set) {
		cout << "my_set el: " << el << endl;
	}

	// multiset

	multiset<string> multi_set = { "a", "a", "d", "big_string" };

	cout << endl << "multiset size: " << multi_set.size() << endl;

	multi_set.insert("ab");
	multi_set.insert("dabd");

	auto _it = multi_set.find("d");
	multi_set.emplace_hint(_it, "de");
	auto _st = multi_set.equal_range("d");

	cout << "equal range: " << *_st.first << endl;
	cout << "equal range: " << *_st.second << endl;

	cout << multi_set.count("a") << endl;

	for (auto el : multi_set) {
		cout << "multi_set el: " << el << endl;
	}

	// map
	map<string, int> my_map;

	my_map["as"] = 2;
	cout << "map: " << my_map.at("as") << endl;
	cout << my_map["a"] << endl; // if there is no value by such key, it will be created with 0 value
	cout << my_map.at("a") << endl; // in this case, if there is no value by such key, it will throw exception

}