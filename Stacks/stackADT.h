#include <cassert>

template <typename E>
class stackADT {
    public:
        stackADT() {
            capcity = 100;
            index_top = -1;
            s = new E[capcity];
        }

        bool empty() const {
            return index_top < 0;
        }

        const E& top() const {
            assert(!empty());
            return s[index_top];
        }

        void push(const E& val) {
            if(capcity == size()) {
                capcity = capcity * 5;
            }
            index_top++;
            s[index_top] = val;
        }

        void pop() {
            assert(!empty());
            index_top--;
        }

        int size() const {
            return index_top + 1;
        }

    private:
        E* s;           //a pointer array of what the data type passed in
        int capcity;    //the max amount of data the stack can hold
        int index_top;  //the index of the top of the stack
};