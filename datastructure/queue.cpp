#include<iostream>
#include<exception>
using namespace std;


const int MAXN  = 5;

class Queue {
	public:
		Queue(): head(0), tail(0), size(0) {
		}

		void enqueue(int data) {
			if (size == MAXN) {
				cout << "overflow" << endl;
				throw overflow_error("queue is full");
			}
			container[tail++] = data;
			size++;
			if (tail == MAXN) {
				tail = 0;
			}
		}

		int dequeue() {
			if (size == 0) {
				cout << "underflow" << endl;
				throw underflow_error("queue is empty");
			}

			int ret = container[head++];
			size--;
			if (head == MAXN) {
				head = 0;
			}

			return ret;
		}

		void print() {
			for (int i = 0; i < MAXN; i++) {
				cout << container[i] << " ";
			}
			cout << endl;
		}
	private:
		int head;
		int tail;
		int size;
		int container[MAXN];
};

int main() {
	Queue q;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(1);
	q.dequeue();
	q.enqueue(3);
	q.enqueue(3);
	q.print();

	try {
		q.enqueue(3);
	} catch (const std::exception& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}
