#include <bits/stdc++.h>
using namespace std;


///////////////Recursive Sequential Search/////////////////


void SequentialSearch(vector<int>& list, int Target) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == Target) {
            cout << "Found At Position By Sequential Search : " << i + 1 << endl;
            return; // Return the index if the target is found
        }
    }
    cout << "This value is not in the list\n";
}


///////////////Recursive Sequential Search/////////////////


void Recursive_Sequential_Search(vector<int>& list, int value, int index = 0) {
    if (index == list.size()) {
        cout << "This value is not in the list\n";
        return;
    }
    if (value == list[index]) {
        cout << "Found At Position By Recursive Sequential Search : " << index + 1 << endl;
        return;
    }

    Recursive_Sequential_Search(list, value, index + 1);
}


//////////////////Binary Search///////////////////////


void BinarySearch(vector<int>& list, int Target, int l, int r) {
    int mid;
    while(l <= r) {
        mid  = (l + r) / 2;
        if (list[mid] == Target) {
            cout << "Found at position By Binary Search : " << mid << endl;
            return;
        }
        else if (list[mid] < Target) {
            l = mid + 1;
        }
        else if (list[mid] > Target) {
            r = mid - 1;
        }
    }
    cout << "This value is not in the list\n";
}

//////////////////Recursive Binary Search///////////////////////

void Recursive_BinarySearch(vector<int>& list, int Target, int l, int r) {
    int mid = (r + l) / 2;
    if (list[mid] == Target) {
        cout << "Found at position By Recursive Binary Search : " << mid << endl;
        return;
    }
    else if (list[mid] < Target) {
        Recursive_BinarySearch(list, Target, mid+1, r);
    }
    else {
        Recursive_BinarySearch(list, Target, l, mid-1);
    }
    cout << "This value is not in the list\n";
}

int main() {
    vector<int> vec = {4, 5, 2, 11, 9, 43};
    int target1 = 11;
    int target2 = 12;

    ///////////////Recursive Sequential Search/////////////////

    SequentialSearch(vec, target1);

    SequentialSearch(vec, target2);

    cout << endl;

    ///////////////Recursive Sequential Search/////////////////

    Recursive_Sequential_Search(vec, target1);

    Recursive_Sequential_Search(vec, target2);

    cout << endl;

    //////////////////Binary Search///////////////////////

    sort(vec.begin(), vec.end());

    int l = 0, r = (int)vec.size() - 1;

    BinarySearch(vec, target1, l, r);

    BinarySearch(vec, target2, l, r);

    cout << endl;

    //////////////////Recursive Binary Search///////////////////////

    Recursive_BinarySearch(vec, target1, l, r);

    Recursive_BinarySearch(vec, target2, l, r);

    cout << endl;

    return 0;
}
