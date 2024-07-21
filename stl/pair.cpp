#include <bits/stdc++.h>
using namespace std;
#define li long int
#define ll long long int
#define si short int

void explainPair(){
    pair<int , int> p ={1,3};
    cout << p.first << " " << p.second << endl;
    pair<int , pair<int, int > > p2= {1,{2,3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second<<endl;
    pair < char ,int > arr[] = {{'a',1} ,{'b',2} ,{'c',3} ,{'d',4}};
    cout << arr[1].first << " " << arr[1].second<<endl; 
}
void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int , char>> vp;
    vp.push_back({1,'c'});
    vp.emplace_back(1,'c');

    vector<int> vi(5,100);
    vector<int> vi2(5) ; 
    vector<int> vi3(v1);

    vector<int>::iterator it = v.begin(); // it pointer pointing first element of vector v;
    it++;
    cout << *(it) << " ";

    it = it+2;
    cout << *(it) << " ";

    vector<int>::iterator it2 = v.end(); // point after the last element in vector v
    vector<int>::iterator it3 = v.rend();// never used but learn ( if array reversed then its end ) 
    vector<int>::iterator it4 = v.rbegin();// never used  (if array reversed then its begin )

    for( vector<int>::iterator it = v.begin(); it!=v.end(); it++){
        cout << *(it) << " ";
    }
    // we will use auto keyword ;
    for( auto::iterator it = v.begin() ; it!=v.end(); it++){
         
    }
    v.erase(starting,number of element or iterator of element before erase end)
    v.pop_back();
    v.insert(v.begin(),copy.begin(),copy.end());
    v1.swap(v2);
    v.clear();//erase the entire vector



}
void explainList(){
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);
    ls.emplace_front();{2,4};
    // begin,end,rbegin,rend,clear,insert,size,swap are same as vector 
}
void explainDeqeue() {
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();
    
}
void explainStack(){
    stack<int> q;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.push(5);

    cout << st.top();
    cout << st.size();
    cout << st.empty();
    // LIFO 
    // push , pop , top , size , clear , swap 
    st1.swap(st2);
}
void explainQueue(){
    queue<int> q;
    q.push();
    q.push();
    q.emplace();
    q.back() +=5;
    cout << q.back();
    cout << q.front();
    q.pop();
    cout << q.front();

    // push , pop , front , back , size ,stack 
}
void explainPriorityQueue(){

    // its a queue , but row is not for first come first server only but priority wise , acending order priority , evne if 2 is pushed to pq , in pq 1, 3, 8 , 10 
    // 2 will end up making queue look like  1, 2, 3, 8 ,10
    // not stored in linear fashion but as a tree 
    // resembles to max heap 
    // push , pop log(n ) , top  O1
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << pq.top() ;
    pq.pop();
    cout << pq.top();

    // for reversing the order or pq to decending
    // resembles to max heap
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(5);
    pq.push(3);
    pq.push(2);
    pq.push(10);
    cout << pq.top();

}
void explainSet(){
    // contains a set of unique element , if insterted again it will insert it as a single entry 
    // frequency of occurance is insignificant  
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3)
    auto it = st.find(3);

    auto it = st.find(6); // return set.end() point to right after the end 

    st.erase(5);// delete 5 and maintain the sorted order 

    int cnt = st.count(1); // 1 or 0 
    auto it st.find(3);
    st.erase(it);

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
    // find count , insert , erase 
}

void explainMultiset(){
    // every thing is same as set 
    // only stored duplicate element also 
    // only obey sorted not unique 
    multiset<int> ms;
    ms.erase(ms.find(1), ms.find(1)+2 );
    // rest are same as set 
}

void explainUSet(){
    // unorderd set 
    unordered_set<int> set;
    // all the operations are same 
    // lower bound and upper bound funcions don't work 
    // order don't followed but uniquness might be 
}
void explainMap(){
    map<int,int> map1;
    map<int ,pair<int,int>> map2;
    map< pair<int,int>,int> map3;
    // map < key , value> map_name;
    // keys are arranged in sorted order , no duplicates only uniques 
    // map[key] = value
    // use iterator to move 
    // unorder map will have unique keys but not be sorted , ( unique keys is must )
    
    map3[{2,3}] = 10;
    for(auto it:map3 ){
        cout<< it.first<< " " << it.second << endl;
    }

    cout<< map2[1];
    cout<< map1[5];

    auto it = map1.find(3);
    cout << *(it).second;
    auto it = map1.find(5);
    auto it = map1.lower_bound(2);
    auto it = map2.upper_bound(3);

}
bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second < p2.second) return false;
    return ( (p1.first > p2.first) ? true : false); 
}
void explainExtra(){
    sort(a,a+n);
    sort(v.begin(),v.end());

    sort(a,a+n ,greater<int>);
    pair<int,int> a[] = {{1,2},{2,1},{4,1}};
    // sort it according to second element 
    // if second element is same , then sort
    // it according to first element but in descending 

    sort(a ,a+n ,comp);
    int num = 7 ;
    int cnt = __builtin_popcount();
    string s =  "123";
    // to print all the permutation of s 
    do{
        cout<< s << endl;
    }while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a,a+n);
    // {4,2}

}
void solve(){
    explainPair();
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}