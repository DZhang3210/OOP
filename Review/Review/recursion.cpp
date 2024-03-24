////
////  recursion.cpp
////  Review
////
////  Created by David Zhang on 5/10/22.
////
//
//#include<iostream>
//#include<vector>
//#include<set>
//#include<map>
//using namespace std;
//
//void displayBits(int n){
//    if(n <= 1){
//        cout << n;
//        return;
//    }
//    else{
//        displayBits(n/2);
//        cout << n%2;
//    }
//}
//int helper1(const string& str, int index){
//    if(index < 0){
//        return 0;
//    }
//    if(str[index] == '1') return 2* helper1(str, index - 1) + 1;
//    else return 2 * helper1(str, index - 1) + 0;;
//}
//
//int bitToIntegers1(const string& str){
//    return helper1(str, str.size() -1);
//}
//
//
//int helper2(const string& str, int index){
//    if(index >= str.size()){
//        return 0;
//    }
//
//
//    if(str[index] == '1'){
//        int returns = 1;
//        for(int i = index; i < str.size() - 1; i++){
//            returns*= 2;
//        }
//        return returns + helper2(str, index + 1);
//    }
//    else return helper2(str, index + 1);
//}
//
//int bitToIntegers2(const string& str){
//    return helper2(str, 0);
//}
//
//int fib(int n, map<int, int> i){
//    if(n <=1){
//        return n;
//    }
//    if(i.find(n) == i.end()){
//        i[n] = fib(n-1, i) + fib(n-2, i);
//    }
//    return i[n];
//}
//
//
//int main(){
//    pair<int, string> li(1, "hello");
//    cout << li.first <<" " << li.second << endl;
//
//    pair<int, string> b = make_pair(2, "Bam");
//
////    cout << bitToIntegers2("110101") << endl;
////    // 1 + 4 + 16 + 32 = 53
////    displayBits(14);
////    cout << "\n";
//
//    map<int, string> list;
//    list[2] = "banana";
//    list[2] = "hello";
//    cout << list[2] << endl;
//
//    set<int> bist {6,10,6,3,2,1};
//    for(int i: bist){
//        cout << i << endl;
//    }
//    cout << "============" << endl;
//    map<int, int> c;
//    cout << fib(18, c) << endl;
//
//}
