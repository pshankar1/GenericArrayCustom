#include <iostream>


template <typename T> 
/***
 * capacity stores the total accepted capacity !
 * 	Array Stores  Elements into val[] arraylist
 * 
 * s is the total length and size of values in a string
 *****/
class ArrayList{
   
   private:
     T *val;
     int capacity;
     int s;
/***********
 * ensureCapacity()
 * increases capacity and adds onto ArrayList Length
**************/
     void ensureCapacity(){

       int fC = capacity * 2;
       T *temp = new T[fC];

       for(int i = 0; i < s ; i++){
         temp[i] = val[i];
       }

       val = temp;
       capacity = fC;
     }
   public:

  /*
  Assigns capacity to arrayList and makes it empty
  hence s(size)= 0
  */   
    ArrayList(){
      this->capacity = 10;
      this->val = new T[capacity];
      this->s = 0;
    }

    ~ArrayList(){
      std::cout << "Deleting ArrayList!" << this ;
      delete[] val;
    }

    /****
 * add() method
 *basically checks capacity and makes sure to locate last element
	  to add new element
 ***********/
    void add(T item){

      if(s == capacity)
           ensureCapacity();
      val[s++] = item;
    }

/***********
 * get() method
 * Gets element at given index
 * returns value 
 **************/
    T get(int index){
         if(index < 0 || index >= s)
              std::cout << "Out of bound exception captured! \n";
         return (T) val[index];
    }


    int size(){
     	  return size(); 
    }
    void add(int index, T item);
    T remove(int index);
  /******
 * 
 * isEmpty() method
 * Checks & Returns boolean (T/F) on whether or not ArrayList is Empty!
 * 
 ******/
    bool isEmpty(){
      if(s==0){
        return true;
      }else{
        return false;
      }
    }

  /***********
 * contains()
 * Can see if an element can be found in a list 
 * returns boolean value if it can!
 **************/
    bool contains(T item){
      for(int i =0; i<s;i++){
	    if(val[i].equals(item)){
	      return true;
	    }
	  }
	  return false;
    }

/****
it didnt work on here ;( 
 * add() method
 * Element is added to ArrayList
 *  if(isFull()){
	    ensureCapacity();
	  }   basically checks capacity and makes sure to locate last element
	  to add new element
 ***********/ 

  //   void add(T index){
	//   if(isFull()){
	//     ensureCapacity();
	//   }
	
	//   val[s++]=index;
	// }

  /***********
 * clear()
 * Clear method takes off the first half of elements of the arrayList
 * reduce() is called again to help cut off values from ArrayList
 **************/
     void clear(){
	  if(isEmpty()){
	    for(int i=0;i<s-1;i++){
	      val[i]=val[i+1];
	    }
	
	    s--;
	
	  }
	}
};
int main() {
  ArrayList<int> intL;
  intL.add(8);
  intL.add(3);
  intL.add(33);
  intL.add(18);
  intL.add(33);
  intL.add(2);
  intL.add(33);
  std::cout << "The Last element of ArrayList: " << intL.get(6) << std::endl;


}