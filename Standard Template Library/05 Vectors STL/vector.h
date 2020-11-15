template<class T>
class Vector {
        // this is defined in a header file
        // in vectors underlying array is dynamic
        int cur_size, max_size;
        T *arr; // pointer that will point to the dynamic array

    public:
        // default ctor
        Vector() {
            cur_size = 0;
            max_size = 1;
            arr = new T[max_size];
        }

        void push_back(const T d) {
            if(cur_size == max_size) {
                // the array is full, so allocate new memory
                T *oldArr = arr;
                arr = new T[2 * max_size];
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
        T front() const{
            return arr[0];
        }

        T back() const{
            return arr[cur_size - 1];
        }

        bool empty() const{
            return cur_size == 0;
        }
        
        int capacity() const{
            return max_size;
        }

        T at(const int index) {
            return arr[index];
        }

        // operator overloading
        T operator[](const int index) const{
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