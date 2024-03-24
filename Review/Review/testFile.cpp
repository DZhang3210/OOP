////
////  testFile.cpp
////  Review
////
////  Created by David Zhang on 5/11/22.
////
//
//#include<iostream>
//#include<set>
//#include<list>
//#include<map>
//#include<vector>
//using namespace std;
//
////towers
//void Towers(int n, char start, char middle, char end){
//    if(n == 0)
//        return;
//    
//    Towers(n-1, start, end, middle);
//    cout << "Disk from " << start << " to " << end << endl;
//    Towers(n-1, middle, start, end);
//}
//int countBits(int i){
//    if(i <= 1) return i;
//    return i%2 + countBits(i/2);
//
//}
//int countTriplets(int i){
//    if(i <= 2) return i;
//    return i%3 + countTriplets(i/3);
//
//}
//
//
//int main(){
//    cout << countBits(8) << endl;
//    cout << countBits(13) << endl;
//    //1101
//    cout << countBits(19) << endl;
//    cout << countTriplets(13) << endl;
//    // 1 3 9 27    1 1 1
//    // 1+ countTriplets(4)
//    //1 + CountTriplets(1)
//    //1
//    cout << countTriplets(17) << endl;
//    // 2 2 1
//    
//    int* const b = new int(3);
//    b = new int(4);
//    delete b;
//    
////    int i = (5,10);
////    i = 2,3,7,9;
////    cout << i << endl;
////
////    map<int, int> myMap;
////    myMap[1] = 3;
////    myMap[3] = 2;
////    myMap [7] = 9;
////    cout << myMap[1] << endl;
////    for(auto& i: myMap){
////        cout << i.second << " " << i.first << endl;
////    }
////
////    pair<int, int> c = make_pair(3, 4);
////    cout << c.second << " " << c.first << endl;
////
////
////    vector<int> b {1,2,3,4,5,6,7};
////    list<int> l (b.begin(), b.end());
////    for(int i: l){
////        cout << i << endl;
////    }
//}
//
