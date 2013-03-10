#include <iostream>
#include <deque>
#include <cstring>
#include <clocale>
#include <cwchar>
#include <sstream>

using namespace std;

/*
 *  问题描述：请将一个小数（c/c++的类型为double）F转换为中文大写，例如32.15转换为"叁拾贰点壹伍",F范围是-2^30~+2^30，小数最多4位，小数多出的位直接舍弃
 *  解题思路：首先将double类型转换成string类型，然后先找到小数点的位置，使用deque数据结构来存储数据，对小数后面的数，直接往deque尾部插入，小数点前面的数字需要跟上拾、佰、仟等数字
 *  重点部分：（1）将double转换成string，注意精度是否有损失
 *            （2）小数只保留4位
 *            （3）个位是没有修饰词的，但是十位之后都是有修饰词的
 *            （4）如果有两个0：9001.15 输出应该是玖仟零壹点壹伍
 *            （5）汉字使用wchar_t和wstring来保存
 */
void Convert(double num,deque<wchar_t> & out_wchar);

int main()
{
    //想要输出汉字，需要设置locale
    ios_base::sync_with_stdio(false);
    wcin.imbue(locale("zh_CN.utf8"));
    wcout.imbue(locale("zh_CN.utf8"));

    deque<wchar_t> out_wchar;
    double num=-98202.143155;
    Convert(num,out_wchar);
    
    deque<wchar_t>::iterator pos;
    for(pos=out_wchar.begin();pos<out_wchar.end();pos++)
    {
        wcout<<*pos<<" ";
    }
    wcout<<endl;
    
    return 0;
}

void Convert(double num,deque<wchar_t> &out_wchar)
{
    wstring num_chs=L"零壹贰叁肆伍陆漆捌玖";
    wstring num_plus=L"拾佰仟万拾佰仟亿点负";//这是根据阶级来排的
    
    //将double转换成string类型的，并且设置精度是15
    string num_str;
    std::stringstream ss;
    ss.precision(15);
    ss<<num;
    ss>>num_str;
    ss.clear();
    

    cout<<num_str<<" "<<num_str.length()<<endl;
    int len=num_str.length();
    int i,j;
    int count=0;
    int xiaoshu_count=0;//用来对小数进行计数，我们只输出前4位小数
    for(i=0;i<len;i++)//找到小数点的位置
    {
        if(num_str[i]=='.')break;
    }
    int i_keep=i;
    if(i<len)
    {
        out_wchar.push_back(num_plus[8]);//将‘点’放入deque中
        i++;
        for(j=i;j<len;j++)
        {
            xiaoshu_count++;
            if(xiaoshu_count>4)break;//多余4位跳出循环
            out_wchar.push_back(num_chs[(int)num_str[j]-48]);//小数后面是没有什么修饰词的

        }
    }
    for(j=i_keep-1;j>=0;j--)
    {
        if(count==0)//个位
        {
            if((int)num_str[j]!=48)//个位是0是不需要显示的
            {
                out_wchar.push_front(num_chs[(int)num_str[j]-48]);
            }
        }
        //考虑到可能是负号
        else if(j==0 && num_str[j]=='-')
        {
            out_wchar.push_front(num_plus[9]);
        }
        //非个位如果不是0，需要数字加上修饰词
        //如果是0，则需要数字零
        //但是如果有两个连续的0，那么只需要输出一个 零
        else
        {
            if((int)num_str[j]!=48)
            {
                out_wchar.push_front(num_plus[count-1]);
            }
            if((int)num_str[j]==48 && j>=2 && (int)num_str[j-1]==48)
            {   
                ++count;
                continue;
            }
            out_wchar.push_front(num_chs[(int)num_str[j]-48]);
        }
        ++count;
    }
}
