#pragma once
#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

void lists_main() {
	cout << "- List and Forward List: " << endl;
	list<int> my_list;
	list<int> my_list2;
	forward_list<int> my_forward_my_list;
	forward_list<int> my_forward_my_list2;

	my_list.push_back(3);
	my_list2.push_front(1);
	my_list.splice(my_list.begin(), my_list2); // move elements from one list to another
	my_list.merge(my_list2);
	my_list.sort();
	my_list.emplace_front(); // the same as "push_front" but did not copy value

	for (auto elem : my_list) {
		cout << "my_list - elem: " << elem << endl;
	}

	cout << endl;

	my_forward_my_list.push_front(100); // have only push_front, there is no push_back

	my_forward_my_list.insert_after(my_forward_my_list.begin(), 7);
	//my_forward_my_list2.emplace_after(my_forward_my_list.begin(), 10); // be careful, in my_forward_my_list we put 10 after first element, my_forward_my_list2 is not changed

	cout << "Is my_forward_my_list2 empty? " << my_forward_my_list2.empty() << endl;

	cout << endl;

	my_forward_my_list2.push_front(111);
	my_forward_my_list.splice_after(my_forward_my_list.before_begin(), my_forward_my_list2);

	for (auto elem : my_forward_my_list) {
		cout << "my_forward_my_list - elem: " << elem << endl;
	}
}