class Vector {
        // this is defined in a header file
        // in vectors underlying array is dynamic
        int cur_size, max_size;
        int *arr; // pointer that will point to the dynamic array

    public:
        // default ctor
        Vector() {
            cur_size = 0;
            max_size = 1;
            arr = new int[max_size];
        }

        void push_back(const int d) {
            if(cur_size == max_size) {
                // the array is full, so allocate new memory
                int *oldArr = arr;
                arr = new int[2 * max_size];
                max_size = 2 * max_size;
                for(int i = 0; i < cur_size; i++) {
                    arr[i] = oldArr[i];
                }

                // clear the old memory
                delete [] oldArr;

            }
            arr[cur_size++] = d; // first assign and then update cur_size
        }

        void pop_back() {
            cur_size--;
            // here we are not implementing shrinking
        }
        // constant function as no changes are being made to any data member
        int front() const{
            return arr[0];
        }

        int back() const{
            return arr[cur_size - 1];
        }

        bool empty() const{
            return cur_size == 0;
        }
        
        int capacity() const{
            return max_size;
        }

        int at(const int index) {
            return arr[index];
        }

        // operator overloading
        int operator[](const int index) const{
            return arr[index];
        }

       /* simply written as
        int operator[](int i) {
            return arr[i];
        }
        */

        int size() const {
            return cur_size;
        }
};