#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 * 需要有序性或者对单次查询有时间要求的应用场景下，应使用map，其余情况应使用unordered_map。
 */

void word_map(vector<string> str)
{
    map<string, int> word_count;
    for(auto it =str.begin(); it != str.end(); it++)
        ++word_count[*it];      //即word_count[*it] = word_count[*it] + 1
    cout << "map：" <<endl;

    word_count.erase("aaa");    //删除一个关键字
    word_count["abcd"] = 4;     //下标操作直接添加
    word_count.at("abcd")++;    //访问某个元素，先检查参数是否存在，不存在抛出out_of_range异常
    for(auto w : word_count)
        cout << w.first << ": " << w.second << endl;
    cout << "关联容器大小为："<< word_count.size() << endl;
    auto fin = word_count.find("abcd");
    if(fin != word_count.end())
        cout<< "查找关键字\"abcd\"的数值：" << fin->second << endl;
}

void word_unorderer(vector<string> str)
{
    unordered_map<string, int> word_count;
    for(auto it =str.begin(); it != str.end(); it++)
        ++word_count[*it];      //即++(word_count[*it])，把*it指向的索引+1

    cout << "unorderer_map：" << endl;

    word_count.erase("bbb");    //删除关键字
    word_count["aaa"] = 10;
    for(auto w : word_count)
        cout << w.first << ": " << w.second << endl;
    /* find使用方法 */
    auto it1 = word_count.find("aaa");      //返回当前的迭代器
    if(it1 != word_count.end())
        cout << "查找\"aaa\"的个数: " << it1->second << endl;



    cout << "桶的数目为：" << word_count.bucket_count() << endl;
    cout << "容器能容纳的最大桶的数目为：" << word_count.max_bucket_count() << endl;
    cout << "每个桶的平均元素数量：" << word_count.load_factor() << endl;
}

int main()
{
    vector<string> str= {"aaa", "abc", "aaa", "bbb" ,"aaa", "abc", "abd", "abd", "abd"};

   // word_map(str);
    word_unorderer(str);

    return 0;
}