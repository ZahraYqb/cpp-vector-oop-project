#include <iostream>
#include <ctime>
#include <string>
using namespace std;
//my vector class
template <typename T>
class MyVector{
    protected:
    
    int m_size;
    T m_defaultValue;
    T* m_vector;
    T value;
    
    public:
    MyVector (int size=0, T defaultValue= T()): m_size(size), m_defaultValue(defaultValue){
        m_vector= new T [m_size];
        for (int i{0}; i<m_size; i++){
            m_vector[i]= m_defaultValue;
        }
    }
    T& operator[] (int i){
        return m_vector[i];
    }
    void PushBack (T NewValue){
         T* tmpVector= new T [m_size + 1];
         for (int j=0; j<m_size; j++){
              tmpVector[j] = m_vector[j];
          }
         tmpVector[m_size]= NewValue;
         delete [] m_vector;
         m_vector = tmpVector;
         m_size++;            
      }
    void resize (int NewSize, T NewValue= T()){
        if (NewSize>m_size){
            T* tmpVector= new T [NewSize];
            for (int j=0; j<m_size; j++){
                tmpVector[j] = m_vector[j];
            }
            for (int k{m_size}; k< NewSize; k++){
                tmpVector[k]= NewValue;
            }
            delete [] m_vector;
            m_vector = tmpVector;
            m_size= NewSize;  
        } 
        else {
            T* tmpVector = new T[NewSize];
            for (int i = 0; i < NewSize; i++) {
                tmpVector[i] = m_vector[i];
            }
            delete[] m_vector;
            m_vector = tmpVector;
            m_size = NewSize;
        }   
    }
    void insert (int i, T insertedValue){
        T* tmpVector= new T [m_size + 1];
         for (int j=0; j<i; j++){
              tmpVector[j] = m_vector[j];
          }
        tmpVector[i]= insertedValue;
         for (int j=i+1; j<=m_size; j++){
              tmpVector[j] = m_vector[j-1];
          }
         
         delete [] m_vector;
         m_vector = tmpVector;
         m_size++;            
    }
    void remove (int i){
        T* tmpVector= new T [m_size - 1];
         for (int j=0; j<i; j++){
              tmpVector[j] = m_vector[j];
          }
         for (int j=i; j<m_size-1; j++){
              tmpVector[j] = m_vector[j+1];
          }
         
         delete [] m_vector;
         m_vector = tmpVector;
         m_size--;            
    }
    ~MyVector() {
        delete[] m_vector;
    }
};
class shape{
    private:
    //allocating a fairly large memory for the “data” member
    int* m_data= new int [100*1024*1024];

   
};
int main (){
    MyVector vect1 (100,shape());
     //Recording how many cpu clocks each operation needs:
//inserting
    clock_t start = std::clock();
    for (int i=0; i<10; i++){
        vect1.insert(i, shape());}
    clock_t end = std::clock();
    cout << "the number of Insert clocks: " << (end - start) << " clocks" <<endl;
//removing
    start = std::clock();
    for (int i=0; i<10; i++){
        vect1.remove(i);}
    end = std::clock();
    cout << "the number of remove clocks: " << (end - start) << " clocks" << endl;
  
}
