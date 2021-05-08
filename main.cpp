#include <iostream>
using namespace std;
template <typename T>
class myArray {
private:
    int size;
    T *array;


public:
    /*
     * myArray() - default constructor
     * */
    myArray() {
        this->size = 10;
        array = new T[this->size];
    }
    /*
     * myArray(size) - if size is given this is the executed constructor
     * */
    myArray(int size) {
        this->size = size;
        array = new T[size];
    }

    ~myArray() {
        delete array;

    }

    /*
     * length() - return size of array
     * */
    int length() {
        return size;
    }

    /*
     * get(index) - returns value from element at that index
     * */
    T get(int index) {
        return array[index];
    }

    /*
     * getAddress(index) - returns address from element at that index
     * */
    // since i am returning an address the function must be a generic pointer
    T* getAddress(int index) {
        return &array[index];
    }

    /*
     * set(index, value) - sets a value at position index, in the array
     * */
    void set(int index, int value) {
        array[index] = value;
    }

    /*
     * isEmpty() - returns whether array is empty or not
     * */
    bool isEmpty() {
        return this->size == 0;
    }

    /*
     * isEqual(otherArr) - checks to see otherArr (of same type) is equal to this->array
     * */
    // the function takes in a address as a parameter
    bool isEqual(myArray &otherArr) {
        if(otherArr.length() != this->size) {
            return false;
        }
        for(int i=0; i < otherArr.length(); i++) {
            if(otherArr.get(i) != array[i]) {
                return false;
            }
        }
        return true;
    }



    void removeAt(int index) {

    }

    void removeDuplicates() {

    }

    void print() {
        for(int i=0; i<this->size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    /*
     * - sort should used by all arrays
     * */
    void sort() {
        sort(0, this->size - 1);
    }

    void sort(int lowIndex, int highIndex) {
        // checks to see if lowIndex and highIndex are valid
        if(lowIndex >= highIndex){
            return;
        }

        int newLowIndex = partition(lowIndex, highIndex);

        // goes to the right of the array
        sort(newLowIndex, highIndex);
        // goes to the left of the array
        sort(lowIndex, newLowIndex - 1);
    }

    /*
     * partition(lowIndex, highIndex) - takes the average of highIndex and lowIndex
     * and sorts depending on that average
     * */
    int partition(int lowIndex, int highIndex) {
        // average of highIndex and lowIndex
        int mid = (highIndex + lowIndex) / 2;
        cout << "High Index: " << highIndex << endl;
        cout << "Low Index: " << lowIndex << endl;
        while(lowIndex <= highIndex) {
            // while array[lowIndex](element) is less than array[mid](element) increment lowIndex
            while(array[lowIndex] < array[mid]) {
                lowIndex++;
            }
            cout << array[lowIndex] << " is greater than " << array[mid] << endl;

            // while array[highIndex](element) is greater than array[mid](element) decrement highIndex
            while(array[highIndex] > array[mid]) {
                highIndex--;
            }
            cout << array[highIndex] << " is less than " << array[mid] << endl;

            // swap
            if(lowIndex <= highIndex) {
                T tmp = array[lowIndex];
                array[lowIndex] = array[highIndex];
                array[highIndex] = tmp;
                cout << "Swapped: " << array[lowIndex] << " and " << array[highIndex] << endl;
                lowIndex++;
                highIndex--;
            }
            print();
        }

        cout << "Returning " << lowIndex << endl;
        return lowIndex;
    }




    void search(T value) {
        // cut it in half
        // find out if place is the element
        // if not then is the element greater than or less than place
        // change where element can see
        section_search(value, 0, this->size - 1);
    }

    void section_search(T value, int lowIndex, int highIndex) {
        int mid = (highIndex+lowIndex) / 2;
        if(array[mid] == value) {
            cout << mid << endl;
        } else if(value > array[mid]) {
            // takes value and searches for it from mid+1 to highIndex
            section_search(value, mid+1, highIndex);
        } else {
            // takes value and searches for it from lowIndex to mid-1
            section_search(value, lowIndex, mid-1);
        }
    }



    void shuffle() {

    }

    void slice() {

    }





};

int main()
{
    myArray<int> intArray;
    myArray<char> charArray;
    myArray<int> intArray2;
    myArray<int> intArray3(10);

    // setting up int array
    intArray.set(0,1);
    intArray.set(1,2);
    intArray.set(2,3);
    intArray.set(3,4);
    intArray.set(4,5);
    intArray.set(5,6);
    intArray.set(6,7);
    intArray.set(7,8);
    intArray.set(8,9);
    intArray.set(9,10);

    intArray2.set(0,1);
    intArray2.set(1,2);
    intArray2.set(2,3);
    intArray2.set(3,4);
    intArray2.set(4,5);
    intArray2.set(5,6);
    intArray2.set(6,7);
    intArray2.set(7,8);
    intArray2.set(8,9);
    intArray2.set(9,10);

    intArray3.set(0,10);
    intArray3.set(1,4);
    intArray3.set(2,2);
    intArray3.set(3,9);
    intArray3.set(4,5);
    intArray3.set(5, 1);
    intArray3.set(6,3);
    intArray3.set(7, 8);
    intArray3.set(8, 7);
    intArray3.set(9,6);

    // setting up char array
    charArray.set(0,'a');
    charArray.set(1,'b');
    charArray.set(2,'c');
    charArray.set(3,'d');
    charArray.set(4,'e');
    charArray.set(5,'f');
    charArray.set(6,'g');
    charArray.set(7,'h');
    charArray.set(8,'i');
    charArray.set(9,'j');


    intArray3.search(9);
    intArray3.print();
    intArray3.sort();
    intArray3.print();

    intArray3.search(9);


    return 0;
}
