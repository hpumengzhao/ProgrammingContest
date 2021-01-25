#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

/*
把一个分割的各个集合中的元素从大到小排序，然后再以集合的最小的元素对这些集合从大到小进行排序，
排在第一的集合对应1，第二的集合对应2，依次类推。对应一个分割，有一个编码与之对应，这个编码如下：
如果元素x属于i集合，则x的码值为i。对每一个元素求出其对应于一个分割的码值，将这些码值组合起来就
得到了这个分割的编码。
如：
{1,2}{3}{4} -> 1123 【表示元素1和2属于1集合，元素3属于2集合，元素4属于3集合】。
*/

/*进行深度优先搜索*/
void DFS_with_MaxCode(int const &Maxcode, int const &distance_to_base, vector<int>set, vector<vector<int>>&result){

    if (distance_to_base == 0){//到达树底

            result.push_back(set);  
            return;
    }

    vector<int> temp;
    for (int i=1; i <= Maxcode; i++){//从1~Maxcode，深度优先遍历
        temp = new vector<int>(set);
        temp.push_back(i);
        DFS_with_MaxCode(Maxcode, distance_to_base - 1, temp, result);  
    }

    //Maxcode+1, 深度优先遍历。
    temp = new vector<int>(set);
    temp.push_back(Maxcode+1);
    DFS_with_MaxCode(Maxcode+1, distance_to_base - 1, temp, result);

}

void partition(int const &n, vector<vector<int>> &result){

    vector<int> set = new vector<int>();
    set.push_back(1);
    DFS_with_MaxCode(1, n - 1,set,result);
}

int main(){

    vector<vector<int>> result;

    int n;
    cin >> n;

    partition(n, result);
    for (int i=0; i < result.size(); i++){
    	for(int v:result[i]){
    		cout<<char('a'+v-'1');
    	}
        cout << endl;
    }
    return 0;
}