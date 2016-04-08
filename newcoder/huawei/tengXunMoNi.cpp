

/**
    二叉树遍历的循环实现  left左边

    **后序遍历**的非递归实现需要额外的存储来判断右节点是否被访问过
    前序和中序使用栈便可以
**/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
typedef struct Node{
    char data;
    Node *lchild, *rchild;
}Node, *Tree;

void createTree(Tree& T)
{
    char ch;
    scanf("%c",&ch);
    if(ch==' ')
    {
        T=nullptr;
        return;
    }
    else
    {
        T=(Tree)malloc(sizeof(Node));
        if(T==nullptr){
            printf("mqlloc error!");
            return;
        }
        T->data=ch;
        createTree(T->lchild);
        createTree(T->rchild);
    }
}

void inOrderTraverse(Tree T)
{

    stack<Tree> Stack;
    if(T==nullptr)
    {
        printf("Null tree！\n");
        return;
    }

    while(T!=nullptr || !Stack.empty())
    {
        while(T!=nullptr)
        {
            Stack.push(T);
            T=T->lchild;
        }
        T=Stack.top();
        Stack.pop();
        printf("%c ",T->data);
        T=T->rchild;
    }
    printf("\n");
}


void preOrderTraverse(Tree T)
{
    stack<Tree> Stack;
    if(T==nullptr){
        printf("Null tree!");
        return;
    }
    while(T!=nullptr || !Stack.empty()){
        while(T!=nullptr){
            Stack.push(T);
            printf("%c ",T->data);
            T=T->lchild;
        }
        T=Stack.top();
        Stack.pop();
        T=T->rchild;
    }
    printf("\n");
}

void postOrderTraverse(Tree T)
{
    int flag[100];
    stack<Tree> Stack;
    if(T==nullptr){
        printf("Null tree!");
        return;
    }
    while(T!=nullptr)
    {
        Stack.push(T);
        //标记右节点是否访问过
        flag[Stack.size()]=0;
        T=T->lchild;
    }
    while(!Stack.empty())
    {
        T=Stack.top();
        while(T->rchild!=nullptr && flag[Stack.size()]==0)
        {
            flag[Stack.size()]=1;
            T=T->rchild;
            while(T!=nullptr)
            {
                Stack.push(T);
                flag[Stack.size()]=0;
                T=T->lchild;
            }
        }
        T=Stack.top();
        printf("%c",T->data);
        Stack.pop();
    }
}

void main()
{

    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    printf("\n");
         InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
}


/**
     Trie树，是一种哈希树的变种。典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串），
     所以经常被搜索引擎系统用于文本词频统计。

     它的优点是：
     利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较，
     查询效率比哈希树高。


**/

/**
    哈希树，例如用质数分辨算法来建立一棵哈希树，
    根节点的子树数为第一个质数2，其子节点的子树数为第二个质数3，以此类推，
    构建十层哈希树，用了2-29十个质数。
    插入时每层取模，最终分配到相应的子节点。

    可随着数据量的增加增大（即结构是动态的，一开始只有一个根节点）但是单向增加，
    非排序性，删除和添加元素时结构不变
    查找迅速
**/

/**
    输入一个头节点，从尾到头只读打印链表

    1.递归，缺点是节点数过多的话，函数栈容易溢出

    2.遍历得到大小，new个数组，然后存放每个节点值
    3.栈

    2和3的效率同个量级，但3明显思维更加高点
**/
/*
void printListRseves(Node* ptr){
    std::stack<Node*> res;
    while(ptr!=nullptr)
        res.push(ptr), ptr=ptr->pNext;
    while(!res.empty()){
        Node* tmp=nullptr;
        tmp=res.top();
        printf("%d\t", tmp->value);
        res.pop();
    }

}
*/
/**
Global Sequence Alignment
Per gap	  2
Per mismatch	1
Per match	0
求两序列的相似度。

把它错误当作LCS来解决了，，

**/

/*
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int getLCS(const char* a, int al, const char* b, int bl){
    if(al==0 || bl==0)
        return 0;
    if(a[al]==b[bl])
        return getLCS(a, al-1, b, bl-1)+1;
    else
        return max(getLCS(a, al, b, bl-1), getLCS(a, al-1, b, bl));
}

int getLCS_(const char* astr, int a, const char* bstr, int b){
    if(astr==nullptr || bstr==nullptr)
        return 0;

    int** res=new int*[a+1];
    for(int i(0); i<=a; ++i)
        res[i]=new int[b+1];

    for(int i(0); i<=a; ++i)
        res[i][0]=0;
    for(int i(0); i<=b; ++i)
        res[0][i]=0;

    for(int i(1); i<=a; ++i)
        for(int j(1); j<=b; ++j)
            if(astr[i-1]==bstr[j-1])
                res[i][j]=res[i-1][j-1]+1;
            else
                res[i][j]=max(res[i][j-1], res[i-1][j]);
    int results=res[a][b];
    for(int i(0); i<=a; ++i)
        delete[] res[i];
    delete[] res;
    return results;
}


int main(){
    string a1, b1;
    cin>>a1>>b1;
    const char* a=a1.c_str();
    const char* b=b1.c_str();
    int aLen=strlen(a), bLen=strlen(b);
    int tmp=getLCS_(a, aLen, b, bLen);
    int res1=min(aLen, bLen)-tmp+(max(aLen, bLen)- min(aLen, bLen))*2;
    cout<<res1<<endl;
}
*/


/**
    问题：给定一个 N × N 的二维数组，找出其中的最大子矩阵和
    输入：此问题的输入里包含一个 N × N 的数组。第一行是一个正整数 N。接下来的 N × N 个数组成了二维数组。
N最大为100，数组中每个数的范围是[−127, 127]。
    输出：输出为最大子矩阵和。


    解法一
    1.最大子段和：状态转移方程b[j]=max(b[j-1]+a[j],a[j])，1<=j<=n，
        b[j]为包含j的最大字段和
        备忘录  DP
    2.把原矩阵任意两行（或一行）压扁看成一个数组，共有n(n+1)/2，
    依次当作求最大字段和问题解决
    O(n3 )

    解法二


**/


/**
    堆排序： 构建堆，交换元素并维护堆

    思想到很好理解，不过编程细节，边界条件容易出错

    建立堆时，从a[len/2]（a[0]处为临时量）循环往a[1]下滤建堆

    别人写堆排序时间消耗是我的16分之1.
**/
/*
#include <iostream>
#include <string>
//#include <vector>
using namespace std;


void heapSort(int* arr, int len);
void buildMaxHeap(int* arr, int len);
void adjustDown(int* arr, int k, int len);
void buildMinHeap(int* arr, int len);
void adjustDown_(int* arr, int k, int len);

int arr[1000];

int main(){
    int i(1);
    while(cin>>arr[i])++i;
    heapSort(arr, i-1);
}

void heapSort(int* arr, int len){
    //buildMaxHeap(arr, len);
    buildMinHeap(arr, len);
    for(int i(len); i>1; --i)
        swap(arr[1], arr[i]), adjustDown_(arr, 1, i-1);
    for(int i(1); i<len; ++i)
        cout<<arr[i]<<" ";
    cout<<arr[len]<<endl;
}

void buildMaxHeap(int* arr, int len){
    for(int i(len/2); i>=1; --i)
        adjustDown(arr, i, len);
    for(int i(1); i<len; ++i)
        cout<<arr[i]<<" ";
    cout<<arr[len]<<endl;
}

void buildMinHeap(int* arr, int len){
    for(int i(len/2); i>=1; --i)
        adjustDown_(arr, i, len);
    for(int i(1); i<len; ++i)
        cout<<arr[i]<<" ";
    cout<<arr[len]<<endl;
}

void adjustDown(int* arr, int k, int len){
    arr[0]=arr[k];
    for(int i(2*k); i<=len; i*=2){
        if(i<len && arr[i]<arr[i+1])
            ++i;
        if(arr[0]>arr[i])
            break;
        else
            arr[k]=arr[i], k=i;
    }
    arr[k]=arr[0];
}

void adjustDown_(int* arr, int k, int len){
    arr[0]=arr[k];
    for(int i(2*k); i<=len; i*=2){
        if(i<len && arr[i]>arr[i+1])
            ++i;
        if(arr[0]<arr[i])
            break;
        else
            arr[k]=arr[i], k=i;
    }
    arr[k]=arr[0];
}
*/

/**
    0-1背包问题
    DP，递推填表

    val[]表示物品价值，wgt[]表示物品重量，重量为0的物品价值为0
    arr[i][j]表示背包重量为i且只能选1到j个物品时的最价值

    1.若是部分背包问题，即物品按计量单位算，则贪心解决
    2.若问法是必须装满背包的前提下，则0-1背包问题的初始化为负无穷
**/
/*
#include <iostream>
#include <string>
using namespace std;

#define nums 3
#define totalWeigth 5

int main(){
    //加上0  编程更方便
    int val[nums+1]={0, 60, 100, 120};
    int wgt[nums+1]={0, 1, 2, 3};
    int arr[totalWeigth+1][nums+1]={0};

    for(int i(1); i<=totalWeigth; ++i)
        for(int j(1); j<=nums; ++j)
            if(wgt[j]>i)
                arr[i][j]=arr[i][j-1];
            else
                arr[i][j]=max(arr[i][j-1], arr[i-wgt[j]][j-1]+val[j]);
    cout<<arr[totalWeigth][nums]<<endl;
}
*/

/**
    bitset的使用
**/


/**
    编程之美2.1: 判断unsigned char变量二进制表示中1的个数
    思路:
    1.比较low的思路:循环吗模2取余并除2, 计算余数为1的个数
    2.判断低位是否为1(& 0x1)然后右移1位(>>1),循环更新num直到为0停止
    3.查表法,统计256个数字的1的个数建表,典型的空间换时间,,,

    >>运算符的操作数是右值,~运算符的操作数也是右值
**/
/*
#include <iostream>
#include <string>
using namespace std;

int countOne(unsigned char a);

int main(){
    unsigned char a(8);
    cout<<countOne(a)<<endl;
}
int countOne(unsigned char a){
    int num(0);
    //while(a>=1)
    while(a){
        num+=a&0x1;
        a>>=1;
    }
    return num;
}
*/

/**
    输入一个字符串，可以去掉某些字符，求最大回文字符串长度
    1.当时问题：完全没思路
    1.2.后来发现可以转化为与逆序列的最长公共子序列问题，但木脑袋没做过LCS，当时也想不出来

    2.经典DP案例LCS，要点是从最后一对字符分析开始，相同和不相同情况下入手
**/
/*
#include <iostream>
#include <string>
using namespace std;

int getLCS(char*, int, char*, int);

int main(){
    string a;
    cin>>a;
    string b(' ',a.size());
    for(int i(0), siz(a.size()); i<siz; ++i)
        b[siz-1-i]=a[i];
    //const_cast<char*>(a.c_str())
    cout<<getLCS(const_cast<char*>(a.c_str()), a.size(), const_cast<char*>(b.c_str()), b.size())<<endl;
}

int getLCS(char* a, int al, char* b, int bl){
    if(al==0 || bl==0)
        return 0;
    if(a[al]==b[bl])
        return getLCS(a, al-1, b, bl-1)+1;
    else
        return max(getLCS(a, al, b, bl-1), getLCS(a, al-1, b, bl));
}
*/

/**
    打印蛇形矩阵
    1.当时问题： 首先题意没看明白，智商堪忧，
    对一次排开硬是理解成依次排开，往找每行数的规律方面想了
    2.要点： 分解问题成多个一圈，，，，
**/
/*
#include <iostream>
#include <string>
using namespace std;

void getSX(int**,int);
void inputValue(int**,int, int, int*);
int main(){
    int n(0);
    cin>>n;
    //
    int** arr=new int* [n];
    for(int i(0);i<n;++i)
        arr[i]=new int[n];

    getSX(arr, n);

    for(int i(0);i<n;++i)
        for(int j(0);j<n;++j)
            cout<<arr[i][j]<<" ";
    cout<<endl;
}


void getSX(int** arr, int n){
    int sta(0);
    int* val=new int;
    *val=1;
    //cout<<*val++<<endl;
    while(sta*2<n)
        inputValue(arr,sta,n,val), ++sta;
}

void inputValue(int** arr, int sta, int n, int* val){
    for(int row(sta), col(sta); col<=n-sta-1; ++col)
        arr[row][col]=(*val)++;
    for(int row(sta+1), col(n-sta-1); row<=n-sta-1; ++row)
        arr[row][col]=(*val)++;
    for(int row(n-sta-1), col(n-sta-1-1); col>=sta; --col)
        arr[row][col]=(*val)++;
    for(int row(n-sta-1-1), col(sta); row>=sta+1; --row)
        arr[row][col]=(*val)++;
}
*/


/**
    格雷码

**/


/**
    一组数中,有个数字重复一半以上,求该数
**/

/**
    大数相乘
    模仿两个数相乘的规则，被乘数为两个数中较大者
**/
/*
#include <iostream>
#include <string>
using namespace std;

void twoNumAdd(string& a, string& b);

int main(){
    //
    string a, b;
    cin>>a>>b;
    //
    unsigned char aSize=a.size(), bSize=b.size();
    for(int i(0); i<aSize; ++i)
        if(a[i]<'0' && a[i]>'9'){
            cout<<"Bad input!"<<endl;
            return -1;
        }
    for(int i(0); i<bSize; ++i)
        if(b[i]<'0' && b[i]>'9'){
            cout<<"Bad input!"<<endl;
            return -1;
        }
    //
    int maxLen(0), strLen(0), mutiTimes(0);
    if(aSize>bSize)
        maxLen=aSize, strLen=aSize*2, mutiTimes=bSize;
    else
        maxLen=bSize, strLen=bSize*2, mutiTimes=aSize, a.swap(b);

    //a*b
    string tmp(strLen, '0'), res(strLen, '0'), tmpTmp=tmp;
    for(int i(mutiTimes-1); i>=0; --i){
        int pushNum(0), s1(0), s2(0), xj(0);
        for(int j(maxLen-1); j>=0; --j){
            s1=a[j]-'0', s2=b[i]-'0', xj=s1*s2;
            //cout<<maxLen+j+(i-mutiTimes+1)<<endl;
            //cout<<(tmp[maxLen+j+(i-mutiTimes+1)]=(xj+pushNum)%10+'0')<<endl;
            tmp[maxLen+j+(i-mutiTimes+1)]=(xj+pushNum)%10+'0';
            pushNum=(xj+pushNum)/10;
        }
        tmp[maxLen-1-(mutiTimes-1-i)]=pushNum+'0';
        //cout<<tmp<<endl;
        twoNumAdd(res, tmp);
        tmp=tmpTmp;
    }
    cout<<res.substr(res.rfind('0')+1)<<endl;
}

void twoNumAdd(string& a, string& b){
    int pushNum(0), s1(0), s2(0), xj(0);
    for(int i(a.size()-1); i>=0; --i){
        s1=a[i]-'0', s2=b[i]-'0', xj=s1+s2;
        a[i]=(xj+pushNum)%10+'0';
        pushNum=(xj+pushNum)/10;
    }
}
*/

