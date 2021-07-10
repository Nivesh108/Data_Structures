#include <bits/stdc++.h>
using namespace std;
#define io  freopen("input.txt","r",stdin); \
            freopen("output.txt","w",stdout);

template<class T>
class Array{
private:
    T *a;
    int length;
    int size;
    void swap(T*,T*);
public:
    Array(){}
    Array(int size){
        this->size=size;
        length=0;
        a=new T[size];
    }
    ~Array(){
        delete []a;
    }
    void display();
    void append(T);
    void insert(int index,T x);
    void remove(int index);
    void Set(int index,T value);
    void Get(int index);
    int LinearSearch(T x);
    int IBinarySearch(T x);
    T max();
    T min();
    T sum();
    double avg();
    void reverse();
    bool IsSorted();
    void InsertInSorted(int element);
    Array<T>* Union(Array arr2);
    Array<T>* Difference(Array arr2);
    Array<T>* Intersection(Array arr2);
    Array<T>* MergeSortedArrays(Array arr2);
};

template<class T>
void Array<T>::swap(T *x,T*y){
    T temp=*x;
    *x=*y;
    *y=temp;
}

template<class T>
void Array<T>::display(){
    for(int i=0;i<length;i++)
        cout<<a[i]<<" ";
}

template<class T>
void Array<T>::append(T x){
    if(length<size){
        a[length++]=x;
    }
    else cout<<"Sorry!! array is full:(\n";
}

template<class T>
void Array<T>::insert(int index,T x){
    if(index>=0 && index<=length){
        int i;
        for(i=length;i>index;i--)
            a[i]=a[i-1];
        a[index]=x;
        length++;
    }
    else cout<<"Error\n";
}

template<class T>
void Array<T>::remove(int index){
    if(index>=0&&index<length){
        for(int i=index;i<length-1;i++)
            a[i]=a[i+1];
        length--;
    }
}

template<class T>
void Array<T>::Set(int index,T value){
    if(index>=0&&index<length)
        a[index]=value;
}

template<class T>
void Array<T>::Get(int index){
    if(index>=0&&index<length)
        cout<<a[index];
    else cout<<"Error";
}

template<class T>
int Array<T>::LinearSearch(T x){
    for(int i=0;i<length;i++){
        if(a[i]==x) return i;
    }
    return -1;
}

template<class T>
int Array<T>::IBinarySearch(T x){
    int l=0,h=length-1;
    int mid;
    while(l<=h){
        mid=(h+l)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]>x) h=mid-1;
        else l=mid+1;
    }
    return -1;
}


/*int Array::RBinarySearch(int l,int h,int element){
    if(h>=l){
        int mid=(h+l)/2;
        if(arr.a[mid]==element) return mid;
        else if(element>arr.a[mid]) 
            return RBinarySearch(arr,mid+1,h,element);
        else return RBinarySearch(arr,l,mid-1,element);
    }
    return -1;
} */

template<class T>
T Array<T>::max(){
    T mx=a[0];
    for(int i=1;i<length;i++)
        if(a[i]>mx) mx=a[i];
    return mx;
}

template<class T>
T Array<T>::min(){
    T mn=a[0];
    for(int i=0;i<length;i++)
        if(a[i]<mn) mn=a[i];
    return mn;
}

template<class T>
T Array<T>::sum(){
    T sum=0;
    for(int i=0;i<length;i++)
        sum+=a[i];
    return sum;
}

template<class T>
double Array<T>::avg(){
    return (double)sum()/length;
}

template<class T>
void Array<T>::reverse(){
    for(int i=0;i<length/2;i++)
        swap(&a[i],&a[length-1-i]);
}

template<class T>
bool Array<T>::IsSorted(){
    for(int i=1;i<length;i++){
        if(a[i]<a[i-1]) return false;
    }
    return true;
}

template<class T>
void Array<T>::InsertInSorted(int element){
    if(length<size){
        int i=length-1;
        while(a[i]>element){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=element;
        length++;
    }
}

template<class T>
Array<T>* Array<T>::MergeSortedArrays(Array y){
    int i=0,j=0,k=0;
    Array *c=new Array<T>(length+y.length);
    while(i<length&&j<y.length){
        if(a[i]<y.a[j]) 
            c->a[k++]=a[i++];
        else c->a[k++]=y.a[j++];
    }
    for(;i<length;i++)
        c->a[k++]=a[i];
    for(;j<y.length;j++)
        c->a[k++]=y.a[j];
    c->length=k;
    return c;
}

template<class T>
Array<T>* Array<T>::Union(Array b){
    Array *arr=new Array<T>(length+b.length);
     if(IsSorted()&&b.IsSorted()){
        int i=0,j=0,k=0;
        while(i<length&&j<b.length){
            if(a[i]<b.a[j])
                arr->a[k++]=a[i++];
            else if(a[i]>b.a[j])
                arr->a[k++]=b.a[j++];
            else{
                arr->a[k++]=a[i++];
                j++;
            }
        }
        for(;i<length;i++)
                arr->a[k++]=a[i];
            for(;j<b.length;j++)
                arr->a[k++]=b.a[j];
            arr->length=k;
     }
     else{
        int i;
         for(i=0;i<length;i++)
            a[i]=arr->a[i];
        arr->length=i;
        for(int j=0;j<b.length;j++){
            if(arr->LinearSearch(b.a[j])==-1){
                arr->a[i++]=b.a[j];
                arr->length++;
            }
        }
     }
     return arr;
}

template<class T>
Array<T>* Array<T>::Intersection(Array b){
     Array *arr=new Array<T>(length+b.length);
     if(IsSorted()&&b.IsSorted()){
        int i=0,j=0,k=0;
        while(i<length&&j<b.length){
            if(a[i]<b.a[j])
                i++;
            else if(a[i]>b.a[j])
                j++;
            else{
                arr->a[k++]=a[i++];
                j++;
            }
        }
      arr->length=k;
     }
     else{
        int i,j=0;
         for(i=0;i<length;i++){
            if(b.LinearSearch(a[i])!=-1)
                arr->a[j++]=a[i];
         }
            arr->length=j;
    }
         return arr;
}

template<class T>
Array<T>* Array<T>::Difference(Array b){
    Array *arr=new Array<T>(length+b.length);
     if(IsSorted()&&b.IsSorted()){
        int i=0,j=0,k=0;
        while(i<length&&j<b.length){
            if(a[i]<b.a[j])
                arr->a[k++]=a[i++];
            else if(a[i]>b.a[j])
                j++;
            else{
                i++;
                j++;
            }
        }
        for(;i<length;i++)
            arr->a[k++]=a[i];
      arr->length=k;
     }
     else{
        int i,j=0;
         for(i=0;i<length;i++){
            if(b.LinearSearch(a[i])==-1)
                arr->a[j++]=a[i];
         }
            arr->length=j;
    }
         return arr;
}

int main(){   
    
    io
    Array<int> *arr1;
    int sz,choice,index,x;
    cout<<"Enter the size of the array:";
    cin>>sz;
    Array<int> ar(sz);
    arr1=&ar;
    do{
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6. Exit\n\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: printf("Enter an element and index");
            scanf("%d%d",&x,&index);
            ar.insert(index,x);
            break;
            case 2: printf("Enter index ");
            scanf("%d",&index);
            ar.remove(index);
            printf("Deleted Element is %d\n",x); 
            break;
            case 3:printf("Enter element to search ");
            scanf("%d",&x);
            index=ar.LinearSearch(x);
            printf("Element index %d",index);
            break;
            case 4:printf("Sum is %d\n",ar.sum());
            break;
            case 5:ar.display();
 
 }
 }while(choice<6);

    return 0;
}