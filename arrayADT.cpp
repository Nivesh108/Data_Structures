#include <bits/stdc++.h>
using namespace std;
#define io  freopen("input.txt","r",stdin); \
            freopen("output.txt","w",stdout);

struct Array{
    int *a;
    int length;
    int size;
};

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        cout<<arr.a[i]<<" ";
}

void append(struct Array *arr,int x){
    if(arr->length<arr->size){
        arr->a[arr->length++]=x;
    }
    else cout<<"Sorry!! array is full:(\n";
}

void insert(struct Array *arr,int index,int x){
    if(index>=0 && index<=arr->length){
        int i;
        for(i=arr->length;i>index;i--)
            arr->a[i]=arr->a[i-1];
        arr->a[index]=x;
        arr->length++;
    }
    else cout<<"Error\n";
}

void remove(struct Array *arr,int index){
    if(index>=0&&index<arr->length){
        for(int i=index;i<arr->length-1;i++)
            arr->a[i]=arr->a[i+1];
        arr->length--;
    }
}

void Set(struct Array *arr,int index,int value){
    if(index>=0&&index<arr->length)
        arr->a[index]=value;
}

void Get(struct Array arr,int index){
    if(index>=0&&index<arr.length)
        cout<<arr.a[index];
    else cout<<"Error";
}

int LinearSearch(struct Array arr,int x){
    for(int i=0;i<arr.length;i++){
        if(arr.a[i]==x) return i;
    }
    return -1;
}

int IBinarySearch(struct Array arr,int x){
    int l=0,h=arr.length-1;
    int mid;
    while(l<=h){
        mid=(h+l)/2;
        if(arr.a[mid]==x) return mid;
        else if(arr.a[mid]>x) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

int RBinarySearch(struct Array arr,int l,int h,int element){
    if(h>=l){
        int mid=(h+l)/2;
        if(arr.a[mid]==element) return mid;
        else if(element>arr.a[mid]) 
            return RBinarySearch(arr,mid+1,h,element);
        else return RBinarySearch(arr,l,mid-1,element);
    }
    return -1;
}

int max(struct Array arr){
    int mx=arr.a[0];
    for(int i=1;i<arr.length;i++)
        if(arr.a[i]>mx) mx=arr.a[i];
    return mx;
}

int min(struct Array arr){
    int mn=arr.a[0];
    for(int i=0;i<arr.length;i++)
        if(arr.a[i]<mn) mn=arr.a[i];
    return mn;
}

int sum(struct Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum+=arr.a[i];
    return sum;
}

float avg(struct Array arr){
    return (float)sum(arr)/arr.length;
}

void Reverse(struct Array *arr){
    for(int i=0;i<arr->length/2;i++)
        swap(arr->a[i],arr->a[arr->length-1-i]);
}

bool IsSorted(struct Array arr){
    for(int i=1;i<arr.length;i++){
        if(arr.a[i]<arr.a[i-1]) return false;
    }
    return true;
}

void InSorted(struct Array *arr,int element){
    if(arr->length<arr->size){
        int i=arr->length-1;
        while(arr->a[i]>element){
            arr->a[i+1]=arr->a[i];
            i--;
        }
        arr->a[i+1]=element;
        arr->length++;
    }
}

struct Array* MergeSortedArrays(struct Array x,struct Array y){
    int i=0,j=0,k=0;
    struct Array *c=new struct Array;
    c->size=x.length+y.length;
    c->a=new int[c->size];
    while(i<x.length&&j<y.length){
        if(x.a[i]<y.a[j]) 
            c->a[k++]=x.a[i++];
        else c->a[k++]=y.a[j++];
    }
    for(;i<x.length;i++)
        c->a[k++]=x.a[i];
    for(;j<y.length;j++)
        c->a[k++]=y.a[j];
    c->length=k;
    return c;
}

struct Array* Union(struct Array a,struct Array b){
    struct Array *arr = new struct Array;
    arr->size=a.length+b.length;
    arr->a=new int[arr->size];
     if(IsSorted(a)&&IsSorted(b)){
        int i=0,j=0,k=0;
        while(i<a.length&&j<b.length){
            if(a.a[i]<b.a[j])
                arr->a[k++]=a.a[i++];
            else if(a.a[i]>b.a[j])
                arr->a[k++]=b.a[j++];
            else{
                arr->a[k++]=a.a[i++];
                j++;
            }
        }
        for(;i<a.length;i++)
                arr->a[k++]=a.a[i];
            for(;j<b.length;j++)
                arr->a[k++]=b.a[j];
            arr->length=k;
     }
     else{
        int i;
         for(i=0;i<a.length;i++)
            a.a[i]=arr->a[i];
        arr->length=i;
        for(int j=0;j<b.length;j++){
            if(LinearSearch(*arr,b.a[j])==-1){
                arr->a[i++]=b.a[j];
                arr->length++;
            }
        }
     }
     return arr;
}

struct Array* Intersection(struct Array a, struct Array b){
     struct Array *arr = new struct Array;
    arr->size=a.length+b.length;
    arr->a=new int[arr->size];
     if(IsSorted(a)&&IsSorted(b)){
        int i=0,j=0,k=0;
        while(i<a.length&&j<b.length){
            if(a.a[i]<b.a[j])
                i++;
            else if(a.a[i]>b.a[j])
                j++;
            else{
                arr->a[k++]=a.a[i++];
                j++;
            }
        }
      arr->length=k;
     }
     else{
        int i,j=0;
         for(i=0;i<a.length;i++){
            if(LinearSearch(b,a.a[i])!=-1)
                arr->a[j++]=a.a[i];
         }
            arr->length=j;
    }
         return arr;
}

struct Array* Difference(struct Array a, struct Array b){
     struct Array *arr = new struct Array;
    arr->size=a.length+b.length;
    arr->a=new int[arr->size];
     if(IsSorted(a)&&IsSorted(b)){
        int i=0,j=0,k=0;
        while(i<a.length&&j<b.length){
            if(a.a[i]<b.a[j])
                arr->a[k++]=a.a[i++];
            else if(a.a[i]>b.a[j])
                j++;
            else{
                i++;
                j++;
            }
        }
        for(;i<a.length;i++)
            arr->a[k++]=a.a[i];
      arr->length=k;
     }
     else{
        int i,j=0;
         for(i=0;i<a.length;i++){
            if(LinearSearch(b,a.a[i])==-1)
                arr->a[j++]=a.a[i];
         }
            arr->length=j;
    }
         return arr;
}


int main()
{   
    io
/*    struct Array arr;
  //  cout<<"Enter the size of array:\n";
    cin>>arr.size;
    arr.a=new int[arr.size];
    arr.length=0;
    int n;
  //  cout<<"Enter number of numbers\n";
    cin>>n;
    arr.length=n;
    for(int i=0;i<n;i++)
        cin>>arr.a[i];
    append(&arr,0);
    display(arr); 
    cout<<endl;
    cout<<arr.length<<endl;
    
(&arr,4,1);
    display(arr);
    cout<<endl;
    cout<<arr.length<<endl;
    remove(&arr,2);
    display(arr);
    cout<<endl<<arr.length;
    cout<<endl<<LinearSearch(arr,5)<<endl; 
    sort(arr.a,arr.a+arr.length);
    display(arr);
    cout<<endl; 
    cout<<IBinarySearch(arr,8)<<endl;
    cout<<RBinarySearch(arr,0,arr.length-1,9)<<endl; 
    Set(&arr,3,9999);
    display(arr);
    cout<<endl; 
    Reverse(&arr);
    display(arr);
    cout<<endl;
    cout<<sum(arr)<<" "<<avg(arr)<<endl;
    Get(arr,5);
    cout<<"\nMax element: "<<max(arr)<<endl;
    cout<<"Min element: "<<min(arr)<<endl;
    cout<<"Is array sorted: "<<IsSorted(arr)<<endl;
    sort(arr.a,arr.a+arr.length);
    display(arr);
    cout<<endl<<"Is array sorted: "<<IsSorted(arr)<<endl;
    
InSorted(&arr,2);
    display(arr);   
    sort(arr.a,arr.a+arr.length);
    display(arr);
    struct Array arr2;
    struct Array arr3;
    cin>>arr2.size;
    arr2.a=new int[arr2.size];
    arr2.length=0;
    int n2;
    cin>>n2;
    arr2.length=n2;
    for(int i=0;i<n2;i++)
        cin>>arr2.a[i];
    sort(arr2.a,arr2.a+arr2.length);
    arr3.size=20;
    arr3.a=new int[arr.size];
    arr3.length=arr.length+arr2.length;
    struct Array *s=Union(arr,arr2);
    cout<<endl<<endl;
    display(*s); */
    struct Array arr1;
    int choice,x,index;
    cout<<"Enter the size of the array:";
    cin>>arr1.size;
    arr1.a=new int[arr1.size];
    arr1.length=0;
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
            insert(&arr1,index,x);
            break;
            case 2: printf("Enter index ");
            scanf("%d",&index);
            remove(&arr1,index);
            printf("Deleted Element is %d\n",x); 
            break;
            case 3:printf("Enter element to search ");
            scanf("%d",&x);
            index=LinearSearch(arr1,x);
            printf("Element index %d",index);
            break;
            case 4:printf("Sum is %d\n",sum(arr1));
            break;
            case 5:display(arr1);
 
 }
 }while(choice<6);

    return 0;
}