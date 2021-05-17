#pragma once

struct MemInfo {

	void* ptr;
	char* fileName;
	int line;

};
namespace __MLC {

	class Stack {

	public:
		Stack(int cap = 1) {
			arr = (int*)malloc(sizeof(int) * cap);
		}

		void push(const int in) {
			if (cap == size) {
				resize(cap * 2);
				cap *= 2;
			}

			arr[size] = in;
			size += 1;
		}

		inline void pop() {
			size -= 1;
		}

		inline int front() {
			return arr[size - 1];
		}

		inline int getSize() {
			return size;
		}

#pragma region private func
	private:
		void resize(int nextCap) {
			int* prevArr = arr;

			arr = (int*)malloc(sizeof(int) * nextCap);

			memcpy_s(arr, nextCap, prevArr, cap);

			delete(prevArr);

		}
#pragma endregion

#pragma region private var
	private:
		int* arr;
		int cap;
		int size;
#pragma endregion

	};


	class List {

	public:

		using valueType = MemInfo*;

#pragma region public struct
	public:

		struct Node {

			valueType value;
			Node* parent;
			Node* child;
			int idx;

		};
#pragma endregion

	public:

		Node* first;

		List(int cap = 1) {
			this->cap = cap;
			allocArr(arr, cap);
		}

		void insert(valueType value, Node* parent = nullptr) {

			if (notUsedIdx.getSize() == 0) {
				resize(cap * 2);
				cap *= 2;
			}

			int idx = notUsedIdx.front();
			notUsedIdx.pop();

			arr[idx]->value = (valueType)malloc(sizeof(valueType));
			arr[idx]->parent = parent;
			arr[idx]->idx = idx;

			if (parent == nullptr) {
				first = arr[idx];
				arr[idx]->child = nullptr;
				return;
			}

			if (parent->child != nullptr) {
				arr[idx]->child = parent->child;
				parent->child->parent = arr[idx];
				parent->child = arr[idx];
			}
		}

		void erase(Node* node) {
			free(node->value);
			notUsedIdx.push(node->idx);
			
			Node* parent = node->parent;
			Node* child = node->child;

			if (parent != nullptr) {
				parent->child = child;
			}
			
			if (child != nullptr) {
				child->parent = parent;
			}
		}

#pragma region private func

		void allocArr(Node** arr, int cap) {

			arr = (Node**)malloc(sizeof(Node*) * cap);

			for (int idxCnt = 0; idxCnt < cap; idxCnt++) {
				arr[idxCnt] = (Node*)malloc(sizeof(Node));
				notUsedIdx.push(idxCnt);
			}
		}
		
		void resize(int nextCap) {
			Node** beforeArr = arr;

			allocArr(arr, nextCap);

		}

#pragma endregion

#pragma region private var
	private:

		Node** arr;
		int cap;
		Stack notUsedIdx;

	};
#pragma endregion
}

class MemoryLeakChecker {

public:

	
private:

	__MLC::List adr;

};
