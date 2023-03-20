// Vector.h

//---------------------------------------------------------------------------------

#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------


	/**
	 * @class Vector
	 * @brief A custom made vector, which is a array that can be extended.
	 *
	 *
	 * @author Anson Ting
	 * @version 01
	 * @date 18/04/2022 Anson Ting, Started
	 *
	 * @author Anson Ting
	 * @version 02
	 * @date 22/04/2022 Anson Ting, class name changed from vectorC to Vector.
	 *
     * @author Anson Ting
	 * @version 03
	 * @date 26/04/2022 Anson Ting, pushBack() algorithm changed.
	 *
	 * @todo To ensure this class is able to store data and function the same as vector STL.
	 *
	 * @bug Not bug has found at the moment.
	 *
	 */

template<typename T>

class Vector{
public:

        /**
        * @brief  a default vector.
        *
        * Create a default vector with having 1 size, the size will only increase after pushBack()
        * a new variable.
        *
        *
        * @return New created Vector object.
        */
    Vector()
    {
        v_arr = new T[1];
        v_capacity = 1;
        v_current = 0;
    }

    ~Vector()
    {
        delete[] v_arr;
    }

        /**
        * @brief  Push a new variable into the vector
        *
        * first check if the current data location is same as the capacity of the vector,
        * the new vector with two times bigger than current capacity will be created, and
        * use for loop to transfer data from temporary array to the new created array.
        *
        * @warning Must delete the temporary array after transfer, to prevent memory leak.
        * @param data - Template
        * @return void
        */
    void pushBack(T data)
    {
        if (v_current == v_capacity){
            v_capacity *= 2;
            T* temp_arr = v_arr;
            v_arr = new T[v_capacity];
        for (int i=0;i<v_current;i++){
            v_arr[i] = temp_arr[i];
        }
            delete[] temp_arr;
        }
        v_arr[v_current++] = data;
        return;
    }

        /**
        * @brief  Push a new variable to a selected location
        *
        * If the selected location same as the vector capacity, the data will be added in with
        * pushBack().
        *
        * If the selected location is not same as the vector capacity, data will be added into selected
        * location.
        *
        * @param i - int, data - Template
        * @return void
        */
    void pushAt(int i, T data)
    {
        if (i == v_capacity){
            pushBack(data);
        } else{
            v_arr[i] = data;
        }
    }

        /**
        * @brief  Retrieves data from selected location of the vector.
        *
        *
        *
        * @param i - int
        * @return const Template
        */
    T get(int i) const
    {
        int index=0;
        if (i < v_current)
        {
            index = i;
        }
        return v_arr[index];
    }

        /**
        * @brief  Clear all the data from the vector, and back to default setting.
        *
        *
        *
        * @return void
        */
    void clearAll()
    {
        v_arr = new T[1];
        v_capacity = 1;
        v_current = 0;
    }

        /**
        * @brief  delete the least data from the vector.
        *
        *
        *
        * @return void
        */
    void pop()
    {
        v_current--;
    }

        /**
        * @brief Retrieves the capacity of the vector
        *
        *
        *
        * @return const int
        */
    int capacity() const
    {
        return v_capacity;
    }

        /**
        * @brief Retrieves the current location of the vector
        *
        *
        *
        * @return const int
        */
    int size() const
    {
        return v_current;
    }

        /**
        * @brief Print out all the data from the vector with designed format.
        *
        *
        *
        * @return const void
        */
    void print() const
    {
        for (int i=0;i<v_current;i++){
            std::cout << v_arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    T* v_arr;           /// template array
    int v_capacity;     /// capacity
    int v_current;      /// current
};

#endif // VECTOR_H
