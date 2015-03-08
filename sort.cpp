#include "sort.h"
#include <iostream>

using namespace std;

void printarray(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mergesort(int a[], int n)
{
    mergesort(a,0, n-1);
}

void mergesort(int a[], int begin, int end)
{
    if(begin>=end) return;
    int mid = begin+(end-begin)/2;
    mergesort(a, begin, mid);
    mergesort(a, mid+1, end);
    int tmp[end-begin+1];
    int i=0;
    int l1=begin;
    int l2=mid+1;
    while(l1<=mid && l2<=end)
    {
        if(a[l1]<a[l2]) tmp[i++]=a[l1++];
        else tmp[i++]=a[l2++];
    }
    while(l1<=mid) tmp[i++]=a[l1++];
    while(l2<=end) tmp[i++]=a[l2++];
    int ai=begin;
    i=0;
    while(ai<=end) a[ai++] = tmp[i++];
}

void quicksort(int a[], int n)
{
    quicksort(a, 0, n-1);
}

void quicksort(int a[], int begin, int end)
{
    if(begin>=end) return;
    int pivot =a[end];
    int i=begin;
    int j=end-1;
    while(j>=i)
    {
        if(a[j]<=pivot) swap(a[i++], a[j]);
        else j--;
    }
    swap(a[i],a[end]);
    quicksort(a, begin, i-1);
    quicksort(a, i+1, end);
}
