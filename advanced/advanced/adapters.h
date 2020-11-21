#pragma once
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void adapters_main() {
	cout << "- Adapters: " << endl;
	stack<int> st; // based on deque
	queue<int> qu; // based on deque

	priority_queue<int> prio; // based on vector

	prio.push(4);
	prio.push(3);
	prio.push(6);

	cout << "priority_queue" << endl;
	while (!prio.empty()) {
		cout << "priority_queue element: " << prio.top() << endl;
		prio.pop();
	}

	// stack
	st.push(4);
	st.push(3);
	st.push(6);

	cout << "stack" << endl;
	while (!st.empty())
	{
		cout << "stack element: " << st.top() << endl;
		st.pop();
	}

	// queue
	qu.push(4);
	qu.push(3);
	qu.push(6);

	cout << "queue" << endl;
	while (!qu.empty())
	{
		cout << "queue element: " << qu.front() << endl;
		qu.pop();
	}
}